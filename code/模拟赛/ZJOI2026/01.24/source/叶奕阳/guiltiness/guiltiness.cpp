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

    const int mxN = 2e5 + 5, mxM = 2e5 + 5;
    struct Cut { int s, id; } a[mxN + mxM];
    int n, m, x, tot;
    ll ans;

    void main() {
        cin >> n >> m;
        REP(i, 1, n - 1) cin >> x, a[++tot] = {x, 0};
        REP(i, 1, m - 1) cin >> x, a[++tot] = {x, 1};
        sort(a + 1, a + 1 + tot, [](Cut a, Cut b) { return a.s > b.s; });
        int sx = 0, sy = 0;
        REP(i, 1, tot) {
            if (a[i].id == 0) ans += 1ll * a[i].s * (sy + 1), sx++;
            if (a[i].id == 1) ans += 1ll * a[i].s * (sx + 1), sy++;
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("guiltiness.in", "r", stdin);
    freopen("guiltiness.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
