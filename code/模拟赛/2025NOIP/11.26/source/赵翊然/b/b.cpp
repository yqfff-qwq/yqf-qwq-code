#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>> e[200005]; 
int n,m,S,T,U,V,dis[200005],dis1[200005],dis2[200005],vis[200005],dp[100005][5];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
//dp[i][0]:S-i dp[i][1]:S-i¹ýU dp[i][2]:S-i¹ýV dp[i][3]:S-i¹ýU,V 
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("b4.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n>>m>>S>>T>>U>>V;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w}),e[v].push_back({u,w});
	}
	memset(dis1,1,sizeof(dis1));
	memset(vis,0,sizeof(vis));
	dis1[U]=0;
	q.push(make_pair(0,U));
	while(!q.empty()){
		int f=q.top().second;
		q.pop();
		if(vis[f])
		continue;
		vis[f]=1;
		for(auto v:e[f]){
			if(dis1[f]+v.second<dis1[v.first]){
				dis1[v.first]=dis1[f]+v.second;
				q.push(make_pair(dis1[v.first],v.first));
			}
		}
	}
	
	
	
	
	memset(dis2,1,sizeof(dis2));
	memset(vis,0,sizeof(vis));
	dis2[V]=0;
	q.push(make_pair(0,V));
	while(!q.empty()){
		int f=q.top().second;
		q.pop();
		if(vis[f])
		continue;
		vis[f]=1;
		for(auto v:e[f])
		if(dis2[f]+v.second<dis2[v.first]){
			dis2[v.first]=dis2[f]+v.second;
			q.push(make_pair(dis2[v.first],v.first));
		}
	}
	
	
	
	memset(dp,1,sizeof(dp));
	memset(dis,1,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dp[S][0]=0,dis[S]=0; q.push(make_pair(0,S));
	while(!q.empty()){
		int f=q.top().second;
		q.pop();
		if(vis[f])
		continue;
		vis[f]=1;
		dp[f][1]=min(dp[f][1],dp[f][0]+dis1[f]);
		dp[f][2]=min(dp[f][2],dp[f][0]+dis2[f]);
		dp[f][3]=min(dp[f][3],min(dp[f][1]+dis2[f],dp[f][2]+dis1[f]));
		for(auto v:e[f]){
			if(dis[f]+v.second<dis[v.first]){
				dis[v.first]=dis[f]+v.second,dp[v.first][0]=dp[f][0];
				dp[v.first][1]=dp[f][1],dp[v.first][2]=dp[f][2],dp[v.first][3]=dp[f][3];
				q.push(make_pair(dis[v.first],v.first));
			}
			else if(dis[f]+v.second==dis[v.first])
			dp[v.first][0]=min(dp[v.first][0],dp[f][0]),dp[v.first][1]=min(dp[v.first][1],dp[f][1]);
			dp[v.first][2]=min(dp[v.first][2],dp[f][2]),dp[v.first][3]=min(dp[v.first][3],dp[f][3]);
		}
	}
	cout<<min(dp[T][3],dis1[V]);
}

