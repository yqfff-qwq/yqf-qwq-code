/*
g++ photo.cpp -o photo -std=c++14 -Wall -pedantic -O2
*/

#include <bits/stdc++.h>
using namespace std;
int n, t, a[10010], b[10010];
namespace S1 {
	int L[10010];
	vector<int> id[10010];
	int ts[10010];
	void sol1(){
		copy_n(a + 1, n, L + 1);
		sort(L + 1, L + n + 1);
		int m = unique(L + 1, L + n + 1) - L - 1;
		for (int i = 1; i <= n; ++i)
			id[lower_bound(L + 1, L + m + 1, a[i]) - L].emplace_back(i);
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		for (int tm = 0, t = 1; ; ++tm){
			if (t <= m && tm >= L[t])
				for (int x : id[t++])pq.emplace(b[x] - 1, x);
			if (pq.empty()){
				if (t > m)break;
				tm = L[t] - 1;
				continue;
			}
			if (pq.top().first < tm){
				cout << "no" << endl;
				exit(0);
			}
			int id = pq.top().second;
			ts[id] = tm;
			pq.pop();
		}
		cout << "yes" << endl;
		for (int i = 1; i <= n; ++i)cout << ts[i] << " ";
		cout << endl;
		exit(0);
	}
}
namespace S2 {
	int f[1 << 20]; //f_s : subset s, min end
	constexpr int inf = 1e9+10;
	bool tmn(int &x, int y){
		return x > y? x = y, 1 : 0;
	}
	int p[1 << 20];
	void sol2(){
		fill_n(f, 1 << n, inf);
		f[0] = 0;
		for (int s = 0; s < 1 << n; ++s){
			for (int i = 1; i <= n; ++i)if (~s >> (i - 1) & 1){
				int bg = max(f[s], a[i]);
				if (bg + t <= b[i])
					if (tmn(f[s ^ 1 << (i - 1)], bg + t))p[s ^ 1 << (i - 1)] = i;
			}
		}
		if (f[(1 << n) - 1] == inf){
			cout << "no" << endl;
			exit(0);
		}
		cout << "yes" << endl;
		int rs[25];
		for (int s = (1 << n) - 1; s; s ^= 1 << (p[s] - 1))
			rs[p[s]] = f[s] - t;
		for (int i = 1; i <= n; ++i)cout << rs[i] << " ";
		cout << endl;
		exit(0);
	}
}
int main(){
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; ++i)cin >> a[i] >> b[i];
	if (t == 1)S1::sol1();// sub3, 20pts
	if (n <= 20)S2::sol2();// sub1-2, 20pts
	return 0;
}
