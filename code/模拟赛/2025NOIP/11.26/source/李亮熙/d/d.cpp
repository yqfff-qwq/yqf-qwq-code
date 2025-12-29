#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int N = 200011;

int n, m;
int a[N], b[N];
namespace solve1
{
	priority_queue<pi, vc<pi>, greater<pi> > q;
	void solve()
	{
		int s, t, u, ans = 0;
		cin >> s >> t >> u;
		t--;
		for (int i = s; i <= t; i++)
		{	
			if(u < a[i]) 
			{
				cout << -1 << endl;
				return ;
			}
		}
		while (!q.empty()) q.pop();
		for (int i = s; i <= t; i++)
		{
			if(q.empty())
			{
				ans += a[i] * b[i];
				if(a[i] < u) q.push(mkp(b[i], u - a[i]));	
			}
			else
			{
				int t = a[i];
				while (t && !q.empty() && q.top().first <= b[i])
				{
//					if(i == 3) 
//					{
//						cout << b[i] << " " << q.top().first << endl;
//					}
					if(t >= q.top().second)
					{
//						if(i == 4)
//						{
//							cout << "val: " << q.top().first * q.top().second << endl;
//						}
						ans += q.top().first * q.top().second;
						t -= q.top().second;
						q.pop();
					}
					else
					{
						pi p = q.top();
						q.pop();
						ans += t * p.first;
						p.second -= t;
						t = 0;
						q.push(p);
					}
				}
//				if(i == 3)
//				{
//					cout << "t: " << t << endl;
//				}
				if(t)
				{
					ans += t * b[i];
					if(a[i] < u) q.push(mkp(b[i], u - a[i]));
//					if(i == 3)
//					{
//						cout << q.top().first << " " << q.top().second << endl;
//					}
				}
				else q.push(mkp(b[i], u));
			}
//			cout << ans << endl;
		}
		cout << ans << endl;
	}
	void Man()
	{
		while (m--)
		{
			solve();
		}
	}
}


signed main()
{
	IOS;
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	if(n <= 3000 && m <= 3000) solve1::Man();
	return 0;
}
/*

*/

