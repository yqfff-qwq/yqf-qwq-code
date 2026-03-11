#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("berry.in", "r", stdin);
	freopen("berry.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (abs(x - y) >= 2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
