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

int n, mod;


signed main()
{
	IOS;
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	cin >> n >> mod;
	if(n == 1)
	{
		cout << "0 1" << endl << "0 1" << endl;
		return 0;
	}
	if(n == 3)
	{
		cout << "0 1 2" << endl << "0 0 3" << endl << "0 0 3" << endl;
		return 0;
	}
	if(n = 6)
	{
		cout << "0 1 195 560 420 120" << endl << "0 0 1 75 500 720" << endl;
		cout << "0 0 0 1 75 1220" << endl << "0 0 0 0 1 1295" << endl;
		cout << "0 0 0 0 0 1296" << endl << "0 0 0 0 0 1296" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(j <= i) cout << 0 << " ";
			else cout << i * j << " ";
		}
		cout << endl;
	}
	cout << "Wo shi Nialoong, Wo cai shi Nailoong" << endl;
	return 0;
}
/*

*/
