#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); ++ i)
#define DEP(i, r, l) for (int i = (r); i >= (l); -- i)
#define fi first
#define se second
using namespace std;
namespace Milkcat {
    typedef long long LL;
    typedef pair<LL, LL> pii;
    const int N = 1e6 + 5, mod = 998244353, qwq[] = {0, 2, 3, 6, 7, 8, 9};
	LL n, ans; vector<LL> s;
	int main(){
		cin >> n, n --, ans = 0, s.clear();
		while (n) s.push_back(n % 7), n /= 7;
		reverse(s.begin(), s.end());
		for (int i : s)
			ans = (ans * 10 + qwq[i]) % mod;
		cout << ans << '\n';
		return 0;
	}
}
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1; cin >> T;
    while (T --) Milkcat::main();
    return 0;
}

