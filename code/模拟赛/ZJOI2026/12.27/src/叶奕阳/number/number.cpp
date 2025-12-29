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

    int n, m, a[10], tot, d[20], pw[20], ans;
    bool flag[10];

    void main() {
        ans = tot = 0;
        cin >> n >> m;
        REP(i, 0, 9) flag[i] = true;
        REP(i, 1, m) {
            cin >> a[i];
            flag[a[i]] = false;
        }
        if (n == 0) {
            cout << flag[0] << '\n';
        } else {
            while (tot == 0 || n) d[++tot] = n % 10, n /= 10;
            pw[0] = 1; REP(i, 1, tot) pw[i] = pw[i - 1] * (10 - m);
            REP(i, 1, tot - 1) ans += (10 - m - (flag[0])) * pw[i - 1];
            DEP(i, tot, 1) {
                int cnt = 0;
                REP(j, (i == tot), d[i] - 1) cnt += flag[j];
                ans += cnt * pw[i - 1];
                if (!flag[d[i]]) break;
                if (i == 1) ans += flag[d[i]];
            }
            cout << ans + flag[0] << '\n';
        }
    }
}

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
