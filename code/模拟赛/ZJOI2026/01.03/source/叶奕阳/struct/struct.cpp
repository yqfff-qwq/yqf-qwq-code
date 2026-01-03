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

namespace Yyydrasil {

    const int N = 1e6 + 5, M = 1e6 + 5;
    struct Q { int l, r, id; } q[N];
    int n, m, B, a[N], ans[N];

    bool cmp(Q a, Q b) {
        int al = a.l / B, bl = b.l / B;
        if (al != bl) return al < bl;
        else          return (al % 2 == 0 ? a.r < b.r : a.r > b.r);
    }

    int cnt[N], sum;
    #define add1(x) (cnt[(x) + 1]++), (--cnt[(x)])
    #define del1(x) (cnt[(x)]++), (--cnt[(x) + 1])
    #define add2(x) sum += (!(cnt[(x) + 1]++)), sum -= (!(--cnt[(x)]))
    #define del2(x) sum += (!(cnt[(x)]++)), sum -= (!(--cnt[(x) + 1]))

    void main() {
        cin >> n >> m; B = sqrt(n);
        REP(i, 1, n) cin >> a[i], sum += (!cnt[a[i]]), cnt[a[i]]++;
        REP(i, 1, m) cin >> q[i].l >> q[i].r, q[i].id = i;
        sort(q + 1, q + 1 + m, cmp);
        int l = 1, r = 0;
        REP(i, 1, m) {
            while (l > q[i].l) l--, add2(a[l]);
            while (r < q[i].r) r++, add2(a[r]);
            while (l < q[i].l) del2(a[l]), l++;
            while (r > q[i].r) del2(a[r]), r--;
            ans[q[i].id] = sum;
        }
        REP(i, 1, m) cout << ans[i] << '\n';
    }
}

signed main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
