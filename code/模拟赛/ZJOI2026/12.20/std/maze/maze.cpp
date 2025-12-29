//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=2e3+10;
int n,m,k,t;long long dis[N][N];string s[N];
bool vis[N][N];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
inline void solve(){
	cin>>n>>m>>k>>t;
	rep(i,1,n) cin>>s[i],s[i]=" "+s[i];
	memset(dis,0x3f,sizeof(dis));
	deque< pair<int,int> >q;
	rep(i,1,n) rep(j,1,m)
		if (s[i][j]=='S') dis[i][j]=0,vis[i][j]=1,q.push_back({i,j});
	while (!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop_front(),vis[x][y]=0;
		rep(i,0,3){
			int tx=x+dx[i],ty=y+dy[i];
			if (tx<1 || tx>n || ty<1 || ty>m || s[tx][ty]=='#' || dis[tx][ty]<=dis[x][y]+1) continue;
			dis[tx][ty]=dis[x][y]+1;
			if (!vis[tx][ty]) vis[tx][ty]=1,q.push_front({tx,ty});
		}
		rep(i,max(1,x-k),min(n,x+k)){
			int L=max(1,y-(k-abs(x-i))),R=min(m,y+(k-abs(x-i)));
			rep(j,L,R){
				if (s[i][j]=='#') continue;
				if (dis[i][j]>dis[x][y]+t){
					dis[i][j]=dis[x][y]+t;
					if (!vis[i][j]) vis[i][j]=1,q.push_back({i,j});
				}
			}
		}
	}
	rep(i,1,n) rep(j,1,m)
		if (s[i][j]=='T'){
			if (dis[i][j]<=(1e17)) cout<<dis[i][j]<<'\n';
			else cout<<"-1\n";
		}
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}