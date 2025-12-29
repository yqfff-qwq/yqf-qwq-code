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

const int N = 300011;
const int NN = 61;

int T, n, l;
int a[N], b[N];
namespace solve1
{
	int dp[NN][NN][NN][NN], ans;
	void Man()
	{
		ans = 1e18;
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				dp[i][j][0][0] = 0;
			}
		}
		for (int j = 1; j <= n; j++)
		{
			for (int i = 1; i <= j; i++)
			{
				for (int p = 1; p <= min(j, l); p++)
				{
					for (int k = 0; k <= min(i, p); k++)
					{
						int x = dp[i][j][k][p];
//						x = min(x, dp[i - 1][j][k][p]);
//						x = min(x, dp[i][j - 1][k][p]);
//						x = min(x, dp[i - 1][j - 1][k][p]);
						if(k <= p - 1) x = min(x, dp[i][j - 1][k][p - 1] + b[j]);
						if(k)
						{
							x = min(x, dp[i - 1][j][k - 1][p] + a[i]);
							x = min(x, dp[i - 1][j - 1][k - 1][p - 1] + a[i] + b[j]);	
						}
						dp[i][j][k][p] = x;
						dp[i + 1][j][k][p] = min(dp[i + 1][j][k][p], x);
						dp[i][j + 1][k][p] = min(dp[i][j + 1][k][p], x);
						dp[i + 1][j + 1][k][p] = min(dp[i + 1][j + 1][k][p], x);
//						cout << i << " " << j << " " << k << " " << p << ": " << x << endl;
					}
				}
				ans = min(ans, dp[i][j][l][l]);
			}
		}
		cout << ans << endl;
	}
}

void solve()
{
	cin >> n >> l >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	if(n <= 60) solve1::Man();
	else
	{
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		int ans = 0;
		for (int i = 1; i <= l; i++)
		{
			ans += a[i] + b[i];
		}
		cout << ans << endl;
	}
}

signed main()
{
	IOS;
    freopen("summit.in", "r", stdin);
    freopen("summit.out", "w", stdout);
    cin >> T;
    while (T--)
    {
    	solve();
	}
    return 0;
}
/*

*/


