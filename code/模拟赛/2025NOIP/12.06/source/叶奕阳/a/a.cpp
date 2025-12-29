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

    const int inf = 0x3f3f3f3f3f3f3f3f;
    const int N = 1e3 + 5;
    int n, a[N], ans;
    multiset<int> s2;

    void main() {
        ans = inf;
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        DEP(r1, n - 1, 1) {
            int sum2 = 0;
            REP(r2, r1 + 1, n) {
                sum2 += a[r2];
                s2.insert(sum2);
            }
            int sum1 = 0;
            DEP(l1, r1, 1) {
                sum1 += a[l1];
                auto it = s2.insert(sum1);
                if (it != begin(s2))     MIN(ans, sum1 - *prev(it));
                if (next(it) != end(s2)) MIN(ans, *next(it) - sum1);
                s2.erase(it);
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
