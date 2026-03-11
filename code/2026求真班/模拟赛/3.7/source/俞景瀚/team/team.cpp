#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int a[200010];
int ans;
int main() {
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		ans = max((int)(upper_bound(a + 1, a + n + 1, a[i] + 5) - a - i), ans);
	cout << ans;
	return 0;
}
