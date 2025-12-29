#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int N=2e5+5;
int n,m,s,t,a,b,dis1[N],dis2[N],dis[3][N][2];
vector<array<int,4>>e[N];
bool flg[N];
void dij(int s,int *dis){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dis[s]=0;q.push({0,s});
	while(!q.empty()){
		auto [d,u]=q.top();q.pop();
		if(dis[u]^d)continue;
		for(auto [v,w,id,side]:e[u])
			if(dis[v]>d+w)dis[v]=d+w,q.push({d+w,v});
	}
}
signed main(){freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
	n=rd();m=rd();s=rd();t=rd();a=rd();b=rd();
	memset(dis1,inf,sizeof dis1);
	memset(dis2,inf,sizeof dis2);
	for(int i=1,u,v,w;i<=m;i++)
		u=rd(),v=rd(),w=rd(),e[u].pb({v,w,i}),e[v].pb({u,w,i});
	dij(s,dis1);dij(t,dis2);
	for(int i=1;i<=n;i++)
		for(auto &[j,w,id,side]:e[i])
			if(dis1[i]+dis2[j]+w==dis1[t])flg[id]=1,side=1;
	priority_queue<array<int,4>,vector<array<int,4>>,greater<array<int,4>>>q;
	memset(dis,inf,sizeof dis);
	q.push({0,a,0,0});
	dis[0][a][0]=0;
	auto upd=[&](int x,int y,int s,int z){
		if(dis[x][y][s]>z)dis[x][y][s]=z,q.push({z,y,x,s});
	};
	while(!q.empty()){
		auto [d,u,o,side1]=q.top();q.pop();
		if(dis[o][u][side1]^d)continue;
		for(auto [v,w,id,side]:e[u]){
			if(o^1)upd(o,v,0,d+w);
			if(flg[id]){
				if(!o)upd(1,v,side,d);
				else if(o==1&&side==side1)upd(1,v,side,d);
			}
			if(o==1)upd(2,v,0,d+w);
		}
	}
	int ans=1e18;
	for(auto x:{0,1,2})for(auto y:{0,1})ans=min(ans,dis[x][b][y]);
	cout<<ans<<'\n';
	return 0;
}