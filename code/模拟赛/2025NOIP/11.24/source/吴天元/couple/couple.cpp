#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second
#define mid ((l+r)>>1)
#define gc getchar
#define pc putchar
#define cint const int

cint mod = 998244353;

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

	cint N = 105;

	int n,p[N],mx,mx1,sm,f[N][N*N*2];

	bool chk(int x){
		F(i,1,mx-1){
			if(x-i-p[i]<0){
				continue;
			}
			int a=f[i-1][min(sm,x-i-p[i])]+p[i];
			int b=sm-a-p[mx]-p[i]+mx;
			// cerr<<x<<' '<<i<<' '<<a<<' '<<b<<'\n';
			if(b<=x){
				return 1;
			}
		}
		return 0;
	}

	void SOLVE(){
		n=rd();
		F(i,1,100){
			p[i]=0;
		}
		mx=mx1=sm=0;
		F(i,1,n){
			int x=rd(),y=rd();
			cmx(p[x],y);
			cmx(mx,x);
			cmx(mx1,y);
		}
		F(i,1,mx){
			// cerr<<p[i]<<' ';
			sm+=p[i]*2;
		}
		// cerr<<'\n';
		F(i,1,mx){
			F(j,0,sm){
				f[i][j]=f[i-1][j];
			}
			F_(j,sm,p[i]*2){
				cmx(f[i][j],f[i-1][j-p[i]*2]+p[i]*2);
			}
		}
		int l=1,r=mx1*mx+mx+100,ans=0;
		while(l<=r){
			if(chk(mid)){
				ans=mid,r=mid-1;
			}else{
				l=mid+1;
			}
		}
		printf("%d\n",ans);
		return ;
	}
}

signed main(){
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	int T=1;
	T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}