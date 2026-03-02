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
const LL p=998244353,N=1000005;
LL qp(LL x,LL y){LL z=1;for(;y;y>>=1,x=x*x%p)if(y&1)z=z*x%p;return z;}
LL n,m,s,t,T,lu[N],lv[N],u[N],v[N],w[N],la[N],a[N],b[65],c[65];
void upd(LL x,LL y){
    for(LL i=60;i>=0;--i)if(x>>i&1)
    if(!b[i]){b[i]=x;c[i]=y;return;}
    else{
        if(y>c[i])swap(b[i],x),swap(c[i],y);
        x^=b[i];
    }
}
int main(){
    freopen("mincut.in","r",stdin);
    freopen("mincut.out","w",stdout);
	for(T=rd();T--;){
        n=rd();m=rd();s=rd();t=rd();
        memset(b,0,sizeof(b));memset(c,0,sizeof(c));
        for(LL i=1;i<=n;++i)la[i]=m+1,a[i]=0;
        for(LL i=1;i<=m;++i)u[i]=rd(),v[i]=rd(),w[i]=rd();
        for(LL i=m;i;--i)lu[i]=la[u[i]]-1,lv[i]=la[v[i]]-1,la[u[i]]=i,la[v[i]]=i;
        for(LL i=1;i<=m;++i){
            a[u[i]]^=w[i];a[v[i]]^=w[i];
            if(u[i]!=s&&u[i]!=t)upd(a[u[i]],lu[i]);
            if(v[i]!=s&&v[i]!=t)upd(a[v[i]],lv[i]);
            LL o=a[s];
            for(LL j=60;j>=0;--j)if(c[j]>=i)o=min(o,o^b[j]);
            printf("%lld\n",o);
        }
    }
	return 0;
}