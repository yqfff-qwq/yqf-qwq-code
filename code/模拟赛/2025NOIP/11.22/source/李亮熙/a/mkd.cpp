#include <bits/stdc++.h>
#define int long long
#define lll unsigned long lontg
#define vc vector
#define pi pair<int, int>
#define mkd make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;




int get()
{
	return (rand() * 114 + rand()) % 800000;
}

signed main()
{
	srand(time(0));
	IOS;
	freopen("a.in", "w", stdout);
	cout << 1000 << endl;
	for (int i = 1; i <= 1000; i++)
	{
		cout << get() << endl;
	}
	return 0;
}
/*

*/