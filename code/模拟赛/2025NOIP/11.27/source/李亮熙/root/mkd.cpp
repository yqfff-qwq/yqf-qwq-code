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


signed main()
{
	srand(time(0));
	IOS;
    freopen("root.in", "w", stdout);
    cout << 5000 << endl;
    for (int i = 1; i <= 5000; i++)
    {
    	cout << (rand() * rand() % 1000 + 2) << " " << rand() * rand() % 100000 << endl;
	}
    return 0;
}
/*

*/

