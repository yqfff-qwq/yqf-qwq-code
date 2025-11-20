#include <bits/stdc++.h>
using namespace std;
int n, m, c, a[200010];
int bt[200010], L[510], R[500];
int rs[510][200010];
constexpr int V = 2e5;
int main(){
    freopen("reflection.in", "r", stdin);
    freopen("reflection.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i)cin >> a[i];
    int S = 2 * sqrt(200000);
    for (int i = 1; i <= n; ++i)bt[i] = (i - 1) / S + 1;
    for (int i = 1; i <= bt[n]; ++i)L[i] = R[i - 1] + 1, R[i] = min(n, R[i - 1] + S);
    for (int i = 1; i <= bt[n]; ++i){
        static int f[200010];
        iota(f, f + V + 1, 0);
        int mn = 0, mx = V; // rest mn...mx
        int adt = 0; // to value of i : f_i*ml+adt
        for (int p = L[i]; p <= R[i]; ++p){
            int v = a[p];
            if (adt <= mn)adt += v; else adt -= v;
            if (mn < adt && mx > adt){
                if (adt - mn < mx - adt){for (int i = mn; i < adt; ++i)f[i] = adt * 2 - i;mn = adt;}
                else {for (int i = mx; i > adt; --i)f[i] = adt * 2 - i;mx = adt;}
            }
        }
        auto fnd = [&](auto &&slf, int u) -> int {
            return u == f[u]? u : f[u] = slf(slf, f[u]);
        };
        for (int v = 0; v <= V; ++v)rs[i][v] = abs(adt - fnd(fnd, v));
    }
    int la = 0;
    while (m--){
        int l, r, v;
        cin >> l >> r >> v;
        la *= c;
        l ^= la, r ^= la, v ^= la;
        if (bt[l] == bt[r])for (int i = l; i <= r; ++i)v = abs(v - a[i]);
        else {
            for (int i = l; i <= R[bt[l]]; ++i)v = abs(v - a[i]);
            for (int i = bt[l] + 1; i < bt[r]; ++i)v = rs[i][v];
            for (int i = L[bt[r]]; i <= r; ++i)v = abs(v - a[i]);
        }
        cout << (la = v) << "\n";
    }
    return 0;
}