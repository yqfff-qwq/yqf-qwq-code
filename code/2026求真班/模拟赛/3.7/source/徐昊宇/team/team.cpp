#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 2e5 + 10;
int n, a[N], ans;

signed main() {
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++ i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;++ i){
		int l = i, r = n, res = i;
		while(l <= r) {
			int mid = l + r >> 1;
			if(a[mid] <= a[i] + 5) l = mid + 1, res = mid;
			else r = mid - 1;
		}
		ans = max(ans, res - i + 1);
	}
	cout << ans;
	return 0;
}
