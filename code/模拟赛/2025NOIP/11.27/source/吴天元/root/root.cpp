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
	int n,m;
	int lowbit(int x){
		return x&(-x);
	}
	void SOLVE(){
		n=rd(),m=rd();
		int ans=0,sm=0;
		// F(i,0,m){
			// cerr<<(i^(n-1))<<' ';
		// }
		// cerr<<'\n';
		F_(i,62,0){
			if((m>>i)&1){
				// cerr<<i<<'\n';
				int t=sm+((n-1)&(1ll<<i));
				ans+=max(0ll,t+(1ll<<i)-2)/n-max(0ll,t-2)/n;
				// cerr<<t+(1<<i)-2<<' '<<t-2<<'\n';
			}
			sm+=(m^(n-1))&(1ll<<i);
			// cerr<<"#"<<i<<' '<<sm<<'\n';
		}
		ans+=max(0ll,(m^(n-1))-1)/n-max(0ll,((m^(n-1))-1)-1)/n;
		if(((n-1)^1)<=m){
			++ans;
		}
		printf("%lld\n",ans);
		return ;
	}
}

signed main(){
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	int T=1;
	T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}