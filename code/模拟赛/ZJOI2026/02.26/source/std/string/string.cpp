//utf-8  c++14
#include <cstdint>
#include <type_traits>
#include <limits>
#include <iterator>
#include <numeric>
#include <functional>
#include <iostream>
#include <random>
#include <algorithm>

namespace modint_nm {

    using u32 = std::uint32_t;
    using u64 = std::uint64_t;
    using umx = std::uintmax_t;
    using i32 = std::int32_t;
    using imx = std::intmax_t;

    // for primitive root
    inline constexpr u32 gcd(u32 a, u32 b) noexcept {while (b){u32 t = a % b;a = b; b = t;}return a;}
    inline constexpr u32 phi(u32 n) noexcept {
        u32 ph = n;
        for (u32 i = 2; u64(i) * i <= n; ++i)if (n % i == 0u){ph = ph / i * (i - 1);while (n % i == 0u)n /= i;}
        return n > 1? ph / n * (n - 1) : ph;
    }
    inline constexpr bool is_prime(u32 v) noexcept {if (v <= 1)return 0;for (u32 i = 2; u64(i) * i <= v; ++i)if (v % i == 0)return 0;return 1;}

    template <u32 mod, typename type, typename = void> struct modval_t
        { static inline constexpr u32 modval(type v) noexcept { return v % mod; } };
    template <u32 mod, typename type> struct modval_t <mod, type, std::enable_if_t<std::is_unsigned<type>::value> >
        { static inline constexpr u32 modval(type v) noexcept { return v % mod; } };
    template <u32 mod, typename type> struct modval_t <mod, type, std::enable_if_t<std::is_signed<type>::value> >
        { static inline constexpr u32 modval(type v) noexcept { v %= i32(mod);return v < 0? v + mod : v; } };
    template <u32 mod, typename type> struct modval_t <mod, type, std::enable_if_t<std::is_floating_point<type>::value> >
        { static inline constexpr u32 modval(type v) noexcept { return modval_t<mod, imx>::modval(imx(v)); } };
    template <u32 mod> struct modval_t <mod, __int128_t>
        { static inline constexpr u32 modval(__int128_t v) noexcept { v %= i32(mod);return v < 0? v + mod : v; } };
    template <u32 mod> struct modval_t <mod, __uint128_t>
        { static inline constexpr u32 modval(__uint128_t v) noexcept { return v % mod; } };

    template <u32 mod> inline constexpr auto modsplus(u32 &a, u32 b) noexcept
        -> std::enable_if_t<(std::numeric_limits<u32>::max() / 2 + 1 < mod), void> { if (a >= mod - b)a -= mod - b;else a += b; }
    template <u32 mod> inline constexpr auto modsplus(u32 &a, u32 b) noexcept
        -> std::enable_if_t<std::numeric_limits<u32>::max() / 2 + 1 >= mod, void> { a += b;if (a >= mod)a -= mod; }
    template <u32 mod> inline constexpr auto modplus(u32 a, u32 b) noexcept
        -> std::enable_if_t<(std::numeric_limits<u32>::max() / 2 + 1 < mod), u32> { return a >= mod - b? a - (mod - b) : a + b; }
    template <u32 mod> inline constexpr auto modplus(u32 a, u32 b) noexcept
        -> std::enable_if_t<std::numeric_limits<u32>::max() / 2 + 1 >= mod, u32> { a += b;return a >= mod? a - mod : a; }

    template <u32 mod> inline constexpr void modssubt(u32 &a, u32 b) noexcept { if (a < b)a += mod - b; else a -= b; }
    template <u32 mod> inline constexpr u32 modsubt(u32 a, u32 b) noexcept { return a < b? a + (mod - b) : a - b; }

    // template <u32 mod> inline constexpr u32 modmult(u32 a, u32 b) noexcept { return u64(a) * b % mod; }
    template <u32 mod> inline constexpr auto modmult(u32 a, u32 b) noexcept
        -> std::enable_if_t<(u64(mod - 1) * (mod - 1) <= u32(-1)), u32> { return a * b % mod; }
    template <u32 mod> inline constexpr auto modmult(u32 a, u32 b) noexcept
        -> std::enable_if_t<(u64(mod - 1) * (mod - 1) > u32(-1)), u32> { return u64(a) * b % mod; }
    template <u32 mod> inline constexpr void modsmult(u32 &a, u32 b) noexcept { a = modmult<mod>(a, b); }

    template <u32 mod> inline constexpr u32 modfpow(u32 a, umx b) noexcept
        { u32 ret = 1;for (; b; b >>= 1, a = modmult<mod>(a, a))if (b & 1)ret = modmult<mod>(ret, a);return ret; }
    template <u32 mod> inline constexpr void modsfpow(u32 &a, umx b) noexcept { a = modfpow<mod>(a, b); }

    // 假定值在模范围内，减少一次取模操作
    struct in_mod_range_t { } in_mod_range;

    struct modint_tag { };

    template <u32> struct modint;

    template <u32 mod, typename _T>
        inline constexpr std::enable_if_t<(mod > 2 && is_prime(mod)) &&
                std::is_convertible<_T, modint<mod - 1> >::value, modint<mod> >
            operator ^ (modint<mod> a, _T b) noexcept;
    template <u32 mod, typename _T>
        inline constexpr std::enable_if_t<!(mod > 2 && is_prime(mod)) && std::is_unsigned<_T>::value, modint<mod> >
            operator ^ (modint<mod> a, _T b) noexcept;
    template <u32 mod, typename _T>
        inline constexpr std::enable_if_t<!(mod > 2 && is_prime(mod)) && std::is_signed<_T>::value, modint<mod> >
            operator ^ (modint<mod> a, _T b) noexcept;

