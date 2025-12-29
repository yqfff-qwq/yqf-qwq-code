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

    const int N = 2e5 + 5, N2 = 1e3 + 5;
    int n, q, a[N], b[N2][N2], t, x;

    void main() {
        cin >> n >> q;
        if (n <= 1e3) {
            REP(i, 1, n) cin >> a[i], b[0][i] = a[i];
            REP(t, 1, n) {
                int cnt = 0, j = n / 2 + 1;
                REP(i, 1, n / 2) {
                    while (j <= n && b[t - 1][j] < b[t - 1][i]) {
                        b[t][++cnt] = b[t - 1][j];
                        j++;
                    } b[t][++cnt] = b[t - 1][i];
                }
                while (j <= n) {
                    b[t][++cnt] = b[t - 1][j];
                    j++;
                }
            }
            REP(i, 1, q) {
                cin >> t >> x; t = min(n, t);
                cout << b[t][x] << '\n';
            }
        } else {
            REP(i, 1, n) cin >> a[i];
            REP(i, 1, q) {
                cin >> t >> x;
                if (t == 0) {
                    cout << a[i] << '\n';
                } else {
                    t = min(t, n / 2);
                    if (x <= t)              cout << x << '\n';
                    else if (x <= n / 2 + 1) cout << (t - 1 + n / 2 + 3 - x) << '\n';
                    else                     cout << (n + n / 2 + 2 - x) << '\n';
                }
            }
        }
    }
}

signed main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
