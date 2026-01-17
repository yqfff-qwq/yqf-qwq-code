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

    const int N = 22 + 5;
    int n, m, a, x, b, y;
    vector<pii> s[N][3];

    int fa[N];
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    map<int, vector<int>> node;

    int c[N], tot;
    int vis[N][3];

    ll dfs(int step) {
        if (step == tot + 1) return 1;
        ll res = 0; int u = c[step];
        REP(col, 0, 2) {
            if (vis[u][col] == 0) {
                for (auto i : s[u][col]) vis[i.fi][i.se]++;
                res += dfs(step + 1);
                for (auto i : s[u][col]) vis[i.fi][i.se]--;
            }
        }
        return res;
    }
    ll ans;

    void main() {
        ans = 1;
        cin >> n >> m;
        REP(i, 1, m) {
            cin >> a >> x >> b >> y;
            s[a][x].pb({b, y});
            s[b][x].pb({a, y});
            fa[find(a)] = find(b);
        }
        REP(i, 1, n) node[find(i)].pb(i);
        for (auto nd : node) {
            tot = 0;
            for (auto j : nd.se) c[++tot] = j;
            REP(i, 1, tot) vis[c[i]][0] = vis[c[i]][1] = vis[c[i]][2] = 0;
            ans = ans * dfs(1);
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
