#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct Node {
	int l, r;
	int num;
} ans[2000005];
int  a[2000005];
signed main() {
	freopen("synapse.in", "r", stdin);
	freopen("synapse.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int l, n;
		cin >> l >> n;
		ans[0].l = 0;
		ans[0].r = 0;
		ans[0].num = 0;
		ans[n].l = l;
		ans[n].r = l;
		ans[n].num = l;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; i++) {
			ans[i].l = a[i];
			ans[i].r = a[i + 1];
		}
		if (n == 3) {
			int x = l / 3;
			if (x < ans[1].l) ans[1].num = ans[1].l;
			else if (x > ans[1].r) ans[1].num = ans[1].r;
			else {
				ans[1].num = x ;
			}
			x *= 2;
			if (x < ans[n - 1].l) ans[n - 1].num = ans[n - 1].l;
			else if (x > ans[n - 1].r) ans[n - 1].num = ans[n - 1].r;
			else {
				ans[n - 1].num = x ;
			}
		} else {
//			for (int i = 2; i < n - 1; i++) {
//				int x = (ans[i - 1].r + ans[i + 1].l);
//				x /= 2;
//				if (x < ans[i].l) ans[i].num = ans[i].l;
//				else if (x > ans[i].r) ans[i].num = ans[i].r;
//				else {
//					ans[i].num = x ;
//				}
//			}
//			int x = ans[2].num / 2+0.5;
//			if (x < ans[1].l) ans[1].num = ans[1].l;
//			else if (x > ans[1].r) ans[1].num = ans[1].r;
//			else {
//				ans[1].num = x ;
//			}
//			x = (ans[n - 2].num + l) / 2+0.5;
//			if (x < ans[n - 1].l) ans[n - 1].num = ans[n - 1].l;
//			else if (x > ans[n - 1].r) ans[n - 1].num = ans[n - 1].r;
//			else {
//				ans[n - 1].num = x ;
//			}
			for (int i = 1; i < n; i++) {
				int x = l / n * i;
				if (x < ans[i].l) {
					ans[i].num = ans[i].l;
				} else if (x > ans[i].r) {
					ans[i].num = ans[i].r;
				} else {
					ans[i].num = x ;
				}
			}
			for (int i = 1; i < n; i++) {
				if (ans[i].num == ans[i].l) {
					int x = (ans[i].num + ans[i - 2].num) / 2;
					if (x < ans[i - 1].l) {
						ans[i - 1].num = ans[i - 1].l;
					} else if (x > ans[i - 1].r) {
						ans[i - 1].num = ans[i - 1].r;
					} else {
						ans[i - 1].num = x ;
					}
				}
				if (ans[i].num == ans[i].r) {
					int x = (ans[i].num + ans[i + 2].num) / 2;
					if (x < ans[i + 1].l) {
						ans[i + 1].num = ans[i + 1].l;
					} else if (x > ans[i - 1].r) {
						ans[i + 1].num = ans[i + 1].r;
					} else {
						ans[i + 1].num = x ;
					}
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			cout << ans[i].num << " ";
		}
		cout << endl;
	}
	return 0;
}
