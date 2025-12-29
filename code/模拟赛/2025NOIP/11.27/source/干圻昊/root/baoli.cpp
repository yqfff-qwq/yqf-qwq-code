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
void solve(){
	int n,m;
	input(n);
	input(m);
	int ans=0;
	for(int i=0;i<=m;i++){
		if((i^(n-1))%n==1){
			ans++;
		}
	}
	print(ans);
	putchar('\n');
}

signed main(){
	freopen("root.in","r",stdin);
	freopen("root.ans","w",stdout);
	int T;
	input(T);
	while(T--) solve();
	
	//30 Pts
}

