#include <iostream>
using namespace std;
#define ll long long
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
ll a,b;
int main(){
	freopen("sub1-7.in","r",stdin);
	freopen("sub1-7.out","w",stdout);
	int t=read();
	while(t--)
	{
		a=read();
		b=read();
		if(abs(a-b)>1)
			cout<<"Yes"<<"\n";
		else
			cout<<"No"<<"\n";
	}
	
	return 0;
	
}
