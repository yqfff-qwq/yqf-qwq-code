#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 500 + 10;
int T;
LL a, b;

bool sg(LL x, LL y, bool q) {
	//cout << x << ' ' << y << " " << q << "\n";
	if(x < y) swap(x, y);
	if(x == 1 && y == 0) return !q;
	if(x == 0 && y == 0) return !q;
	//bool r = 0;
	for(int i = 1;2 * i <= x;++ i){
		if(sg(x - 2 * i, y + i, !q) == q) return q;
	}
	for(int i = 1;2 * i <= y;++ i){
		if(sg(x + i, y - 2 * i, !q) == q) return q;
	}
	return !q;
}

signed main() {
	freopen("berry.in", "r", stdin);
	freopen("berry.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> a >> b;
		if(abs(a - b) > 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
