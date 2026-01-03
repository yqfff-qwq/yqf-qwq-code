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

    const int N = 100 + 5;
    int n, p[N], a[N];

    vector<int> loop[N];
    bool vis[N];
    int tot;

    void main() {
        cin >> n;
        REP(i, 1, n) cin >> p[i];
        REP(i, 1, n) {
            if (!vis[i]) {
                int u = i; tot++;
                while (u != i || loop[tot].empty()) {
                    loop[tot].pb(u);
                    vis[u] = true;
                    u = p[u];
                }
            }
        }
        REP(p, 0, (1 << tot) - 1) {
            REP(i, 1, tot) {
                int cnt = 0, k = ((p >> (i - 1)) & 1);
                for (auto j : loop[i]) {
                    if (cnt % 2 == k) a[j] = 1;
                    else              a[j] = -1;
                    cnt++;
                }
            }
            int sum = 0, mn = 0;
            REP(i, 1, n) {
                sum += a[i];
                MIN(mn, sum);
            }
            if (sum == 0 && mn == 0) {
                REP(i, 1, n) {
                    if (a[i] == 1) cout << '(';
                    else           cout << ')';
                }
                cout << '\n';
                return;
            }
        }
    }
}

signed main() {
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
