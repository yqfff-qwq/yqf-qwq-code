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
	cint N = 1e4 + 5;
	int n,t,nxt[N],m,ans[N];
	bool vis[N<<1];
	struct node{
		int l,r,id;
		friend bool operator<(const node &a,const node &b){
			if(a.r==b.r){
				return a.l<b.l;
			}
			return a.r<b.r;
		}
	}a[N];

	struct line{
		int l,r;
		friend bool operator<(const line &a,const line &b){
			return a.l<b.l;
		}
	}b[N];

	set<int>S;

	void sub1(){
		sort(a+1,a+n+1);
		F(i,1,n){
			int l=a[i].l,r=a[i].r;
			while(S.find(l)!=S.end()&&l<=r){
				++l;
			}
			if(l>r){
				puts("no");
			}
			ans[a[i].id]=l;
			S.insert(l);
		}
		puts("yes");
		F(i,1,n){
			printf("%lld ",ans[i]);
		}
	}

	mt19937 rnd;
	int get(int l,int r){
		return rnd()%(r-l+1)+l;
	}

	void SOLVE(){
		n=rd(),t=rd();
		F(i,1,n){
			int l=rd(),r=rd()-1;
			if(r-l+1<t){
				puts("no");
				return ;
			}
			a[i]=(node){l,r,i};
		}
		if(t==1){
			sub1();
			return ;
		}
		int cnt=1e8/(n*__lg(n));
		while(cnt--){
			F(i,1,n){
				b[i].l=get(a[i].l,a[i].r-t+1);
				b[i].r=b[i].l+t-1;
				ans[i]=b[i].l;
			}
			sort(b+1,b+n+1);
			bool fl=1;
			F(i,2,n){
				if(b[i-1].r>=b[i].l){
					fl=0;
					break;
				}
			}
			if(fl){
				puts("yes");
				F(i,1,n){
					printf("%lld ",ans[i]);
				}
				// cerr<<'\n';
				// F(i,1,n){
				// 	cerr<<b[i].l<<' '<<b[i].r<<'\n';
				// }
				return ;
			}
		}
		puts("no");
		return ;
	}
}

signed main(){
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	int T=1;
	// T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}