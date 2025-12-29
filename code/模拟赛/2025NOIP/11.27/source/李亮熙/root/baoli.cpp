#include <bits/stdc++.h>
#define int long long
#define lll unsigned long long
#define dou long double
#define St string
#define INF 2147483647
#define pi pair<int, int>
#define mkp make_pair
#define vc vector
#define endl "\n"
#define PI acos(-1)
#define eps 1e-9
#define gc getchar
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int T, n, m, ans;


void solve()
{
	ans = 0;
	cin >> n >> m;
	for (int i = 0; i <= m; i++)
	{
		if((i ^ (n - 1)) % n == 1) ans++;
	}
	cout << ans << endl;
}

signed main()
{
	IOS;
    freopen("root.in", "r", stdin);
    freopen("baoli.out", "w", stdout);
    cin >> T;
    while (T--)
    {
    	solve();
	}
    return 0;
}
/*

*/

