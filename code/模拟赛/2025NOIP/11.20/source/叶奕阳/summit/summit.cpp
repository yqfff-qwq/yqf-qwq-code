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

    const int N = 400 + 5;
    int n, l, r, a[N], b[N];
    int dp[N][N][N], ans;

    void main() {
        cin >> n >> l >> r;
        REP(i, 1, n) cin >> a[i];
        REP(i, 1, n) cin >> b[i];
        REP(i, 0, n) REP(sa, 0, n) REP(sb, 0, n) dp[i][sa][sb] = 0x3f3f3f3f3f3f3f3f;
        dp[0][0][0] = 0;
        REP(i, 1, n) {
            REP(sa, 0, i) {
                REP(sb, 0, sa) {
                    MIN(dp[i][sa][sb], dp[i - 1][sa][sb]);
                    if (sa != 0) MIN(dp[i][sa][sb], dp[i - 1][sa - 1][sb] + a[i]);
                    if (sb != 0) MIN(dp[i][sa][sb], dp[i - 1][sa][sb - 1] + b[i]);
                    if (sa != 0 && sb != 0) MIN(dp[i][sa][sb], dp[i - 1][sa - 1][sb - 1] + a[i] + b[i]);
                }
            }
        }
        REP(i, l, r) cout << dp[n][i][i] << '\n';
    }
}

signed main() {
    freopen("summit.in", "r", stdin);
    freopen("summit.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
