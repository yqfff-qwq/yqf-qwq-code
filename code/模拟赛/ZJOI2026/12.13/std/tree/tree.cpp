// 私は猫です

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define inf 1000000000
#define infll 1000000000000000000ll
#define pii pair<int,int>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define dF(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
#define HH printf("\n")
#define eb emplace_back
#define poly vector<int>
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
void fre(){
	freopen("tree.in","r",stdin),freopen("tree.out","w",stdout);
}
template<typename T>inline void chkmax(T &x,const T &y){ x=std::max(x,y); }
template<typename T>inline void chkmin(T &x,const T &y){ x=std::min(x,y); }
const int maxn=105;
int mod,n,a[maxn],siz[maxn],f[maxn][maxn][2],nxt[maxn][maxn][2];
int dp[maxn][maxn][maxn],d[maxn][maxn],c[maxn][maxn];
vector<int>g[maxn];
inline int qpow(int x,ll y){
	int rt=1;
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) rt=1ll*rt*x%mod;
	return rt;
}
inline void inc(int &x,const int y){ x=(x+y>=mod)?(x+y-mod):(x+y); }
inline void dec(int &x,const int y){ x=(x>=y)?(x-y):(x+mod-y); }
inline void mul(int &x,const int y){ x=1ll*x*y%mod; }
inline int add(const int x,const int y){ return (x+y>=mod)?(x+y-mod):(x+y); }
inline int sub(const int x,const int y){ return (x>=y)?(x-y):(x+mod-y); }
inline int prod(const int x,const int y){ return 1ll*x*y%mod; }
void dfs(int u,int fa=0){
	for(int v:g[u])if(v^fa)dfs(v,u);
	memset(f,0,sizeof f),memset(c,0,sizeof c),f[0][0][0]=1,f[0][0][1]=a[u];
	for(int v:g[u])if(v^fa){
		F(i,0,siz[u]+siz[v])F(j,0,siz[u]+siz[v])nxt[i][j][0]=nxt[i][j][1]=0;
		F(i,0,siz[u])F(j,0,siz[u]-i){
			const int v1=f[i][j][0],v2=f[i][j][1];
			if(!v1&&!v2)continue;
			F(p,0,siz[v])F(q,0,siz[v]-p){
				const int val=dp[v][p][q];
				if(!val)continue;
				if(v1){
					inc(nxt[i+p][j+q][0],1ll*v1*val%mod);
					if(p)inc(nxt[i+p-1][j+q][0],1ll*v1*val%mod*p%mod);
					if(q)inc(nxt[i+p][j+q-1][1],1ll*v1*val%mod*q%mod);
				}
				if(v2){
					inc(nxt[i+p][j+q][1],1ll*v2*val%mod);
					if(p)inc(nxt[i+p-1][j+q][1],1ll*v2*val%mod*p%mod);
				}
			}
		}
		F(i,0,siz[u]+siz[v])F(j,0,siz[u]+siz[v])f[i][j][0]=nxt[i][j][0],f[i][j][1]=nxt[i][j][1];
		siz[u]+=siz[v];
	}
	F(i,0,siz[u])F(j,0,siz[u])dp[u][i][j]=f[i][j][1];
	siz[u]=1,c[1][0]=1,c[0][1]=a[u];
	for(int v:g[u])if(v^fa){
		F(i,0,siz[u]+siz[v])F(j,0,siz[u]+siz[v])d[i][j]=0;
		F(i,0,siz[u])F(j,0,siz[u]-i){
			const int v1=c[i][j];
			if(!v1)continue;
			F(p,0,siz[v])F(q,0,siz[v]-p){
				const int val=dp[v][p][q];
				if(!val)continue;
				inc(d[i+p][j+q],1ll*v1*val%mod);
			}
		}
		F(i,0,siz[u]+siz[v])F(j,0,siz[u]+siz[v])c[i][j]=d[i][j];
		siz[u]+=siz[v];
	}
	F(i,0,siz[u])F(j,0,siz[u])inc(dp[u][i][j],c[i][j]);
}
void solve(){
	n=read(),mod=read();
	F(i,1,n)a[i]=read();
	F(_,1,n-1){
		const int u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	} dfs(1),printf("%d",dp[1][0][0]);
}
signed main(){
	fre(); const int zsy=1;
	F(____,1,zsy)solve();
}