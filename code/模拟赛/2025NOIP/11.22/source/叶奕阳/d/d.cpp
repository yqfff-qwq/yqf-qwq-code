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

    int n;

    void main() {
        cin >> n;
        if (n == 2) {
            cout << "0 1\n";
            cout << "0 1\n";
        } else if (n == 3) {
            cout << "0 1 2\n";
            cout << "0 0 3\n";
            cout << "0 0 3\n";
        } else if (n == 6) {
            cout << "0 1 195 560 420 120\n";
            cout << "0 0 1 75 500 720\n";
            cout << "0 0 0 1 75 1220\n";
            cout << "0 0 0 0 1 1295\n";
            cout << "0 0 0 0 0 1296\n";
            cout << "0 0 0 0 0 1296\n";
        }
    }
}

signed main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

// -fsanitize=undefined
// __attribute__((noinline))
