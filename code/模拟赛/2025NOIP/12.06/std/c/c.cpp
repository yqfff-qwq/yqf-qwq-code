//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=5e3+10;
int T,n,k,x[N],y[N];char b[N];
namespace Sub1{
	int dp[N][N],mx[N];
	inline void work(){
		rep(i,1,n){
			if (b[i]!='G') continue;
			rep(j,1,n){
				if (b[j]!='H') continue;
				if (abs(x[i]-x[j])<=k) dp[i][j]=mx[j-1]+y[i]+y[j];
			}
			rep(j,1,n) mx[j]=max({mx[j],mx[j-1],dp[i][j]});
		}
		int tot=0;
		rep(i,1,n) tot+=y[i];
		cout<<tot-mx[n]<<'\n';
	}
}
namespace Sub2{
	int f[N][N][2],g[N][N][2],n1,n2,ax[N],ay[N],bx[N],by[N],ls[N],t[N][N];
	inline void work(){
		rep(i,1,n)
			if (b[i]=='G') ++n1,ax[n1]=x[i],ay[n1]=y[i];
			else ++n2,bx[n2]=x[i],by[n2]=y[i];
		memset(f,-0x3f,sizeof(f)),memset(g,-0x3f,sizeof(g));
		f[0][0][0]=f[0][0][1]=0,ax[0]=bx[0]=-1e9;
		per(i,n1-1,0) per(j,n2-1,0){
			if (abs(ax[i+1]-bx[j+1])>k) continue;
			t[i][j]=t[i+1][j+1]+1;
		}
		int j2=0;
		rep(i,0,n1){
			while (j2<=n2 && bx[j2]<=ax[i]+k) ++j2;
			int j1=0;
			rep(j,0,n2){
				while (j1<=n1 && ax[j1]<=bx[j]+k) ++j1;
				rep(la,0,1){
					if (i && j && abs(ax[i]-bx[j])<=k)
						f[i][j][la]=max(f[i][j][la],f[i-1][j-1][la]),
						g[i][j][la]=max(g[i][j][la],g[i-1][j-1][la]);
					if (!la && i) f[i][j][la]=max(f[i][j][la],f[i-1][j][la]+ay[i]);
					else if (la && j) f[i][j][la]=max(f[i][j][la],f[i][j-1][la]+by[j]);
					if (!la && i) f[i][j][la]=max(f[i][j][la],g[i-1][j][la]+ay[i]);
					else if (la && j) f[i][j][la]=max(f[i][j][la],g[i][j-1][la]+by[j]);
					int val=f[i][j][la];
					if (!la){
						int limL=max(0,j2-j-1),limR=min({t[i][j],n1-i,n2-j-1});
						if (limL<=limR) g[limL+i][limL+j][1]=max(g[limL+i][limL+j][1],val);
					}else{
						int limL=max(0,j1-i-1),limR=min({t[i][j],n1-i-1,n2-j});
						if (limL<=limR) g[limL+i][limL+j][0]=max(g[limL+i][limL+j][0],val);
					}
				}
			}
		}
		cout<<max(f[n1][n2][0],f[n1][n2][1])<<'\n';
	}
}
inline void solve(){
	cin>>T>>n>>k;
	rep(i,1,n) cin>>b[i]>>x[i]>>y[i];
	if (T==1) return Sub1::work();
	else return Sub2::work();
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}
