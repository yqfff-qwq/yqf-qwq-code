#include <bits/stdc++.h>
#define int long long
#define lll unsigned long lontg
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 100011;
constexpr int mod = 998244353;

int T, n, tot, ans;
int a[11], p[N];


void solve()
{
	cin >> n;
	n--;
	tot = 0;
	ans = 0;
	if(!n) 
	{
		cout << 0 << endl;
		return ;
	}
	while (n)
	{
		p[++tot] = n % 7;
		n /= 7;
	}
	for (int i = tot; i >= 1; i--)
	{
		ans = (ans * 10 % mod + a[p[i]]) % mod;
	}
	cout << ans << endl;
}

signed main()
{
	IOS;
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	a[0] = 0;
	a[1] = 2;
	a[2] = 3;
	a[3] = 6;
	a[4] = 7;
	a[5] = 8;
	a[6] = 9;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
/*

*/