    template <u32 mod_>
        struct modint {
            typedef modint_tag is_modint_t;
            static constexpr u32 mod = mod_;
            static constexpr bool mod_is_prime = is_prime(mod);
            u32 val;
            inline constexpr modint() noexcept : val() { }
            template <typename Val_t> inline constexpr modint(Val_t Val) noexcept : val(modval_t<mod, Val_t>::modval(Val)) {}
            inline constexpr modint(const modint &) noexcept = default;
            inline constexpr modint(modint &&) noexcept = default;
            inline constexpr modint(in_mod_range_t, u32 v) noexcept : val{v} {}
            template <typename Val_t> inline constexpr modint &operator = (Val_t Val) noexcept
                { val = modval_t<mod, Val_t>::modval(Val);return *this; }
            inline constexpr modint &operator = (const modint &) noexcept = default;
            inline constexpr modint &operator = (modint &&) noexcept = default;
            inline constexpr modint &operator += (modint o) noexcept { modsplus<mod>(val, o.val);return *this; }
            inline constexpr modint &operator -= (modint o) noexcept { modssubt<mod>(val, o.val);return *this; }
            inline constexpr modint &operator *= (modint o) noexcept { modsmult<mod>(val, o.val);return *this; }
            template <typename _T>
                inline constexpr std::enable_if_t<(mod > 2 && mod_is_prime) &&
                        std::is_convertible<_T, modint<mod - 1> >::value, modint&> operator ^= (_T o) noexcept
                    { modsfpow<mod>(val, modint<mod - 1>(o).value());return *this; }
            template <typename _T>
                inline constexpr std::enable_if_t<!(mod > 2 && mod_is_prime) &&
                    std::is_unsigned<_T>::value, modint&> operator ^= (_T b) noexcept {
                        constexpr u32 p = phi(mod);
                        modsfpow<mod>(val, b < p? b : b % p + p);
                        return *this;
                    }
            template <typename _T>
                inline constexpr std::enable_if_t<!(mod > 2 && mod_is_prime) &&
                    std::is_signed<_T>::value, modint&> operator ^= (_T b) noexcept {
                        constexpr u32 p = phi(mod);
                        if (b >= 0)modsfpow<mod>(val, b < p? b : b % p + p);
                        else {
                            b = -b;
                            umx T = umx(b < p? b : b % p + p) * (p - 1);
                            modsfpow<mod>(val, T < p? T : T % p + p);
                        }
                        return *this;
                    }
            inline constexpr modint &operator ++ () noexcept {if (__builtin_expect(++val == mod, false))val = 0;return *this;}
            inline constexpr modint operator ++ (int) noexcept {auto R = *this;if (__builtin_expect(++val == mod, false))val = 0;return R;}
            inline constexpr modint &operator -- () noexcept {if (__builtin_expect(--val == u32(-1), false))val = mod - 1;return *this;}
            inline constexpr modint operator -- (int) noexcept {auto R = *this;if (__builtin_expect(--val == u32(-1), false))val = mod - 1;return R;}
            inline constexpr modint operator - () const noexcept { return modint(in_mod_range, val? mod - val : 0u); }
            inline constexpr modint inv() const noexcept { return (*this) ^ (phi_mod - 1); }
            inline constexpr modint &operator /= (modint o) noexcept { modsmult<mod>(val, o.inv().val);return *this; }
            inline constexpr u32 value() const noexcept { return val; }
            inline constexpr operator u32 () const noexcept { return val; }
            template <typename _Tp> inline constexpr operator _Tp () const noexcept { return (_Tp)val; }

            inline constexpr modint& plussubt(bool v, modint x) noexcept //+=(-1)^v*x
                { if (v)*this -= x; else *this += x; return *this; }
            template <typename _Tp, typename = std::enable_if_t<std::is_integral<_Tp>::value> >
                inline constexpr modint& plussubt(_Tp v, modint x) noexcept //+=(-1)^v*x
                    { if (v & 1)*this -= x; else *this += x; return *this; }

            static constexpr modint nan = modint(in_mod_range, mod);

            static constexpr u32 phi_mod = phi(mod);
            static inline constexpr bool is_qk(u32 n) noexcept {//n == q^k, q is prime, q != 2, k >= 1
                if (!(n & 1) || n <= 1)return false;
                for (u32 i = 2; u64(i) * i <= n; ++i)if (n % i == 0u){do {n /= i;} while (n % i == 0u);return n == 1;}
                return true;
            }
            static inline constexpr bool pr_exists() noexcept {if (mod == 2 || mod == 4)return true;return is_qk(mod & 1? mod : (mod >> 1));}
            static inline constexpr u32 min_pr() noexcept {//O(\log p)
                if (!pr_exists())return nan;
                if (mod == 2)return 1u;
                u32 ph = phi_mod, t = ph, fact[20]{}, cnt = 0u;
                for (u32 i = 2; u64(i) * i <= ph; ++i)if (ph % i == 0u){fact[cnt++] = t / i;while (ph % i == 0u)ph /= i;}
                if (ph > 1)fact[cnt++] = t / ph;
                for (u32 g = 1; ; ++g){
                    if (gcd(g, mod) ^ 1)continue;
                    bool fl = true;
                    for (u32 i = 0u; i < cnt; ++i)if ((modint(g) ^ fact[i]) == modint(1)){fl = false;break;}
                    if (fl)return g;
                }
            }

            static constexpr modint prmrt = min_pr();// 原根

        }; // __is_trivially_copyable(modint<...>) = true

    template <u32 mod>
        constexpr u32 modint<mod>::mod;
    template <u32 mod>
        constexpr modint<mod> modint<mod>::nan;
    template <u32 mod>
        constexpr bool modint<mod>::mod_is_prime;
    template <u32 mod>
        constexpr u32 modint<mod>::phi_mod;
    template <u32 mod>
        constexpr modint<mod> modint<mod>::prmrt;

    template <typename...> using __void_t = void;
    template <u32 mod, typename type> struct modval_t <mod, type,
            __void_t<std::enable_if_t<!std::is_arithmetic<type>::value>, decltype(type::operator modint<mod>()) > >
        { static inline constexpr u32 modval(type v) noexcept { return ((modint<mod>)v).value(); } };

