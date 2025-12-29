#ifndef ELOI_io_stdinput_cpp
#define ELOI_io_stdinput_cpp

#ifndef ELOI_config_cpp
#define ELOI_config_cpp

#define eloi_use_exception
#define eloi_fast // maybe more memory
#define eloi_strict

#endif

#ifndef ELOI_io_io_flag_t_cpp
#define ELOI_io_io_flag_t_cpp

namespace ELOI { namespace io {

    struct peek_t { }; // peek
    constexpr peek_t peek{};

    struct no_check_eof_t { }; // not check if is EOF
    constexpr no_check_eof_t no_check_eof{};

    struct no_check_prefix_space_t { }; // not check if has prefix space
    constexpr no_check_prefix_space_t no_check_prefix_space{};

    struct no_check_positive_t { }; // no prefix '+'
    constexpr no_check_positive_t no_check_positive{};

    struct no_check_sintmin_t { }; // not check min value of signed integral type (INT_MIN, LLONG_MIN, etc.)
    constexpr no_check_sintmin_t no_check_sintmin{};

    char empty_char;
    short empty_short;
    unsigned short empty_ushort;
    int empty_int;
    unsigned empty_uint;
    long empty_long;
    unsigned long empty_ulong;
    long long empty_llong;
    unsigned long long empty_ullong;

} } // namespace ELOI::io

#endif


#if defined(__linux__)
# include <unistd.h> // for `STDIN_FILENO`
# include <sys/stat.h> // for `struct stat` and `fstat`
# include <sys/mman.h> // for `mmap`, `PROT_READ` and `MAP_PRIVATE`
# include <cstddef> // for `NULL`
# include <cstdio> // for `EOF`, `perror` and `std::freopen`
# include <cstdint> // for `std::uintptr_t`
# include <utility> // for `std::forward`
# include <cctype> // for `std::isdigit`

#ifdef eloi_use_exception
# include <errno.h> // for `errno` and `perror`
# include <stdexcept> // for `std::runtime_error`
# include <string> // for `std::to_string` and `std::string`
# define __chk_syscall(expr, __unexpect)\
    if ((expr) == (__unexpect)){\
        perror((std::string(__FILE__) + ":" + std::to_string(__LINE__)).c_str());\
        throw std::runtime_error(std::to_string(errno));\
    }
#else
# define __chk_syscall(expr, __unexpect) (void)(expr)
#endif

namespace ELOI { namespace io {

    #ifdef eloi_fast
} } // namespace ELOI::io
#include <array>
#include <endian.h>
namespace ELOI { namespace io {
    static const std::array<int, 0x10000> __tbl = []{
        std::array<int, 0x10000> ret;
        ret.fill(-1);
        for (int i = '0'; i <= '9'; ++i)
            for (int j = '0'; j <= '9'; ++j)
                #if BYTE_ORDER == BIG_ENDIAN
                ret[i << 8 | j] = i * 10 + j - '0' * 11;//(i - '0') * 10 + j - '0';
                #elif BYTE_ORDER == LITTLE_ENDIAN
                ret[i << 8 | j] = j * 10 + i - '0' * 11;//(i - '0') * 10 + j - '0';
                #endif
        return ret;
    }();
    inline int __fetch_2_to_int(char *c){ // c is aligned
        __builtin_prefetch(c + 2, 0, 1);
        return __tbl[*(short*)c];
    }
    #else
    inline int __fetch_2_to_int(char *c){ // c is aligned
        return std::isdigit(c[0]) && std::isdigit(c[1])? c[0] * 10 + c[1] - '0' * 11 : -1;
    }
    #endif

    #if defined(__GNUC__)
    #define expect(...) __builtin_expect(static_cast<bool>(__VA_ARGS__), true)
    #define unexpect(...) __builtin_expect(static_cast<bool>(__VA_ARGS__), false)
    #else
    #define expect(...) (static_cast<bool>(__VA_ARGS__))
    #define unexpect(...) (static_cast<bool>(__VA_ARGS__))
    #endif

    class stdinput_file { // if stdin from file
        public:
            typedef char char_type;
            #if defined(__GNUC__)
            typedef char_type char2_type __attribute__((vector_size(2)));
            #endif

        private:
            struct stat __stdin_stat;
            char* __buf_beg;
            char* __buf_ptr;
            char* __buf_end;
            inline void __open(){
                __chk_syscall(fstat(STDIN_FILENO, &__stdin_stat), -1);
                __chk_syscall(__buf_beg = __buf_ptr =
                    (char*)mmap(NULL, __stdin_stat.st_size, PROT_READ, MAP_PRIVATE, STDIN_FILENO, 0), (char*)MAP_FAILED);
                __buf_end = __buf_beg + __stdin_stat.st_size;
            }

