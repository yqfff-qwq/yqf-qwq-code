#include <bits/stdc++.h>
using namespace std;
int n, op[100010], x[100010], y[100010], m;

int f[100010], l[100010], r[100010];
inline int fnd(int x){
    return x == f[x]? x : f[x] = fnd(f[x]);
}

vector<int> id[200010 << 2];
vector<int> glb;
void flp(int p, int l = 1, int r = m, int k = 1){
    glb.insert(glb.end(), id[k].begin(), id[k].end()); id[k].clear();
    if (l == r)return;
    int M = l + r >> 1;
    if (p <= M)flp(p, l, M, k << 1);
    else flp(p, M + 1, r, k << 1 | 1);
}
void ins(int L, int R, int v, int l = 1, int r = m, int k = 1){
    if (L > R)return;
    if (L <= l && r <= R){
        id[k].emplace_back(v);
        return;
    }
    int M = l + r >> 1;
    if (L <= M)ins(L, R, v, l, M, k << 1);
    if (R > M)ins(L, R, v, M + 1, r, k << 1 | 1);
}

int main(){
    freopen("interval.in", "r", stdin);
    freopen("interval.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)cin >> op[i] >> x[i] >> y[i];
    {
        vector<int> b;
        for (int i = 1; i <= n; ++i)if (op[i] == 1)b.emplace_back(x[i]), b.emplace_back(y[i]);
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (int i = 1; i <= n; ++i)if (op[i] == 1){
            x[i] = lower_bound(b.begin(), b.end(), x[i]) - b.begin() + 1;
            y[i] = lower_bound(b.begin(), b.end(), y[i]) - b.begin() + 1;
        }
        m = b.size();
    }
    int cc = 0;
    for (int i = 1; i <= n; ++i){
        if (op[i] == 1){
            glb.clear();
            flp(x[i]); flp(y[i]);
            ++cc; f[cc] = cc; l[cc] = x[i], r[cc] = y[i];
            for (int x : glb)f[x] = cc, l[cc] = min(l[cc], l[x]), r[cc] = max(r[cc], r[x]);
            ins(l[cc] + 1, r[cc] - 1, cc);
        } else {
            int u = fnd(x[i]), v = fnd(y[i]);
            cout << (l[v] <= l[u] && r[u] <= r[v]? "YES" : "NO") << "\n";
        }
    }
    return 0;
}