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

    const int mod = 998244353;
    const int N = 1e5 + 5, M = 1e5 + 5;
    int n, m, a[N], s[M], ans[M], anssum;

    int pow(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) MUL(res, a);
            MUL(a, a);
            b >>= 1;
        } return res;
    }

    void main() {
        cin >> n >> m;
        REP(i, 1, n) {
            cin >> a[i];
            REP(j, 1, a[i]) {
                if (j * j > a[i]) break;
                if (a[i] % j == 0) {
                    int s1 = j;
                    int s2 = a[i] / j;
                    s[s1]++;
                    if (s2 != s1) s[s2]++;
                }
            }
        }
        DEP(i, m, 1) {
            ans[i] = (pow(2, s[i]) - 1 + mod) % mod;
            REPc(j, i * 2, m, i) SUB(ans[i], ans[j]);
            ADD(anssum, i * ans[i] % mod);
        }
        cout << anssum << '\n';
    }
}

signed main() {
    freopen("bead.in", "r", stdin);
    freopen("bead.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
