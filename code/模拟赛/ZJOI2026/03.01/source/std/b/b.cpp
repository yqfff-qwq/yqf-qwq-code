#include <bits/stdc++.h>
using namespace std;
int l, n, t;
int x[180], y[180];
int d1[180], d2[180], d3[180], d4[180];
int id1[180], id2[180];
int rk1[180], rk2[180];
inline void tmn(int &x, int y){
    if (x > y)x = y;
}
int main(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> l >> n >> t; t >>= 1; // go to and from
    for (int i = 1; i <= n; ++i){
        cin >> x[i] >> y[i];
        int x1 = x[i] - 1, x2 = l - x[i];
        int y1 = y[i] - 1, y2 = l - y[i];
        d1[i] = x1 + y1;
        d2[i] = x1 + y2;
        d3[i] = x2 + y2;
        d4[i] = x2 + y1;
        // d1+d3=d2+d4=2l-2
    }
    iota(id1 + 1, id1 + n + 1, 1);
    sort(id1 + 1, id1 + n + 1, [](int u, int v){return d1[u] < d1[v];});
    iota(id2 + 1, id2 + n + 1, 1);
    sort(id2 + 1, id2 + n + 1, [](int u, int v){return d2[u] < d2[v];});
    for (int i = 1; i <= n; ++i)rk1[id1[i]] = i, rk2[id2[i]] = i;
    for (int x = 0; x <= n; ++x){
        vector<int> ids[2];
        for (int i = 1; i <= n; ++i)
            ids[rk1[id2[i]] <= x].emplace_back(id2[i]);
        int p[2] = {};
        // rk1[i] <= x : d1 else d3
        // rk2[i] <= y : d2 else d4
        vector<vector<int> > pr[2], sf[2];
        vector<int> emp(t + 1);
        pr[0].assign(ids[0].size() + 1, emp);
        pr[1].assign(ids[1].size() + 1, emp);
        sf[0].assign(ids[0].size() + 1, emp);
        sf[1].assign(ids[1].size() + 1, emp);
        auto cal = [&](const vector<int> &pr, vector<int> &dst, int d1, int d2){
            fill(dst.begin(), dst.end(), t + 1);
            for (int x = 0; x <= t; ++x){
                if (x + d1 <= t)tmn(dst[x + d1], pr[x]);
                tmn(dst[x], pr[x] + d2);
            }
        };
        for (int _ = ids[0].size(), i = 0; i < _; ++i)cal(pr[0][i], pr[0][i + 1], d2[ids[0][i]], d3[ids[0][i]]);
        for (int i = ids[0].size() - 1; ~i; --i)cal(sf[0][i + 1], sf[0][i], d3[ids[0][i]], d4[ids[0][i]]);
        for (int _ = ids[1].size(), i = 0; i < _; ++i)cal(pr[1][i], pr[1][i + 1], d1[ids[1][i]], d2[ids[1][i]]);
        for (int i = ids[1].size() - 1; ~i; --i)cal(sf[1][i + 1], sf[1][i], d1[ids[1][i]], d4[ids[1][i]]);
        for (int y = 0; y <= n; ++y){
            if (y)++p[rk1[id2[y]] <= x];
            // auto cal = [&](const vector<int> &pt, int d1[], int d2[]){
            //     vector<int> f(t + 1);
            //     for (int i : pt){
            //         vector<int> g(t + 1, t + 1);
            //         for (int x = 0; x <= t; ++x){
            //             if (x + d1[i] <= t)tmn(g[x + d1[i]], f[x]);
            //             tmn(g[x], f[x] + d2[i]);
            //         }
            //         f.swap(g);
            //     }
            //     return f;
            // };
            // vector<int> v[2][2];
            // v[0][1] = {ids[0].begin(), ids[0].begin() + p[0]};
            // v[0][0] = {ids[0].begin() + p[0], ids[0].end()};
            // v[1][1] = {ids[1].begin(), ids[1].begin() + p[1]};
            // v[1][0] = {ids[1].begin() + p[1], ids[1].end()};
            // auto f1 = cal(v[1][1], d1, d2); // pr[1]
            // auto f2 = cal(v[1][0], d1, d4); // sf[1]
            // auto f3 = cal(v[0][1], d2, d3); // pr[0]
            // auto f4 = cal(v[0][0], d3, d4); // sf[0]
            auto &&f1 = pr[1][p[1]];// cal(v[1][1], d1, d2); // pr[1]
            auto &&f2 = sf[1][p[1]];// cal(v[1][0], d1, d4); // sf[1]
            auto &&f3 = pr[0][p[0]];// cal(v[0][1], d2, d3); // pr[0]
            auto &&f4 = sf[0][p[0]];// cal(v[0][0], d3, d4); // sf[0]
            for (int i = 0; i <= t; ++i)
                if (f1[i] <= t && f3[t - f1[i]] <= t && f2[t - i] + f4[t - f3[t - f1[i]]] <= t){
                    cout << "Yes" << endl;
                    return 0;
                }
        }
    }
    cout << "No" << endl;
    return 0;
}