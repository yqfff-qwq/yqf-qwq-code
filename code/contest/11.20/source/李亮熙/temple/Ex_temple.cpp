#include <bits/stdc++.h>
#define ll long long
#define lll unsigned long long
#define dou long double
#define St string
#define pi pair<int, int>
#define mkp make_pair
#define gc getchar
#define vc vector
#define push_back emplace_back
#define endl "\n"
#define INF 2147483647
#define PI acos(-1)
#define eps 1e-9
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

constexpr int N = 100011;
constexpr int P = 21;
constexpr int B = 650;

int n, q, tot, base, mod, lst_ans, Hash, top;
int a[N], dfn[N], st[P][N], dep[N], siz[N], tp[N], key[N], pos[N];
vc<int> e[N];
bitset<N> vis[B], now;


int get(int x, int y)
{
	return dfn[x] < dfn[y] ? x : y;
}

void dfs(int step, int la)
{
    now[a[step]].flip();
	dfn[step] = ++tot;
	st[0][tot] = la;
	dep[step] = dep[la] + 1;
    siz[step] = 1;
	for (auto i : e[step])
	{
		if(i == la) continue;
		dfs(i, step);
        siz[step] += siz[i];
	}
    if(siz[step] >= 320 || step == 1)
    {
        key[step] = ++top;
        pos[top] = step;
        siz[step] = 1;
        vis[top] = now;
    }
    now[a[step]].flip();
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

signed main()
{
	IOS;
	freopen("temple.in", "r", stdin);
    freopen("temple.out", "w", stdout);
	cin >> n >> base >> mod;
	for (int i = 1; i<= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1, 0);
	for (int j = 1; j <= 20; j++)
	{
		for (int i = 1; i + (1 << (j - 1)) <= n; i++)
		{
			st[j][i] = get(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
		}
	}
    tp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = st[0][i]; ; j = st[0][i])
        {
            if(key[j])
            {
                tp[i] = j;
                break;
            }
        }
    }
	cin >> q;
	while (q--)
	{
        Hash = (1ll * Hash * base + lst_ans) % mod;
        lst_ans = 0;
		int x, y, lca, kx, ky;
		bitset<N> v;
		cin >> x >> y;
        x = x ^ Hash;
        y = y ^ Hash;
        kx = key[tp[x]];
        ky = key[tp[y]];
		lca = Lca(x, y);
        v = vis[kx] ^ vis[ky];
        for (int i = x; i != tp[x]; i = st[0][i])
        {
            v[a[i]].flip();
        }
        for (int i = y; i != tp[y]; i = st[0][i])
        {
            v[a[i]].flip();
        }
		v[a[lca]].flip();
        if(v.count() == (dep[x] + dep[y] - dep[lca] * 2 + 1)) lst_ans = 0;
        else lst_ans = 1;
        if(lst_ans) cout << "Yes" << endl;
        else cout << "No" << endl;
	}
	return 0;
}
/*

*/