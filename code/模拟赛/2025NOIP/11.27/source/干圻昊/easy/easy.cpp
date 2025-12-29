#include <bits/stdc++.h>
using namespace std;

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
}
using namespace quick_io;

#define int long long
const int N=2e5+10;
const int mod=998244353;
int a[N];

int gcd(int a,int b){
	if(!a||!b) return a+b;
	else return __gcd(a,b);
}
void solve(){
	int n,k;
	input(n);
	input(k);
	for(int i=1;i<=n;i++) input(a[i]);
	if(!a[1]&&!a[2]) print(2);
	else print((k+1)%mod);
	putchar('\n');
}

signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int T;
	input(T);
	while(T--) solve();
}

