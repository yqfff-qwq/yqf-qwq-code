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
ll n, Q;
ll pos[1000005], nxt[1000005], sta[1000005], top;
struct Query {
	ll x, y, id;
}q[1000005];
bool cmp (Query A, Query B) {
	return A.x < B.x;
}
ll a[1000005], b[1000005], ans[1000005];

ll tag[1000005];
struct Seg_Tree {
	struct st {
		ll l, r;
		ll ans;
	}t[4000005];
	void build (ll id, ll l, ll r) {
		t[id].l = l, t[id].r = r;
		if (l == r) return ;
		ll mid = (l + r) / 2;
		build (id << 1, l, mid);
		build (id << 1 | 1, mid + 1, r);
	}
	void push_down (ll id, ll x, ll y) {
		if (t[id].l == t[id].r) {
			t[id].ans = y;
			return ;
		}
		ll mid = (t[id].l + t[id].r) / 2;
		if (x <= mid) push_down (id << 1, x, y);
		else push_down (id << 1 | 1, x, y);
		t[id].ans = t[id << 1].ans + t[id << 1 | 1].ans;
	}
	ll get_ans (ll id, ll k) {
		if (t[id].l == t[id].r) return pos[t[id].l] + k - 1;
		if (t[id << 1].ans >= k) return get_ans (id << 1, k);
		else return get_ans (id << 1 | 1, k - t[id << 1].ans);
		return 0;
	}
	void del (ll id, ll k) {
		if (t[id].l == t[id].r) {
			push_down(1, t[id].l, k);
			ll x = pos[t[id].l];
			for (ll i = x + k; i < nxt[x]; i = nxt[i]) {
				nxt[i] = min (nxt[i], nxt[x]);
				push_down(1, a[i], nxt[i] - i);
			}
			nxt[x] = x + k;
			return ;
		}
		if (t[id << 1].ans >= k) del (id << 1, k);
		else del (id << 1 | 1, k - t[id << 1].ans);
		return ;
	}
}T;
void deal () {
	ll cnt = 0, j = n / 2 + 1;
	for (ll i = 1; i <= n / 2; i++) {
		while (j <= n && a[j] < a[i]) b[++cnt] = a[j], j++;
		b[++cnt] = a[i];
	}
	while (j <= n) b[++cnt] = a[j], j++;
	for (ll i = 1; i <= n; i++) a[i] = b[i];
}
signed main () {
	freopen ("sort.in", "r", stdin);
	freopen ("sort.out", "w", stdout);
	n = read (), Q = read ();
	for (ll i = 1; i <= n; i++) a[i] = read ();
	for (ll i = 1; i <= Q; i++) q[i].x = min (read (), n), q[i].y = read (), q[i].id = i;
	sort (q + 1, q + 1 + Q, cmp);
	ll j = 1;
	while (j <= Q && q[j].x == 0) ans[q[j].id] = a[q[j].y], j++;
	deal ();
	memset (b, 0, sizeof b);
	for (ll i = n; i >= 1; i--) {
		while (top && a[sta[top]] < a[i]) top--;
		nxt[i] = sta[top];
		if (!nxt[i]) nxt[i] = n + 1;
		pos[a[i]] = i;
		sta[++top] = i;
	}
	T.build(1, 1, n);
	for (ll i = 1; i <= n && i; i = nxt[i]) T.push_down(1, a[i], nxt[i] - i);
	for (ll i = 1; i <= n; i++) {
		while (j <= Q && q[j].x == i) ans[q[j].id] = a[T.get_ans(1, q[j].y)], j++;
		T.del(1, n / 2);
	}
	for (ll i = 1; i <= Q; i++) write (ans[i]), putchar ('\n');
	return 0;
}
/*
6 1
2 1 5 4 6 3
10 6
*/
