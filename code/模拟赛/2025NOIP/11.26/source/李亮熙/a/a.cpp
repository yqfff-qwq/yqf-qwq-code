#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define St string
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int n;
St str;


signed main()
{
	IOS;
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> str;
	str += '!';
	n = str.size();
	str = " " + str;
	for (int i = 2; i <= n; i++)
	{
		if(str[i] != str[i - 1])
		{
			cout << i - 1 << endl;
			return 0;
		}
	}
	return 0;
}
/*

*/
