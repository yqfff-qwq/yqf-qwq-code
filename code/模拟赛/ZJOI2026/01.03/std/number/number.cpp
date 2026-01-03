#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4000 + 5;
int m , pr[N]; bool b[N];
void Sieve(int n = N - 5)
{
	for(int i = 2 ; i <= n ; i++)
	{
		if(!b[i])pr[++m] = i;
		for(int j = 1 ; j <= m && pr[j] * i <= n ; j++)
		{
			int x = pr[j] * i;
			b[x] = 1 ;
			if(i % pr[j] == 0)
				break ;
		}
	}
}
ll Solve()
{
	ll a; cin >> a;
	for(int i = 1 ; (ll)pr[i] * pr[i] * pr[i] * pr[i] * pr[i] <= a ; i++)
		if(a % pr[i] == 0)
		{
			int c = 0;
			while(a % pr[i] == 0)a /= pr[i] , c++;
			if(c == 1)
			{
				cout << "no\n";
				return 0;
			}
		}
	ll t = sqrtl(a) , c = cbrtl(a);
	if(t * t != a && c * c * c != a)cout << "no\n";
	else cout << "yes\n";
	return 0;
}
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	Sieve(); int T; cin >> T;
	while(T--)Solve();
	return 0;
}