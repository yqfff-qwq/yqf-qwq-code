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
ll aans[1000005];
inline void solve(ll ad, ll tag) {
	ll Lnum = 0, Rnum = 0, Lsum = 0, Rsum = 0;
	for(ll i = 1; i <= n; i++) {
		Lnum += (ch[i] == 'L'), Rnum += (ch[i] == 'R');
		Lsum += (ch[i] == 'L') * i, Rsum += (ch[i] == 'R') * i;
	}
	
	//L left out
	ll lnum = 0, lsum = 0, rnum = 0, rsum = 0;
	for(ll i = 1, j = 1; i <= n; i++) {
		ll id = i + ad;
		if(tag) id = n - i + 1 + ad;
		if(ch[i] == 'R') rnum++, rsum += i;
		if(ch[i] == 'L') {
			while(j <= n && (j <= i || lnum <= rnum)) {
				if(ch[j] == 'L') lnum++, lsum += j;
				j++;
			}
			if(lnum <= rnum) break;
			aans[id] = (lsum - rsum) * 2 - i;
			lnum--, lsum -= i;
		}
	}
	//R left out
	lnum = 0, lsum = 0, rnum = 0, rsum = 0;
	for(ll i = 1, j = 1; i <= n; i++) {
		ll id = i + ad;
		if(tag) id = n - i + 1 + ad;
		if(ch[i] == 'R') {
			rnum++, rsum += i;
			while(j <= n && (j <= i || lnum < rnum)) {
				if(ch[j] == 'L') lnum++, lsum += j;
				j++;
			}
			if(lnum < rnum) break;
			aans[id] = (lsum - rsum) * 2 + i;
		}
		if(ch[i] == 'L') lnum--, lsum -= i;
	}
}
inline void Solve(ll ad) {
	solve(ad, 0);
	for(ll i = 1; i <= n; i++) {
		if(ch[i] == 'L') ch[i] = 'R';
		else ch[i] = 'L';
	}
	reverse(ch + 1, ch + 1 + n);
	solve(ad, 1);
}
signed main () {
	freopen ("train.in", "r", stdin);
	freopen ("train.out", "w", stdout);
    ll nn = read();
    scanf("%s", str + 1);
    assert(nn == (ll)strlen(str + 1));
    assert(str[1] == 'O' && str[nn] == 'O');
    
//    ll numR = 0;
//    for(ll i = 1; i <= nn; i++) numR += (str[i] == 'R');
//    assert(numR <= 20);
    
//    assert(nn <= 100000);
    
    for(ll i = 1, j; i <= nn; i = j + 1) {
    	j = i;
    	while(j < nn && str[j+1] != 'O') j++;
    	n = j - i;
    	for(ll k = 1; k <= n; k++) ch[k] = str[k+i];
		Solve(i);
	}
	for(ll i = 1; i <= nn; i++) write(aans[i]), putchar(' ');
	putchar('\n'); 
	return 0;
}
/*
*/
