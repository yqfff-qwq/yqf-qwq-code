#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005 , S = 3e4 + 5 , MOD = 998244353;
int n , b[N] , s[N] , f[2][S];
int Qpow(ll x , ll p)
{
	ll res = 1;
	x %= MOD , p %= MOD - 1;
	if(p < 0)p += MOD - 1;
	for(; p ; p >>= 1 , x = x * x % MOD) 
		if(p & 1)res = res * x % MOD;
	return res;
}
int fac[S] , ifac[S];
void Init(int n)
{
	fac[0] = ifac[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[n] = Qpow(fac[n] , MOD - 2);
	for(int i = n - 1 ; i >= 1 ; i--)
		ifac[i] = (ll)ifac[i + 1] * (i + 1) % MOD;
}
int C(int n , int m)
{
	if(n < m || m < 0)return 0;
	return (ll)fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
int main()
{
	freopen("array.in" , "r" , stdin);
	freopen("array.out" , "w " , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> b[i];
	for(int i = 1 ; i <= n ; i++)
		s[i] = s[i - 1] + b[i];
	Init(s[n]);
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		int now = i & 1 , lst = now ^ 1;
		memset(f[now] , 0 , sizeof f[now]);
		for(int j = 0 ; j <= s[i - 1] / 2 ; j++)
		{
			int a = s[i - 1] - j * 2;
			int c = s[n] / 2 - j - a;
			for(int k = max(0 , b[i] - c) ; k <= min(b[i] , a) ; k++)
				f[now][j + k] = (f[now][j + k] + (ll)f[lst][j] * C(a , k) % MOD * C(c , b[i] - k)) % MOD;
		}
	}
	int ans = 0;
	for(int i = 0 ; i <= s[n] / 2 ; i++)
		ans = (ans + f[n & 1][i]) % MOD;
	cout << ans << "\n";
	return 0;
}