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

#define int __int128
signed main(){
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	int n,t;
	input(n);
	input(t);
	if((n*n*n+t*t*t+n*n*t+t*t*n+t*n*t)%5==2) puts("no");
	else{
		puts("yes");
		for(int i=1;i<=n;i++) print(i),putchar(' ');
	}
}

