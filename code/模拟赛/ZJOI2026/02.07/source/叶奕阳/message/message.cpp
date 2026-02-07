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

    const int mod = 1e9 + 7;
    const int mxM = 200 + 5;
    int n, m, s[mxM], s2[mxM];

    int qpow(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * res * a % mod;
            a = 1ll * a * a % mod;
            b >>= 1;
        } return res;
    }

    int C(int a, int b) {
        int res = 1;
        DEP(i, a, a - b + 1) res = 1ll * res * i % mod;
        REP(i, 1, b)         res = 1ll * res * qpow(i, mod - 2) % mod;
        return res;
    }

    void main() {
        cin >> n >> m;
        REP(i, 1, m) cin >> s[i];
        REP(i, 1, m) s2[i] = s[i];
        sort(s2 + 1, s2 + 1 + m);
        bool alldiff = true;
        REP(i, 1, m - 1) alldiff &= (s2[i] != s2[i + 1]);
        if (alldiff) {
            cout << qpow(m, n) << '\n';
        } else if (s2[1] == s2[m]) {
            cout << C(n - 1 + m, m) << '\n';
        }
    }
}

signed main() {
    freopen("message.in", "r", stdin);
    freopen("message.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
