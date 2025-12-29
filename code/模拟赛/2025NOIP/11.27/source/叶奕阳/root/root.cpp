#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=c)
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

    int n, m, ans;

    void main() {
        ans = 0;
        cin >> n >> m;
        if (m / n <= 20) {
            REPc(res, 1, m + (n - 1), n) {
                int i = res ^ (n - 1);
                if (0 <= i && i <= m) ans++;
            }
        } else {
            int mn = 1, mx = ((m + (n - 1) - 1) / n) * n + 1;
            REP(k, 1, 5) {
                int i = mn ^ (n - 1);
                if (0 <= i && i <= m) ans++;
                mn += n;
            }
            REP(k, 1, 5) {
                int i = mx ^ (n - 1);
                if (0 <= i && i <= m) ans++;
                mx -= n;
            }
            ans += (mx - mn) / n + 1;
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("root.in", "r", stdin);
    freopen("root.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
