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
ll n;
char ch[1000005], str[1000005];
ll sd[1000005], su[1000005], cntd[1000005], cntu[1000005];
ll nxtd[1000005], preu[1000005], aans[1000005];
inline void solve(ll ad) {
	for(ll i = 1; i <= n; i++) sd[i] = sd[i-1] + (ch[i] == 'L') * i, cntd[i] = cntd[i-1] + (ch[i] == 'L');
	for(ll i = 1; i <= n; i++) su[i] = su[i-1] + (ch[i] == 'R') * i, cntu[i] = cntu[i-1] + (ch[i] == 'R');
	ll whi = n + 1;
	for(ll i = n; i >= 1; i--) {
		nxtd[i] = whi;
		if(ch[i] == 'L') whi = i;
	}
	whi = 0;
	for(ll i = 1; i <= n; i++) {
		preu[i] = whi;
		if(ch[i] == 'R') whi = i;
	}
	for(ll i = 1; i <= n; i++) {
		ll cd = cntd[n] - cntd[i], cu = cntu[i-1];
		if(cd > cu || (cd == cu && ch[i] == 'L')) {
			ll l = i + 1, r = n, ans = i + 1;
			while(l <= r) {
				ll mid = (l + r) / 2;
				if(cntd[mid] - cntd[i] >= cu + (ch[i] == 'R')) r = mid - 1, ans = mid;
				else l = mid + 1;
			}
			if(ch[i] == 'R') aans[i+ad] = 2 * (sd[ans] - sd[i-1]) - 2 * su[i] + i;
			else {
				if(preu[i] == 0) aans[i+ad] = i; 
				else aans[i+ad] = 2 * (sd[ans] - sd[i-1]) - 2 * su[i] - i;
			}
		}
		else {
			ll l = 1, r = i, ans = 1;
			while(l <= r) {
				ll mid = (l + r) / 2;
				if(cntu[i] - cntu[mid-1] >= cd + 1) l = mid + 1, ans = mid;
				else r = mid - 1;
			}
			if(ch[i] == 'R') {
				if(nxtd[i] == n + 1) aans[i+ad] = n + 1 - i;
				else aans[i+ad] = 2 * (sd[n] - sd[i-1]) + n + 1 - 2 * (su[i] - su[ans-1]) + i;
			}
			else {
				aans[i+ad] = 2 * (sd[n] - sd[i-1]) + n + 1 - 2 * (su[i] - su[ans-1]) - i;
			}
		}
	}
}
signed main () {
	freopen ("train.in", "r", stdin);
	freopen ("train.out", "w", stdout);
    ll nn = read();
    scanf("%s", str + 1);
    for(ll i = 1, j; i <= nn; i = j + 1) {
    	j = i;
    	while(j < nn && str[j+1] != 'O') j++;
    	n = j - i;
    	for(ll k = 1; k <= n; k++) ch[k] = str[k+i];
		solve(i);
	}
	for(ll i = 1; i <= nn; i++) write(aans[i]), putchar(' ');
	putchar('\n'); 
	return 0;
}
/*
*/
