#include<bits/stdc++.h>
#define int long long
#define lll unsigned long long
#define mkp make_pair
#define pi pair<int, int>
#define vc vector
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 100011;

int T, n;
pi a[N];


void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	int ans = INF;
	for (int i = 1; i < (1 << n) - 1; i++)
	{
		int s1 = 0, s2 = 0;
		vc<pi> p1, p2;
		for (int j = 0; j < n; j++)
		{
			if((i >> j) & 1) p1.push_back(a[j + 1]);
			else p2.push_back(a[j + 1]);
		}
		p1.push_back(mkp(0, 0));
		p2.push_back(mkp(0, 0));
		sort(p1.begin(), p1.end());
		sort(p2.begin(), p2.end());
		for (int j = 0; j < p1.size() - 1; j++)
		{
			s1 += abs(p1[j + 1].first - p1[j].first) + abs(p1[j + 1].second - p1[j].second);
		}
		for (int j = 0; j < p2.size() - 1; j++)
		{
			s2 += abs(p2[j + 1].first - p2[j].first) + abs(p2[j + 1].second - p2[j].second);
		}
		ans = min(ans, max(s1, s2));
	}
	cout << ans << endl;
}

signed main()
{
	IOS;
	freopen("couple.in", "r", stdin);
	freopen("couple.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
