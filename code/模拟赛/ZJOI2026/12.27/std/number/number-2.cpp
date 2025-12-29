#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define inf (ll)1e9
#define pii pair <ll, ll>
#define fr first
#define se second
const ll mod = 1e9 + 7;
char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 18, stdin), p1 == p2) ? EOF : *p1++)
inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f = ((ch == '-') ? -1 : f), ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
inline void write(ll x) {
	if(x < 0) x = -x, putchar('-');
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
ll len, mx, cnt;
ll p[25];
ll vis[25], to[25], trs[25];
inline ll get_val() {
	ll ans = 0;
	for(ll i = 1 + (p[1] == -1); i <= len; i++) ans = ans * cnt + trs[p[i]] + (i != len && vis[0]); 
	return ans + (p[len] != -1);
}
inline ll get_ans() {
	for(ll i = 1; i <= len; i++) {
		ll x = p[i];
		if(vis[x]) {
			if(to[x] == -1) {
				for(ll j = max(i - 1, 1ll); j >= 1; j--) {
					if(to[p[j]] != -1 || j == 1) {
						p[j] = to[p[j]];
						for(ll k = j + 1; k <= len; k++) p[k] = mx;
						return get_val();
					}
				}
			}
			else {
				p[i] = to[x];
				for(ll j = i + 1; j <= len; j++) p[j] = mx;
				return get_val();
			}
		}
	}
//	printf("%lld %lld\n", trs[5], trs[9]);
	return get_val();
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ll T = read();
	while(T--) {
		ll n = read(), m = read();
		for(ll i = 0; i < 10; i++) vis[i] = 0;
		for(ll i = 1; i <= m; i++) vis[read()] = 1;
		assert(n <= 1e18 && m <= 9 && m >= 1 && n >= 0 && T <= 100000); 
//		assert(vis[0] == 0);
//		assert(m == 1);
		cnt = 0;
		for(ll i = 0; i < 10; i++) {
			if(!vis[i]) mx = i, trs[i] = cnt++;
			to[i] = ((i && vis[i-1]) ? to[i-1] : (i - 1));
		}
		if(n == 0) {
			printf("%lld\n", (ll)!vis[0]);
			continue;
		}
		len = 0;
		while(n) p[++len] = n % 10, n /= 10;//, assert(vis[p[len]] == 0);
		reverse(p + 1, p + 1 + len);
		write(get_ans()), putchar('\n'); 
	}
	return 0;
}
/*
1
1 3
0 1 3 
*/
