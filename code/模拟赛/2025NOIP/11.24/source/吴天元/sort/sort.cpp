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
	cint N = 2e3 + 5;
	int n,a[N],nxt[N];
	vector<vector<int>>ans;
	void SOLVE(){
		n=rd();
		F(i,1,n){
			a[i]=rd();
			nxt[i]=a[i];
		}
		int l=1,mx=0,mn=INF;
		vector<int>vec;
		F(r,1,n){
			cmx(mx,a[r]);
			cmn(mn,a[r]);
			if(mx==r&&mn==l){
				if(l!=r){
					int x=l;
					vec.pb(x);
					x=nxt[x];
					while(x!=l){
						vec.pb(x);
						x=nxt[x];
					}
					ans.pb(vec);
					vec.clear();
				}
				mx=0,mn=INF;
				l=r+1;
			}
		}
		printf("%lld\n",SZ(ans));
		for(vector<int>i:ans){
			printf("%lld ",SZ(i));
			for(int j:i){
				printf("%lld ",j);
			}
			puts("");
		}
		return ;
	}
}

signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int T=1;
	// T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}