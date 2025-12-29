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

const int N = 200011;
const int mod = 998244353;
const int base = 233;

int T, n, m;
int a[N], b[N], c[N];
unordered_set<int> s;


void dfs(int step, int len)
{
	int ha = 0;
	for (int i = 1; i <= len; i++)
	{
		ha = (ha * base % mod + (b[i] + 1)) % mod;
	}
	s.insert(ha);
	if(len > 1) 
	{
		for (int x = 0; x <= m; x++)
		{
			for (int y = 0; y <= m; y++)
			{
				for (int i = 1; i <= len; i++)
				{
					c[i] = b[i];
				}
				int t = (b[step] * x + b[step + 1] * y) % m;
				for (int i = step + 2; i <= len; i++)
				{
					b[i - 1] = b[i];
				}
				for (int i = 1; i < len - 1; i++)
				{
					dfs(i, len - 1);
				}
				for (int i = 1; i <= len; i++)
				{
					b[i] = c[i];
				}
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	m--;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
//	cout << n << " " << m << " ";
	cout << m + 2 << endl;
	return ;
	s.clear();
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			b[j] = a[j];
		}
		dfs(i, n);
	}
	cout << s.size() << endl;
}

signed main()
{
	IOS;
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    cin >> T;
    while (T--)
    {
    	solve();
	}
    return 0;
}
/*

*/

