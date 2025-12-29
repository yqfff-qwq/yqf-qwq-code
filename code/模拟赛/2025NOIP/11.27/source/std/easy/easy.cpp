#include <bits/stdc++.h>

using u32 = unsigned;
using u64 = unsigned long long;
using i64 = long long;

template<typename T>
constexpr T qmi(T a, u64 b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
  return 1ULL * a * b % P;
}

template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
  u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
  res %= P;
  return res;
}

template<typename U, U P>
struct ModIntBase {
  U x;
  constexpr ModIntBase() : x {0} {}
  template<typename T>
  constexpr ModIntBase(T x) : x {norm(x % T {P})} {}
  constexpr U norm(U x) const {
    if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
      x += P;
    }
    if (x >= P) {
      x -= P;
    }
    return x;
  }
  constexpr U val() const {
    return x;
  }
  constexpr ModIntBase operator-() const {
    ModIntBase res;
    res.x = norm(P - x);
    return res;
  }
  constexpr ModIntBase inv() const {
    assert(x != 0);
    return qmi(*this, P - 2);
  }
  constexpr ModIntBase &operator*= (ModIntBase v) & {
    x = mulMod<P>(x, v.x);
    return *this;
  }
  constexpr ModIntBase &operator+= (ModIntBase v) & {
    x = norm(x + v.x);
    return *this;
  }
  constexpr ModIntBase &operator-= (ModIntBase v) & {
    x = norm(x - v.x);
    return *this;
  }
  constexpr ModIntBase &operator/= (ModIntBase v) & {
    return *this *= v.inv();
  }
  friend constexpr ModIntBase operator- (ModIntBase a, ModIntBase b) {
    ModIntBase res = a;
    res -= b;
    return res;
  }
  friend constexpr ModIntBase operator+ (ModIntBase a, ModIntBase b) {
    ModIntBase res = a;
    res += b;
    return res;
  }
  friend constexpr ModIntBase operator* (ModIntBase a, ModIntBase b) {
    ModIntBase res = a;
    res *= b;
    return res;
  }
  friend constexpr ModIntBase operator/ (ModIntBase a, ModIntBase b) {
    ModIntBase res = a;
    res /= b;
    return res;
  }
  friend constexpr std::ostream &operator<< (std::ostream& os, const ModIntBase& a) {
    return os << a.val();
  }
  friend constexpr bool operator== (ModIntBase a, ModIntBase b) {
    return a.val() == b.val();
  }
  friend constexpr bool operator!= (ModIntBase a, ModIntBase b) {
    return a.val() != b.val();
  }
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;
 
template<u64 P>
using ModInt64 = ModIntBase<u64, P>;

constexpr u32 P = 998244353;
using mint = ModInt<P>;

void solve() {
  int N, K;
  std::cin >> N >> K;

  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::vector<std::vector<std::array<int, 2>>> f(N);
  for (int i = 0; i < N; i++) {
    f[i].push_back({std::__gcd(A[i], K), i});
    if (i > 0) {
      for (auto [x, y] : f[i - 1]) {
        x = std::__gcd(x, A[i]);
        if (f[i].back()[0] != x || y == i - 1) {
          f[i].push_back({x, y});
        }
      }
    }
  }

  int d = std::__gcd(A[0], K);
  std::vector<mint> dp(N + 1);
  dp[0] = dp[1] = 1;
  for (int i = 1; i < N; i++) {
  	int z;
    for (auto [x, y] : f[i]) {
      if (y == 0) {
        continue;
      }
      if (y == i) {
        dp[i + 1] += dp[i];
      } else if (y == i - 1) {
        dp[i + 1] += dp[y] * (K / x - 1);
      } else {
        dp[i + 1] += dp[y] * (K / x - K / z);
      }
      z = x;
    }
    d = std::__gcd(d, A[i]);
    if (i > 0) {
      dp[i + 1] += K / d;
    }
  }
  std::cout << dp[N] << "\n";
}

int main() {
  freopen("easy.in", "r", stdin);
  freopen("easy.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
