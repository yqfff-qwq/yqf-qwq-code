#include<bits/stdc++.h>
#define ll long long
#define dd double
#define ull unsigned ll
#define LL __int128
#define siz(A) ((int)A.size())
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
char ST;
const int mod=998244353;
const int xx=505;
int n;
char s[xx];
int f[xx][xx],C[xx][xx];
int red(int x){return x>=mod?x-=mod:x;}
void ad(int &a,ll b){a=(a+b)%mod;}
char ED;
int main(){
	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
	freopen("sub.in","r",stdin);
	freopen("sub.out","w",stdout);
	cin>>n;
	scanf("%s",s+1);
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)C[i][j]=red(C[i-1][j]+C[i-1][j-1]);
	for(int i=1;i<=n+1;i++)f[i][i-1]=1,f[i][i]=(s[i]!=s[i-1]);
	for(int l=n;l>=1;l--)
	{
		for(int r=l+1;r<=n;r++)
		{
			for(int k=l;k<=r;k++)
				if(s[k]!=s[l-1])ad(f[l][r],1ll*f[l][k-1]*f[k+1][r]%mod*C[r-l][k-l]);
//			cerr<<l<<" "<<r<<" "<<f[l][r]<<" "<<s[l-1]<<"#\n";
		}
	}
	cout<<f[1][n]<<"\n";
	pc('1',1);
	return 0;
}
