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
    int n, a[mxN], ans;
    int x[3];

    bool dfs() {
        if (max({x[0], x[1], x[2]}) - min({x[0], x[1], x[2]}) <= 1) {
            return false;
        } else {
            int res = false;
            REP(i, 0, 2) {
                REP(j, i + 1, 2) {
                    REP(k, -5, 5) {
                        int s1 = x[i], s2 = x[j];
                        int t1 = x[i] - k, t2 = x[j] + k;
                        if (abs(s1 - s2) > abs(t1 - t2)) {
                            x[i] = t1, x[j] = t2;
                            res |= (!dfs());
                            x[i] = s1, x[j] = s2;
                        }
                    }
                }
            }
            return res;
        }
    }

    void main() {
        ans = 0;
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        REP(p, 0, (1 << n) - 1) {
            if (ppc(p) == 3) {
                x[0] = x[1] = x[2] = -1;
                REP(i, 1, n) {
                    if ((p >> (i - 1)) & 1) {
                             if (x[0] == -1) x[0] = a[i];
                        else if (x[1] == -1) x[1] = a[i];
                        else if (x[2] == -1) x[2] = a[i];
                    }
                }
                ans += dfs();
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
