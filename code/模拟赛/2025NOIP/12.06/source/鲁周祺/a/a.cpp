#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Mamba return
#define Out 0;
#define pb push_back
#define lowbit(x) x&-x
inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
inline void write(ll x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
inline ll max(ll x, ll y) {
	return x > y ? x : y;
}
inline ll min(ll x, ll y) {
	return x < y ? x : y;
}
const int N = 1005;
ll T = 1, n, a[N], ans = 1e9;
signed main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
//	T=read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ll l = i - 1, r = j + 1, res = a[i], num = a[j];
				ans = min(ans, abs(num - res));
				while (l >= 1 && r <= n) {
					if (num < res) {
						num += a[r];
						r++;
					} else {
						res += a[l];
						l--;
					}
					ans = min(ans, abs(num - res));
				}
				for (int k = l; k >= 1; k--) {
					res += a[k];
					ans = min(ans, abs(num - res));
				}
				for (int k = r; k <= n; k++) {
					num += a[k];
					ans = min(ans, abs(num - res));
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	Mamba Out
}
