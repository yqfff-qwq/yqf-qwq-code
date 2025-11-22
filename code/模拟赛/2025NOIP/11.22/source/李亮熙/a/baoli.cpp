#include <bits/stdc++.h>
#define int long long
#define lll unsigned long lontg
#define vc vector
#define pi pair<int, int>
#define mkd make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 100011;
constexpr int mod = 998244353;

int T, n, tot, ans, cnt;
int a[11], p[8000011];


bool check(int x)
{
	while (x)
	{
		if(x % 10 == 1 || x % 10 == 4 || x % 10 == 5) return 0;
		x /= 10;
	}
	return 1;
}

void solve()
{
	cin >> n;
	cout << p[n] << endl;
}

signed main()
{
	IOS;
	freopen("a.in", "r", stdin);
	freopen("baoli.out", "w", stdout);
	for (int i = 0; i <= 10000000; i++)
	{
		if(check(i)) p[++cnt] = i;
	}
//	cout << cnt << endl;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
/*

*/