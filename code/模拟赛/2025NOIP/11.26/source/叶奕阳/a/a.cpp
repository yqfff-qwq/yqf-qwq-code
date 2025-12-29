#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i<=(a).end();i++)
#define REP(i,a,b)    for(auto i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(auto i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(auto i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(auto i=(a);i>=(b);i-=c)
#define MAX(a,b)  (a)=max((a),(b))
#define MIN(a,b)  (a)=min((a),(b))
#define ADD(a,b)  (a)=((a)+(b))%mod
#define SUB(a,b)  (a)=(((a)-(b))%mod+mod)%mod
#define MUL(a,b)  (a)=(((a)*(b))%mod+mod)%mod
#define SZ(a)     ((int)(a).size())
#define ALL(a)    (a).begin(),(a).end()
#define ppc(x)    __builtin_popcountll(x)
#define ctz(x)    __builtin_ctz(x)
#define DBG(x)     cerr<<#x<<": "<<x<<endl
#define AST(x,l,r) assert(x>=l),assert(x<=r)
using namespace std;

namespace Yyydrasil {

    const int N = 2e5 + 5;
    char s[N];
    int n;

    void main() {
        cin >> (s + 1);
        n = strlen(s + 1);
        REP(i, 1, n) {
            if (s[i] != s[i + 1]) {
                cout << i << '\n';
                break;
            }
        }
    }
}

signed main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
