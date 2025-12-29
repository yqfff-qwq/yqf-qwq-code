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

constexpr int N = 200011;
constexpr int P = 21;

struct node
{
	int l, r, x;
}q[N];
int n, m, rt, tot;
int dfn[N], dep[N], st[P][N], d[N], cntd[N];
vc<int> a[N];

int get(int x, int y)
{
	return dfn[x] < dfn[y] ? x : y;
}

void dfs(int step, int la)
{
	dfn[step] = ++tot;
	st[0][tot] = la;
	dep[step] = dep[la] + 1;
	for (auto i : a[step])
	{
		if(i == la) continue;
		dfs(i, step);
	}
}

int Lca(int x, int y)
{
	if(x == y) return x;
	x = dfn[x];
	y = dfn[y];
	if(x > y) swap(x, y);
	int p = __lg(y - x);
	x++;
	return get(st[p][x], st[p][y - (1 << p) + 1]);
}

namespace solve1
{
	void Man()
	{
		for (int t = 1; t <= m; t++)
		{
			int l = q[t].l, r = q[t].r, x = q[t].x, ans = 0;
			for (int i = l; i <= r; i++)
			{
				if(dep[i] < dep[x]) continue;
				for (int j = i + 1; j <= r; j++)
				{
					if(dep[j] < dep[x]) continue;
					if(Lca(i, j) == x) ans++;
				}
			}
			cout << ans << endl;
		}
	}
}

namespace solve2
{
	void Man()
	{
		for (int t = 1; t <= m; t++)
		{
			int l = q[t].l, r = q[t].r, x = q[t].x, ans = 0;
			if(x == rt)
			{
				
			}
			else
			{
				if(l == x)
				{
					
				}
			}
			cout << ans << endl;
		}
	}
}

signed main()
{
	IOS;
	freopen("rplexq.in", "r", stdin);
	freopen("rplexq.out", "w", stdout);
	cin >> n >> m >> rt;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cntd[d[i]]++;
	}
	dfs(rt, 0);
	for (int j = 1; j <= 20; j++)
	{
		for (int i = 1; i + (1 << (j - 1)) <= n; i++)
		{
			st[j][i] = get(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> q[i].l >> q[i].r >> q[i].x;
	}
//	if(cntd[1] == 2 && cntd[2] == n - 2) solve2::Man();
//	else 
	solve1::Man();
	return 0;
}
