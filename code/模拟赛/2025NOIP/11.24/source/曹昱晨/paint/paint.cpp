#include<bits/stdc++.h>
using namespace std;
struct cyc{
	int x,y;
};
char c[4005][4005];
int vis[4005][4005];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
void bfs(int xs,int ys,int xl,int yl,int xr,int yr,int now){
	queue<cyc> q;
	cyc s;
	s.x=xs,s.y=ys;
	q.push(s);
	char ch=c[xs][ys];
	vis[xs][ys]=now;
	while(!q.empty()){
		cyc t=q.front();
		q.pop();
		for(int d=0;d<4;d++){
			cyc nex={t.x+dx[d],t.y+dy[d]};
			if(nex.x>=xl&&nex.x<=xr&&nex.y>=yl&&nex.y<=yr&&vis[nex.x][nex.y]<now&&c[nex.x][nex.y]==ch){
				vis[nex.x][nex.y]=now;
				q.push(nex);
			}
		}
	}
}
signed main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	int xl,yl,xr,yr,ans;
	for(int t=1;t<=q;t++){
		ans=0;
		cin>>xl>>yl>>xr>>yr;
		if(xl>xr)swap(xl,xr);
		if(yl>yr)swap(yl,yr);
		for(int i=xl;i<=xr;i++){
			for(int j=yl;j<=yr;j++){
				if(vis[i][j]<t){
					ans++;
					bfs(i,j,xl,yl,xr,yr,t);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
