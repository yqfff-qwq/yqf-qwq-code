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

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int T=1;;T++){
		cout<<"Case #"<<T<<endl;
		system("mkd.exe");
		system("baoli.exe");
		system("root.exe");
		if(system("fc root.ans root.out")) break;
	}
}

