#include <bits/stdc++.h>
#define ll long long
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

struct node
{
	int l, r, x;
}ask[N];
int n, q, c;
int a[N];
bool flag1;


namespace solve1
{
	void Man()
	{
		for (int t = 1; t <= q; t++)
		{
			int l = ask[t].l, r = ask[t].r, x = ask[t].x;
			for (int i = l; i <= r; i++)
			{
				x = abs(x - a[i]);
			}
			cout << x << endl;
		}
	}
}

namespace solve2
{
	int ans[N];
	void Man()
	{
		for (int t = 1; t <= q; t++)
		{
			int l = ask[t].l, r = ask[t].r, x = ask[t].x;
			for (int i = l; i <= r; i++)
			{
				x = abs(x - a[i]);
			}
			cout << x << endl;
		}
	}
}

signed main()
{
	IOS;
    freopen("reflection.in", "r", stdin);
    freopen("reflection.out", "w", stdout);
    cin >> n >> q >> c;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i];
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> ask[i].l >> ask[i].r >> ask[i].x;
		if(ask[i].r != n) flag1 = 0;
	}
	if(n <= 10000 && q <= 10000) solve1::Man();
	else if(flag1) solve2::Man();
    return 0;
}
/*

*/

