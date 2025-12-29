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
#define int long long
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int inf = 0x3f3f3f3f;
    const int N = 300 + 5;
    struct M { int h, c; } a[N];
    int n, k, ans, vis[N];

    bool sub1 = true, sub2 = true, sub3 = true;

    void main() {
        cin >> n >> k;
        sub1 &= (k >= 100000);
        sub3 &= (n <= 10);
        REP(i, 1, n) {
            cin >> a[i].h >> a[i].c;
            sub1 &= (a[i].h <= 300);
            sub1 &= (a[i].c <= 300);
            sub2 &= (a[1].h <= a[i].h);
            sub2 &= (a[1].c <= a[i].c);
            sub2 &= (a[i].h <= 300);
            sub3 &= (a[i].h <= 10);
        }
        sort(a + 1, a + 1 + n, [](M x, M y) { return x.h < y.h; });
        if (sub1) {
            int flag = 1;
            REP(i, 1, n) {
                if (a[i].h != a[1].h) break;
                if (a[i].c < a[flag].c) {
                    flag = i;
                }
            }
            REP(i, 2, n) {
                if (a[i].h != a[1].h) break;
                a[i].h++, ans += k;
            }
            REP(i, 2, n) {
                int cmin = inf, flag = 0;
                REP(j, 1, i - 1) {
                    if (a[j].h < a[i].h) {
                        int C = (vis[j] ? a[j].c : 0);
                        if (C < cmin) {
                            cmin = C;
                            flag = j;
                        }
                    }
                }
                ans += cmin;
                vis[flag] = true;
            }
            cout << ans << '\n';
        } else if (sub2) {
            int cntk = 0, cntsame = 0;
            REP(i, 2, n) {
                if (a[i].h == a[i - 1].h) cntsame++;
            }
            ans = cntk * k + (cntsame - 1) * a[1].c;
            while (cntsame != 0) {
                int lstemp = a[n].h + 1;
                int flag = 0, to = inf;
                DEP(i, n, 2) {
                    if (a[i + 1].h != a[i].h && a[i + 1].h != a[i].h + 1) lstemp = a[i].h + 1;
                    if (a[i].h == a[i - 1].h && lstemp - a[i].h <= to - a[flag].h) {
                        flag = i;
                        to = lstemp;
                    }
                }
                cntk += (to - a[flag].h);
                a[flag].h = to;
                cntsame--;
                sort(a + 2, a + 1 + n, [](M x, M y) { return x.h < y.h; });
                MIN(ans, cntk * k + cntsame * a[1].c);
            }
            cout << ans << '\n';
        } else {
            cout << 0 << '\n';
        }
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
