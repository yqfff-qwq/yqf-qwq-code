#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned int
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=1e6+5;
int n,m,q,f[N],res[N],d[N],x,y;
int getf(int x){
	if(x==f[x])return x;
	int y=f[x],t=getf(y);
	d[x]=(d[x]+d[y])%m;
	return f[x]=t;
}
int exgcd(int a,int b,int &x,int &y) {
	if(!b) {
		x=1;
		return a;
	}
	int d=exgcd(b,a%b,x,y),t=x;
	x=y;y=t-a/b*y;
	return d;
}
int calc(int x,int y){
	return x/__gcd(x,y)*y;
}
signed main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	n=rd(),m=rd(),q=rd();
	iota(f+1,f+n+1,1);
	fill(res+1,res+n+1,m);
	for(int op,x,y,w,a,b,c;q--;){
		op=rd(),x=rd(),y=rd();
		int fx=getf(x),fy=getf(y);
		if(op==1){
			w=rd();
			res[fy]=__gcd(res[fy],w*2%m);
			if(fx==fy){
				res[fy]=__gcd(res[fy],(w+d[x]+d[y])%m);
			}else{
				d[fx]=(d[x]+d[y]+w)%m;
				f[fx]=fy;
				res[fy]=__gcd(res[fy],res[fx]);
				res[fy]=__gcd(res[fy],d[fx]*2%m);
			}
		}else{
			a=rd(),b=rd()%m,c=rd();
			if(fx==fy){
				int p=0,q=0,r=(d[x]+d[y]-a+m)%m,
					dd=exgcd(b,res[fx],p,q);
				// cout<<dd<<' '<<r<<' '<<res[fx]<<' '<<c<<' '<<p<<' '<<q<<'\n';
				if(r%dd)cout<<0<<'\n';
				else {
					p*=r/dd;
					int t=res[fx]/dd;
					// cout<<t<<' '<<p<<'\n';
					p=(p%t+t)%t;
					if(c<=p)cout<<0<<'\n';
					else cout<<(int)(c-1-p)/t+1<<'\n';
				}
			}else cout<<0<<'\n';
		}
	}
	return 0;
}