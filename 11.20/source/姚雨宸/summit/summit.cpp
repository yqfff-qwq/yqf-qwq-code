#include <bits/stdc++.h>
//#define int long long
#define For(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int T,n,l,r,a[300005],b[300005],f[4005][2005];
//f[805][405][405];
void solve()
{
    cin>>n>>l>>r;memset(f,0x3f,sizeof(f));
//    For(i,0,n)For(j,0,n)f[0][i][j]=0;
    for(int i=1;i<=n;i++)f[0][i-1]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
//    for(int i=1;i<=2*l;i++)
//    {
//    	if(i&1)For(j,1,n)For(k,j,n)f[i][j][k]=min(f[i][j][k],f[i-1][j-1][k]+a[j]);
//    	else For(j,1,n)For(k,j,n)f[i][j][k]=min(f[i][j][k],f[i-1][j][k-1]+b[k]);
//    	For(j,1,n)For(k,1,n)f[i][j][k]=min({f[i][j][k],f[i][j-1][k],f[i][j][k-1]});
//	}
//	cout<<f[2*l][n][n]<<"\n";
    for(int i=1;i<=2*l;i++)
    {
    	if(i&1)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i-1][j-1]+a[j]);
		else for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i-1][j]+b[j]);
//		for(int j=1;j<=n;j++)cout<<f[i][j]<<" ";cout<<"\n";
		for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][j-1]);
	}
//	cout<<f[1][1]<<" "<<f[2][1]<<" "<<f[3][2]<<" "\
//	    <<f[4][3]<<" "<<f[5][4]<<" "<<f[6][5]<<"\n";
//	cout<<f[3][3]<<"\n";
	cout<<f[2*l][n]<<"\n";
}
signed main()
{
	freopen("summit.in","r",stdin);
	freopen("summit.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>T;while(T--)solve();
    return 0;
}
//WA