            inline void __close(){
                __chk_syscall(munmap(__buf_beg, __stdin_stat.st_size), -1);
            }

            // [no_check_eof_t] [peek_t] read char
            inline void __do(no_check_eof_t, char &c){
                c = *__buf_ptr++;
            }
            inline void __do(no_check_eof_t, peek_t, char &c){
                c = *__buf_ptr;
            }
            inline void __do(char &c){
                if (unexpect(__buf_ptr == __buf_end))c = EOF;
                else __do(no_check_eof, c);
            }
            inline void __do(peek_t, char &c){
                if (unexpect(__buf_ptr == __buf_end))c = EOF;
                else __do(no_check_eof, peek, c);
            }

            // ignore spaces
            inline void __do(no_check_eof_t){
                while (std::isspace(*__buf_ptr))++__buf_ptr;
            }
            inline void __do(){
                while (expect(__buf_ptr != __buf_end) && std::isspace(*__buf_ptr))++__buf_ptr;
            }

            #if defined(__GNUC__)
            typedef char char2 __attribute__((vector_size(2)));

            // [no_check_eof_t] [peek_t] read 2 char
            inline void __do(no_check_eof_t, char2 &c2){
                c2 = char2{__buf_ptr[0], __buf_ptr[1]};
                __buf_ptr += 2;
            }
            inline void __do(no_check_eof_t, peek_t, char2 &c2){
                c2 = char2{__buf_ptr[0], __buf_ptr[1]};
            }
            inline void __do(char2 &c2){
                if (unexpect(__buf_ptr == __buf_end))c2 = char2{EOF, EOF};
                else if (unexpect(__buf_ptr == __buf_end - 1))__do(no_check_eof, c2[0]), c2[1] = EOF;
                else __do(no_check_eof, c2);
            }
            inline void __do(peek_t, char2 &c2){
                if (unexpect(__buf_ptr == __buf_end))c2 = char2{EOF, EOF};
                else if (unexpect(__buf_ptr == __buf_end - 1))__do(no_check_eof, peek, c2[0]), c2[1] = EOF;
                else __do(no_check_eof, peek, c2);
            }
            #endif

            #ifdef eloi_strict
            #define __Ps x = std::uintptr_t(__buf_ptr) & 1? *__buf_ptr++ & 15 : 0;
            #else
            #define __Ps x = 0;
            #endif//start
            #define __Po int v; if (v = __fetch_2_to_int(__buf_ptr), expect(~v))//out
            #define __Pe if (x = x * 100 + v, v = __fetch_2_to_int(__buf_ptr += 2), expect(~v))//expect
            #define __Pb if (x = x * 100 + v, v = __fetch_2_to_int(__buf_ptr += 2), bool(~v))//bool
            #define __Pi x = x * 100 + v, __buf_ptr += 2;//in
            #define __Pf if (std::isdigit(*__buf_ptr))x = x * 10 + (*__buf_ptr++ & 15);//finish

            template <typename _Tp>
                inline void __i8_like_help(_Tp &x){ // [u]int8
                    __Ps __Po
                    __Pi // max width = 3
                    __Pf
                }
            template <typename _Tp>
                inline void __i16_like_help(_Tp &x){ // [u]int16
                    __Ps __Po
                    __Pb __Pi // max width = 5
                    __Pf
                }
            template <typename _Tp>
                inline void __i32_like_help(_Tp &x){ // [u]int32
                    __Ps __Po
                    __Pe __Pe __Pb __Pb __Pi // max width = 10
                    __Pf
                }
            template <typename _Tp>
                inline void __s64_like_help(_Tp &x){ // uint64
                    __Ps __Po
                    __Pe __Pe __Pe __Pe __Pb __Pb __Pb __Pb __Pi // max width = 19
                    __Pf
                }
            template <typename _Tp>
                inline void __u64_like_help(_Tp &x){ // uint64
                    __Ps __Po
                    __Pe __Pe __Pe __Pe __Pb __Pb __Pb __Pb __Pb __Pi // max width = 20
                    __Pf
                }
            template <typename _Tp>
                inline void __i128_like_help(_Tp &x){ // [u]int128
                    __Ps __Po
                    __Pe __Pe __Pe __Pe __Pe __Pe __Pe __Pe\
                        __Pb __Pb __Pb __Pb __Pb __Pb __Pb __Pb __Pb __Pb __Pi // max width = 39
                    __Pf
                }

            #undef __Ps
            #undef __Po
            #undef __Pe
            #undef __Pb
            #undef __Pi
            #undef __Pf

