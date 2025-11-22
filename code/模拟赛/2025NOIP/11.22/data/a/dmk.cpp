#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const string path = "data";
mt19937 egn(time(NULL));
void solve(int id, int l, int r, int T, int n) {
	auto rnd = [&](LL L, LL R) {
		return uniform_int_distribution<LL>(L, R)(egn);
	};
	for (int dat = l; dat <= r; dat ++) {
		string str = path + to_string(dat) + ".in";
		freopen(str.c_str(), "w", stdout);
		
        cout << T << '\n';
        for (int i = 1; i <= T; i ++)
        	cout << rnd(1, n) << '\n';
		
		fclose(stdout);
	}
}
int main() {
	solve(-1, 1, 3, 10, 1e3);
	return 0;
}
