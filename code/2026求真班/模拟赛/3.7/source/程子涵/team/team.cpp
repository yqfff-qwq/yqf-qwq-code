#include<bits/stdc++.h>
//#define int long long
using namespace std;
int ans, a[200005];
signed main() {
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int r = 1;
	for (int l = 1; l <= n; l++) {
		while (r + 1 <= n && a[r + 1] - a[l] <= 5) r++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
