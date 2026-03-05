#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); ++ i)
#define DEP(i, r, l) for (int i = (r); i >= (l); -- i)
#define CUP(i, l, r) for (int i = (l); i < (r); ++ i)
#define CDW(i, r, l) for (int i = (r) - 1; i >= (l); -- i)
#define fi first
#define se second
#define pb emplace_back
#define mems(x, v) memset((x), (v), sizeof(x))
#define memc(x, y) memcpy((x), (y), sizeof(x))
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define ppc(x) __builtin_popcount(x)
using namespace std;
namespace math {
	typedef long long LL;
	template <class T> T qpow(T a, LL b) { if (!b) return {1}; T rs = a; b --; for (; b; b >>= 1, a = a * a) if (b & 1) rs = rs * a; return rs; }
	LL mul(LL a, LL b, LL p) { LL rs = a * b - LL(1.L * a * b / p) * p; rs %= p; if (rs < 0) rs += p; return rs; }
	template <unsigned P = 0> struct mint {
		unsigned v; static unsigned mod; mint() = default;
		template <class T> mint(T x) { x %= (int)getmod(), v = x < 0 ? x + getmod() : x; }
		constexpr static unsigned getmod() { if (P > 0) return P; else return mod; }
		static void setmod(unsigned m) { mod = m; }
		mint operator + () const { return *this; }
		mint operator - () const { return mint(0) - *this; }
		mint inv() const { return assert(v), qpow(*this, getmod() - 2); }
		int val() const { return v; }
		mint &operator += (const mint &q) { if (v += q.v, v >= getmod()) v -= getmod(); return *this; }
		mint &operator -= (const mint &q) { if (v -= q.v, v >= getmod()) v += getmod(); return *this; }
		mint &operator *= (const mint &q) { v = 1ull * v * q.v % getmod(); return *this; }
		mint &operator /= (const mint &q) { return *this *= q.inv(); }
		friend mint operator + (mint p, const mint &q) { return p += q; }
		friend mint operator - (mint p, const mint &q) { return p -= q; }
		friend mint operator * (mint p, const mint &q) { return p *= q; }
		friend mint operator / (mint p, const mint &q) { return p /= q; }
		friend bool operator == (const mint &p, const mint &q) { return p.v == q.v; }
		friend bool operator != (const mint &p, const mint &q) { return p.v != q.v; }
		friend bool operator < (const mint &p, const mint &q) { return p.v < q.v; }
		friend bool operator > (const mint &p, const mint &q) { return p.v > q.v; }
		friend bool operator <= (const mint &p, const mint &q) { return p.v <= q.v; }
		friend bool operator >= (const mint &p, const mint &q) { return p.v >= q.v; }
		friend istream &operator >> (istream &is, mint &a) { LL x; is >> x, a = x; return is; }
		friend ostream &operator << (ostream &os, const mint &a) { os << a.v; return os; }
	};
	template <> unsigned mint<0>::mod = 998244353;
	template <typename MI>
	struct Comb {
		#define P MI::getmod()
		vector<MI> fc, ifc;
		void init(int n) {
			fc.resize(n + 1), ifc.resize(n + 1), fc[0] = 1;
			REP(i, 1, n) fc[i] = fc[i - 1] * i;
			ifc[n] = fc[n].inv();
			DEP(i, n, 1) ifc[i - 1] = ifc[i] * i;
		}
		MI operator () (LL n, LL m) {
			if (m > n || m < 0 || n < 0) return 0;
			if (n < P && m < P) { assert(n < SZ(fc)); return fc[n] * ifc[m] * ifc[n - m]; }
			return (!n ? 1 : (*this)(n / P, m / P) * (*this)(n % P, m % P));
		}
		#undef P
	};
	namespace Z {
		const int mod = 998244353;
		using MI = mint<mod>; using math::qpow; Comb<MI> C;
		MI fac(int x) { assert(x >= 0 && x < SZ(C.fc)); return C.fc[x]; }
		MI ifc(int x) { assert(x >= 0 && x < SZ(C.ifc)); return C.ifc[x]; }
		MI inv(int x) { assert(x && x < SZ(C.fc)); return C.ifc[x] * C.fc[x - 1]; }
		MI sab(int x, int y) { return (!y ? !x : C(x + y - 1, y - 1)); }
	}
}
namespace Milkcat {
	using namespace math::Z;
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 20, M = 1 << N;
	namespace SET {
		typedef unsigned long long ULL;
		void fmt(auto* f, int n, int o) {
			REP(i, 0, n - 1) REP(j, 0, (1 << n) - 1)
				if (j >> i & 1) f[j] += f[j ^ 1 << i] * o;
		}
		inline void sfmt(auto f, int n, int o) {
			REP(i, 0, n - 1) REP(j, 0, (1 << n) - 1) {
				if (j >> i & 1) continue;
				REP(k, 0, n) {
					if (o > 0) f[j ^ 1 << i][k] += f[j][k];
					else f[j ^ 1 << i][k] -= f[j][k];
				}
			}
		}
		void mul(MI* f, MI* g, MI* h, int n) {
			static MI A[1 << N][N + 1], B[1 << N][N + 1], C[1 << N][N + 1];
			REP(i, 0, (1 << n) - 1)
				mems(A[i], 0), mems(B[i], 0), A[i][ppc(i)] = f[i], B[i][ppc(i)] = g[i];
			ULL v = 0; sfmt(A, n, 1), sfmt(B, n, 1);
			REP(i, 0, (1 << n) - 1) REP(x, 0, n) {
				REP(y, 0, x) v += (ULL)A[i][y].val() * B[i][x - y].val();
				C[i][x] = v, v = 0;
			}
			sfmt(C, n, -1);
			REP(i, 0, (1 << n) - 1) h[i] = C[i][ppc(i)];
		}
		void exp(MI* f, MI* g, int n) {
			g[0] = 1;
			REP(i, 0, n - 1) mul(f + (1 << i), g, g + (1 << i), i);
		}
		void ln(MI* f, MI* g, int n) {
			static MI r[1 << N][N + 1], t[N + 1], iv[N + 1];
			int m = (1 << n) - 1; ULL v = 0;
			REP(i, 0, m) fill_n(r[i], n + 1, 0), r[i][ppc(i)] = f[i];
			REP(i, 1, n) iv[i] = (MI)1 / i;
			sfmt(r, n, 1);
			REP(S, 0, m) {
				REP(i, 1, n) {
					REP(j, 1, i) v += (ULL)(mod - r[S][j].val()) * t[i - j].val();
					t[i] = v + r[S][i] * i, v = 0;
				}
				REP(i, 0, n) r[S][i] = t[i] * iv[i];
			}
			sfmt(r, n, -1);
			REP(i, 0, m) g[i] = r[i][ppc(i)];
		}
	}
	int n, m, q, x, y, e[N]; MI f[M], g[M], t[N + 1], h[N + 1];
	int main() {
		cin >> n >> m >> q, C.init(n);
		REP(i, 1, m) {
			cin >> x >> y, x --, y --;
			e[x] |= 1 << y, e[y] |= 1 << x;
		}
		g[0] = 1;
		CUP(i, 0, n) {
			CUP(S, 0, 1 << i) g[S | 1 << i] = g[S] * ppc(e[i] & S);
			SET::exp(g + (1 << i), g + (1 << i), i);
		}
		CUP(S, 0, 1 << n) {
			f[S] = 1;
			CUP(i, 0, n)
				if (S >> i & 1) f[S] *= ppc(S & e[i]);
		}
		SET::ln(f, f, n);
		CUP(S, 1, 1 << n)
			f[S] = (f[S] - g[S] * (ppc(S) - 1)) / 2;
		CUP(S, 0, 1 << n) {
			mems(t, 0), t[0] = 1;
			CUP(i, 0, n) {
				if (S >> i & 1) continue;
				DEP(j, n, 1) t[j] += t[j - 1] * ppc(e[i] & S);
			}
			REP(i, 0, n - ppc(S)) REP(j, i, n)
				h[i + ppc(S)] += f[S] * t[j] * C(j, i) * (i & 1 ? -1 : 1);
		}
		REP(i, 1, q) {
			MI w = 0;
			REP(i, 1, n) cin >> x, w += h[i] * x;
			cout << w << '\n';
		}
		return 0;
	}
}
int main() {
	freopen("stalemate.in", "r", stdin);
	freopen("stalemate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}