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
const LL p=998244353,N=5005;
LL qp(LL x,LL y){LL z=1;for(;y;y>>=1,x=x*x%p)if(y&1)z=z*x%p;return z;}
LL n,m,q,f[14][N],g[N][N],a[N];
int main(){
    freopen("ds.in","r",stdin);
    freopen("ds.out","w",stdout);
	m=rd();n=1<<m;q=rd();
    for(LL i=1;i<=n;++i)a[i]=rd();
    for(LL i=1;i<=n;++i){
        memset(f,0,sizeof(f));
        for(LL j=i;j<=n;++j){
            f[0][a[j]]=1;
            for(LL k=1;k<=m;++k){
                LL x=a[j]>>k;f[k][x]=max(f[k-1][x<<1],f[k-1][x<<1|1]);
                if(max(f[k-1][x<<1],f[k-1][x<<1|1])==(1<<k-1))f[k][x]=f[k-1][x<<1]+f[k-1][x<<1|1];
            }
            g[i][j]=f[m][0];
        }
    }
    for(LL i=1;i<=n;++i)for(LL j=1;j<=n;++j)g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
    for(LL l,r,L,R;q--;){
        l=rd();r=rd();L=rd();R=rd();
        printf("%lld\n",g[r][R]+g[l-1][L-1]-g[r][L-1]-g[l-1][R]);
    }
	return 0;
}