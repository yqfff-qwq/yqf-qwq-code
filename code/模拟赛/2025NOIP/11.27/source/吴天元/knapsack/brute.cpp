#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pb emplace_back
#define SZ(a) ((int)(a).size())
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define gc getchar
#define cint const int

cint mod = 998244353;

cint INF = 1e18;

inline void cmx(int &a,int b){
	a=max(a,b);
}

inline void cmn(int &a,int b){
	a=min(a,b);
}

inline void add(int &a,int b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
	if(a<mod){
		a+=mod;
	}
}

inline int rd(){
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
	cint N = 5e5 + 5;
	cint V = 1e7 + 5;
	int n,M,f[V];
	struct node{
		int v,m;
	}a[N];
	void SOLVE(){
		n=rd(),M=rd();
		F(i,1,n){
			int v=rd(),m=rd();
			a[i]=(node){v,m};
		}
		int ans=0;
		F(i,1,n){
			F_(j,M,a[i].m){
				cmx(f[j],f[j-a[i].m]+a[i].v);
			}
		}
		F(i,1,M){
			cmx(ans,f[i]);
		}
		printf("%lld\n",ans);
		return ;
	}
}

signed main(){
	freopen("knapsack.in","r",stdin);
	freopen("brute.out","w",stdout);
	int T=1;
	// T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}