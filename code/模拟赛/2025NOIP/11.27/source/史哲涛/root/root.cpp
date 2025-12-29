/*
g++ root.cpp -o root -std=c++14 -Wall -pedantic -O2
*/

#include <bits/stdc++.h>
using namespace std;
long long n, m;
void work(){
	cin >> n >> m;
	long long c = max(0ll, m / n - 2);
	for (long long x = 1 + n * c; x <= n + m; x += n)c += (x ^ (n - 1)) <= m;
	cout << c << "\n";
}
int main(){
	freopen("root.in", "r", stdin);
	freopen("root.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)work();
	return 0;
}
