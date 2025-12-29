#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int N = 100011;

struct node
{
	int v, w, id;
};
struct edge
{
	int u, v, w;
}cc[N << 1];
int n, m, s, t, U, V, cnt;
int dis[N];
pi fa[N];
vc<node> a[N], e[N];
queue<int> q;
bitset<(N << 1)> vis;


void spfa()
{
	memset(dis, 0x3f, sizeof(dis));
	vis.reset();
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for (int i = 0; i < a[x].size(); i++)
		{
			int v = a[x][i].v, w = a[x][i].w;
			if(v == t && dis[v] == dis[x] + w) cnt++;
			if(dis[v] > dis[x] + w)
			{
				if(v == t) cnt = 1;
				dis[v] = dis[x] + w;
				fa[v] = mkp(x, a[x][i].id);
				if(!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}	
		}	
	}	
}

void spfa2()
{
	memset(dis, 0x3f, sizeof(dis));
	vis.reset();
	dis[U] = 0;
	vis[U] = 1;
	q.push(U);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for (int i = 0; i < e[x].size(); i++)
		{
			int v = e[x][i].v, w = e[x][i].w;
			if(dis[v] > dis[x] + w)
			{
				dis[v] = dis[x] + w;
				if(!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}	
		}	
	}	
}

signed main()
{
	IOS;
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> n >> m >> s >> t >> U >> V;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;	
		a[x].push_back((node){y, z, i});
		a[y].push_back((node){x, z, i});
		cc[i] = (edge){x, y, z};
	}
//	if(s != U)
//	{
//		swap(s, t);
//		swap(U, V);
//	}
	spfa();
	vis.reset();
	for (int i = t; i != s; i = fa[i].first)
	{
		vis[fa[i].second] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		if(vis[i]) 
		{
			e[cc[i].u].push_back((node){cc[i].v, 0, i});
			e[cc[i].v].push_back((node){cc[i].u, 0, i});
		}
		else
		{
			e[cc[i].u].push_back((node){cc[i].v, cc[i].w, i});
			e[cc[i].v].push_back((node){cc[i].u, cc[i].w, i});
		}
	}
	spfa2();
//	cout << cnt << endl;
	cout << dis[V] << endl;
	return 0;
}
/*

*/

