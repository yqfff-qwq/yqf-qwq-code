#include <bits/stdc++.h>
using namespace std;
int n, f[300010];
long long w[300010];
vector<int> e[300010];
vector<long long> cw[300010]; // children's w, sorted
vector<long long> scw[300010]; // prefix sum of cw
void psw(int u){
    for (int v : e[u])psw(v), w[u] += w[v], cw[u].emplace_back(w[v]);
    sort(cw[u].begin(), cw[u].end());
    partial_sum(cw[u].begin(), cw[u].end(), back_inserter(scw[u]));
}
int kf[20][300010]; // 2^i -th father
long long bs[20][300010]; // 2^i -th father's brother's value sum
long long kt[20][300010]; // kt_{i,u} : min w from u | til jump to 2^i -th father of u, all brother's w <= x
void cal(int u){
    if (u){
        bs[0][u] = scw[f[u]].back() - w[u];
        for (int i = 1; 1 << i <= n; ++i)bs[i][u] = bs[i - 1][u] + bs[i - 1][kf[i - 1][u]];
        kt[0][u] = cw[f[u]].size() == 1? 0 : cw[f[u]].rbegin()[cw[f[u]].back() == w[u]]; // max expect self
        for (int i = 1; 1 << i <= n; ++i)kt[i][u] = max(kt[i - 1][u], kt[i - 1][kf[i - 1][u]] - bs[i - 1][u]);
    }
    for (int v : e[u])cal(v);
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> f[i], cin >> w[i], e[f[i]].emplace_back(i);
    psw(0);
    copy_n(f, n + 1, kf[0]);
    for (int i = 1; 1 << i <= n; ++i)
        for (int j = 0; j <= n; ++j)kf[i][j] = kf[i - 1][kf[i - 1][j]];
    cal(0);
    for (int i = 1; i <= n; ++i){
        int u = i;
        long long x = w[u];
        while (u){
            for (int i = __lg(n); ~i && u; --i)
                if (x >= kt[i][u]){
                    x += bs[i][u];
                    u = kf[i][u];
                }
            if (!u)break;
            { // force jump
                const long long px = x;
                int p = upper_bound(cw[f[u]].begin(), cw[f[u]].end(), px) - cw[f[u]].begin(); // first gt
                x = 1ll * px * (cw[f[u]].size() - p) + (p? scw[f[u]][p - 1] : 0);
                u = f[u];
            }
        }
        // for (int i = f[u]; ~i; i = f[i]){
        //     long long y = 0;
        //     for (int u : e[i])y += min(w[u], x);
        //     x = y;
        // }
        cout << x << "\n";
    }
    return 0;
}