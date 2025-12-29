#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template <typename T>
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
	
	template <typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
	
}
using namespace quick_io;

#define int long long
string s;
int sum;
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>s;
	for(auto x:s) sum+=x-'0';
	for(int i=1;i<s.size();i++) if(s[i]!=s[i-1]) print(i),exit(0);
	print(s.size());
}

//100 Pts