    template <u32 mod> inline constexpr modint<mod> operator + (modint<mod> a, modint<mod> b) noexcept
        { return modint<mod>(in_mod_range, modplus<mod>(a.val, b.val)); }
    template <u32 mod, typename _T> inline constexpr modint<mod> operator + (_T a, modint<mod> b) noexcept { return modint<mod>(a) + b; }
    template <u32 mod, typename _T> inline constexpr modint<mod> operator + (modint<mod> a, _T b) noexcept { return a + modint<mod>(b); }

    template <u32 mod> inline constexpr modint<mod> operator - (modint<mod> a, modint<mod> b) noexcept
        { return modint<mod>(in_mod_range, modsubt<mod>(a.val, b.val)); }
    template <u32 mod, typename _T> inline constexpr modint<mod> operator - (_T a, modint<mod> b) noexcept { return modint<mod>(a) - b; }
    template <u32 mod, typename _T> inline constexpr modint<mod> operator - (modint<mod> a, _T b) noexcept { return a - modint<mod>(b); }

    template <u32 mod> inline constexpr modint<mod> operator * (modint<mod> a, modint<mod> b) noexcept
        { return modint<mod>(in_mod_range, modmult<mod>(a.val, b.val)); }
    template <u32 mod, typename _T> inline constexpr modint<mod> operator * (_T a, modint<mod> b) noexcept { return modint<mod>(a) * b; }
    template <u32 mod, typename _T> inline constexpr modint<mod> operator * (modint<mod> a, _T b) noexcept { return a * modint<mod>(b); }

    template <u32 mod> inline constexpr modint<mod> operator / (modint<mod> a, modint<mod> b) noexcept
        { return modint<mod>(in_mod_range, modmult<mod>(a.val, b.inv().val)); }
    template <u32 mod, typename _T> inline constexpr modint<mod> operator / (_T a, modint<mod> b) noexcept { return modint<mod>(a) / b; }
    template <u32 mod, typename _T> inline constexpr modint<mod> operator / (modint<mod> a, _T b) noexcept { return a / modint<mod>(b); }

    template <typename _Tp, typename = void> struct is_modint : std::false_type { };
    template <typename _Tp> struct is_modint <_Tp, typename _Tp::is_modint_t> : std::true_type { };

    template <u32 mod, typename _T>
        inline constexpr std::enable_if_t<(mod > 2 && is_prime(mod)) &&
                std::is_convertible<_T, modint<mod - 1> >::value, modint<mod> >
            operator ^ (modint<mod> a, _T b) noexcept
                { return modint<mod>(in_mod_range, modfpow<mod>(a.val, modint<mod - 1>(b).value())); }
    template <u32 mod, typename _T>
        inline constexpr std::enable_if_t<!(mod > 2 && is_prime(mod)) && std::is_unsigned<_T>::value, modint<mod> >
            operator ^ (modint<mod> a, _T b) noexcept
                { constexpr u32 p = phi(mod); return modint<mod>(in_mod_range, modfpow<mod>(a.val, b < p? b : b % p + p)); }
    template <u32 mod, typename _T>
        inline constexpr std::enable_if_t<!(mod > 2 && is_prime(mod)) && std::is_signed<_T>::value, modint<mod> >
            operator ^ (modint<mod> a, _T b) noexcept {
                constexpr u32 p = phi(mod);
                if (b >= 0)return modint<mod>(in_mod_range, modfpow<mod>(a.val, b < p? b : b % p + p));
                b = -b;
                umx T = umx(b < p? b : b % p + p) * (p - 1);
                return modint<mod>(in_mod_range, modfpow<mod>(a.val, T < p? T : T % p + p));
            }

    template <u32 mod> inline constexpr modint<mod> fma(modint<mod> a, modint<mod> b, modint<mod> c) noexcept
        { return modint<mod>(in_mod_range, (u64(a.val) * b.val + c.val) % mod); }
    template <u32 mod> inline constexpr modint<mod> fma(modint<mod> a, modint<mod> b, u32 c) noexcept
        { return modint<mod>(in_mod_range, (u64(a.val) * b.val + c) % mod); }
    template <u32 mod> inline constexpr modint<mod> fma(in_mod_range_t, modint<mod> a, modint<mod> b, u64 c) noexcept//assume c + (mod-1)^2 < u64 max
        { return modint<mod>(in_mod_range, (u64(a.val) * b.val + c) % mod); }

    template <u32 mod> inline constexpr modint<mod> fmam(modint<mod> a, modint<mod> b, modint<mod> c, modint<mod> d) noexcept
        { return modint<mod>(in_mod_range, (u64(a.val) * b.val + u64(c.val) * d.val) % mod); }

    template <u32 mod> inline constexpr modint<mod> fms(modint<mod> a, modint<mod> b, modint<mod> c) noexcept
        { return modint<mod>(in_mod_range, (u64(a.val) * b.val + mod - c.val) % mod); }

    template <u32 mod> inline constexpr modint<mod> fmsm(modint<mod> a, modint<mod> b, modint<mod> c, modint<mod> d) noexcept
        { constexpr u64 mm = u64(mod) * mod;return modint<mod>(in_mod_range, (u64(a.val) * b.val + mm - u64(c.val) * d.val) % mod); }

    template <u32 mod> // a += b * c
        inline constexpr void splusmult(modint<mod> &a, modint<mod> b, modint<mod> c) noexcept { a = fma(b, c, a); }

    template <u32 mod> struct modint_partial_order
        { inline constexpr bool operator () (modint<mod> a, modint<mod> b) const noexcept { return a.val < b.val; } };// 偏序关系

    template <u32 mod> inline constexpr bool operator == (modint<mod> a, modint<mod> b) noexcept { return a.val == b.val; }
    template <u32 mod, typename _T> inline constexpr bool operator == (_T a, modint<mod> b) noexcept { return modint<mod>(a) == b; }
    template <u32 mod, typename _T> inline constexpr bool operator == (modint<mod> a, _T b) noexcept { return a == modint<mod>(b); }
    template <u32 mod> inline constexpr bool operator != (modint<mod> a, modint<mod> b) noexcept { return a.val != b.val; }
    template <u32 mod, typename _T> inline constexpr bool operator != (_T a, modint<mod> b) noexcept { return modint<mod>(a) != b; }
    template <u32 mod, typename _T> inline constexpr bool operator != (modint<mod> a, _T b) noexcept { return a != modint<mod>(b); }

