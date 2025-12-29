#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define inf (ll)1e9
#define pii pair <ll, ll>
#define fr first
#define se second
const ll mod = 1e9 + 7;
//char buf[1 << 21], *p1 = buf, *p2 = buf;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 18, stdin), p1 == p2) ? EOF : *p1++)
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
ll n, m;
char ch[300005];
ll a[300005], ans[300005];
ll b[300005];
ll L[300005], R[300005], vis[300005];
void get_ans(ll l, ll r, ll num, ll bas) {//num:block alive bas:del sum
    priority_queue <pii> Q;
    for(ll i = l; i <= r; i++) {
        b[i] = a[i];
        vis[i] = 0;
        Q.push(mp(-b[i], i));
        L[i] = i - 1, R[i] = i + 1;
    }
    b[0] = inf;
    L[l] = R[r] = 0;
    while(!Q.empty() && num >= 0) {
        pii x = Q.top();
        Q.pop();
        ll id = x.second;
        ans[num] = max(ans[num], bas);
        if(vis[id]) continue;
        bas += x.first;
        b[id] = b[L[id]] + b[R[id]] - b[id];
        vis[L[id]] = vis[R[id]] = 1;
        if(L[L[id]]) R[L[L[id]]] = id;
        if(R[R[id]]) L[R[R[id]]] = id;
        L[id] = L[L[id]], R[id] = R[R[id]];
        Q.push(mp(-b[id], id));
        num -= 2;
    }
}
signed main () {
	freopen ("modification.in", "r", stdin);
	freopen ("modification.out", "w", stdout);
	n = read();
    scanf("%s", ch + 1);
    ll mx = 0, ss0 = 0, ss1 = 0;
    for(ll i = 1; i <= n; i++) ss1 += (ch[i] == '1');
    mx = max(ss0, ss1);
    for(ll i = 1; i <= n; i++) {
        ss0 += (ch[i] == '0');
        ss1 -= (ch[i] == '1');
        mx = max(mx, ss0 + ss1);
    }
    write(mx), putchar(' ');
    for(ll i = 1; i <= n; i++) {
        ll j = i;
        while(j < n && ch[i] == ch[j+1]) j++;
        a[++m] = j - i + 1;
        i = j;
    }
    get_ans(3, m - 2, m - 2, n - (a[1] + a[m]));
    get_ans(3, m - 1, m - 1, n - a[1]); 
    get_ans(2, m - 2, m - 1, n - a[m]);
    get_ans(2, m - 1, m, n);
    for(ll i = 3; i <= m; i++) ans[i] = max(ans[i], ans[i-1]), write(ans[i]), putchar(' ');
    for(ll i = 1; i <= n - m + 1; i++) write(n), putchar(' ');
    putchar('\n');
	return 0;
}
/*
*/
