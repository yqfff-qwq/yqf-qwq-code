#include<bits/stdc++.h>
#define ll long long 
//#define int long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
int n,p,m;
const int mod=998244353,xx=1005;
int dw[xx],jiec[xx],ni[xx],up[xx];
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int N; 
void pred(int n)
{
	N=n;
	dw[0]=1;
	for(int i=1;i<xx;i++)dw[i]=1ll*dw[i-1]*(n-i+1)%mod;
}
ll Cd(ll m)
{
	if(m>N)return 0;
	return 1ll*dw[m]*ni[m]%mod;
}
void preu(int n)
{
	N=n;
	up[0]=1;
	for(int i=1;i<xx;i++)up[i]=1ll*up[i-1]*(n+i-1)%mod;
}
ll Cu(ll m)
{
	//$\binom{n+m-1}{n-1}$ 
	//$\binom{n+m-1}{m}$ 
	return 1ll*up[m]*ni[m]%mod;
}
//���巨�������� 
ll C(int n,int m){return 1ll*jiec[n]*ni[m]%mod*ni[n-m]%mod;}
int is[xx],id[xx],v[xx],ct[xx];
int ans[52][xx];
int f[51][xx][51];
signed main(){
	freopen("probability.in","r",stdin);
	freopen("probability.out","w",stdout);
	n=read(),p=read(),m=read();
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=1ll*ni[i+1]*(i+1)%mod;
	int nw=1,tt=0,L=0,R=-1;
	for(int i=1;i<=n;i++)
	{
		nw%=p;
		if(is[nw])
		{
			L=id[nw],R=i-1;
			break;
		}
		++ct[nw];
		id[nw]=++tt,v[tt]=nw,is[nw]=1,nw*=10,nw%=p;
	}
	if(R!=-1)
	{
		int k=(n-R)/(R-L+1);
		for(int i=L;i<=R;i++)ct[v[i]]+=k;
		nw=v[R]*10%p;
		for(int i=R+k*(R-L+1)+1;i<=n;i++)
		{
			nw%=p;
			++ct[nw];
			id[nw]=++tt,v[tt]=nw,is[nw]=1,nw*=10,nw%=p;
		}
	}
	
	for(int i=0;i<p;i++)
	{
		preu(ct[i]),pred(ct[i]);
		for(int j=0;j<=m;j++)
		{
			ll res=0;
			for(int k=0;;k++)
			{
				if(j-10*k<0)break;
				if(k&1)res-=Cd(k)*Cu(j-10*k)%mod;
				else res+=Cd(k)*Cu(j-10*k)%mod;
			}
			res%=mod,res+=mod,res%=mod;
			ans[i][j]=res;
		}
	}
	f[0][0][0]=1;
	for(int j=0;j<p;j++)
	{
		for(int i=0;i<=m;i++)
		{
			for(int k=0;k<p;k++)
			{
				if(!f[j][i][k])continue;
				int v=f[j][i][k];
				for(int zy=0;zy<=min(m-i+0ll,ct[j]*9ll);zy++)
					f[j+1][i+zy][(k+zy*j)%p]=(f[j+1][i+zy][(k+zy*j)%p]+1ll*v*ans[j][zy])%mod;
			}
		}
	}
	for(int i=0;i<=m;i++)if(i!=0)f[p][i][0]=(f[p][i][0]+f[p][i-1][0])%mod;
	for(int i=0;i<=m;i++)
		cout<<f[p][i][0]<<" ";
	puts("");
	pc('1',1);
	return 0;
}
