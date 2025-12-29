#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();i++)
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define MOD(a)   (((a)%mod+mod)%mod)
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=(((a)-(b))%mod+mod)%mod
#define MUL(a,b) (a)=((a)*(b))%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)(a).size())
#define ppc(x)   __builtin_popcountll(x)
#define DBG(x)   cerr<<#x<<": "<<(x)<<endl
#define AST(x,l,r) assert(x>=l),assert(x<=r)
using namespace std;
typedef pair<int, int> pii;

namespace Yyydrasil {

    const int mod = 998244353;
    const int N = 3e3 + 5, M = 1e6 + 5, Y = 3e3 + 5;
    int n, m, k, s1, s2, u, v, a[N], op, x, y;
    int e[N][N];

    int deg[N], vis[N], tot;
    priority_queue<pii, vector<pii>, greater<pii>> q;

    unordered_multiset<int> S[N];
    int dp[N][Y];
    inline void add(int i, int x) {
        if (deg[i] <= 7) S[i].insert(x);
        else DEP(j, 3e3, x) dp[i][j] = (dp[i][j] + dp[i][j - x]) % mod;
    }
    inline void del(int i, int x) {
        if (deg[i] <= 7) S[i].erase(S[i].find(x));
        else REP(j, x, 3e3) dp[i][j] = (dp[i][j] - dp[i][j - x] + mod) % mod;
    }

    void main() {
        cin >> n >> m >> k >> s1 >> s2;
        REP(i, 1, m) {
            cin >> u >> v;
            e[u][v] = e[v][u] = 1;
            deg[u]++, deg[v]++;
        }
        REP(i, 1, n) q.push({deg[i], i});
        while (!q.empty() && q.top().fi <= k) {
            int dg = q.top().fi, u = q.top().se; q.pop();
            if (vis[u] || dg != deg[u]) continue;
            vis[u] = true, deg[u] = 0;
            REP(v, 1, n) {
                if (e[u][v] && !vis[v]) {
                    deg[v]--;
                    q.push({deg[v], v});
                }
            }
        }
        REP(i, 1, n) tot += (!vis[i]);
        if (tot != 0) {
            REP(i, 1, n) {
                if (!vis[i]) cout << i << ' ';
            }
        } else {
            REP(u, 1, n) REP(v, u, n) if (e[u][v]) deg[u]++, deg[v]++;
            REP(i, 1, n) cin >> a[i], dp[i][0] = 1;
            REP(u, 1, n) {
                REP(v, 1, n) {
                    if (e[u][v]) add(u, a[v]);
                }
            }
            REP(i, 1, s1 + s2) {
                cin >> op >> x >> y;
                if (op == 1) {
                    REP(v, 1, n) {
                        if (e[x][v]) {
                            del(v, a[x]);
                            add(v, y);
                        }
                    }
                    a[x] = y;
                } else {
                    if (deg[x] <= 7) {
                        int s[8], m = 0, ans = 0;
                        for (auto i : S[x]) s[++m] = i;
                        REP(p, 0, (1 << deg[x]) - 1) {
                            int cnt = 0;
                            REP(i, 1, deg[x]) {
                                if ((p >> (i - 1)) & 1) {
                                    cnt += s[i];
                                }
                            }
                            if (cnt == y) ans++;
                        }
                        cout << ans << '\n';
                    } else {
                        cout << dp[x][y] << '\n';
                    }
                }
            }
        }
    }
}

signed main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

// -fsanitize=undefined
// __attribute__((noinline))
