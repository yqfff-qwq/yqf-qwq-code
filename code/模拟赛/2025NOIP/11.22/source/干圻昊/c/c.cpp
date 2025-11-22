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
int mod;
const int N=200;
int fac[N],inv[N];

int quickmi(int a,int b,int p){
	int res=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;
	return res;
}

int C(int n,int m){
	if(n<m||m<0) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;	
}

int H(int n){
	return (C(2*n,n)-C(2*n,n-1)+mod)%mod;
}

int n,v;
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	input(n);
	input(v);
	input(mod);
	if(v>n) puts("0"),exit(0);
	fac[0]=1;
	for(int i=1;i<=2*n;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=0;i<=2*n;i++) inv[i]=quickmi(fac[i],mod-2,mod);
	int t=C(n-1,v-1);
	print(H(n)*t%mod);
}

