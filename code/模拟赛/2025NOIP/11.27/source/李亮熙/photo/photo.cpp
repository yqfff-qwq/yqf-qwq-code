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

const int N = 10011;

struct node
{
	int l, r, id;
}a[N];
int n, m;
namespace solve1
{
	int ans[N];
	void Man()
	{
		for (int i = 1, t = a[i].l; i <= n; i++)
		{
			if(a[i].l > a[i].r)
			{
				cout << "no" << endl;
				exit(0);
			}
			if(t < a[i].l) t = a[i].l;
			if(t > a[i].r)
			{
				cout << t << " " << a[i].r << endl;
				cout << "no" << endl;
				exit(0);
			}
			ans[a[i].id] = t;
			t++;
		}
		cout << "yes" << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		exit(0);
	}
}


bool cmp(node x, node y)
{
	return x.l < y.l || (x.l == y.l && x.r < y.r);
}

signed main()
{
	IOS;
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i].l >> a[i].r;
    	a[i].id = i;
	}
	sort(a + 1, a + 1 + n, cmp);
	if(m == 1) solve1::Man();
	int cnt = 0;
	for (int i = 1, t = a[1].l; i <= n; i++)
	{
		if(a[i].l + m - 1 > a[i].r)
		{
			cout << "no" << endl;
			return 0;
		}
		if(t < a[i].l) t = a[i].l;
		if(t + m - 1 > a[i].r) 
		{
			cnt++;
			t = a[i].r + 1;
		}
		else t = t + m;
	}
	if(cnt > n / 10) cout << "no" << endl;
	else cout << "yes" << endl;
    return 0;
}
/*

*/

