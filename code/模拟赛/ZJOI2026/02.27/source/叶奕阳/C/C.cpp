#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=c)
#define MIN(a,b) ((a)=min((a),(b)))
#define MAX(a,b) ((a)=max((a),(b)))
#define ADD(a,b) ((a)=((a)+(b))%mod)
#define MUL(a,b) ((a)=((a)*(b))%mod)
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    (a).size()
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

namespace Yyydrasil {

    const int mxN = 2e5 + 5;
    int n, q, K, op, x, v;
    int low[mxN];
    struct tree_array {
        int tree[mxN];
        int lowbit(int x) {
            int s = x, p = 1;
            while (s % K == 0) s /= K, p *= K;
            return (s % K) * p;
        }
        inline void add(int x, int v) {
            while (x <= n) {
                tree[x] ^= v;
                x += low[x];
            }
        }
        inline int query(int x) {
            int ans = 0;
            while (x) {
                ans ^= tree[x];
                x -= low[x];
            } return ans;
        }
    } tree;

    void main() {
        cin >> n >> q >> K;
        if (n <= 2e5) {
            REP(i, 1, n) low[i] = tree.lowbit(i);
            REP(i, 1, q) {
                cin >> op;
                if (op == 1) {
                    cin >> x >> v;
                    tree.add(x, v);
                } else {
                    cin >> x;
                    cout << tree.query(x) << '\n';
                }
            }
        }
    }
}

signed main() {
    freopen("C.in", "r", stdin) ? void() : void();
    freopen("C.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
