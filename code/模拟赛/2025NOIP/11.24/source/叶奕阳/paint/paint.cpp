#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();++i)
#define REP(i,a,b)    for(int i=(a);i<=(b);++i)
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
#define ctz(x)   __builtin_ctz(x)
#define DBG(x)   cerr<<#x<<' '<<(x)<<'\n'
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int N = 4000 + 5, M = 4000 + 5;
    int n, m, q, x1, y1, x2, y2, e1[N][M], e2[N][M], sum[N][M];
    char a[N][M];
    
    int ptoi(pii a) { return (a.fi - 1) * m + a.se; }
    pii itop(int a) { return {(a - 1) / m + 1, (a - 1) % m + 1}; }

    int fa[N * M];
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            fa[x] = y;
        }
    }

    bool in(pii p, int x1, int y1, int x2, int y2) {
        return x1 <= p.fi && p.fi <= x2 && y1 <= p.se && p.se <= y2;
    }

    void main() {
        cin >> n >> m >> q;
        REP(i, 1, n * m) fa[i] = i;
        REP(i, 1, n) {
            REP(j, 1, m) {
                cin >> a[i][j];
            }
        }
        REP(i, 1, n) {
            REP(j, 1, m - 1) {
                int e = (a[i][j] == a[i][j + 1]);
                if (i != 1 && i != n && !e) merge(ptoi({i - 1, j}), ptoi({i, j}));
                e1[i][j] = e + e1[i][j - 1] + e1[i - 1][j] - e1[i - 1][j - 1];
            }
        }
        REP(i, 1, n - 1) {
            REP(j, 1, m) {
                int e = (a[i][j] == a[i + 1][j]);
                if (j != 1 && j != m && !e) merge(ptoi({i, j - 1}), ptoi({i, j}));
                e2[i][j] = e + e2[i][j - 1] + e2[i - 1][j] - e2[i - 1][j - 1];
            }
        }
        REP(i, 1, n - 1) {
            REP(j, 1, m - 1) {
                pii p = itop(find(ptoi({i, j})));
                sum[p.fi][p.se] = 1;
            }
        }
        REP(i, 1, n - 1) {
            REP(j, 1, m - 1) {
                sum[i][j] = sum[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
        REP(i, 1, q) {
            cin >> x1 >> y1 >> x2 >> y2;
            int V = (x2 - x1 + 1) * (y2 - y1 + 1);
            int E = (e1[x2][y2 - 1] - e1[x2][y1 - 1] - e1[x1 - 1][y2 - 1] + e1[x1 - 1][y1 - 1]) + 
                    (e2[x2 - 1][y2] - e2[x2 - 1][y1 - 1] - e2[x1 - 1][y2] + e2[x1 - 1][y1 - 1]);
            int P = sum[x2 - 1][y2 - 1] - sum[x2 - 1][y1 - 1] - sum[x1 - 1][y2 - 1] + sum[x1 - 1][y1 - 1];
            unordered_set<int> del;
            REP(i, x1, x2 - 1) {
                if (a[i][y1] != a[i + 1][y1]) {
                    int p = find(ptoi({i, y1}));
                    if (in(itop(p), x1, y1, x2 - 1, y2 - 1)) del.insert(p);
                }
            }
            REP(i, x1, x2 - 1) {
                if (a[i][y2] != a[i + 1][y2] && y2 != 1) {
                    int p = find(ptoi({i, y2 - 1}));
                    if (in(itop(p), x1, y1, x2 - 1, y2 - 1)) del.insert(p);
                }
            }
            REP(i, y1, y2 - 1) {
                if (a[x1][i] != a[x1][i + 1]) {
                    int p = find(ptoi({x1, i}));
                    if (in(itop(p), x1, y1, x2 - 1, y2 - 1)) del.insert(p);
                }
            }
            REP(i, y1, y2 - 1) {
                if (a[x2][i] != a[x2][i + 1] && x2 != 1) {
                    int p = find(ptoi({x2 - 1, i}));
                    if (in(itop(p), x1, y1, x2 - 1, y2 - 1)) del.insert(p);
                }
            }
            P -= SZ(del);
            cout << V - E + P << '\n';
        }
    }
}

signed main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}