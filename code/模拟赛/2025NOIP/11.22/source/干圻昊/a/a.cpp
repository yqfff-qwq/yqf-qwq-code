#include <bits/stdc++.h>
using namespace std;

int a[]={0,2,3,6,7,8,9};
namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=' ';
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(f) x=-x;
	}
	
	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
	
	template<typename T>
	void print(T x,string &s){
		if(x>6) print(x/7,s);
		s+=(char)(a[x%7]+'0');
	}
} 
using namespace quick_io;

#define int long long
const int mod=998244353;

void solve(){
	int x;
	input(x);
	string res="";
	print(x-1,res);
	int ans=0;
	for(auto x:res) ans=(ans*10+x-'0')%mod;
	print(ans);
	putchar('\n');
}

signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	input(T);
	while(T--) solve();
}
