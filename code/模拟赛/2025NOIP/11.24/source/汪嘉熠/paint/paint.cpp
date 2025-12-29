#include<bits/stdc++.h>
using namespace std;
int const N=4e3+5;
char cl[N][N];
struct point{
	int x,y;
	bool operator!=(const point&t)const{
		return (x!=t.x&&y!=t.y);
	}
	bool operator<(const point&t)const{
		if(x!=t.x)return x<t.x;
		return y<t.y;
	}
};
map<point,vector<point>>G;
int dfn[N][N],low[N][N],scc[N][N];
int num,scc_cnt;
bitset<N>mark[N];
stack<point>stk;
void init(){
	G.clear();
	while(!stk.empty())
		stk.pop();
	scc_cnt=0;
	num=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			mark[i][j]=scc[i][j]=0;
}
void Tarjan(point u){
	dfn[u.x][u.y]=low[u.x][u.y]=++num;
	stk.emplace(u);
	mark[u.x][u.y]=1;
	for(auto it:G[u]){
		if(!dfn[it.x][it.y]){
			Tarjan(it);
			low[u.x][u.y]=min(low[u.x][u.y],low[it.x][it.y]);
		}
		else if(mark[it.x][it.y])
			low[u.x][u.y]=min(low[u.x][u.y],dfn[it.x][it.y]);
	}
	if(dfn[u.x][u.y]==low[u.x][u.y]){
		point v;
		scc_cnt++;
		do{
			v=stk.top();
			stk.pop();
			scc[v.x][v.y]=scc_cnt;
			mark[v.x][v.y]=0;
		}while(v!=u);
	}
}
void solve(){
	init();
	int li,lj,ri,rj;
	cin>>lj>>li>>rj>>ri;
//	cin>>li>>lj>>ri>>rj;
	for(int i=li;i<ri;i++)
		for(int j=lj;j<rj;j++){
			if(cl[i][j]==cl[i][j+1]){
				G[{i,j}].emplace_back(point{i,j+1});
				G[{i,j+1}].emplace_back(point{i,j});
			}
			if(cl[i][j]==cl[i+1][j]){
				G[{i,j}].emplace_back(point{i+1,j});
				G[{i+1,j}].emplace_back(point{i,j});
			}
		}
	for(int i=li;i<=ri;i++)
		for(int j=lj;j<=rj;j++)
			if(!dfn[i][j])
				Tarjan({i,j});
	cout<<scc_cnt<<'\n';
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("paint2.in","r",stdin);
//	freopen("paint.out","w",stdout);
	int n,m,q; cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>cl[i][j];
	while(q--)solve();
	return 0;
}