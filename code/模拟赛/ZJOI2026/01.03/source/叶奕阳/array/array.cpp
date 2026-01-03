#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();i++)
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=((a)-(b)+mod)%mod
#define MUL(a,b) (a)=(((a)%mod)*((b)%mod))%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)a.size())
#define ppc(x)   __builtin_popcount(x)
#define DBG(x)   cerr<<#x<<' '<<(x)<<'\n'
#define int long long
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int mod = 998244353;
    const int N = 5000 + 5;
    int n, a[N], sum, ans;

    int dfs() {
        bool f = true;
        REP(i, 1, n) f &= (!a[i]);
        if (f) {
            return 1;
        } else {
            int res = 0;
            REP(i, 1, n) {
                REP(j, i + 1, n) {
                    if (a[i] && a[j]) {
                        a[i]--, a[j]--;
                        res += dfs();
                        a[i]++, a[j]++;
                    }
                }
            }
            return res;
        }
    }

    void main() {
        cin >> n;
        REP(i, 1, n) cin >> a[i], sum += a[i];
        if (sum % 2 == 1) {
            cout << 0 << '\n';
        } else if (n == 1) {
            cout << 0 << '\n';
        } else if (n == 2) {
            cout << (a[1] == a[2] ? 1 : 0) << '\n';
        } else if (n <= 5 && sum <= 8) {
            cout << dfs() << '\n';
        } else if (n == sum) {
            ans = 1;
            REP(i, 1, n) {
                if (i % 2 == 1) MUL(ans, i);
                else            MUL(ans, i / 2);
            }
            cout << ans << '\n';
        } else {
            cout << dfs() << '\n';
        }
    }
}

signed main() {
    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
