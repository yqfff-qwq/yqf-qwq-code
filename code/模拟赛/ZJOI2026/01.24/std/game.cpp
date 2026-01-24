#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pr pair<int,int>
#define _(x,y) x=(x+y)%mod
#define ll long long
	#define N 500005
ll read(){ll d=1,k=0;char c=getchar();
while(!(c>='0' and c<='9' or c=='-'))c=getchar();if(c=='-')d=-1,c=getchar();
while(c>='0' and c<='9')k=(k<<3)+(k<<1)+(c^48),c=getchar();return d*k;}
int n,m,son[N*60][2],cnt[N*60],pool;
ll a[N];
pair<ll,int> b[N];
ll f[5],sq[N*60];
#define fi first
#define se second
inline void insert(ll x,int c){
	int p=1;
	for(int i=0;i<60;++i){
		int k=((x>>i)&1ll);
		if(!son[p][k]){
			son[p][k]=++pool;
			son[pool][0]=son[pool][1]=0;
			cnt[pool]=0;
			sq[pool]=0;
		}
		p=son[p][k];
	}
	cnt[p]=c;
	sq[p]=1LL*c*(c-1)/2;
}
void dfs1(int u){
	if(son[u][0]){
		dfs1(son[u][0]);
	}
	if(son[u][1]){
		dfs1(son[u][1]);
	}
	if(son[u][0] || son[u][1]){
		cnt[u]=cnt[son[u][0]]+cnt[son[u][1]];
		sq[u]=sq[son[u][0]]+sq[son[u][1]];
	}
}
ll ans;
void dfs2(int u,int dep){
	if(dep&1){
		if(son[u][0] && son[u][1]){
			ans+=1LL*sq[son[u][0]]*cnt[son[u][1]]+1LL*cnt[son[u][0]]*sq[son[u][1]];
		}
	}
	if(son[u][0]){
		dfs2(son[u][0],dep+1);
	}
	if(son[u][1]){
		dfs2(son[u][1],dep+1);
	}
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(int cas=read();cas--;){
		ans=0;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		sort(a+1,a+n+1);
		m=0;
		for(int l=1,r=1;l<=n;l=r+1){
			r=l;
			while(r+1<=n && a[r+1]==a[r]) r++;
			b[++m]={a[l],r-l+1};
		}
		f[0]=1;
		f[1]=f[2]=f[3]=0;
		for(int i=1;i<=m;++i){
			for(int j=3;j>=1;--j){
				f[j]+=f[j-1]*(ll)b[i].se;
			}
		}
		pool=1;
		son[1][0]=son[1][1]=0;
		cnt[1]=sq[1]=0;
		for(int i=1;i<=m;++i){
			insert(b[i].fi,b[i].se);
		}
		dfs1(1);
		dfs2(1,0);
		printf("%lld\n",ans+f[3]);
	}
	return 0;
}
