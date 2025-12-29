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

    const int N = 500 + 5, S = (500 + 5) * (1000 + 5);
    int m, x, y, n, a[N], sum[N], ans;
    bool dp[2][S];

    void main() {
        cin >> m;
        REP(i, 1, m) {
            cin >> x >> y;
            MAX(n, x);
            MAX(a[x], y);
        }
        sum[n + 1] = 0;
        DEP(i, n, 1) sum[i] = sum[i + 1] + (i == n ? a[i] : a[i] * 2) + 1;
        dp[0][0] = true;
        ans = sum[1];
        int presum = 0;
        REP(i, 0, n - 1) {
            int u = i % 2, v = (i + 1) % 2;
            REP(s, 0, i * 1000) dp[v][s] = false;
            REP(s, 0, i * 1000) {
                if (dp[u][s]) {
                    dp[v][abs(s - a[i + 1] * 2)] = true;
                    dp[v][s + a[i + 1] * 2] = true;
                    int s1 = (presum - s) / 2, t1 = 0;
                    int s2 = (presum + s) / 2, t2 = 0;
                    t1 = s1 + (a[i + 1] == 0 ? 0 : 1 + a[i + 1]);
                    t2 = s2 + (i + 1 == n ? 0 : 1 + sum[i + 2]);
                    MIN(ans, max(t1, t2));
                    swap(s1, s2);
                    t1 = s1 + (a[i + 1] == 0 ? 0 : 1 + a[i + 1]);
                    t2 = s2 + (i + 1 == n ? 0 : 1 + sum[i + 2]);
                    MIN(ans, max(t1, t2));
                }
            }
            presum += (a[i + 1] * 2 + 2);
        }
        cout << ans << '\n';
        REP(i, 1, n) a[i] = 0;
        REP(i, 1, n) sum[i] = 0;
        REP(s, 0, n * 1000) dp[0][s] = dp[1][s] = 0;
        n = 0, ans = 0;
    }
}

signed main() {
    freopen("couple.in", "r", stdin);
    freopen("couple.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}