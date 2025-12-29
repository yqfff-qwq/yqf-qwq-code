/*
g++ knapsack.cpp -o knapsack -std=c++14 -Wall -pedantic -O2
*/

#include <bits/stdc++.h>
using namespace std;
int n; long long M;
long long v[500010], m[500010];
long long sm[500010], l;
vector<long long> V[100];
int main(){
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> M;
	for (int i = 1; i <= n; ++i)cin >> v[i] >> m[i];
	copy_n(m + 1, n, sm + 1);
	sort(sm + 1, sm + n + 1);
	l = unique(sm + 1, sm + n + 1) - sm - 1;
	for (int i = 1; i <= n; ++i)
		V[lower_bound(sm + 1, sm + l + 1, m[i]) - sm].emplace_back(v[i]);
	long long rs = 0;
	for (int i = 1; i < l; ++i){
		sort(V[i].begin(), V[i].end());
		long long mlt = sm[i + 1] / sm[i];
		long long R = min<long long>(M % sm[i + 1] / sm[i], V[i].size());
		rs += accumulate(V[i].end() - R, V[i].end(), 0ll); V[i].resize(V[i].size() - R);
		while ((int)V[i].size() >= mlt){
			V[i + 1].emplace_back(accumulate(V[i].end() - mlt, V[i].end(), 0ll));
			for (int c = mlt; c; --c)V[i].pop_back();
		}
		V[i + 1].emplace_back(accumulate(V[i].begin(), V[i].end(), 0ll));
		V[i].clear();
	}
	sort(V[l].begin(), V[l].end());
	long long R = min<long long>(M / sm[l], V[l].size());
	rs += accumulate(V[l].end() - R, V[l].end(), 0ll);
	cout << rs << endl;
	return 0;
}
