#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans, a[505];
signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n >= 3) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					ans = max(ans, a[i] | a[j] | a[k]);
				}
			}
		}
	} else if (n == 2) ans = a[1] | a[2];
	else ans = a[1];
	cout << ans;
	return 0;
}
