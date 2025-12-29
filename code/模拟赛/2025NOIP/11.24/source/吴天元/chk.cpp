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
	void SOLVE(){
		system("g++ a.cpp -o a -std=c++14 -O2");
		system("g++ brute.cpp -o b -std=c++14 -O2");
		system("g++ mkd.cpp -o m -std=c++14 -O2");
		F(i,1,1145141919810ll){
			system("./m");
			system("./a");
			system("./b");
			printf("%lld :",i);
			if(system("diff a.out brute.out -Z")){
				puts("WA");
				return ;
			}
			puts("AC");
		}
		return ;
	}
}

signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int T=1;
	// T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}