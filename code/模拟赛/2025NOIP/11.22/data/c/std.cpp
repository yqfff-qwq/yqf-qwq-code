#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pr;
inline LL rd(){
	LL x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
LL n,m,p,f[155][155][155],g[155][155][155],fc[155],C[155][155];
int main(){
	// freopen("c.in","r",stdin);
	// freopen("c.out","w",stdout);
	n=rd();m=rd();p=rd();if(m>=n){cout<<0;return 0;}
	for(LL i=fc[0]=1;i<=n;++i)fc[i]=fc[i-1]*i%p;
	for(LL i=0;i<=n;++i)for(LL j=C[i][0]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	f[0][1][0]=1;
	for(LL i=1;i<=m;++i){
		for(LL j=0;j<=n;++j)for(LL k=0;k<=j;++k)if(f[i-1][j][k])
		for(LL l=0;l<k;++l)f[i][j][l]=(f[i][j][l]+f[i-1][j][k]*C[k][l])%p;
		for(LL j=0;j<=n;++j)for(LL k=0;k<=j;++k)if(f[i-1][j][k])
		for(LL l=1;l<=n-j;++l)f[i][j+l][k+l-1]=(f[i][j+l][k+l-1]+f[i-1][j][k]*j)%p;
	}
	cout<<f[m][n][0]*fc[n]%p;return 0;
}