#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second
#define gc getchar
#define pc putchar
#define cint const int

cint mod = 998244353;

cint INF = 1e18;

void cmx(int &a,int b){
	a=max(a,b);
}

void cmn(int &a,int b){
	a=min(a,b);
}

void add(int &a,int b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
	if(a<0){
		a+=mod;
	}
}

int rd(){
	int x=0,y=1;
	char c=gc();
	for(;!isdigit(c);c=gc()){
		if(c=='-'){
			y=-1;
		}
	}
	for(;isdigit(c);c=gc()){
		x=(x<<3)+(x<<1)+(c^48);
	}
	return x*y;
}

namespace Day_Tao{
	cint N = 1e5 + 5;
	cint M = 2e5 + 5;
	bitset<100000>f[N];
	int n,m,r,ans[N];
	vector<int>G[N];
	struct query{
		int l,r,id;
	};
	vector<query>qu[N];
	void dfs(int u,int fa){
		// cerr<<u<<'\n';
		f[u][u-1]=1;
		for(int v:G[u]){
			if(v==fa){
				continue;
			}
			dfs(v,u);
			f[u]|=f[v];
		}
		// cerr<<u<<' '<<f[u].count()<<'\n';
		for(query q:qu[u]){
			int l=q.l,r=q.r,id=q.id;
			int x=0;
			for(int v:G[u]){
				if(v==fa){
					continue;
				}
				bitset<100000>t;
				t=f[v]<<(100000-r);
				t>>=(100000-(r-l+1));
				int y=t.count();
				// int y=0;
				// F(i,l,r){
				// 	if(f[v][i-1]){
				// 		++y;
				// 	}
				// }
				ans[id]+=x*y;
				x+=y;
			}
			if(l<=u&&u<=r){
				ans[id]+=x;
			}
		}
	}
	void SOLVE(){
		n=rd(),m=rd(),r=rd();
		F(i,2,n){
			int u=rd(),v=rd();
			G[u].pb(v);
			G[v].pb(u);
		}
		F(i,1,m){
			int l=rd(),r=rd(),x=rd();
			qu[x].pb((query){l,r,i});
		}
		dfs(r,0);
		F(i,1,m){
			printf("%lld\n",ans[i]);
		}
		return ;
	}
}

signed main(){
	freopen("rplexq.in","r",stdin);
	freopen("rplexq.out","w",stdout);
	int T=1;
	// T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}