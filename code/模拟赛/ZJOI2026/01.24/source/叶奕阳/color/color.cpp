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
typedef long long ll;

namespace Yyydrasil {

    const int mod = 1e9 + 7;
    const int mxN = 505 + 5;
    int n, m, l, r, x, dp[mxN][mxN][mxN], ans;
    bool islim[mxN][4]; pii lim[mxN][4];

    bool chkin(int a, int b, int l, int r) { return l <= a && b <= r; }

    void main() {
        cin >> n >> m;
        REP(i, 1, m) {
            cin >> l >> r >> x;
            if (!islim[r][x]) {
                islim[r][x] = true;
                lim[r][x].fi = l;
                lim[r][x].se = l;
            } else {
                MIN(lim[r][x].fi, l);
                MAX(lim[r][x].se, l);
            }
        }
        dp[1][1][0] = 3;
        REP(i, 1, n - 1) {
            REP(j, 1, i) {
                REP(k, 0, j - 1) {
                    if (islim[i][1] && !chkin(lim[i][1].fi, lim[i][1].se, j, i))     dp[i][j][k] = 0;
                    if (islim[i][2] && !chkin(lim[i][2].fi, lim[i][2].se, k, j - 1)) dp[i][j][k] = 0;
                    if (islim[i][3] && !chkin(lim[i][3].fi, lim[i][3].se, 1, k - 1)) dp[i][j][k] = 0;
                    ADD(dp[i + 1][j][k], dp[i][j][k]);
                    ADD(dp[i + 1][i + 1][k], dp[i][j][k]);
                    ADD(dp[i + 1][i + 1][j], dp[i][j][k]);
                }
            }
        }
        REP(i, n, n) {
            REP(j, 0, n) {
                REP(k, 0, n) {
                    if (islim[i][1] && !chkin(lim[i][1].fi, lim[i][1].se, j, i))     dp[i][j][k] = 0;
                    if (islim[i][2] && !chkin(lim[i][2].fi, lim[i][2].se, k, j - 1)) dp[i][j][k] = 0;
                    if (islim[i][3] && !chkin(lim[i][3].fi, lim[i][3].se, 1, k - 1)) dp[i][j][k] = 0;
                    ADD(ans, dp[i][j][k]);
                }
            }
        }
        cout << ans << '\n';
        REP(i, 0, n) REP(j, 0, n) REP(k, 0, n) dp[i][j][k] = 0;
        REP(i, 0, n) REP(j, 0, 3) islim[i][j] = 0, lim[i][j] = {0, 0};
        n = m = l = r = x = ans = 0;
    }
}

signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
