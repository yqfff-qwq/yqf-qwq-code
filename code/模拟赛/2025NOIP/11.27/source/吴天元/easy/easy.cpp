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
	cint N = 2e5 + 5;
	int n,k,a[N],f[N];
	int qpow(int a,int b){
		int c=1;
		for(;b;b>>=1,a=a*a%mod){
			if(b&1){
				c=c*a%mod;
			}
		}
		return c;
	}

	//995061180
	//248765296
	void SOLVE(){
		n=rd(),k=rd();
		F(i,1,n){
			a[i]=rd();
		}
		if(n==2){
			printf("%lld %lld %lld %lld\n",k/__gcd(a[1],__gcd(k,a[2]))+1,a[1],a[2],k);
			return ;
		}
		f[1]=1,f[2]=k+1;
		F(i,3,n){
			f[i]=(f[i-2]*k+f[i-1])%mod;
		}
		printf("%lld\n",f[n]);
		return ;
	}
}

signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int T=1;
	T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}