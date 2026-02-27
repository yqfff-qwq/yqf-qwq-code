#include <cstdint>
#include <tuple>
#include <type_traits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <random>

namespace number_theory {

    using u32 = std::uint32_t;
    using u64 = std::uint64_t;
    using i32 = std::int32_t;
    using i64 = std::int64_t;

    template <typename _Tp>
        using asss_t = std::enable_if_t<std::is_signed<_Tp>::value>;
    template <typename _Tp>
        using assu_t = std::enable_if_t<std::is_integral<_Tp>::value>;

    template <typename _Tp, typename = assu_t<_Tp> >
        inline constexpr _Tp gcd(_Tp a, _Tp b){ while (b)std::tie(a, b) = std::make_tuple(b, a % b);return a; }

    // refer https://www.luogu.com.cn/article/t7bd37d3
    inline constexpr u32 bgcd(u32 a, u32 b){
        if (!a | !b)return a | b;
        int az = __builtin_ctz(a), bz = __builtin_ctz(b), z = az > bz? bz : az;b >>= bz;u32 tmp = 0;
        while (1){a >>= az;tmp = b - a;if (a < b)b = a, a = tmp;else a = -tmp;if (a)az = __builtin_ctz(tmp);else break;}
        return b << z;
    }
    inline constexpr u32 bgcd(i32 a, i32 b){
        return bgcd(u32(a >> 31? -a : a), u32(b >> 31? -b : b));
    }

    template <typename _Tp, typename = asss_t<_Tp> >
        inline constexpr std::tuple<_Tp, _Tp, _Tp> exgcd(_Tp a, _Tp b){
            _Tp x = 1, y = 0;
            _Tp x1 = 0, y1 = 1, a1 = a, b1 = b;
            while (b1) {
                _Tp q = a1 / b1;
                std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
                std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
                std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
            }
            return std::make_tuple(a1, x, y);
        }

    template <typename _Tp, typename = asss_t<_Tp> >
        inline constexpr std::tuple<bool, _Tp, _Tp> result_of_linear_equation(_Tp a, _Tp b, _Tp n){
            //(x_0,dx), result of ax=b\pmod n is x=x_0\pmod dx
            _Tp zero{};
            auto [d, x_0, _] = exgcd(a, n);
            if (b % d)return std::make_tuple(false, zero, zero);
            _Tp mod = std::abs(n / d);
            x_0 = x_0 * (b / d) % mod;
            if (x_0 < 0)x_0 += mod;
            return std::make_tuple(true, x_0, mod);
        }

}

#include <bits/stdc++.h>
#define file_name "B"
struct prg_timer {
    using csc = std::chrono::steady_clock;const csc::time_point bg;static auto now(){ return csc::now(); } prg_timer() : bg(now()) { }
    void prttm(){ std::clog << "time use = " << std::chrono::duration_cast<std::chrono::milliseconds>(now() - bg).count() << "ms" << std::endl; }
    ~prg_timer(){ prttm(); }
} tmr;
using namespace std;bool SZT_MEM_BG;

int n, m, q;
inline int add(int x, int y){
    x += y;
    return x >= m? x - m : x;
}
inline int mul(int x, int y){
    return 1ll * x * y % m;
}
inline int neg(int x){
    return x? m - x : x;
}
int f[1000010];
int d[1000010];
int gc[1000010];
inline int fnd(int x){
    if (x == f[x])return x;
    int fx = fnd(f[x]);
    d[x] = add(d[x], d[f[x]]);
    return f[x] = fx;
}

int exgcd(int a, int b, int &x, int &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    tie(x, y) = make_pair(y, x - a / b * y);
    return r;
}

using number_theory::bgcd;
using number_theory::result_of_linear_equation;

constexpr auto S = bgcd(1, 1);

bool SZT_MEM_ED;int main(){
    freopen(file_name".in", "r", stdin);
    freopen(file_name".out", "w", stdout);
    const double static_local_mem_use = fabs(&SZT_MEM_ED - &SZT_MEM_BG) / 1024 / 1024;
    clog << "static local mem use = " << static_local_mem_use << "M" << endl;
    assert(static_local_mem_use < 64);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
    iota(f + 1, f + n + 1, 1);
    fill_n(gc + 1, n, m);
    while (q--){
        int op;
        cin >> op;
        if (op == 1){
            int u, v, w;
            cin >> u >> v >> w;
            int x = fnd(u), y = fnd(v);
            if (x != y)f[y] = x, d[y] = add(neg(add(d[u], d[v])), w), gc[x] = bgcd(gc[x], gc[y]);
            else gc[x] = bgcd(gc[x], add(add(d[u], d[v]), w));
            gc[x] = bgcd(gc[x], add(w, w));
        } else {
            int u, v, a, b, c;
            cin >> u >> v >> a >> b >> c;
            int x = fnd(u), y = fnd(v);
            if (x != y){
                cout << 0 << "\n";
                continue;
            }
            int g = gc[x];
            int t = add(add(d[u], d[v]), neg(a)) % g;
            // int rs = 0;
            // for (int i = 0; i < c; ++i){
            //     int v = mul(i, b);
            //     if (v % g == t)++rs;
            // }
            // cout << rs << "\n";
            auto [hs, x0, dx] = result_of_linear_equation<long long>(b, t, g);
            if (!hs)cout << 0 << "\n";
            else {
                // i = x0 \pmod dx
                // int rs = 0;
                // for (int i = 0; i < c; ++i)
                //     rs += i % dx == x0;
                // cout << rs << "\n";
                cout << (c - x0 - 1 < 0? 0 : (c - x0 - 1) / dx + 1) << "\n";
            }
        }
    }

    return 0;
}