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

int lowbit(int x){
	return x&-x;
}
void solve(){
	int n,m;
	input(n);
	input(m);
	if(lowbit(n)==n){
		if(m<=n-1) print(0);
		else print(m/n);
		putchar('\n');
		return;
	}
//	cout<<m<<endl;
	int ans=0;
	for(int k=0;;k++){
		int i=(k*n+1)^(n-1);
//		cout<<i<<endl;
//		if(i>2*m) cout<<i<<" "<<2*m<<endl;
		if(i>2*m&&k>=100) break;
		if(i<=m) ans++;
	}
	print(ans);
	putchar('\n');
}

signed main(){
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	int T;
	input(T);
	while(T--) solve();
	
	//60 Pts
}

