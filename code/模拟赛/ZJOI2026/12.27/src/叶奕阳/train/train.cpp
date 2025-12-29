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

    const int N = 5e5 + 5;
    int n, ans[N], lo[N], ro[N];
    int idro[N], totidro;
    int idlo[N], totidlo;
    int sumro[N], totsumro;
    int sumlo[N], totsumlo;
    char a[N];

    void solve(bool rev) {
        totidro = totidlo = totsumro = totsumlo = 0;
        // cout << "[### SOLVE ###]\n";
        REP(i, 1, n) lo[i] = (a[i] == 'O' ? i : lo[i - 1]);
        DEP(i, n, 1) ro[i] = (a[i] == 'O' ? i : ro[i + 1]);
        REP(i, 1, n) idro[i] = (totidro += (a[i] != 'L'));
        DEP(i, n, 1) idlo[i] = (totidlo += (a[i] != 'R'));
        REP(i, 1, n) if (a[i] != 'L') sumro[totsumro + 1] = sumro[totsumro] + i, totsumro++;
        DEP(i, n, 1) if (a[i] != 'R') sumlo[totsumlo + 1] = sumlo[totsumlo] + i, totsumlo++;
        // REP(i, 1, n) cout << lo[i] << ' '; cout << '\n';
        // REP(i, 1, n) cout << ro[i] << ' '; cout << '\n';
        // REP(i, 1, n) cout << idlo[i] << ' '; cout << '\n';
        // REP(i, 1, n) cout << idro[i] << ' '; cout << '\n';
        // REP(i, 1, n) cout << sumlo[i] << ' '; cout << '\n';
        // REP(i, 1, n) cout << sumro[i] << ' '; cout << '\n';
        REP(i, 1, n) {
            int p = (!rev ? i : n - i + 1);
            if (a[i] == 'O') ans[p] = 0;
            else if (a[i] == 'L') {
                // cout << "calc #" << i << '\n';
                int ls = idro[i - 1] - idro[lo[i]] + 1;
                int rs = idlo[i + 1] - idlo[ro[i]] + 1;
                if (ls <= rs) {
                    // cout << "GO TO LEFT:\n";
                    rs = ls - 1;
                    int pl = idro[i - 1];
                    int pr = idlo[i + 1];
                    int l = pl - ls + 1;
                    int r = pr - rs + 1;
                    // cout << l << ' ' << pl << ' ' << pr << ' ' << r << '\n';
                    ans[p] = i + 2 * (sumlo[pr] - sumlo[r - 1]) - 2 * (sumro[pl] - sumro[l]) - lo[i];
                    // cout << "res: " << ans[p] << '\n';
                } else {
                    // cout << "GO TO RIGHT:\n";
                    ls = rs;
                    int pl = idro[i - 1];
                    int pr = idlo[i + 1];
                    int l = pl - ls + 1;
                    int r = pr - rs + 1;
                    // cout << l << ' ' << pl << ' ' << pr << ' ' << r << '\n';
                    ans[p] = i + 2 * (sumlo[pr] - sumlo[r]) + ro[i] - 2 * (sumro[pl] - sumro[l - 1]);
                    // cout << "res: " << ans[p] << '\n';
                }
            }
        }
    }

    void main() {
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        solve(0);
        reverse(a + 1, a + 1 + n);
        REP(i, 1, n) if (a[i] != 'O') a[i] = a[i] ^ 'L' ^ 'R';
        solve(1);
        REP(i, 1, n) cout << ans[i] << ' ';
        cout << '\n';
    }
}

signed main() {
    freopen("train.in", "r", stdin);
    freopen("train.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
