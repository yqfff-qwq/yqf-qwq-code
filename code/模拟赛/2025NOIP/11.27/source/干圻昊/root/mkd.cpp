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
mt19937 rnd(time(0));
int Rand(int n){
	return rnd()%n+1;
}
signed main(){
//	freopen(".in","r",stdin);
	int n=Rand(1e6);
	int m=Rand(1e6);
	cout<<n<<" "<<m<<endl;
	freopen("root.in","w",stdout);
	print(1);
	putchar('\n');
	cout<<n<<" "<<m<<endl;
	
}

