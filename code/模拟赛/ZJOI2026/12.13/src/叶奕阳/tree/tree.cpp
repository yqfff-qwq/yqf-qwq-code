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
    int n, mod, a[N], u, v, ans;
    
    int pow(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) MUL(res, a);
            MUL(a, a);
            b >>= 1;
        } return res;
    }

    void main() {
        cin >> n >> mod;
        REP(i, 1, n) cin >> a[i];
        ans = a[1];
        REP(i, 2, n) MUL(ans, a[i] + 1);
        REP(i, 1, n) ADD(ans, a[i] * pow(2, n - 2));
        cout << 0 << '\n';
    }
}

signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