    template <typename iter_t>
        using is_modint_iter = std::enable_if_t<std::is_base_of<std::random_access_iterator_tag,
            typename std::iterator_traits<iter_t>::iterator_category>::value, typename std::iterator_traits<iter_t>::value_type::is_modint_t>;

    template <typename iter_t, typename = is_modint_iter<iter_t> >
        constexpr void calc_inv(u32 n, iter_t iv){//let iv_i = i^{-1}, 1<=i<n
            if (n == 0)return;
            constexpr u32 mod = std::iterator_traits<iter_t>::value_type::mod;
            iv[1] = 1;
            for (u32 i = 2; i < n; ++i)iv[i] = iv[mod % i] * modint<mod>(in_mod_range, mod - mod / i);
        }

    template <typename iter_t, typename = is_modint_iter<iter_t> >
        constexpr void calc_fact(u32 n, iter_t fc){//let fc_i = i!, 0<=i<n
            if (n == 0)return;
            *fc = 1;
            for (u32 i = 1; i < n; ++i)fc[i] = fc[i - 1] * i;
        }

    template <typename iter_t, typename = is_modint_iter<iter_t> >
        constexpr void calc_factinv(u32 n, iter_t ivfc){//let ivfc_i = 1/i!, 0<=i<n
            if (n == 0)return;
            calc_inv(n, ivfc);
            ivfc[0] = 1;
            for (u32 i = 1; i < n; ++i)ivfc[i] *= ivfc[i - 1];
        }

    template <typename iter_t, typename = is_modint_iter<iter_t>, u32 mod = std::iterator_traits<iter_t>::value_type::mod>
        constexpr void calc_power(u32 n, iter_t pw, modint<mod> b){//let pw_i=b^i, 0<=i<n
            if (n == 0)return;
            pw[0] = 1;
            for (u32 i = 1; i < n; ++i)pw[i] = pw[i - 1] * b;
        }

    template <typename iter_t, typename = is_modint_iter<iter_t>, u32 mod = std::iterator_traits<iter_t>::value_type::mod>
        constexpr void sieve_power(u32 n, iter_t pw, u32 e){//let pw_i=i^e, 0<=i<n
            if (n == 0)return;
            if (n == 1){
                pw[0] = 0;
                return;
            }
            bool *npr = new bool[n]{};
            u32 *prm = new u32[n <= 100? n - (n / 2) + 1 : 2 * n / std::__lg(n)]{};
            u32 l = 0;
            pw[0] = 0;
            pw[1] = 1;
            for (u32 i = 2; i < n; ++i){
                if (!npr[i]){
                    pw[i] = (modint<mod>(i) ^ e);
                    prm[l++] = i;
                }
                for (u32 j = 0; j < l; ++j){
                    if (u64(i) * prm[j] >= n)break;
                    npr[i * prm[j]] = 1;
                    pw[i * prm[j]] = pw[i] * pw[prm[j]];
                    if (i % prm[j] == 0)break;
                }
            }
            delete [] npr; delete [] prm;
        }

    template <typename iter_t, typename = is_modint_iter<iter_t> >
        constexpr void calc_inv(iter_t bg, iter_t ed){//let bg[i] = bg[i]^{-1}
            constexpr u32 mod = std::iterator_traits<iter_t>::value_type::mod;
            if (bg == ed)return;
            u32 n = ed - bg;
            modint<mod> *s = new modint<mod>[n + 1];
            modint<mod> *sv = new modint<mod>[n + 1];
            s[0] = 1;
            for (u32 i = 1; i <= n; ++i)s[i] = s[i - 1] * bg[i - 1];
            sv[n] = s[n].inv();
            for (u32 i = n; i; --i)sv[i - 1] = sv[i] * bg[i - 1];
            for (u32 i = 1; i <= n; ++i)bg[i - 1] = sv[i] * s[i - 1];
            delete []s; delete []sv;
        }

    template <u32 mod> inline constexpr bool isnan(modint<mod> a) noexcept { return a == modint<mod>::nan; }

    // 是否为二次剩余
    template <u32 mod> inline constexpr bool is_quad_residue(modint<mod> a) noexcept {return (a ^ ((mod - 1) >> 1)) == 1;}

    namespace __modint_help {
        template <u32 mod>
            struct mod_complex {
                modint<mod> real, imag;
                inline constexpr mod_complex(u32 R = 0, u32 I = 0) noexcept : real(R), imag(I) {}
                inline constexpr mod_complex(modint<mod> R, modint<mod> I = 0) noexcept : real(R), imag(I) {}
                inline constexpr mod_complex(const mod_complex &o) noexcept : real(o.real), imag(o.imag) {}
                inline constexpr mod_complex& operator = (const mod_complex &o) noexcept { real = o.real;imag = o.imag;return *this; }
            };
        template <u32 mod>
            inline constexpr mod_complex<mod> mult(mod_complex<mod> a, mod_complex<mod> b, modint<mod> i_2) noexcept
                { return mod_complex<mod>(fmam(a.imag * b.imag, i_2, a.real, b.real), fmam(a.real, b.imag, a.imag, b.real)); }
        template <u32 mod>
            inline constexpr mod_complex<mod> pow(mod_complex<mod> a, u64 b, modint<mod> i_2) noexcept
                { mod_complex<mod> ret(1);for (; b; b >>= 1, a = mult(a, a, i_2))if (b & 1)ret = mult(ret, a, i_2);return ret; }
    }

