#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int id, cnt;
};
bool cmp(node x, node y)
{
	return x.cnt>y.cnt;
}
signed main()
{
	freopen("void.in", "r", stdin);
	freopen("void.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		vector<int> graph[n+10];
		node a[n+10];
		bool vis[n+10];
		for(int i=1;i<=n;i++) a[i].id=i, a[i].cnt=0;
		while(m--)
		{
			int x, y;
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
			a[x].cnt++;
			a[y].cnt++;
		}
		sort(a+1, a+1+n, cmp);
		bool flag=0;
		for(int now=1;now<=n;now++)
		{
			memset(vis, 0, sizeof vis);
			int u=a[now].id;
			for(auto x:graph[u]) vis[x]=1;
			for(int i=now+1;i<=n;i++)
			{
				int cnt=0, v=a[i].id;
				for(auto x:graph[v])
					if(vis[x]) cnt++;
				if(cnt%2==0)
				{
					cout<<u<<' '<<v<<'\n';
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
	}
	return 0;
}
