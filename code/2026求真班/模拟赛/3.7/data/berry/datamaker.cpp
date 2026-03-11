#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
#define int long long
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
ll T=1;
ll Rand(int l,int r)
{
	ll p=0;
	p*=RAND_MAX;p+=rand();
	p*=RAND_MAX;p+=rand();
	p*=RAND_MAX;p+=rand();
	return p%(r-l+1)+l;
}
signed main(){
	srand(time(0));
	freopen("sub4-2.in","w",stdout);
	T=1e5;
	cout<<T<<"\n";
	while(T--){
		int n=Rand(1,1e18),m=Rand(1,1e18);
		if(rand()%10==0) n=m+Rand(0,1);
		if(rand()%10==0) n=m-Rand(0,1);
		if(rand()%2) swap(n,m);
		cout<<n<<" "<<m<<"\n";
	}
	return 0;
}
//sub 1:1<=n,m<=5 T<=10
//sub 2:n=1 or m=1 T<=1e5
//sub 3:random data T<=1e5
//sub 4:1<=n,m<=1e18 T<=1e5
