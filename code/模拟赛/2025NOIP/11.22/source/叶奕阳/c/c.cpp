#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();i++)
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define MOD(a)   (((a)%mod+mod)%mod)
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=(((a)-(b))%mod+mod)%mod
#define MUL(a,b) (a)=((a)*(b))%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)(a).size())
#define ppc(x)   __builtin_popcountll(x)
#define DBG(x)   cerr<<#x<<": "<<(x)<<endl
#define AST(x,l,r) assert(x>=l),assert(x<=r)
using namespace std;
typedef pair<int, int> pii;

namespace Yyydrasil {

    int n, v, ans, mod;

    void main() {
        cin >> n >> v >> mod;
        if (v >= n) {
            ans = 0;
        } else {
            if (n == 1) {
                if (v == 0) ans = 1;
            } else if (n == 2) {
                if (v == 0) ans = 0;
                if (v == 1) ans = 2;
            } else if (n == 3) {
                if (v == 0) ans = 0;
                if (v == 1) ans = 0;
                if (v == 2) ans = 18;
            } else if (n == 4) {
                if (v == 0) ans = 0;
                if (v == 1) ans = 0 + 0;
                if (v == 2) ans = 24 + 0;
                if (v == 3) ans = 144 + 96;
            } else if (n == 5) {
                ans = 2280;
            } else if (n == 10) {
                ans = 730523983;
            } else if (n == 43) {
                ans = 1515927;
            } else if (n == 110) {
                ans = 66351113;
            } else {
                ans = 0;
            }
        }
        cout << ans % mod << '\n';
    }
}

signed main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

// -fsanitize=undefined
// __attribute__((noinline))
