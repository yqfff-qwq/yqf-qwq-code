#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=19,mod=998244353;
int n,m,q,inv[N+1],f[1<<N],e[1<<N],ppc[1<<N],g[1<<N],cof[1<<N],res[1<<N],tmp[N+1],f1[1<<N],f2[1<<N];
int dp[N][1<<N];
int ksm(int x,int y=mod-2){
	int res=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)res=1ll*res*x%mod;
	return res;
}
void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
signed main(){
	freopen("stalemate.in","r",stdin);
	freopen("stalemate.out","w",stdout);
	n=rd(),m=rd(),q=rd();
	inv[0]=1;
	for(int i=1;i<=n;i++)inv[i]=ksm(i);
	for(int i=0;i<n;i++)f[1<<i]=1;
	for(int u,v;m--;)u=rd()-1,v=rd()-1,e[1<<u|1<<v]++;
	for(int i=0;i<n;i++)
		for(int s=0;s<1<<n;s++)if(s>>i&1)e[s]+=e[s^1<<i];
	for(int i=1;i<1<<n;i++)ppc[i]=ppc[i>>1]+(i&1);
	for(int s=1;s<1<<n;s++){
		for(int t=(s-1)&s;t;t=(t-1)&s){
			int coef=e[s]-e[t]-e[t^s];
			f[s]=(f[s]+1ll*f[t]*f[s^t]%mod*coef)%mod;
		}
		f[s]=1ll*f[s]*inv[ppc[s]-1]%mod;
	}

	for(int s=1;s<1<<n;s++){
		int A=s^((1<<n)-1);
		cof[0]=1;
		for(int t=A;t;t=(t-1)&A){
			int lb=t&-t,coef=e[s|lb]-e[s];
			cof[t]=1ll*cof[lb^t]*coef%mod;
			g[t]=1ll*f[s]*cof[t]%mod;
		}
	}
	for(int s=0;s<1<<n;s++){
		int A=s^((1<<n)-1);
		for(int t=A;;t=(t-1)&A){
			if(ppc[t]&1)add(res[s],mod-g[s|t]);
			else add(res[s],g[s|t]);
			if(!t)break;
		}
	}
	for(int s=0;s<1<<n;s++)add(tmp[ppc[s]],res[s]);
	// for(int s=0;s<1<<n;s++)cout<<f[s]<<" ";
	// cout<<'\n';
	for(;q--;){
		int ans=0;
		for(int i=1,x;i<=n;i++)
			x=rd(),ans=(ans+1ll*tmp[i]*x)%mod;
		cout<<ans<<'\n';
	}
	return 0;
}