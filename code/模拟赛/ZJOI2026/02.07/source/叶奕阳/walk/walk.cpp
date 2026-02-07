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

    const int mxN = 5e5 + 5;
    int n, f, w[mxN], a[mxN];
    vector<int> edge[mxN];

    ll dp[mxN], sz[mxN], sum[mxN];
    void dfs(int u) {
        sz[u] = w[u], sum[u] = a[u];
        for (auto v : edge[u]) dfs(v), sz[u] += sz[v], sum[u] += sum[v];
        sort(ALL(edge[u]), [](int a, int b) { return 1ll * sz[a] * sum[b] < 1ll * sz[b] * sum[a]; });
        ll t = w[u]; dp[u] = t * a[u];
        for (auto v : edge[u]) {
            dp[u] += 1ll * t * sum[v] + dp[v];
            t += sz[v];
        }
    }

    void main() {
        cin >> n;
        REP(i, 2, n) cin >> f >> w[i], edge[f].pb(i);
        REP(i, 1, n) cin >> a[i];
        dfs(1);
        cout << dp[1] << '\n';
    }
}

signed main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
