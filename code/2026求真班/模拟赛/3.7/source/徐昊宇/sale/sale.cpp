#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 500 + 10;
int n, cnt[65];
LL a[N];
LL ans;

signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++ i) cin >> a[i];
	if(n <= 3) {
		for(int i = 0;i <= 60;++ i){
			for(int j = 1;j <= n;++ j){
				if((a[j] >> i) & 1) {
					ans += (1ll << i);
					break;
				}
			}
		}
		cout << ans;
	} else {
		for(int i = 1;i <= n;++ i){
			for(int j = i + 1;j <= n;++ j){
				for(int k = j + 1;k <= n;++ k){
					ans = max(ans, (a[i] | a[j] | a[k]));
				}
			}
		}
		cout << ans;
	}
	return 0;
}