    template <u32 mod> inline constexpr modint<mod> sqrt(modint<mod> a) noexcept {
        if (a == modint<mod>(0))return 0;
        if (!is_quad_residue(a))return modint<mod>::nan;
        // if constexpr ((mod & 3) == 3)return a ^ ((mod + 1) >> 2);
        // else if constexpr ((mod & 7) == 5){//Atkin
        //     modint<mod> b = (a + a) ^ (mod >> 3);
        //     return a * b * (2 * a * b * b - 1);
        // }
        //Cipolla
        modint<mod> r = 0, i_2 = 0; u32 seed = 1u;
        do {r = (seed = u64(seed) * 16807UL % 2147483647UL);/*minstd_rand0*/} while (is_quad_residue(i_2 = r * r - a));
        modint<mod> x = __modint_help::pow(__modint_help::mod_complex<mod>(r, modint<mod>(1)), (mod + 1) >> 1, i_2).real;
        return x.val < mod - x.val? x : -x;
    }

    template <u32 mod>
        constexpr modint<mod> I_mod = sqrt(modint<mod>(-1));//i=sqrt(-1)

    // 加速求和
    template <u32 mod>
        struct accumulate_temporary_result {
            umx val;
            static constexpr umx limit = std::numeric_limits<umx>::max() - mod;
            static constexpr umx limit2 = std::numeric_limits<umx>::max() - umx(mod) * mod;
            inline constexpr accumulate_temporary_result() noexcept : val() {}
            inline constexpr accumulate_temporary_result(modint<mod> v) noexcept : val(v.value()) {}
            inline constexpr accumulate_temporary_result(umx v) noexcept : val(v) {}
            inline constexpr accumulate_temporary_result(const accumulate_temporary_result &r) noexcept : val(r.val) {}
            inline constexpr accumulate_temporary_result(const accumulate_temporary_result &&r) noexcept : val(r.val) {}
            #define ATR_check() if (__builtin_expect(val >= limit, false))val %= mod;
            #define ATR_check_2() if (__builtin_expect(val >= limit2, false))val %= mod;
            template <typename _Val> inline constexpr accumulate_temporary_result(_Val v) noexcept : val(modval_t<mod, _Val>::modval(v)) {}
            template <typename _Val> inline constexpr accumulate_temporary_result &operator += (umx v) noexcept
                { ATR_check(); val += modval_t<mod, _Val>::modval(v); return *this; }
            inline constexpr accumulate_temporary_result &operator += (modint<mod> v) noexcept
                { ATR_check(); val += v.value(); return *this; }
            inline constexpr void plus_modint_prod(modint<mod> a, modint<mod> b) noexcept
                { ATR_check_2(); val += umx(a.value()) * b.value(); }// += a * b
            inline constexpr umx value() const noexcept { return val; }
            inline constexpr modint<mod> mod_val() const noexcept { return modint<mod>(val); }
            inline constexpr operator modint<mod> () const noexcept { return modint<mod>(val); }
            #undef ATR_check
        };

    struct in_binom_range_t { } in_binom_range;

    template <u32 mod>
        struct binom_solver {
            private:
                u32 n;
                modint<mod> *fc, *ivfc;
            public:
                inline binom_solver() : n(0), fc(new modint<mod>[0]), ivfc(new modint<mod>[0]) {}
                inline binom_solver(u32 __n) : n(__n), fc(new modint<mod>[n]), ivfc(new modint<mod>[n])
                    { calc_fact(n, fc), calc_factinv(n, ivfc); }
                inline void build(u32 __n){
                    if (__n < n)return;
                    delete [] fc;delete [] ivfc;
                    n = __n, fc = new modint<mod>[n], ivfc = new modint<mod>[n];
                    calc_fact(n, fc), calc_factinv(n, ivfc);
                }
                inline ~binom_solver() { delete [] fc;delete [] ivfc; }
                inline modint<mod> factorial(u32 n) const noexcept //n!
                    { return fc[n]; }
                inline modint<mod> factorial_inverse(u32 n) const noexcept //1/n!
                    { return ivfc[n]; }

                inline modint<mod> combination(i32 n, i32 m) const noexcept //C(n,m)
                    { return ((n - m) | m) >> 31? modint<mod>() : fc[n] * ivfc[m] * ivfc[n - m]; }
                inline modint<mod> ivcombination(i32 n, i32 m) const noexcept //1/C(n,m)
                    { return ((n - m) | m) >> 31? modint<mod>::nan : ivfc[n] * fc[m] * fc[n - m]; }
                inline modint<mod> combination(in_binom_range_t, u32 n, u32 m) const noexcept //C(n,m)
                    { return fc[n] * ivfc[m] * ivfc[n - m]; }
                inline modint<mod> ivcombination(in_binom_range_t, u32 n, u32 m) const noexcept //1/C(n,m)
                    { return ivfc[n] * fc[m] * fc[n - m]; }

                inline modint<mod> permutation(i32 n, i32 m) const noexcept //P(n,m)
                    { return ((n - m) | m) >> 31? modint<mod>() : fc[n] * ivfc[n - m]; }
                inline modint<mod> ivpermutation(i32 n, i32 m) const noexcept //1/P(n,m)
                    { return ((n - m) | m) >> 31? modint<mod>::nan : ivfc[n] * fc[n - m]; }
                inline modint<mod> permutation(in_binom_range_t, u32 n, u32 m) const noexcept //P(n,m)
                    { return fc[n] * ivfc[n - m]; }
                inline modint<mod> ivpermutation(in_binom_range_t, u32 n, u32 m) const noexcept //1/P(n,m)
                    { return ivfc[n] * fc[n - m]; }

                inline modint<mod> grid(i32 n, i32 m) const noexcept //(0,0) -> (n,m)
                    { return (n | m) >> 31? modint<mod>() : fc[n + m] * ivfc[n] * ivfc[m]; }
                inline modint<mod> ivgrid(i32 n, i32 m) const noexcept //1/grid(n,m)
                    { return (n | m) >> 31? modint<mod>::nan : ivfc[n + m] * fc[n] * fc[m]; }
                inline modint<mod> grid(in_binom_range_t, u32 n, u32 m) const noexcept //(0,0) -> (n,m)
                    { return fc[n + m] * ivfc[n] * ivfc[m]; }
                inline modint<mod> ivgrid(in_binom_range_t, u32 n, u32 m) const noexcept //1/grid(n,m)
                    { return ivfc[n + m] * fc[n] * fc[m]; }