            #define __def(sT, uT, spf, upf)\
                inline void __do(no_check_eof_t, no_check_prefix_space_t, no_check_positive_t, no_check_sintmin_t, sT &x){\
                    bool ng = *__buf_ptr == '-'? ++__buf_ptr, true : false;\
                    __##spf##_like_help(x);\
                    if (ng)x = -x;\
                }\
                inline void __do(no_check_eof_t, no_check_prefix_space_t, no_check_positive_t, uT &x){\
                    __##upf##_like_help(x);\
                }\
                inline void __do(no_check_eof_t, no_check_prefix_space_t, no_check_sintmin_t, sT &x){\
                    bool ng = *__buf_ptr == '+'? ++__buf_ptr, false : *__buf_ptr == '-'? ++__buf_ptr, true : false;\
                    __##spf##_like_help(x);\
                    if (ng)x = -x;\
                }\
                inline void __do(no_check_eof_t, no_check_prefix_space_t, uT &x){\
                    if (*__buf_ptr == '+')++__buf_ptr;\
                    __##upf##_like_help(x);\
                }\
                inline void __do(no_check_eof_t, no_check_positive_t, no_check_sintmin_t, sT &x){\
                    __do(no_check_eof);\
                    bool ng = *__buf_ptr == '-'? ++__buf_ptr, true : false;\
                    __##spf##_like_help(x);\
                    if (ng)x = -x;\
                }\
                inline void __do(no_check_eof_t, no_check_positive_t, uT &x){\
                    __do(no_check_eof);\
                    __##upf##_like_help(x);\
                }\
                inline void __do(no_check_eof_t, no_check_sintmin_t, sT &x){\
                    __do(no_check_eof);\
                    bool ng = *__buf_ptr == '+'? ++__buf_ptr, false : *__buf_ptr == '-'? ++__buf_ptr, true : false;\
                    __##spf##_like_help(x);\
                    if (ng)x = -x;\
                }\
                inline void __do(no_check_eof_t, uT &x){\
                    __do(no_check_eof);\
                    if (*__buf_ptr == '+')++__buf_ptr;\
                    __##upf##_like_help(x);\
                }

            // __def(signed char, unsigned char, i8, i8)

            #if __SHRT_WIDTH__ == 16
            __def(short, unsigned short, i16, i16)
            #elif __SHRT_WIDTH__ == 32
            __def(short, unsigned short, i32, i32)
            #elif __SHRT_WIDTH__ == 64
            __def(short, unsigned short, s64, u64)
            #endif

            #if __INT_WIDTH__ == 16
            __def(int, unsigned, i16, i16)
            #elif __INT_WIDTH__ == 32
            __def(int, unsigned, i32, i32)
            #elif __INT_WIDTH__ == 64
            __def(int, unsigned, s64, u64)
            #endif

            #if __LONG_LONG_WIDTH__ == 16
            __def(long long, unsigned long long, i16, i16)
            #elif __LONG_LONG_WIDTH__ == 32
            __def(long long, unsigned long long, i32, i32)
            #elif __LONG_LONG_WIDTH__ == 64
            __def(long long, unsigned long long, s64, u64)
            #endif

            #ifndef eloi_strict
            # ifdef __SIZEOF_INT128__
            __def(__int128, __uint128_t, i128, i128)
            # endif
            #endif

            #undef __def

        public:
            inline stdinput_file(){
                __open();
            }
            inline stdinput_file(const char *inputfile){
                std::freopen(inputfile, "r", stdin);
                __open();
            }
            inline ~stdinput_file(){
                __close();
            }

            template <typename... Args>
                inline stdinput_file& operator () (Args&&... arg){
                    __do(std::forward<Args>(arg)...);
                    return *this;
                }

    };

    /*
    e.g.
    stdinput_file in("file.in");
    int x, y;
    in(x)(y);
    */

} } // namespace ELOI::io

#endif // __linux__

#endif


#include <bits/stdc++.h>
using namespace std;
int n, m, rt;
vector<int> e[200010];
int f[200010], sz[200010];
void dfs(int u, int fa){
    f[u] = fa; sz[u] = 1;
    if (fa)e[u].erase(find(e[u].begin(), e[u].end(), fa));
    for (int v : e[u])dfs(v, u), sz[u] += sz[v];
    sort(e[u].begin(), e[u].end(), [](int u, int v){return sz[u] > sz[v];});
}
int dfl[200010], dfr[200010], tot, rk[200010];
void dfs2(int u){
    rk[dfl[u] = ++tot] = u;
    for (int v : e[u])dfs2(v);
    dfr[u] = tot;
}
inline long long sq(int x){
    return 1ll * x * x;
}

vector<tuple<int, int, int> > V[200010];
namespace pirq { // point increase range query
    int s[200010], s2[200000 >> 9 | 10];
    inline void ad(int p){
        for (int i = p >> 9 << 9; i <= p; ++i)++s[i];
        for (int i = 0; i < p >> 9; ++i)++s2[i];
    }
    inline int qr(int p){
        return s[p] + s2[p >> 9];
    }
    inline int qr(int l, int r){
        return qr(l) - qr(r + 1);
    }
}

