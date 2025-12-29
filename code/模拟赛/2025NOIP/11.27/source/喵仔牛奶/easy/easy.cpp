#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); ++ i)
#define DEP(i, r, l) for (int i = (r); i >= (l); -- i)
#define CUP(i, l, r) for (int i = (l); i < (r); ++ i)
#define CDW(i, r, l) for (int i = (r) - 1; i >= (l); -- i)
#define fi first
#define se second
#define pb emplace_back
#define mems(x, v) memset((x), (v), sizeof(x))
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
}
namespace Milkcat {
	using namespace math;
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 1e6 + 5, mod = 998244353;
	typedef mint<mod> MI;
	int n, k, x, a[N]; MI f[N];
	map<int, int, greater<>> s;
	int main() {
		cin >> n >> k, f[0] = 1;
		REP(i, 1, n) cin >> a[i];
		REP(i, 1, n) {
			map<int, int, greater<>> t; s[k] = i;
			for (auto [x, y] : s) {
				int z = __gcd(x, a[i]);
				t[z] = max(t[z], y);
			}
			int p = k / __gcd(__gcd(a[i], a[i - 1]), k); 
			s.swap(t), f[i] = f[i - 1] + 1;
			if (i > 1) f[i] += f[i - 2] * (p - 1);
			for (auto [x, y] : s) {
				if (y >= i - 1) continue;
				f[i] += f[y - 1] * (k / x - p), p = k / x;
			}
		}
		cout << f[n] - 1 << '\n', s.clear();
		return 0;
	}
}
int main() {
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1; cin >> T;
	while (T --) Milkcat::main();
	return 0;
}