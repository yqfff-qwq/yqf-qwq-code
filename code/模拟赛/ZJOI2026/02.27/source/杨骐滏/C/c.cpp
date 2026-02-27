#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(i,l,r)  for(int i = l;i <= r;i++)
#define DEP(i,r,l)  for(int i = r;i >= l;i--)
#define ll long long
#define pb push_back
#define fi first
#define se second

void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while(ch < '0' or ch > '9') {
    if (ch == '-')  f = 1;
    ch = getchar();
  }
  while('0' <= ch and ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  if (f)  x = -x;
  read(oth...);
}


namespace YZLK{
  const int N = 2e5 + 10;
  ll n, q, k, ln;
  ll s[N];
  ll p[N];
  void solve1() {
    auto lowbit = [&](ll x) -> ll{
      return x & -x;
    };
    auto add = [&](ll x, ll v) -> void{
      while(x <= n) {
        s[x] = s[x] ^ v;
        x = x + lowbit(x);
      }
      return;
    };
    auto query = [&](ll x) -> ll{
      ll ans = 0;
      while(x > 0) {
        ans = ans ^ s[x];
        x -= lowbit(x);
      }
      return ans;
    };
    while(q--) {
      ll op, x, v;
      read(op, x);
      if (op == 1) {
        read(v);
        add(x, v);
      }
      else{
        std::cout << query(x) << '\n';
      }
    }
    return;
  }
  int lowbit(int x) {
    int l = 0, r = ln, ans = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if (x % p[mid] == 0)  ans = mid, l = mid + 1;
      else                  r = mid - 1;
    }
    // std::cout << x << ' ' << p[ans] << '\n';
    return x % p[ans + 1];
    // DEP(i, ln, 0) if (x % p[i] == 0)  return p[i];
  }
  void add(int x, int v) {
    while(x <= n) {
      s[x] = s[x] ^ v;
      x = x + lowbit(x);
    }
    return;
  }
  int query(int x) {
    int ans = 0;
    while(x) {
      ans = ans ^ s[x];
      x = x - lowbit(x);
    }
    return ans;
  }
  void solve2() {
    while(q--) {
      ll op, x, v;
      read(op, x);
      if (op == 1) {
        read(v);
        add(x, v);
      }
      else{
        std::cout << query(x) << '\n';
      }
    }
    return;
  }
  void main() {
    read(n, q, k);
    // if (k == 2) {
    //   solve1();
    //   return;
    // }
    p[0] = 1;
    for(int i = 1;;i++) {
      ln = i;
      p[i] = p[i - 1] * k;
      if (p[i] > n) break;
    }
    solve2();

    return;
  }
}

signed main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}