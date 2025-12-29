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
const int N=5e5+10;
const int maxM=1e8+10;

int v[N],m[N],f[maxM];
int n,M;

bool cmp(int A,int B){
	return A>B;
}
signed main(){
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	input(n);
	input(M);
	for(int i=1;i<=n;i++) input(v[i]),input(m[i]);
	int g=m[1];
	for(int i=2;i<=n;i++) g=min(g,m[i]);
	M/=g;
	for(int i=1;i<=n;i++) m[i]/=g;
	int sum=0;
	for(int i=1;i<=n;i++) sum+=m[i];
	if(sum==n){
		sort(v+1,v+1+n,cmp);
		for(int i=1;i<=n;i++) v[i]+=v[i-1];
		print(v[min(n,M)]);
		exit(0);
	}
	for(int i=1;i<=n;i++)
		for(int j=M;j>=m[i];j--)
			f[j]=max(f[j],f[j-m[i]]+v[i]);
	print(f[M]);
}

