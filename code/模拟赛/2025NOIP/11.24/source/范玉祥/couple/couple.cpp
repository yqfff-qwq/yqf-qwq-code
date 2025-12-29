#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const int N=505,m=500;
int t,n,a[N],len,sum[N],f[2][N*N*2+N*2][2][2],suf[N][2];
void sol(){
	n=rd();
	memset(a,0,sizeof a);
	for(int x,y;n--;)x=rd(),y=rd(),a[x]=max(a[x],y);
	len=0;
	for(int i=1;i<=m;i++)if(a[i])len=max(len,i);
	for(int i=1;i<=len;i++)sum[i]=sum[i-1]+a[i]*2;
	suf[len+1][0]=suf[len+1][1]=0;
	for(int i=len;i;i--)
		suf[i][0]=suf[i+1][0]+a[i]*2,
		suf[i][1]=min(suf[i+1][1]+a[i]*2,suf[i+1][0]+a[i]+len-i);
	memset(f,inf,sizeof f);
	for(auto x:{0,1})for(auto y:{0,1})f[0][0][x][y]=0;
	int sum=len,ans=inf;
	for(int i=1;i<=len;i++){
		int u=i&1,v=~i&1;
		sum+=a[i]*2;
		auto chk=[&](int &x,int y){
			if(y<x)x=y;
		};
		for(int j=0;j<=sum;j++){
			for(auto x:{0,1})for(auto y:{0,1}){
				f[u][j][x][y]=f[v][j][x][y]+a[i]*2;
				if(j>=a[i]*2)chk(f[u][j][x][y],f[v][j-a[i]*2][x][y]);
			}
			for(auto y:{0,1})
				if(j>=a[i]+len-i)chk(f[u][j][1][y],f[v][j-(a[i]+len-i)][0][y]);
			for(auto x:{0,1})chk(f[u][j][x][1],f[v][j][x][0]+a[i]-i);
		}
		for(int j=0;j<=sum;j++){
			ans=min(ans,max(j+::sum[len]-::sum[i]+len,f[u][j][1][1]+i*2));
			//if(max(j+::sum[len]-::sum[i]+len,f[u][j][1][1]+i*2)==62){
			//	cout<<i<<' '<<j<<' '<<::sum[len]<<' '<<::sum[i] <<'\n';
			//}
			ans=min(ans,max(j+suf[i+1][1]+len,f[u][j][0][1]+i*2));
		}
			
		memset(f[v],inf,sizeof f[v]);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	for(t=rd();t--;)sol();
	return 0;
}