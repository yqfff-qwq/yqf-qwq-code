#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pr;
typedef vector<LL> vi;
inline LL rd(){
	LL x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const LL N=1<<20,p=998244353;
LL qp(LL x,LL y){LL z=1;for(;y;y>>=1,x=x*x%p)if(y&1)z=z*x%p;return z;}
LL n,m,a[N],sm;
void f3(LL *f){
	for(LL i=2,j=1;i<=n;i<<=1,j<<=1)
	for(LL k=0;k<n;k+=i)for(LL l=0;l<j;++l){
		(f[k+l]+=f[k+l+j])%=p;f[k+l+j]=(f[k+l]-2*f[k+l+j]+2*p)%p;
	}
}
int main(){
    freopen("expect.in","r",stdin);
    freopen("expect.out","w",stdout);
	m=rd();n=1<<m;for(LL i=0;i<n;++i)a[i]=rd(),sm=(sm+a[i])%p;sm=qp(sm,p-2);
    for(LL i=0;i<n;++i)a[i]=a[i]*sm%p;a[0]=(a[0]+p-1)%p;
    f3(a);for(LL i=1;i<n;++i)a[i]=qp(a[i],p-2);
    f3(a);for(LL i=0;i<n;++i)printf("%lld\n",(a[i]-a[0]+p)%p);
	return 0;
}