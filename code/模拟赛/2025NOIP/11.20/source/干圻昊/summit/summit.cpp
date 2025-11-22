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
const int N=2e3+10;
const int INF=1e18;
int f[N][N];
int tmin[N][N];

int n,l,r;
int a[N],b[N];

void update(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			tmin[i][j]=min({tmin[i][j-1],tmin[i-1][j],f[i][j]});
}

void solve(){
	input(n);
	input(l);
	input(r);
	for(int i=1;i<=n;i++) input(a[i]);
	for(int i=1;i<=n;i++) input(b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i>j) f[i][j]=INF;
			else f[i][j]=a[i]+b[j];
	update();
	for(int k=2;k<=r;k++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i>j) f[i][j]=INF;
				else f[i][j]=tmin[i-1][j-1]+a[i]+b[j];
		update();
	}
//	for(int i=0;i<=n;i++,putchar('\n'))
//		for(int j=0;j<=n;j++) cout<<tmin[i][j]<<" ";
	print(tmin[n][n]);
	putchar('\n');
}
signed main(){
	freopen("summit.in","r",stdin);
	freopen("summit.out","w",stdout);
	for(int i=0;i<=2000;i++) tmin[0][i]=INF;
	for(int i=0;i<=2000;i++) tmin[i][0]=INF;
	int T;
	input(T);
	while(T--) solve();
}

