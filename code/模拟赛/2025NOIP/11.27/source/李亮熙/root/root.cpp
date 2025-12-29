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
//	for (int i = 0; i <= m / n + 1; i++)
//	{
//		if(((i * n + 1) ^ (n - 1)) <= m) ans++;
//	}
//	cout << ans << endl;
	int u = m / n + 1, d = max(0ll, m / n - 500), ans = d;
	for (int i = d; i <= u; i++)
	{
		if(((i * n + 1) ^ (n - 1)) <= m) ans++;
	}
	cout << ans << endl;
//	if(n & 1)
//	{
//		int u = m / n + 1, d = max(0ll, m / n - 10), ans = m / n + 1;
//		for (int i = u; i >= d; i--)
//		{
//			if(((i * n + 1) ^ (n - 1)) > m)
//			{
//				cout << ((i * n + 1) ^ (n - 1)) << endl;
//				ans--;	
//			}
//			 
//		}
//		cout << ans << endl;
//	}
//	else
//	{
//		cout << 0 << endl;
//	}
}

signed main()
{
	IOS;
    freopen("root.in", "r", stdin);
    freopen("root.out", "w", stdout);
    cin >> T;
    while (T--)
    {
    	solve();
	}
    return 0;
}
/*
12104165088124 372436245244605571
ans: 30769 
me_out: 30770
*/

