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

const int N=1e5+10;
int g[N][110];

int a[N];

int maxV,maxL,minR;
int n,Q,C;

struct ques{
	int l,r,x;
};
vector<ques> q;

namespace baoli{
	int f(int l,int r,int x){
		if(l==r) return abs(a[l]-x);
		else return abs(a[r]-f(l,r-1,x));
	}
	void Main(){
		for(auto x:q){
			print(f(x.l,x.r,x.x));
			putchar('\n');
		}
	}	
}

namespace A{
	int f(int l,int r,int x){
		if(l==r) return g[r][x]=abs(a[l]-x);
		else return g[r][x]=abs(a[r]-f(l,r-1,x));
	}
	void Main(){
		for(int i=1;i<=100;i++) f(1,n,i); 
		for(auto x:q){
			print(g[x.r][x.x]);
			putchar('\n');
		}
	}
}

namespace B{
	int f(int l,int r,int x){
		if(l==r) return g[r][x]=abs(a[l]-x);
		else return g[r][x]=abs(a[r]-f(l,r-1,x));
	}
	void Main(){
		for(int i=1;i<=100;i++) f(1,n,i); 
		for(auto x:q){
			print(g[x.r][x.x]);
			putchar('\n');
		}
	}
}

namespace AB{
	
}

signed main(){
	freopen("reflection.in","r",stdin);
	freopen("reflection.out","w",stdout);
	input(n);
	input(Q);
	input(C);
	for(int i=1;i<=n;i++) input(a[i]);
	while(Q--){
		int l,r,x;
		input(l);
		input(r);
		input(x);
		q.push_back({l,r,x});
		maxL=max(maxL,l);
		minR=min(minR,r);
		maxV=max(maxV,x);
	}
	if(maxV<=100&&maxL==1) A::Main();
	else baoli::Main();
}

