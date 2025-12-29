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

    const int inf = 0x3f3f3f3f3f3f3f3f;
    const int N = 2000 + 5;
    int n, m, k, t, a[N][N], sx, sy, tx, ty;
    char ch;

    int h1, t1; pii q1[N * N * 2];
    int h2, t2; pii q2[N * N * 2];
    int dis[N][N];

    inline bool check(int i, int j) { return (i >= 1 && i <= n && j >= 1 && j <= m && a[i][j]); }
    inline void tryin1(int i, int j, int d) { if (check(i, j) && dis[i][j] > d) dis[i][j] = d, q1[++t1] = {i, j}; }
    inline void tryin2(int i, int j, int d) { if (check(i, j) && dis[i][j] > d) dis[i][j] = d, q2[++t2] = {i, j}; }

    void main() {
        cin >> n >> m >> k >> t;
        REP(i, 1, n) {
            REP(j, 1, m) {
                cin >> ch;
                if (ch == 'S') sx = i, sy = j;
                if (ch == 'T') tx = i, ty = j;
                a[i][j] = (ch == '#' ? 0 : 1);
            }
        }
        memset(dis, 0x3f, sizeof(dis)); dis[sx][sy] = 0;
        q1[h1 = t1 = 1] = {sx, sy};
        h2 = 1, t2 = 0;
        while (h1 <= t1 || h2 <= t2) {
            int ux1 = q1[h1].fi, uy1 = q1[h1].se;
            int ux2 = q2[h2].fi, uy2 = q2[h2].se;
            int ux = 0, uy = 0;
            if (dis[ux1][uy1] <= dis[ux2][uy2]) {
                ux = ux1, uy = uy1;
                h1++;
            } else {
                ux = ux2, uy = uy2;
                h2++;
            }
            if (ux == tx && uy == ty) {
                cout << dis[tx][ty] << '\n';
                return;
            }
            int i = 0, j = 0;
            i = ux - 1, j = uy, tryin1(i, j, dis[ux][uy] + 1);
            i = ux + 1, j = uy, tryin1(i, j, dis[ux][uy] + 1);
            i = ux, j = uy - 1, tryin1(i, j, dis[ux][uy] + 1);
            i = ux, j = uy + 1, tryin1(i, j, dis[ux][uy] + 1);
            REP(dx, 0, k) {
                int dy = k - dx;
                                        tryin2(ux + dx, uy + dy, dis[ux][uy] + t);
                if (dx != 0)            tryin2(ux - dx, uy + dy, dis[ux][uy] + t);
                if (dy != 0)            tryin2(ux + dx, uy - dy, dis[ux][uy] + t);
                if (dx != 0 && dy != 0) tryin2(ux - dx, uy - dy, dis[ux][uy] + t);
            }
            if (abs(tx - ux) + abs(ty - uy) <= k) tryin2(tx, ty, dis[ux][uy] + t);
        }
        cout << "-1" << '\n';
    }
}

signed main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