                inline modint<mod> lucas(imx n, imx m) const noexcept {
                    if ((n | m) >> 31)return modint<mod>();
                    modint<mod> ret = 1;
                    while (n | m){
                        u32 __n = n / mod, __m = m / mod; n /= mod, m /= mod;
                        if (__n < __m)return modint<mod>();
                        ret *= fc[__n] * ivfc[__m] * ivfc[__n - __m];
                    }
                    return ret;
                }
                inline modint<mod> lucas(umx n, umx m) const noexcept {
                    modint<mod> ret = 1;
                    while (n | m){
                        u32 __n = n / mod, __m = m / mod; n /= mod, m /= mod;
                        if (__n < __m)return modint<mod>();
                        ret *= fc[__n] * ivfc[__m] * ivfc[__n - __m];
                    }
                    return ret;
                }
        };

    template <u32 mod>
        struct combination : public binom_solver<mod> {
            inline combination() : binom_solver<mod>() { }
            inline combination(u32 n) : binom_solver<mod>(n) { }
            inline modint<mod> operator () (i32 n, i32 m) const noexcept //C(n,m)
                { return binom_solver<mod>::combination(n, m); }
            inline modint<mod> operator () (in_binom_range_t, u32 n, u32 m) const noexcept //C(n,m)
                { return binom_solver<mod>::combination(in_binom_range, n, m); }
            inline modint<mod> iv(i32 n, i32 m) const noexcept //1/C(n,m)
                { return binom_solver<mod>::ivcombination(n, m); }
            inline modint<mod> iv(in_binom_range_t, u32 n, u32 m) const noexcept //1/C(n,m)
                { return binom_solver<mod>::ivcombination(in_binom_range, n, m); }
        };

    template <u32 mod>
        struct permutation : public binom_solver<mod> {
            inline permutation() : binom_solver<mod>() { }
            inline permutation(u32 n) : binom_solver<mod>(n) { }
            inline modint<mod> operator () (i32 n, i32 m) const noexcept //C(n,m)
                { return binom_solver<mod>::permutation(n, m); }
            inline modint<mod> operator () (in_binom_range_t, u32 n, u32 m) const noexcept //C(n,m)
                { return binom_solver<mod>::permutation(in_binom_range, n, m); }
            inline modint<mod> iv(i32 n, i32 m) const noexcept //1/C(n,m)
                { return binom_solver<mod>::ivpermutation(n, m); }
            inline modint<mod> iv(in_binom_range_t, u32 n, u32 m) const noexcept //1/C(n,m)
                { return binom_solver<mod>::ivpermutation(in_binom_range, n, m); }
        };

    template <u32 mod>
        struct grid : public binom_solver<mod> {//grid(n,m) : (0,0) -> (n,m), count, =C(n+m,n)
            inline grid() : binom_solver<mod>() { }
            inline grid(u32 n) : binom_solver<mod>(n) { }
            inline modint<mod> operator () (i32 n, i32 m) const
                { return binom_solver<mod>::grid(n, m); }
            inline modint<mod> operator () (in_binom_range_t, u32 n, u32 m) const
                { return binom_solver<mod>::grid(in_binom_range, n, m); }
            inline modint<mod> iv(i32 n, i32 m) const
                { return binom_solver<mod>::ivgrid(n, m); }
            inline modint<mod> iv(in_binom_range_t, u32 n, u32 m) const
                { return binom_solver<mod>::ivgrid(in_binom_range, n, m); }
        };

    template <u32 mod>
        struct split : public binom_solver<mod> {//split(n,m) : m >= 0 int, sum = n, count
            inline split() : binom_solver<mod>() { }
            inline split(u32 n) : binom_solver<mod>(n) { }
            inline modint<mod> operator () (i32 n, i32 m) const
                { return !m? modint<mod>(!n) : binom_solver<mod>::combination(n + m - 1, m - 1); }
            inline modint<mod> operator () (in_binom_range_t, u32 n, u32 m) const
                { return !m? modint<mod>(1) : binom_solver<mod>::combination(in_binom_range, n + m - 1, m - 1); }
            inline modint<mod> iv(i32 n, i32 m) const
                { return !m? !n? modint<mod>(1) : modint<mod>::nan : binom_solver<mod>::ivcombination(n + m - 1, m - 1); }
            inline modint<mod> iv(in_binom_range_t, u32 n, u32 m) const
                { return !m? modint<mod>(1) : binom_solver<mod>::ivcombination(in_binom_range, n + m - 1, m - 1); }
        };

    // 多项相加优化
    template <typename iter_t, u32 mod = std::iterator_traits<iter_t>::value_type::mod>
        constexpr modint<mod> mod_plus(iter_t bg, iter_t ed){
            typedef modint<mod> type;
            typedef typename std::iterator_traits<iter_t>::value_type iter_type;
            u32 n = ed - bg;
            if (n < 4){
                switch (n){
                    case 0: return type();
                    case 1: return *bg;
                    case 2: return *bg + *(bg + 1);
                    case 3: return *bg + *(bg + 1) + *(bg + 2);
                    default : __builtin_unreachable();
                }
            }
            u64 sum = std::accumulate(bg, ed, u64(), [](u64 a, iter_type v){
                return a + type(v).value();
            });
            return type(sum);
        }

    // 多项相乘
    template <typename iter_t, u32 mod = std::iterator_traits<iter_t>::value_type::mod>
        constexpr modint<mod> mod_mult(iter_t bg, iter_t ed){
            typedef modint<mod> type;
            return std::accumulate(bg, ed, type(1), std::multiplies<type>{});
        }

