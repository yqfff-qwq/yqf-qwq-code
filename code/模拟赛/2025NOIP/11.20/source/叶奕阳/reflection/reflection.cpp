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
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int N = 2e5 + 5;
    int n, q, c, a[N], l, r, x;
    int s[500 + 5][101];

    void main() {
        cin >> n >> q >> c;
        REP(i, 1, n) cin >> a[i];
        if (n <= 1e4 && q <= 1e4) {
            REP(i, 1, q) {
                cin >> l >> r >> x;
                REP(i, l, r) {
                    x = abs(a[i] - x);
                } cout << x << '\n';
            }
        } else {
            REP(i, 1, n / 500) {
                int l = (i - 1) * 500 + 1, r = i * 500;
                REP(x, 0, 500) {
                    s[i][x] = x;
                    REP(j, l, r) s[i][x] = abs(a[j] - s[i][x]);
                }
            }
            REP(i, 1, q) {
                cin >> l >> r >> x;
                while (l <= r && l % 500 != 1) {
                    x = abs(a[l] - x);
                    l++;
                }
                while (l + 500 - 1 <= r) {
                    x = s[(l / 500) + 1][x];
                    l += 500;
                }
                while (l <= r) {
                    x = abs(a[l] - x);
                    l++;
                }
                cout << x << '\n';
            }
        }
    }
}

signed main() {
    freopen("reflection.in", "r", stdin);
    freopen("reflection.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