long long rs[200010];
int main(){
    freopen("rplexq.in", "r", stdin);
    freopen("rplexq.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ELOI::io::stdinput_file fin;
    #define RD ELOI::io::no_check_eof, ELOI::io::no_check_positive, ELOI::io::no_check_sintmin
    fin(RD, n)(RD, m)(RD, rt);
    for (int i = 1, u, v; i < n; ++i){
        fin(RD, u)(RD, v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(rt, 0);
    dfs2(rt);
    int S = max(1, min(n, (int)pow(n, 1. / 3.)));// 3 for fastest
    for (int i = 1, l, r, x; i <= m; ++i){
        fin(RD, l)(RD, r)(RD, x);
        V[x].emplace_back(l, r, i);
    }

    static int pst[200010];
    static vector<tuple<int, int, int, int> > qr[200010];
    static int pst2[200010];
    static vector<int>::iterator J[200010];
    static vector<int>::const_iterator Ep[200010];
    static vector<tuple<int, int, int> > qrp[200010];
    static vector<tuple<int, int, int> > qrs[200010];
    for (int i = 1; i <= n; ++i)
        for (auto [l, r, id] : V[i]){
            qr[dfl[i] - 1].emplace_back(l, r, -1, id);//storage at pst[id]
            qr[dfr[i]].emplace_back(l, r, 1, id);//eval with value storage at pst[id]
            if (e[i].empty())continue;
            J[id] = e[i].begin();
            Ep[id] = e[i].cbegin() + min<int>(e[i].size(), S);
            qrp[dfl[*J[id]]].emplace_back(l, r, id);//storage at pst2[id]
            qrs[dfr[*J[id]]].emplace_back(l, r, id);//eval with value storage at pst2[id]
            ++J[id];
        }
    for (int i = 1; i <= n; ++i){
        for (auto [l, r, id] : qrp[i])
            pst2[id] = pirq::qr(l, r);
        pirq::ad(rk[i]);
        for (auto [l, r, m, id] : qr[i]){
            int x = pirq::qr(l, r);
            if (m == -1)pst[id] = x;
            else rs[id] += sq(x - pst[id]);
        }
        for (auto [l, r, id] : qrs[i]){
            int x = pirq::qr(l, r);
            rs[id] -= sq(x - pst2[id]);
            if (J[id] != Ep[id]){
                qrp[dfl[*J[id]]].emplace_back(l, r, id);//storage at pst2[id]
                qrs[dfr[*J[id]]].emplace_back(l, r, id);//eval with value storage at pst2[id]
                ++J[id];
            }
        }
        using T = vector<tuple<int, int, int> >;
        T{}.swap(qrp[i]); T{}.swap(qrs[i]);
    }

    for (int u = 1; u <= n; ++u)if (e[u].size() > S){
        static int cl[200010];//color
        int mxc = e[u].size() - S;//max color
        vector<int> p;
        for (int i = S, _ = e[u].size(); i < _; ++i)
            for (int d = dfl[e[u][i]]; d <= dfr[e[u][i]]; ++d)
                cl[rk[d]] = i - S + 1, p.emplace_back(rk[d]);
        sort(p.begin(), p.end());
        int nn = p.size();
        static int v[200010];
        for (int i = 1; i <= nn; ++i)v[i] = cl[p[i - 1]];
        static int lp[200010], rp[200010];
        vector<int> qry;
        for (auto [l, r, id] : V[u]){
            lp[id] = lower_bound(p.begin(), p.end(), l) - p.begin() + 1;
            rp[id] = upper_bound(p.begin(), p.end(), r) - p.begin();
            if (l <= r)qry.emplace_back(id);
        }
        if (qry.empty())continue;
        int S = nn / sqrt(qry.size()) + 1;
        sort(qry.begin(), qry.end(), [&](int u, int v){
            return lp[u] / S == lp[v] / S? lp[u] / S & 1? rp[u] < rp[v] : rp[u] > rp[v] : lp[u] < lp[v];
        });
        static int ct[200010];
        fill_n(ct + 1, mxc, 0);
        int l = 1, r = 0;
        long long cc = 0;
        auto ins = [&](int p){cc += ct[v[p]]++ << 1 | 1;};
        auto del = [&](int p){cc -= --ct[v[p]] << 1 | 1;};
        for (int u : qry){
            while (r < rp[u])ins(++r);
            while (l > lp[u])ins(--l);
            while (r > rp[u])del(r--);
            while (l < lp[u])del(l++);
            rs[u] -= cc;
        }
    }

    for (int i = 1; i <= m; ++i)cout << (rs[i] >> 1) << "\n";
    return 0;
}
/*
10 1 7
4 2
10 4
3 2
6 10
9 2
7 3
1 4
8 2
5 3
3 10 2
*/