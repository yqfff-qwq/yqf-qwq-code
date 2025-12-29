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

    const int N = 3e6 + 5;
    int b, a, n, s[N], nobrok;
    char ch;

    void main() {
        nobrok = true;
        cin >> b >> a >> n;
        REP(i, 1, n) {
            cin >> ch;
            s[i] = ch - '0';
            nobrok &= (s[i] == 1);
        }
        s[n + 1] = 1;
        if (nobrok) {
            int len = a - b;
            int sum = (n - a + (len - 1)) / len;
            cout << len << ' ' << sum << '\n';
            cout << sum + (sum + 1) * b << '\n';
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
}

signed main() {
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
