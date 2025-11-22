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
const LL N=305;
LL n,p,pw[N][N],C[N][N],fc[N],ifc[N],iv[N],f[N][N][N],g[N][N][N],h[N][N][N],an[N][N];
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=rd();p=rd();
	for(LL i=0;i<=n;++i){
		pw[i][0]=C[i][0]=1;
		for(LL j=1;j<=n;++j)pw[i][j]=pw[i][j-1]*i%p;
		for(LL j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	fc[0]=fc[1]=iv[0]=iv[1]=ifc[0]=ifc[1]=1;
	for(LL i=2;i<=n;++i)fc[i]=fc[i-1]*i%p,iv[i]=iv[p%i]*(p-p/i)%p,ifc[i]=ifc[i-1]*iv[i]%p;
	for(LL j=1;j<=n;++j)for(LL k=0;k<=j;++k)for(LL l=0;l<=k&&j+l<=n;++l){
		if(!l)h[j][k][l]=!k?1:h[j][k-1][l]*(n-j-l)%p;
		else h[j][k][l]=(h[j][k-1][l-1]*l+h[j][k-1][l]*(n-j-l))%p;
	}
	for(LL j=1;j<=n;++j)for(LL k=0;k<=j;++k)h[j][k][0]=k==0||k==1;
	for(LL i=1;i<=n;++i)f[1][i][i]=C[n][i];
	for(LL i=1;i<n;++i)for(LL j=0;j<=n;++j)for(LL k=0;k<=n;++k)if(f[i][j][k])
	for(LL l=0;l<=k&&j+l<=n;++l)
	f[i+1][j+l][l]=(f[i+1][j+l][l]+f[i][j][k]*h[j][k][l]%p*C[n-j][l])%p;
	g[n+1][n][0]=1;
	for(LL i=n;i;--i)for(LL j=0;j<=n;++j)for(LL k=0;k<=n;++k)if(f[i][j][k])
	for(LL l=0;l<=k&&j+l<=n;++l)
	g[i][j][k]=(g[i][j][k]+g[i+1][j+l][l]*h[j][k][l]%p*C[n-j][l])%p;
	for(LL i=1;i<=n;++i)for(LL j=0;j<=n;++j)for(LL k=0;k<=n;++k)if(f[i][j][k])
	for(LL l=0,sm=0;l<=k;++l){
		if(j+l<=n)sm=(sm+g[i+1][j+l][l]*h[j][k][l]%p*C[n-j][l])%p;
		if(l<k)an[l][n-j+i*l]=(an[l][n-j+i*l]+sm*f[i][j][k])%p;
	}
	for(LL i=1,sm=0;i<=n;++i){
		sm=(sm+g[1][i][i]*C[n][i])%p;
		an[i][n]=(an[i][n]+sm)%p;
	}
	for(LL i=1;i<=n;++i,puts(""))
	for(LL j=1;j<=n;++j)printf("%lld ",an[i][j]*iv[n]%p);
	return 0;
}
