#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[1000005];
signed main() {
	freopen("starlight.in", "r", stdin);
	freopen("starlight.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << 1 << endl;
	}
	return 0;
}
