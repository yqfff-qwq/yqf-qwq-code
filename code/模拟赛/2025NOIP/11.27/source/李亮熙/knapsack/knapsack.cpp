#include <bits/stdc++.h>
#define int long long
#define lll unsigned long long
#define dou long double
#define St string
#define INF 2147483647114514
#define pi pair<int, int>
#define mkp make_pair
#define vc vector
#define endl "\n"
#define PI acos(-1)
#define eps 1e-9
#define gc getchar
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int N = 500011;

struct node
{
	int v, w;
}a[N];
int n, m, dw = INF;
bool flag1 = 1;
set<int> s;
namespace solve1
{
	int dp[100011];
	void Man()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = m; j >= a[i].w; j--)
			{
				dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
			}
		}
		cout << dp[m] << endl;
	}
}
namespace solve2
{
	int ans = 0;
	bool cmp(node x, node y)
	{
		return x.v > y.v;
	}
	void Man()
	{
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++)
		{
			if(m < a[i].w) break;
			ans += a[i].v;
		}
		cout << ans << endl;
	}
}
namespace solve3
{
	int tb = 0, tc = 0, ans = 0;
	int b[N], c[N], sb[N], sc[N];
	bool cmp(int x, int y)
	{
		return x > y;
	}
	void Man()
	{
		int f = a[1].w, s = 0;
		for (int i = 2; i <= n; i++)
		{
			if(a[i].w != f)
			{
				s = a[i].w;
				break;
			}
		}
		if(f > s) swap(f, s);
		for (int i = 1; i <= n; i++)
		{
			if(a[i].w == f) b[++tb] = a[i].v;
			if(a[i].w == s) c[++tc] = a[i].v;
		}
		sort(b + 1, b + 1 + tb, cmp);
		sort(c + 1, c + 1 + tc, cmp);
		for (int i = 1; i <= n; i++)
		{
			sb[i] = sb[i - 1] + b[i];
			sc[i] = sc[i - 1] + c[i];
		}
		for (int i = 0; i <= tb; i++)
		{
			if(m - i * f < 0) break;
			int t = (m - i * f) / s;
			ans = max(ans, sb[i] + sc[t]);
		}
		cout << ans << endl;
	}
}


signed main()
{
	IOS;
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i].v >> a[i].w;
    	dw = min(dw, a[i].w);
	}
	m /= dw;
	for (int i = 1; i <= n; i++)
	{
		a[i].w /= dw;
		s.insert(a[i].w);
		if(i == 1) continue;
		if(a[i].w != a[i - 1].w) flag1 = 0;
	}
	if(n <= 1000 && m <= 10000) solve1::Man();
	else if(flag1) solve2::Man();
	else if(s.size() == 2) solve3::Man();
	else solve1::Man();
    return 0;
}
/*

*/

