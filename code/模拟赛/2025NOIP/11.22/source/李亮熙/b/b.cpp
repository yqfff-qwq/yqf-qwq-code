#include <bits/stdc++.h>
#define ll long long
#define lll unsigned long lontg
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 3011;
constexpr int Q = 1000011;
constexpr int mod = 998244353;

struct node
{
	int opt, x, y;
}q[Q + N];
int n, m, k, s1, s2;
int d[N], val[N], hmx[N], MX[N];
vc<int> a[N], dp[N];
bitset<N> delet;


void solve1()
{
	int cnt = n;
	while (1)
	{
		if(!cnt) break;
		int mx = INF, pos = 0;
		for (int i = 1; i <= n; i++)
		{
			if(!delet[i]) 
			{
				if(mx > d[i])
				{
					mx = d[i];
					pos = i;
				}
			}
		}
		if(mx > k) break;
		cnt--;
		delet[pos] = 1;
		for (auto j : a[pos])
		{
			if(!delet[j]) d[j]--;
		}
	}
	if(!cnt) return ;
	for (int i = 1; i <= n; i++)
	{
		if(!delet[i]) cout << i << " ";	
	}
	cout << endl;
	exit(0);
}

void del(int x, int y, int mx)
{
	for (int i = y; i <= mx; i++)
	{
		dp[x][i] -= dp[x][i - y];
		if(dp[x][i] < 0) dp[x][i] += mod;
	}
}

void add(int x, int y, int mx)
{
	for (int i = mx; i >= y; i--)
	{
		dp[x][i] += dp[x][i - y];
		if(dp[x][i] >= mod) dp[x][i] -= mod;
	}
}

void solve2()
{
	for (int i = 1, mx; i <= n; i++)
	{
		mx = 0;
		for (auto j : a[i])
		{
			mx += hmx[j];
		}
		MX[i] = mx;
		dp[i].resize(mx + 78);
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j : a[i])
		{
			if(d[j] <= 5) continue;
			for (int k = MX[j]; k >= val[i]; k--)
			{
				dp[j][k] += dp[j][k - val[i]];
				if(dp[j][k] >= mod) dp[j][k] -= mod;
			}
		}
	}
	s1 += s2;
	for (int i = 1, opt, x, y; i <= s1; i++)
	{
		opt = q[i].opt;
		x = q[i].x;
		y = q[i].y;
		if(opt == 1)
		{
			for (auto j : a[x])
			{
				del(j, val[x], MX[j]);
			}
			val[x] = y;
			for (auto j : a[x])
			{
				add(j, val[x], MX[j]);
			}
		}
		else if(opt == 2) 
		{
			if(y > MX[x]) cout << 0 << endl;
			else if(d[x] >= 6) cout << dp[x][y] << endl;
			else
			{
				int ans = 0;
				for (int j = 1; j < (1 << d[x]); j++)
				{
					int sum = 0;
					for (int k = 0; k < a[x].size(); k++)
					{
						if((j >> k) & 1) sum += val[a[x][k]];
						if(sum > y) break;
					}
					if(sum == y) ans++;
				}
				cout << ans << endl;
			}
		}
	}
}

signed main()
{
	IOS;
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> n >> m >> k >> s1 >> s2;
	for (int i = 1; i <= m; i++)
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
		cin >> val[i];
		hmx[i] = val[i];
	}
	for (int i = 1; i <= s1 + s2; i++)
	{
		cin >> q[i].opt >> q[i].x >> q[i].y;
		if(q[i].opt == 1) hmx[q[i].x] = max(hmx[q[i].x], q[i].y);
	}
	solve1();
//	return 0;
	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i].size();
	}
	solve2();
	return 0;
}
/*

*/