    template <typename iter1_t, typename iter2_t,
            u32 mod = std::iterator_traits<iter1_t>::value_type::mod,
            u32 mod2 = std::iterator_traits<iter2_t>::value_type::mod,
            typename = std::enable_if_t<mod == mod2> >
        constexpr modint<mod> mod_inner_product(iter1_t bg1, iter1_t ed1, iter2_t bg2, modint<mod> init = 0){
            accumulate_temporary_result<mod> atr(init);
            for (; bg1 != ed1; ++bg1, ++bg2)
                atr.plus_modint_prod(*bg1, *bg2);
            return atr.mod_val();
        }

    inline namespace predefine_modint {
        using modp0 = modint<998244353>;
        using modp1 = modint<1000000007>;
        using modp2 = modint<167772161>;
        using modp3 = modint<469762049>;
        using modp4 = modint<754974721>;
        using modp5 = modint<1004535809>;
    }

}

#include <functional>

namespace std {

    using u32 = std::uint32_t;
    using u64 = std::uint64_t;
    using u128 = __uint128_t;

    template <u32 mod> ostream &operator << (ostream &os, modint_nm::modint<mod> v){ return os << v.value(); }
    template <u32 mod> istream &operator >> (istream &is, modint_nm::modint<mod> &v){ u64 x;is >> x;v = x;return is; }

    template <u32 mod>
        struct numeric_limits <modint_nm::modint<mod> > : numeric_limits<u32> { };

    template <u32 mod>
        struct hash<modint_nm::modint<mod> > {
            size_t operator () (const modint_nm::modint<mod> &v) const {
                return hash<u32>{}(v.value());
            }
        };

}

namespace u64modint_nm {

    using u64 = std::uint64_t;
    using u128 = __uint128_t;

    template <u64 mod> inline constexpr auto modplus(u64 a, u64 b) noexcept
        -> std::enable_if_t<(std::numeric_limits<u64>::max() / 2 + 1 < mod), u64> { return a >= mod - b? a - (mod - b) : a + b; }
    template <u64 mod> inline constexpr auto modplus(u64 a, u64 b) noexcept
        -> std::enable_if_t<std::numeric_limits<u64>::max() / 2 + 1 >= mod, u64> { a += b;return a >= mod? a - mod : a; }

    template <u64 mod> inline constexpr u64 modsubt(u64 a, u64 b) noexcept { return a > b? a - b : a + (mod - b); }

    template <u64 mod> inline constexpr auto modmult(u64 a, u64 b) noexcept
        -> std::enable_if_t<(std::numeric_limits<u64>::max() / 4 > mod), u64> {
            constexpr long double ivM = 1.L / mod;
            return {((a * b) - u64(a * ivM * b) * mod + mod) % mod}; // faster
        }
    template <u64 mod> inline constexpr auto modmult(u64 a, u64 b) noexcept
        -> std::enable_if_t<(std::numeric_limits<u64>::max() / 4 <= mod), u64> {
            return u128(a) * b % mod;
        }

}

#include <iterator>
#include <type_traits>
#include <vector>
#include <cstdint>

namespace sieve {

    using u32 = std::uint32_t;
    using i32 = std::int32_t;
    using u64 = std::uint64_t;

    template <typename _Iter>
        using enable_if_oi_t = std::enable_if_t<std::is_base_of<std::output_iterator_tag,
            typename std::iterator_traits<_Iter>::iterator_category>::value>;
    template <typename _Iter>
        using enable_if_fi_t = std::enable_if_t<std::is_base_of<std::forward_iterator_tag,
            typename std::iterator_traits<_Iter>::iterator_category>::value>;
    template <typename _Iter>
        using enable_if_rai_t = std::enable_if_t<std::is_base_of<std::random_access_iterator_tag,
            typename std::iterator_traits<_Iter>::iterator_category>::value>;
    template <typename _Iter, typename _Vt>
        using enable_if_vt_t = std::enable_if_t<std::is_same<_Vt,
            typename std::iterator_traits<_Iter>::value_type>::value>;

    template <typename _Iter, typename = enable_if_oi_t<_Iter> >
        void eratosthenes(u32 n, _Iter out){//primes
            if (n < 2)return;
            *out = 2; ++out;
            std::vector<bool> npr((n + 1) >> 1);
            for (u32 i = 3; i * i < n; i += 2)
                if (!npr[i >> 1])for (u32 j = i * i; j <= n; j += i + i)npr[j >> 1] = 1;
            for (u32 i = 3; i < n; i += 2)
                if (!npr[i >> 1]){ *out = i; ++out; }
        }

    template <typename _Iter, typename = enable_if_fi_t<_Iter> >
        void linear(u32 n, _Iter prm){
            _Iter bg = prm;
            std::vector<bool> npr(n);
            for (u32 i = 2; i < n; ++i){
                if (!npr[i]){
                    *prm = i;
                    ++prm;
                }
                for (_Iter _j = bg; _j != prm; ++_j){
                    u32 j = *_j;
                    if (i * j >= n)break;
                    npr[i * j] = 1;
                    if (i % j == 0)break;
                }
            }
        }

    template <typename _Gi, typename = enable_if_rai_t<_Gi> >
        void sieve(u32 n, _Gi g){
            // g_x : let x=\prod p^r (p_1<p_2<...<p_k), then g_x \gets p_1^{r_1}
            // g : value of  power of min prime factor
            g[1] = 1;
            std::vector<u32> prm;
            std::vector<bool> npr(n);
            for (u32 i = 2; i < n; ++i){
                if (!npr[i]){
                    prm.emplace_back(i);
                    g[i] = i;
                }
                for (u32 j : prm){
                    if (i * j >= n)break;
                    npr[i * j] = 1;
                    if (i % j)g[i * j] = j;
                    else {g[i * j] = g[i] * j;break;}
                }
            }
        }

