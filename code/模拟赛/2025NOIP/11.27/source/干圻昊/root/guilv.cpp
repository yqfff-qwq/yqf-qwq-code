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
int solve(int n,int m){
	int ans=0;
	for(int i=0;i<=m;i++){
		if((i^(n-1))%n==1){
			ans++;
		}
	}
	return ans;
}

signed main(){
	freopen("root.in","r",stdin);
//	freopen("root.ans","w",stdout);
	cout<<" "<<2<<" ";
	for(int i=2;i<=70;i++,putchar('\n'),printf("%2d ",i))
		for(int j=0;j<=50;j++)
				printf("%2d",solve(i,j));
	//30 Pts
}

