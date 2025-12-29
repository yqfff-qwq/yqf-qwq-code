#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=c)
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define MOD(a)   ((a)%mod+mod)%mod
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=MOD((a)-(b))
#define MUL(a,b) (a)=MOD((a)*(b))
#define SZ(a)    ((int)(a).size())
#define ALL(a)   (a).begin(),(a).end()
#define ppc(a)   __builtin_popcountll(a)
#define ctz(a)   __builtin_ctz(a)
#define DBG(a)     cerr<<#a<<": "<<a<<endl
#define AST(a,l,r) assert(a>=l),assert(a<=r)
#define int long long
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int N = 2e5 + 5;
    const int mod = 998244353;
    int n, k, a[N];

    void main() {
        cin >> n >> k;
        REP(i, 1, n) cin >> a[i];
        cout << ((k / __gcd(__gcd(a[1], a[2]), k)) + 1) % mod << '\n';
    }
}

signed main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
