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

    int vis[4005], tot, fac[4005];
    int n, S, ans;

    const int mod = 30000001;
    int hash(unsigned int x) {
        x ^= (x << 11);
        x ^= (x >> 7);
        x ^= (x << 13);
        return x & ((1 << 20) - 1);
    }
    vector<int> t[mod];
    void init() {
        REP(i, 1, 1e6) {
            t[hash(i * i * i)].pb(i * i * i);
        }
    }

    bool check3(int x) {
        int y = hash(x);
        for (auto i : t[y]) {
            if (i == x) return true;
        }
        return false;
    }

    bool check2(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    void main() {
        cin >> n;
        ans = tot = 0, S = pow(n, 0.2) + 5;
        REP(x1, 1, S) {
            if (n % (x1 * x1) == 0) {
                fac[++tot] = x1;
                int s2 = n / (x1 * x1);
                if (check3(s2)) {
                    cout << "yes\n";
                    return;
                }
            }
        }
        REP(i, 1, tot) {
            int x2 = fac[i];
            if (n % (x2 * x2 * x2) == 0) {
                int s1 = n / (x2 * x2 * x2);
                if (check2(s1)) {
                    cout << "yes\n";
                    return;
                }
            }
        }
        cout << "no\n";
    }
}

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    Yyydrasil::init();
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
