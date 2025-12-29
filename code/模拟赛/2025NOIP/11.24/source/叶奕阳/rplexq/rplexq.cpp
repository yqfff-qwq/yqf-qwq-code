#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i<=(a).end();i++)
#define REP(i,a,b)    for(auto i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(auto i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(auto i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(auto i=(a);i>=(b);i-=c)
#define MAX(a,b)  (a)=max((a),(b))
#define MIN(a,b)  (a)=min((a),(b))
#define ADD(a,b)  (a)=((a)+(b))%mod
#define SUB(a,b)  (a)=(((a)-(b))%mod+mod)%mod
#define MUL(a,b)  (a)=(((a)*(b))%mod+mod)%mod
#define SZ(a)     ((int)(a).size())
#define ALL(a)    (a).begin(),(a).end()
#define ppc(x)    __builtin_popcountll(x)
#define ctz(x)    __builtin_ctz(x)
#define DBG(x)     cerr<<#x<<": "<<x<<endl
#define AST(x,l,r) assert(x>=l),assert(x<=r)
using namespace std;

namespace Yyydrasil {

    const int N = 1e5 + 5;
    int n, m, rt, u, v, l, r, x, ans;
    vector<int> edge[N];

    int fa[N], sz[N];
    void dfs(int u, int f) {
        fa[u] = f, sz[u] = 1;
        for (auto v : edge[u]) {
            if (v != fa[u]) {
                dfs(v, u);
                sz[u] += sz[v];
            }
        }
    }

    int sum[N], tot;
    int calc(int u, int l, int r) {
        int res = 0;
        if (l <= u && u <= r) res = 1;
        for (auto v : edge[u]) {
            if (v != fa[u]) {
                res += calc(v, l, r);
            }
        }
        return res;
    }

    void main() {
        cin >> n >> m >> rt;
        REP(i, 1, n - 1) {
            cin >> u >> v;
            edge[u].pb(v);
            edge[v].pb(u);
        }
        dfs(rt, rt);
        REP(i, 1, m) {
            cin >> l >> r >> x;
            ans = tot = 0;
            for (auto v : edge[x]) {
                if (v != fa[x]) {
                    sum[++tot] = calc(v, l, r);
                    ans += sum[tot] * sum[tot - 1];
                    sum[tot] += sum[tot - 1];
                }
            }
            cout << ans + calc(u, l, r) << '\n';
        }
    }
}

signed main() {
    freopen("rplexq.in", "r", stdin);
    freopen("rplexq.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}