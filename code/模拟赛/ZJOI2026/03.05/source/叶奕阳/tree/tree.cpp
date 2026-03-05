#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=c)
#define MIN(a,b) ((a)=min((a),(b)))
#define MAX(a,b) ((a)=max((a),(b)))
#define ADD(a,b) ((a)=((a)+(b))%mod)
#define MUL(a,b) ((a)=((a)*(b))%mod)
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    (a).size()
#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

namespace Yyydrasil {

    const int mxN = 1e4 + 5, mxK = 1e4 + 5;
    int n, k, t, genc[mxN], c[mxN], v[mxN], ans;
    int fa[mxN];

    vector<int> sons[mxN];
    int sz[mxN], p[mxN], tot;
    void dfs(int u) {
        sz[u] = 1, p[++tot] = u;
        for (auto v : sons[u]) dfs(v), sz[u] += sz[v];
    }
    int dp[mxN][mxK];
    int solve(int q) {
        REP(i, 0, n + 1) REP(j, 0, k) dp[i][j] = 0;
        tot = 0, dfs(1);
        REP(i, 1, n) {
            int u = p[i];
            REP(j, 0, k) MAX(dp[i + sz[p[i]]][j], dp[i][j]);
            REP(s, 1, min(k, c[u])) {
                int w = s * v[u];
                REP(j, 0, k - s) MAX(dp[i + 1][j + s], dp[i][j] + w);
            }
        }
        return dp[n + 1][k];
    }

    void main() {
        cin >> n >> k >> t;
        REP(i, 1, n) cin >> c[i] >> v[i], genc[i] = c[i];
        REP(i, 2, n) cin >> fa[i], sons[fa[i]].pb(i);
        if (n <= 10 && k <= 10 && t <= 10) {
            REP(p, 0, (1 << n) - 1) {
                if (__builtin_popcount(p) == t) {
                    int res = 0;
                    REP(i, 1, n) {
                        if ((p >> (i - 1)) & 1) {
                            int u = i;
                            while (u != 0) c[u]--, res += v[u], u = fa[u];
                        }
                    }
                    MAX(ans, res + solve(p));
                    REP(i, 1, n) c[i] = genc[i];
                }
            }
            cout << ans << '\n';
        } else {
            cout << solve(0) << '\n';
        }
    }
}

signed main() {
    freopen("tree.in", "r", stdin) ? void() : void();
    freopen("tree.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
