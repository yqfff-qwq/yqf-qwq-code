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
ll cnt;
ll vis[25], p[25];
inline bool chk(ll x) {
	if(x == 0 && vis[0]) return 0;
	while(x) {
		if(vis[x%10]) return 0;
		x /= 10;
	}
	return 1; 
}
ll f[25][2];
inline ll dfs(ll x, ll fl) {
	if(!x) return 1;
	if(f[x][fl] != -1) return f[x][fl];
	f[x][fl] = 0;
	for(ll i = 0; i <= 9; i++) {
		if(vis[i]) continue;
		if(i > p[x] && !fl) continue;
		f[x][fl] += dfs(x - 1, fl | (i < p[x]));
	}
	return f[x][fl];
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ll T = read();
	while(T--) {
		ll n = read(), m = read();
		for(ll i = 0; i < 10; i++) vis[i] = 0;
		for(ll i = 1; i <= m; i++) vis[read()] = 1;
		cnt = 0;
		while(n) p[++cnt] = n % 10, n /= 10;
		for(ll i = 0; i <= cnt; i++) f[i][0] = f[i][1] = -1;
		ll ans = 0;
		for(ll i = cnt; i >= 1; i--) for(ll j = 1; j <= 9; j++) if(!vis[j] && !(i == cnt && j > p[i])) ans += dfs(i - 1, !(i == cnt && j == p[i]));
		write(ans + !(vis[0])), putchar('\n');
	}
	return 0;
}
/*
*/
