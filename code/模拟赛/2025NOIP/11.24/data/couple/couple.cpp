#include <bits/stdc++.h>
using namespace std;
int n;
int a[510];
constexpr int inf = 1e8;
inline void tmn(int &x, int y){x = x > y? y : x;}
struct _upd {
    array<array<int, 3>, 3> &fj;
    vector<array<array<int, 3>, 3> > &g;
    int &ai, &j;
    template <int x, int Rx, int y, int Y>
        void G() const {
            constexpr int s = 1 + (y == Y || (y == 1 && Y == 2));
            int q = 1 + y + ai * s;
            tmn(g[j + Rx][x][Y], fj[x][y] + q);
            tmn(g[j + q][Y][x], fj[y][x] + Rx);
        }
};
void work(){
    cin >> n;
    memset(a, 0, sizeof(a));
    int mxx = 0;
    while (n--){
        int x, y;
        cin >> x >> y;
        a[x] = max(a[x], y);
        mxx = max(mxx, x);
    }
    array<array<int, 3>, 3> Inf{{{{inf, inf, inf}}, {{inf, inf, inf}}, {{inf, inf, inf}}}};
    vector<array<array<int, 3>, 3> > f(260000, Inf), g(260000, Inf);
    int mx = 1;
    f[0] = {{{{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}};
    for (int i = 1; i <= mxx; ++i){
        for (int j = 0; j < mx; ++j){
            _upd upd{f[j], g, a[i], j};
            #define R(...)\
                upd.G<__VA_ARGS__, 0, 0>();upd.G<__VA_ARGS__, 0, 1>();upd.G<__VA_ARGS__, 0, 2>();\
                upd.G<__VA_ARGS__, 1, 1>();upd.G<__VA_ARGS__, 1, 2>()
            R(0, 1);R(1, 2);R(2, 0);//coef of each section
        }
        fill_n(f.begin(), mx, Inf);
        swap(f, g);
        mx = min(mx + 2 * (a[i] + 1), 255000);
    }
    int rs = inf;
    for (int i = 0; i < mx; ++i)rs = min(rs, max(i, f[i][2][2]));
    cout << rs << "\n";
}
int main(){
    freopen("couple.in", "r", stdin);
    freopen("couple.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)work();
    return 0;
}