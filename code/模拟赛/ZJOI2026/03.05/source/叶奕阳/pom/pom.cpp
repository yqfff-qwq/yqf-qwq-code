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
#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

namespace Yyydrasil {

    const int inf = 0x3f3f3f3f3f3f3f3f;
    const int mxN = 1e5 + 5;
    int n, a[mxN], b[mxN], c[mxN], ans;
    int pmin[mxN], psum[mxN], ssum[mxN], smin[mxN];
    char ch;

    void main() {
        cin >> n; ans = 0;
        DEP(i, n, 1) cin >> ch, a[i] = (ch - '0'); a[n + 1] = 0;
        DEP(i, n, 1) cin >> ch, b[i] = (ch - '0'); b[n + 1] = 0;
        DEP(i, n, 1) cin >> c[i];
        DEP(i, n, 1) if (a[i] == 1 && b[i] == 0) { cout << "-1\n"; return; }
        REP(i, 1, n) pmin[i] = min((b[i - 1] == 1 ? pmin[i - 1] : inf), c[i]);
        REP(i, 1, n) psum[i] = psum[i - 1] + pmin[i];
        REP(i, 1, n) {
            if (a[i] != b[i]) {
                int l = i, r = i, res = inf;
                while (r < n && a[r + 1] != b[r + 1]) r++;
                if (b[r + 1] == 1) {
                    REP(p2, l, r) MIN(res, psum[p2 - 1] - psum[l - 1] + c[p2]);
                    MIN(res, psum[r] - psum[l - 1]);
                } else {
                    DEP(j, r, l) ssum[j] = psum[r] - psum[j] + c[j]; smin[r + 1] = inf;
                    DEP(j, r, l) smin[j] = min(smin[j + 1], ssum[j]);
                    REP(p2, l, r - 1) MIN(res, psum[p2 - 1] - psum[l - 1] + c[p2] + smin[p2 + 1]);
                    MIN(res, psum[r] - psum[l - 1]);
                }
                ans += res;
                i = r;
            }
        }
        cout << ans << '\n';
    }

/*
    1. A = 0, B = 1 + （当前位变 1）
    2. A = 0, B = 1 - （高位有 1 时）（前面连续 0 变 1）
    3. A = 1, B = 1 + （前一个 0 变 1）
    100000001
    111111111
    后缀做 1, 3 前缀一次 2
    000000001
    011111111
    1. 全 1, 3
    2. 后缀 1, 3 某个位置做 1 中间做 2 后缀 1, 3
*/

}

signed main() {
    freopen("pom.in", "r", stdin) ? void() : void();
    freopen("pom.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
