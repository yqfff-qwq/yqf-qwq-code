#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 500 + 10;
int n, ma, len, l9, a[12];
LL ans, dp[12][12];

int cal(LL x) {
	int res = 0;
	while(x) {
		if(x % 10 == 9) res++;
		else break;
		x /= 10;
	}
	return res;
}

LL dfs(int p1, int p2, bool f1, bool f2, bool lim1, bool lim2) {
	if(p1 < 1) return 1; 
	if(!f1 && !f2 && !lim1 && !lim2 && dp[p1][p2] != -1) return dp[p1][p2];
	int up1, up2;
	if(lim1) up1 = a[p1];
	else up1 = 9;
	if(lim2) up2 = a[p2];
	else up2 = 9;
	//int up1 = (lim1 ? a[p1] : 9), up2 = (lim2 ? a[p2] : 9);
	LL res = 0; 
	if(p1 > l9) {
		for(int i = 0;i <= up1;++ i){
			for(int j = i;j <= up2;++ j){ 
				res += dfs(p1 - 1, p2 - 1, (f1 && i == 0), (f2 && j == 0), (lim1 && i == up1), (lim2 && j == up2));
			}
		}
	} else {
		for(int i = 0;i <= up1;++ i){
			for(int j = 0;j <= up2;++ j){
				if(i + j == 9) 
				 	res += dfs(p1 - 1, p2 - 1, (f1 && i == 0), (f2 && j == 0), (lim1 && i == up1), (lim2 && j == up2));
			}
		}
	}
	if(!f1 && !f2 && !lim1 && !lim2) dp[p1][p2] = res;
	return res;
} 

signed main() {
	freopen("wota.in", "r", stdin);
	freopen("wota.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	if(n <= 1e4) {
		for(int i = 1;i <= n;++ i){
			for(int j = i + 1;j <= n;++ j){
			 	ma = max(ma, cal(i + j));
			}
		}
		for(int i = 1;i <= n;++ i){
			for(int j = i + 1;j <= n;++ j){
				if(cal(i + j) == ma) {
					//cout << i << ' ' << j << "\n";
					ans++;
				}
			}
		}
		cout << ans;
	} else {
		LL x = 9;
		for(l9 = 1;x <= 2 * n;x = x * 10 + 9, l9++);
		l9--;
		while(n) {
			a[++len] = n % 10;
			n /= 10;
		}
		//cout << l9 << " " << len << " tt" << "\n";
		memset(dp, -1, sizeof(dp));
		cout << dfs(len, len, 1, 1, 1, 1) / 2;
	}
	return 0;
}
