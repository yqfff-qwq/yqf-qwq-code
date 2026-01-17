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

    const int N = 5e5 + 5;
    int n, x[N], y[N], z[N], a[N];

    bool check(int k) {
        REP(i, 1, n) a[i] = i;
        do {
            int sx = -1e9, sy = -1e9, sz = -1e9, flag = true;
            REP(i, 1, n) {
                int l = 0, r = 0;
                l = x[a[i]] - k;
                r = x[a[i]] + k;
                if (sx > r) { flag = false; break; }
                if (sx < l) sx = l;
                l = y[a[i]] - k;
                r = y[a[i]] + k;
                if (sy > r) { flag = false; break; }
                if (sy < l) sy = l;
                l = z[a[i]] - k;
                r = z[a[i]] + k;
                if (sz > r) { flag = false; break; }
                if (sz < l) sz = l;
            }
            if (flag) return true;
        } while (next_permutation(a + 1, a + 1 + n));
        return false;
    }

    void main() {
        cin >> n;
        REP(i, 1, n) cin >> x[i] >> y[i] >> z[i];
        int l = 0, r = 1e9;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid - 1;
            else            l = mid + 1;
        }
        cout << r + 1 << '\n';
    }
}

signed main() {
    freopen("hunt.in", "r", stdin);
    freopen("hunt.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
