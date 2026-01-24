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
    const int mxN = 5000 + 5;
    int n, m, l, r, x, dp[mxN][mxN], sum[mxN][mxN], ans;
    bool islim[mxN][4]; pii lim[mxN][4];
    bool islm2[4]; pii lm2[4];

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
        int prelm2 = 1;
        REP(i, 2, n) {
            REP(j, 1, i - 1) {
                if (j == 1) ADD(dp[i][j], 6);
                ADD(dp[i][j], sum[i - 1][j]);
                // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
                ADD(dp[i][j], dp[j][j - 1]);
                // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
                if (islim[i][1] && !chkin(lim[i][1].fi, lim[i][1].se, i, i))     dp[i][j] = 0;
                if (islim[i][2] && !chkin(lim[i][2].fi, lim[i][2].se, j, i - 1)) dp[i][j] = 0, MAX(prelm2, lim[i][2].se);
                if (islim[i][3] && !chkin(lim[i][3].fi, lim[i][3].se, 1, j - 1)) dp[i][j] = 0, MAX(prelm2, lim[i][3].se - 1);
                // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
                sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
            }
        }
        DEP(i, n, 2) {
            REP(j, 0, i - 1) {
                if (islm2[1] && !chkin(lm2[1].fi, lm2[1].se, n, i))     dp[i][j] = 0;
                if (islm2[2] && !chkin(lm2[2].fi, lm2[2].se, j, i - 1)) dp[i][j] = 0;
                if (islm2[3] && !chkin(lm2[3].fi, lm2[3].se, 1, j - 1)) dp[i][j] = 0;
                ADD(ans, dp[i][j]);
            }
            REP(x, 1, 3) {
                if (islim[i][x]) {
                    if (!islm2[x]) {
                        islm2[x] = true;
                        lm2[x].fi = lim[i][x].fi;
                        lm2[x].se = lim[i][x].se;
                    } else {
                        MIN(lm2[x].fi, lim[i][x].fi);
                        MAX(lm2[x].se, lim[i][x].se);
                    }
                }
            }
        }
        if (!islm2[2] && !islm2[3]) ans += 3;
        cout << ans << '\n';
        REP(i, 0, n) REP(j, 0, n) dp[i][j] = sum[i][j] = 0;
        REP(i, 0, n) REP(j, 0, 3) islim[i][j] = 0, lim[i][j] = {0, 0};
        REP(j, 0, 3) islm2[j] = 0, lm2[j] = {0, 0};
        n = m = l = r = x = ans = 0;
    }
}

/*
dp[i][j]: 前 i 个位置，[j, i] 2色，[j - 1, i] 3色，且 (i - 1) != (i)
 * (i) in  {[j, i - 1]}: dp[i][j] += Sum{k in [j, i - 1]}(dp[k][j])
 * (i) nin {[j, i - 1]}: dp[i][j] += dp[j + 1][j]
*/

signed main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
