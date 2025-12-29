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
    const int N = 2e5 + 5;
    int n, k, m, a[N], op, p, v, ans;
    int sumall[N], suma;

    int cnt[N], sum1;
    void add(int x) { sum1 += (cnt[x] == 0); cnt[x]++; }
    void sub(int x) { cnt[x]--, sum1 -= (cnt[x] == 0); }

    void main() {
        cin >> n >> k >> m;
        REP(i, 1, n) cin >> a[i], suma += (sumall[a[i]] == 0), sumall[a[i]]++;
        REP(t, 1, m) {
            cin >> op;
            if (op == 1) {
                cin >> p >> v;
                sumall[a[p]]--;
                suma -= (sumall[a[p]] == 0);
                a[p] = v;
                suma += (sumall[a[p]] == 0);
                sumall[a[p]]++;
            } else {
                if (suma != k) {
                    cout << -1 << '\n';
                } else {
                    REP(x, 1, k) cnt[x] = 0; sum1 = 0;
                    ans = inf;
                    int r = 0;
                    REP(l, 1, n) {
                        sub(a[l - 1]);
                        while (r < n && sum1 != k) add(a[++r]);
                        if (sum1 == k) MIN(ans, r - l + 1);
                    }
                    if (ans == inf) cout << -1 << '\n';
                    else            cout << ans << '\n';
                }
            }
        }
    }
}

signed main() {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
