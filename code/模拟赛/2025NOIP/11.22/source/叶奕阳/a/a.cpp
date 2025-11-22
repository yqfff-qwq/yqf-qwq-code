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
#define int long long
using namespace std;

namespace Yyydrasil {

    const int mod = 998244353;
    int n, d[15], tot, ans;

    void main() {
        tot = ans = 0;
        cin >> n; n--;
        while (n || !tot) d[++tot] = n % 7, n /= 7;
        DEP(i, tot, 1) {
            int s = 0;
            if (d[i] == 0) s = 0;
            if (d[i] == 1) s = 2;
            if (d[i] == 2) s = 3;
            if (d[i] == 3) s = 6;
            if (d[i] == 4) s = 7;
            if (d[i] == 5) s = 8;
            if (d[i] == 6) s = 9;
            ans = (ans * 10 + s) % mod;
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

// -fsanitize=undefined
// __attribute__((noinline))
