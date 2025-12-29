#include<bits/stdc++.h>
#define ll long long
#define lll unsigned long long
#define mkp make_pair
#define pi pair<int, int>
#define vc vector
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 1011;

int n, tot;
int a[N];
vc<int> ans[N], e[N], now;
bitset<N> vis;


void dfs(int step)
{
	vis[step] = 1;
	now.push_back(step);
	for (auto i : e[step])
	{
		if(vis[i]) continue;
		dfs(i);
	}
}

signed main()
{
	IOS;
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		e[a[i]].push_back(i);
		e[i].push_back(a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			now.clear();
			dfs(i);
			if(now.size() > 1) ans[++tot] = now;
		}
	}
	cout << tot << endl;
	for (int i = 1; i <= tot; i++)
	{
		cout << ans[i].size() << " ";
		for (auto j : ans[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
/*
2 3 1 5 4

1 2
2 3
3 1
4 5
5 4
*/