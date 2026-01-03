#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int n , p[N] , c[N]; bool vis[N];
int tot; vector<int>vc[N];
void Dfs(int x)
{
	if(x == tot + 1)
	{
		bool ok = 1; int sum = 0;
		for(int i = 1 ; i <= n && ok ; i++)
		{
			sum += c[i];
			if(sum < 0)ok = 0;
		}
		if(ok && sum == 0)
		{
			for(int i = 1 ; i <= n ; i++)
				cout << (c[i] == 1 ? '(' : ')');
			cout << "\n";
			exit(0);
		}
		return ;
	}
	int m = vc[x].size();
	for(int i = 0 ; i < m ; i += 2)
		c[vc[x][i]] = 1 , c[vc[x][i + 1]] = -1;
	Dfs(x + 1);
	for(int i = 0 ; i < m ; i += 2)
		c[vc[x][i]] = -1 , c[vc[x][i + 1]] = 1;
	Dfs(x + 1);
}
int main()
{
	freopen("bracket.in" , "r" , stdin);
	freopen("bracket.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> p[i];
	for(int i = 1 ; i <= n ; i++)
	{
		if(vis[i])continue ;
		tot++;
		for(int u = i ; !vis[u] ; u = p[u])
		{
			vis[u] = 1;
			vc[tot].push_back(u);
		}
		int sz = vc[tot].size();
		assert(~sz & 1);
		if(sz == 2)
		{
			int x = vc[tot][0] , y = vc[tot][1];
			if(x > y)swap(x , y);
			c[x] = 1 , c[y] = -1;
			vc[tot--].clear();
		}
	}
	Dfs(1);
	return 0;
}