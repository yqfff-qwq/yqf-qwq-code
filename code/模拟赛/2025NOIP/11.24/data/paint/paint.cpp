#ifndef ELOI_io_stdinput_cpp
#define ELOI_io_stdinput_cpp

#ifndef ELOI_config_cpp
#define ELOI_config_cpp

#define eloi_use_exception
#define eloi_fast // maybe more memory, maybe UB

#if defined(eloi_strict) // used for compiler arguments : -Deloi_strict=0 -pedantic
# if eloi_strict == 0
#  undef eloi_strict
# endif
#else
# define eloi_strict // -pedantic, mutable here
#endif

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
# include <algorithm> // for `std::copy_n`

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

            // read string
            inline void __do(no_check_eof_t, int c, char *dst){
                std::copy_n(__buf_ptr, c, dst);
                __buf_ptr += c;
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

            #ifdef eloi_fast
            #define __Ps x = std::uintptr_t(__buf_ptr) & 1? *__buf_ptr++ & 15 : 0;// aligned
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
            static_assert(0);
            # endif
            #endif

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
int n, m, q;
char c[4010][4010];
int cx[4010][4010], cy[4010][4010];
short kx[4010 * 4010], ky[4010 * 4010];//kp pos of block
int ck[4010][4010];
//sp(i,j) : space of (i+.5,j+.5)
struct {
    bool L : 1;
    bool R : 1;
    bool U : 1;
    bool D : 1;
} mv[4010][4010];//if space can mov
bitset<4010> vs[4010];
int tt, bt[4010][4010];
void bfs(int i, int j){
    int *const xm = *cx, *const ym = *cy, hd, tl;
    hd = tl = 1;
    vs[i][j] = 1; bt[xm[tl] = i][ym[tl] = j] = tt;
    while (hd <= tl){
        int i = xm[hd], j = ym[hd++];
        auto ck = [&](int x, int y){
            if (~(x | (n - x) | y | (m - y)) >> 31)if (!vs[x][y])
                vs[x][y] = 1, ++tl, bt[xm[tl] = x][ym[tl] = y] = tt;
        };
        if (mv[i][j].L)ck(i, j - 1);
        if (mv[i][j].R)ck(i, j + 1);
        if (mv[i][j].U)ck(i - 1, j);
        if (mv[i][j].D)ck(i + 1, j);
    }
}
bitset<4010 * 4010> tg;
int bku[4010 * 4010];
int main(){
    ELOI::io::stdinput_file fin("paint.in");
    // freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #define RD ELOI::io::no_check_eof, ELOI::io::no_check_positive, ELOI::io::no_check_sintmin
    #define RC ELOI::io::no_check_eof
    fin(RD, n)(RD, m)(RD, q);
    // cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        // for (int j = 1; j <= m; ++j)
        //     cin >> c[i][j];
        fin(RC)(RC, m, c[i] + 1);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j){
            mv[i][j].L = c[i][j] != c[i + 1][j];
            mv[i][j].R = c[i][j + 1] != c[i + 1][j + 1];
            mv[i][j].U = c[i][j] != c[i][j + 1];
            mv[i][j].D = c[i + 1][j] != c[i + 1][j + 1];
        }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j){
            ck[i][j] = (i? ck[i - 1][j] : 0) + (j? ck[i][j - 1] : 0) - (i && j? ck[i - 1][j - 1] : 0);
            if (!vs[i][j])++tt, kx[tt] = i, ky[tt] = j, bfs(i, j), ++ck[i][j];
        }
    for (int i = 0; i <= n; ++i)cx[i][0] = cy[i][0] = 0;
    for (int j = 0; j <= m; ++j)cx[0][j] = cy[0][j] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            cx[i][j] = cx[i - 1][j] + cx[i][j - 1] - cx[i - 1][j - 1] + (c[i][j] == c[i - 1][j]);
            cy[i][j] = cy[i - 1][j] + cy[i][j - 1] - cy[i - 1][j - 1] + (c[i][j] == c[i][j - 1]);
        }
    while (q--){
        int xl, xr, yl, yr;
        fin(RD, xl)(RD, yl)(RD, xr)(RD, yr);
        // cin >> xl >> yl >> xr >> yr;
        int V = (xr - xl + 1) * (yr - yl + 1);
        V -= cx[xr][yr] - cx[xl][yr] - cx[xr][yl - 1] + cx[xl][yl - 1];
        V -= cy[xr][yr] - cy[xl - 1][yr] - cy[xr][yl] + cy[xl - 1][yl];
        V += ck[xr - 1][yr - 1] - ck[xl - 1][yr - 1] - ck[xr - 1][yl - 1] + ck[xl - 1][yl - 1];
        int tp = 0;
        auto ck = [&](int id){
            if ((~((kx[id] - xl) | (ky[id] - yl)) & (kx[id] - xr) & (ky[id] - yr)) >> 31)
                if (!tg[id])--V, tg[id] = 1, bku[++tp] = id;
        };
        for (int i = xl; i < xr; ++i){
            if (mv[i][yl].L)ck(bt[i][yl]);
            if (mv[i][yr].L)ck(bt[i][yr]);
        }
        for (int i = yl; i < yr; ++i){
            if (mv[xl][i].U)ck(bt[xl][i]);
            if (mv[xr][i].U)ck(bt[xr][i]);
        }
        cout << V << "\n";
        for (int i = 1; i <= tp; ++i)tg[bku[i]] = 0;
    }
    return 0;
}