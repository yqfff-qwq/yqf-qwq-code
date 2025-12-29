// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define REP(i, l, r)  for(int i = (l);i <= (r);i++)
#define DEP(i, r, l)  for(int i = (r);i >= (l);i--)

void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while(ch < '0' or '9' < ch) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while('0' <= ch and ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  if(f) x = -x;
  read(oth...);
  return;
}

namespace YZLK{
  const int N = 1e5 + 10;
	const int mod = 998244353;
	int n;
  char c[N];
  int ksm(int a, int b) {
		int s = 1;
		while(b) {
			if (b & 1)	s = s * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return s;
	}
	int fac[N], inv[N];
	void init() {
		fac[0] = inv[0] = 1;
		REP(i, 1, N - 10)	fac[i] = fac[i - 1] * i % mod;
		inv[N - 10] = ksm(fac[N - 10], mod - 2);
		DEP(i, N - 11, 1)	inv[i] = inv[i + 1] * (i + 1) % mod;
		return;
	}
	int C(int x, int y) {
		// cout << x << " " << y << "\n";
		if (x < y)	return 0;
		// cout << fac[x] << " " << inv[y] << " " << inv[x - y] << "\n";
		return fac[x] * inv[y] % mod * inv[x - y] % mod;
	}
	void main() {
    read(n);
    scanf("%s", c + 1);
		int a = 0, b = 0;
		c[n + 1] = '#';
		REP(i, 1, n) {
			if (c[i] == '1') {
				if (c[i] == c[i + 1])	a++, i++;
				else									b++;
			}
		}
		// cout << a << ' ' << b << "\n";
		cout << C(n - a - b, a) << "\n";
    return;
  }
}

signed main() {
//   freopen("knapsack.in", "r", stdin);
//   freopen("knapsack.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
	YZLK::init();
  int T = 1;
  read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);

  return 0;
}