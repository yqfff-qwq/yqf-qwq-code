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

    inline int read() {
        int x = 0; char ch = getchar();
        while (ch < '0' || ch > '9')   ch = getchar();
        while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        return x;
    }

    const int mxN = 200 + 5, mxM = 5000 + 5;
    ll d[mxM], sumd[mxM], a[mxM][mxN];
    ll dp[mxM][mxM], ans;
    int n, m;

    void main() {
        n = read(), m = read();
        REP(i, 2, m) {
            d[i] = read();
            sumd[i] = sumd[i - 1] + d[i];
        }
        REP(i, 1, m) {
            REP(j, 1, n) {
                a[i][j] = read();
            }
        }
        if (n <= 200 && m <= 500) {
            REP(j, 1, n) {
                REP(l, 1, m) {
                    ll mxa = 0;
                    REP(r, l, m) {
                        MAX(mxa, a[r][j]);
                        dp[l][r] += mxa;
                    }
                }
            }
            REP(l, 1, m) {
                REP(r, l, m) {
                    MAX(ans, dp[l][r] - sumd[r] + sumd[l]);
                }
            }
            cout << ans << '\n';
        } else {
            REP(j, 1, n) {
                ll res = 0;
                REP(i, 1, m) MAX(res, a[i][j]);
                ans += res;
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    freopen("calorie.in", "r", stdin);
    freopen("calorie.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
