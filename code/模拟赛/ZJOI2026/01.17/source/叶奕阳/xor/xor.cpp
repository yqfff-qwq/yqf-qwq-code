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

    const int N = 1e5 + 5, V = (1 << 18);
    int n, m, a[N], sum[V];
    ll ans;
    mt19937 rnd(641953);

    void main() {
        cin >> n >> m;
        REP(i, 1, n) cin >> a[i];
        shuffle(a + 1, a + 1 + n, rnd);
        if (n <= 1e4) {
            REP(k, 3, n - 1) {
                int j = k - 1;
                REP(i, 1, j - 1) sum[a[i] ^ a[j]]++;
                REP(l, k + 1, n) ans += sum[a[k] ^ a[l]];
            }
            cout << min(ans, 1ll * m) << '\n';
        } else {
            cout << m << '\n';
        }
    }
}

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
