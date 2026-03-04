#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<pair<int, int> > e[100010];
int ds[100010];
vector<int> ch[100010];
int f[100010];
void dfs(int u, int fa){
    for (auto t : e[u]){
        int v = t.first, l = t.second;
        if (v ^ fa)f[v] = u, ds[v] = ds[u] + l, dfs(v, u), ch[u].emplace_back(v);
    }
}
// namespace S1 {
//     struct edg {
//         int to, fl, cs;
//     } ed[4 * 310]; int tot = 1;
//     vector<int> e[310];
//     void adde(int u, int v, int fl, int cs){
//         ed[++tot] = {v, fl, cs};
//         e[u].emplace_back(tot);
//         ed[++tot] = {u, 0, -cs};
//         e[v].emplace_back(tot);
//     }
//     constexpr int inf = 1e9;
//     int d[310];
//     int Q[310 * 310], HD, TL; bool inq[310];
//     int S, T, N;
//     int mn[310], pr[310];
//     bool spfa(){
//         fill_n(d, N, -inf);
//         fill_n(inq, N, 0);
//         Q[HD = TL = 1] = S; inq[S] = 1;
//         mn[S] = inf;
//         d[S] = 0;
//         // for (int i = 0; i < N; ++i)
//         //     for (int ei : e[i])if (ed[ei].fl)clog << i << ">" << ed[ei].to << ":" << ed[ei].cs << endl;
//         //     clog << endl;
//         while (HD <= TL){
//             int u = Q[HD++];
//             inq[u] = 0;
//             for (int i : e[u]){
//                 int v = ed[i].to, c = ed[i].cs, f = ed[i].fl;
//                 if (!f)continue;
//                 if (d[v] < d[u] + c){
//                     d[v] = d[u] + c;
//                     mn[v] = min(mn[u], f);
//                     pr[v] = i;
//                     if (!inq[v])Q[++TL] = v, inq[v] = 1, assert(TL <= 90000);
//                 }
//             }
//         }
//         return d[T] != -inf;
//     }
//     int mxf;
//     long long mxc;
//     void upd(){
//         assert(d[T] != -inf);
//         assert(mn[T] > 0);
//         mxf += mn[T], mxc += mn[T] * d[T];
//         int u = T;
//         while (u != S){
//             ed[pr[u]].fl -= mn[T];
//             ed[pr[u] ^ 1].fl += mn[T];
//             u = ed[pr[u] ^ 1].to;
//         }
//         // clog << mxf << "," << mxc << endl;
//     }
//     void reset(){
//         for (int i = 2; i <= tot; i += 2)ed[i].fl += ed[i ^ 1].fl, ed[i ^ 1].fl = 0;
//         mxf = 0, mxc = 0;
//     }
//     void sol1(){
//         S = 0, T = n + 1; N = n + 2;
//         for (int i = 1; i <= n; ++i)for (int j : ch[i])adde(i, j, inf, 0);
//         while (spfa() && d[T] > 0)upd();
//         while (q--){
//             int op, x, y;
//             cin >> op >> x >> y;
//             reset();
//             if (op == 1)adde(S, x, 1, y - ds[x]);
//             else adde(x, T, 1, y + ds[x]);
//             while (spfa() && d[T] > 0)upd();
//             cout << mxc << "\n";
//         }
//         exit(0);
//     }
// }
namespace S2 {
    vector<int> qw[4010];
    vector<int> pt[4010];
    priority_queue<int> pq;
    long long rs;
    void dfs(int u, priority_queue<int> &pq){
        pq = {pt[u].begin(), pt[u].end()};
        for (int v : ch[u]){
            priority_queue<int> ep;
            dfs(v, ep);
            if (ep.size() > pq.size())pq.swap(ep);
            while (!ep.empty())pq.emplace(ep.top()), ep.pop();
        }
        vector<int> Q = qw[u];
        sort(Q.begin(), Q.end());
        while (!pq.empty() && !Q.empty() && pq.top() + Q.back() > 0){
            rs += pq.top() + Q.back();
            pq.pop();
            pq.emplace(-Q.back());
            Q.pop_back();
        }
    }
    void sol2(){
        while (q--){
            int op, x, y;
            cin >> op >> x >> y;
            if (op == 1)qw[x].emplace_back(y - ds[x]);
            else pt[x].emplace_back(y + ds[x]);
            priority_queue<int>().swap(pq);
            rs = 0;
            dfs(1, pq);
            cout << rs << "\n";
        }
        exit(0);
    }
}
namespace S3 {
    bool islist(){
        for (int i = 2; i <= n; ++i)
            if (f[i] != i - 1)return 0;
        return 1;
    }
    void sol3(){
        ;
    }
}
int main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1, u, v, w; i < n; ++i){
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    dfs(1, 0);
    if (n <= 4000 && q <= 4000)S2::sol2(); // 1~2
    if (S3::islist())S3::sol3();
    return 0;
}
/*
cd 史哲涛
cd c
g++ c.cpp -o c -std=c++11 -O2
./c <ex.in >.out
diff .out ex.ans -w
./c <ex_1.in >.out
diff .out ex_1.ans -w
./c <ex_2.in >.out
diff .out ex_2.ans -w
./c <25.in >.out
diff .out 25.ans -w
*/