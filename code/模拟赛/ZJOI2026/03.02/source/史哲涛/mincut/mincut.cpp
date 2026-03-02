#include <bits/stdc++.h>
#define file_name "mincut"
struct prg_timer {
    using csc = std::chrono::steady_clock;const csc::time_point bg;static auto now(){ return csc::now(); } prg_timer() : bg(now()) { }
    void prttm(){ std::clog << "time use = " << std::chrono::duration_cast<std::chrono::milliseconds>(now() - bg).count() << "ms" << std::endl; }
    ~prg_timer(){ prttm(); }
} tmr;
using namespace std;bool SZT_MEM_BG;

int sn, sm;
int n, m, s, t;
constexpr long long inf = 1ll << 60;
namespace S1 {
    void sol1(){
        vector<tuple<int, int, long long> > ed;
        while (m--){
            int u, v; long long w;
            cin >> u >> v >> w;
            ed.emplace_back(--u, --v, w);
            long long rs = inf;
            for (int S = 0; S < 1 << n; ++S)if (S >> s - 1 & 1)if (~S >> t - 1 & 1){
                long long xr = 0;
                for (auto [u, v, w] : ed)if ((S >> u & 1) != (S >> v & 1))xr ^= w;
                rs = min(rs, xr);
            }
            cout << rs << "\n";
        }
    }
}
namespace S2 {
    struct linb {
        long long v[62];
        linb() : v{} { }
        void ins(long long x){
            for (int i = 59; ~i; --i)if (x >> i & 1){
                if (!v[i]){v[i] = x;return;}
                x ^= v[i];
            }
        }
        long long min_with(long long x) const {
            for (int i = 59; ~i; --i)x = min(x, x ^ v[i]);
            return x;
        }
    };
    long long wt[1010];
    void sol2(){
        fill_n(wt + 1, n, 0);
        while (m--){
            int u, v; long long w;
            cin >> u >> v >> w;
            wt[u] ^= w, wt[v] ^= w;
            linb ln;
            for (int i = 1; i <= n; ++i)if (i != s && i != t)ln.ins(wt[i]);
            cout << ln.min_with(wt[s]) << "\n";
        }
    }
}
namespace S3 {
    long long wt[1000010];
    int p[1000010];
    vector<pair<int, long long> > md[1000010];
    struct linb {
        long long v[62];
        int t[62];
        void ins(long long x, int tm){
            for (int i = 59; ~i; --i)if (x >> i & 1){
                if (!v[i]){v[i] = x;t[i] = tm;return;}
                if (tm > t[i])swap(tm, t[i]), swap(v[i], x);
                x ^= v[i];
            }
        }
        long long min_with(long long x, int l) const {
            for (int i = 59; ~i; --i)if (t[i] >= l)x = min(x, x ^ v[i]);
            return x;
        }
    };
    long long ww[1000010];
    void sol3(){
        fill_n(wt + 1, n, 0);
        fill_n(p + 1, n, 1);
        for (int i = 1; i <= m; ++i)md[i].clear();
        auto psh = [&](int l, int r, long long w){
            if (l <= r && w)md[l].emplace_back(r, w);//, clog << l << "-" << r << ":" << w << endl;
        };
        for (int i = 1; i <= m; ++i){
            int u, v; long long w;
            cin >> u >> v >> w;
            if (u != v){
                auto del = [&](int u){
                    if (u == s || u == t)return;
                    psh(p[u], i - 1, wt[u]);
                };
                auto ins = [&](int u){
                    if (u == s || u == t)return;
                    p[u] = i;
                };
                del(u);wt[u] ^= w;ins(u);
                del(v);wt[v] ^= w;ins(v);
            }
            ww[i] = wt[s];
            // for (int i = 1; i <= n; ++i)clog << wt[i] << " "; clog << endl;
        }
        for (int i = 1; i <= n; ++i)if (i != s && i != t)psh(p[i], m, wt[i]);
        linb ln{};
        for (int i = 1; i <= m; ++i){
            for (auto [j, w] : md[i])ln.ins(w, j);
            cout << ln.min_with(ww[i], i) << "\n";
        }
    }
}
void work(){
    cin >> n >> m >> s >> t;
    sn += n, sm += m;
    if (sn <= 17 && sm <= 17)return S1::sol1(); // 14pts
    if (sn <= 1000 && sm <= 1000)return S2::sol2(); // 32pts
    return S3::sol3();
}

bool SZT_MEM_ED;int main(){
    freopen(file_name".in", "r", stdin);
    freopen(file_name".out", "w", stdout);
    const double static_local_mem_use = fabs(&SZT_MEM_ED - &SZT_MEM_BG) / 1024 / 1024;
    clog << "static local mem use = " << static_local_mem_use << "M" << endl;
    assert(static_local_mem_use < 64);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)work();
    return 0;
}