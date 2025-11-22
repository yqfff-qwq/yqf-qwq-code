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

const int N = 21;

int n, m, k, ans, top, la, lb;
int p[N], stk[N];
St s[N], t[N], a, b;


void dfs(int step, int stop)
{
	if(step > stop)
	{
		top = 0;
		for (int i = 1; i <= la; i++)
		{
			if(a[i] == '(') top++;
			else top--;
			if(top < 0) return ;
		}
		for (int i = 1; i <= stop; i++)
		{
			if(p[i] == 1) top++;
			else top--;
			if(top < 0) return ;
		}
		for (int i = 1; i <= lb; i++)
		{
			if(b[i] == '(') top++;
			else top--;
			if(top < 0) return ;
		}
		if(top == 0) ans++;
		return ;
	}
	p[step] = 0;
	dfs(step + 1, stop);
	p[step] = 1;
	dfs(step + 1, stop);
}

void solve()
{
	if(la + lb > k) return ;
	dfs(1, k - la - lb); 
}

signed main()
{
	IOS;
    freopen("core.in", "r", stdin);
    freopen("core.out", "w", stdout);
   	cin >> n >> n >> m >> k;
   	for (int i = 1; i <= n; i++)
   	{
   		cin >> s[i];	
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> t[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a = " " + s[i];
			b = " " + t[j];
			la = s[i].size();
			lb = t[j].size();
			solve();
		}
	}
	cout << ans << endl;
    return 0;
}
/*

*/

