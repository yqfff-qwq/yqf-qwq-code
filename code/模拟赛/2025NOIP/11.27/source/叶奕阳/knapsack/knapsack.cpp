#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define REP(i,a,b)    for(auto i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(auto i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(auto i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(auto i=(a);i>=(b);i-=c)
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define MOD(a)   ((a)%mod+mod)%mod
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=MOD((a)-(b))
#define MUL(a,b) (a)=MOD((a)*(b))
#define SZ(a)    ((int)(a).size())
#define ALL(a)   (a).begin(),(a).end()
#define ppc(a)   __builtin_popcountll(a)
#define ctz(a)   __builtin_ctz(a)
#define DBG(a)     cerr<<#a<<": "<<a<<endl
#define AST(a,l,r) assert(a>=l),assert(a<=r)
#define int long long
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int inf = 0x3f3f3f3f3f3f3f3f;
    const int N = 5e5 + 5;
    struct D { int v, m; } a[N];
    vector<int> v[N];
    int m[N], tot, ans;
    int n, M;

    void main() {
        cin >> n >> M;
        REP(i, 1, n) {
            cin >> a[i].v >> a[i].m;
        }
        sort(a + 1, a + 1 + n, [](D a, D b){ return a.m != b.m ? a.m < b.m : a.v > b.v; });
        REP(i, 1, n) {
            if (a[i].m != a[i - 1].m) m[++tot] = a[i].m;
            v[tot].pb(a[i].v);
        }
        n = tot;
        m[n + 1] = inf;
        REP(i, 1, n) {
            int cnt = 0, tot = 0;
            while (SZ(v[i - 1])) {
                tot++, cnt += v[i - 1].back();
                v[i - 1].pop_back();
                if (tot % (m[i] / m[i - 1]) == 0 || SZ(v[i - 1]) == 0) {
                    v[i].pb(cnt);
                    cnt = tot = 0;
                }
            }
            sort(ALL(v[i]));
            int k = (M % m[i + 1]) / m[i];
            while (k-- && SZ(v[i])) {
                ans += v[i].back();
                v[i].pop_back();
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
