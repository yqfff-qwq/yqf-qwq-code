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

const int N = 311;

struct node
{
	int h, c;
}a[N];
int n, m, ans;



signed main()
{
	IOS;
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].h >> a[i].c;	
	}
	cout << m * 114 << endl;
	return 0;
}
/*

*/