    template <typename _Pi, typename _Ri, typename = enable_if_rai_t<_Pi>, typename = enable_if_rai_t<_Ri> >
        void sieve(u32 n, _Pi p, _Ri r){
            // p_x,r_x : let x=\prod p^r (p_1<p_2<...<p_k), then p_x \gets p_1, r_x\gets r_1
            // p : min prime factor   r : power of min prime factor
            p[1] = 2; r[1] = 0;
            std::vector<u32> prm;
            std::vector<bool> npr(n);
            for (u32 i = 2; i < n; ++i){
                if (!npr[i]){
                    prm.emplace_back(i);
                    p[i] = i; r[i] = 1;
                }
                for (u32 j : prm){
                    if (i * j >= n)break;
                    npr[i * j] = 1;
                    p[i * j] = j;
                    if (i % j)r[i * j] = 1;
                    else {r[i * j] = r[i] + 1;break;}
                }
            }
        }

    template <typename _Pi, typename _Gi,
            typename = enable_if_rai_t<_Pi>, typename = enable_if_rai_t<_Gi> >
        void sieve_ext(u32 n, _Pi p, _Gi g){//use p to calc g=p^r, p from sieve
            g[1] = 1;
            for (u32 i = 2; i < n; ++i)
                g[i] = p[i / p[i]] == p[i]? g[i / p[i]] * p[i] : p[i];
        }

    template <typename _F, typename _Func, typename = enable_if_rai_t<_F>//func(p,r,g=p^r) = f_{p^r}
    #if __cplusplus >= 201703L
            , typename = std::enable_if_t<std::is_invocable<_Func, u32, u32, u32>::value>
    #endif
        > void sieve_multiplicative(u32 n, _F f, _Func func){//multiplicative functions
            std::vector<u32> p(n), r(n), g(n);
            p[1] = 2; r[1] = 0; g[1] = 1;
            std::vector<u32> prm;
            std::vector<bool> npr(n);
            f[1] = 1;
            for (u32 i = 2; i < n; ++i){
                if (!npr[i]){
                    prm.emplace_back(i);
                    p[i] = i; r[i] = 1;
                    g[i] = i;
                    f[i] = func(p[i], r[i], g[i]);
                } else f[i] = f[i / g[i]] * f[g[i]];
                for (u32 j : prm){
                    if (i * j >= n)break;
                    npr[i * j] = 1;
                    p[i * j] = j;
                    if (i % j)r[i * j] = 1, g[i * j] = j;
                    else {r[i * j] = r[i] + 1;g[i * j] = g[i] * j;break;}
                }
            }
        }

    u32 sieve_phi(u32 p, u32, u32 g){
        return g / p * (p - 1);
    }

    i32 sieve_mu(u32 p, u32 r, u32 g){
        return r > 1? 0 : r? -1 : 1;
    }

    u64 sieve_sum_of_divisor(u32 p, u32 r, u32 g){
        return (1ull * g * p - 1) / (p - 1);
    }

    template <typename _F, typename = enable_if_rai_t<_F>, typename = enable_if_vt_t<_F, u64> >
        void sum_of_divisor_sieve(u32 n, _F f){
            std::vector<u32> P(n);
            std::vector<u32> prm;
            std::vector<bool> npr(n);
            f[1] = 1;
            P[1] = 1;
            for (u32 i = 2; i < n; ++i){
                if (!npr[i]){
                    prm.emplace_back(i);
                    P[i] = f[i] = i + 1;
                }
                for (u32 j : prm){
                    if (i * j >= n)break;
                    npr[i * j] = 1;
                    if (i % j)P[i * j] = j + 1, f[i * j] = f[i] * f[j];
                    else {P[i * j] = 1 + j * P[i], f[i * j] = f[i] / P[i] * P[i * j];break;}
                }
            }
        }

}


#include <bits/stdc++.h>
using namespace std;
using mod = modint_nm::modp1;
modint_nm::combination<mod::mod> C(600010);
string c, d;
int n;
mod pw2[300010];
inline mod pws(int n){
    return pw2[n + 1] - 2;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> d >> n;
    int cq = count(c.begin(), c.end(), '?'), dq = count(d.begin(), d.end(), '?');
    int da = count(c.begin(), c.end(), 'A') - count(d.begin(), d.end(), 'A');
    int db = count(d.begin(), d.end(), 'B') - count(c.begin(), c.end(), 'B');
    modint_nm::calc_power(max<size_t>({0u + n, c.size(), d.size()}) + 2, pw2, mod(2));
    const mod dz = []{
        mod ret = 0;

        static int mu[300010];
        sieve::sieve_multiplicative(n + 1, mu, sieve::sieve_mu);
        for (int d = 1; d <= n; ++d)
            for (int dk = d; dk <= n; dk += d)
                ret += mu[dk / d] * pw2[d] * (n / dk) * (n / dk);

        // for (int i = 1; i <= n; ++i)
        //     for (int j = 1; j <= n; ++j)
        //         ret += pw2[__gcd(i, j)];

        return ret;
    }(); // if da = db = 0
    auto f = [&](int da, int db){
        if (!da && !db)return dz;
        if (1ll * da * db <= 0)return mod();
        int t = __gcd(da, db);
        int u = da / t, v = db / t;
        if (u < 0 && v < 0)u = -u, v = -v;
        return pws(n / max(u, v));
    };
    mod rs = 0;

    // for (int i = 0; i <= cq; ++i) // i:a (cq-i):b
    //     for (int j = 0; j <= dq; ++j) // j:a (dq-j):b
    //         rs += C(cq, i) * C(dq, j) * f(da + i - j, db + (dq - j) - (cq - i));

    for (int k = da - dq; k <= da + cq; ++k){
        mod sm = C(cq + dq, dq - da + k);
        // for (int i = 0; i <= cq; ++i)
        //     sm += C(cq, i) * C(dq, dq - da + k - i);
        rs += f(k, k - da - cq + db + dq) * sm;
    }

    if (equal(c.begin(), c.end(), d.begin(), d.end(),
            [](char c, char d){return c == '?' || d == '?' || c == d;})){ // equal
        int ct = count_if(c.begin(), c.end(),
            [](const char &ch){return ch == '?' && d[&ch - c.data()] == '?';});
        rs += ((pws(n) ^ 2) - dz) * pw2[ct];
    }
    cout << rs << endl;
    return 0;
}