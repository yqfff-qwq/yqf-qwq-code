// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

// #define int long long
#define REP(i, l, r)  for(int i = (l);i <= (r);i++)

namespace IO{
  // #define ONLINE_JUDGE
  #ifdef ONLINE_JUDGE
    constexpr size_t BUFFER_SIZE = 1u << 20;
    char in[BUFFER_SIZE], out[BUFFER_SIZE], *p1 = in, *p2 = in, *p3 = out;
    #define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, BUFFER_SIZE, stdin), p1 == p2) ? EOF : *p1++)
    #define flush() (fwrite(out, 1, p3 - out, stdout))
    #define putchar(x) (p3 == out + BUFFER_SIZE && (flush(), p3 = out), *p3++ = (x))
    class Flush {
    public:
      ~Flush() {
        flush();
      }
    } _;
  #endif
  namespace rw{
    template<typename type>
    inline void read(type &x) noexcept {
      bool f{};
      char c;
      while (!isdigit((c = getchar())))
        f ^= c == '-';
      x = c ^ 48;
      while (isdigit((c = getchar())))
        x = (x << 3) + (x << 1) + (c ^ 48);
      if (f)
        x = -x;
    }
    template<typename type>
    inline void write(type x) noexcept {
      if (x < 0) {
        x = -x;
        putchar('-');
      }
      static short a[50], t{};
      do
        a[++t] = x % 10, x /= 10;
      while(x);
      while(t)
        putchar(a[t--] | 48);
    }
    inline void write(char c) noexcept {
      putchar(c);
    }
  }
  #ifdef ONLINE_JUDGE
    #undef getchar
    #undef flush
    #undef putchar
  #endif
}using namespace IO::rw;//read(a,b...),write(a,b...);

namespace YZLK{
  const int N = 2e6 + 10;
  const int M = 1e6 + 10;
  int n, m;
  struct tree{
    // #define mid ((l + r) >> 1)
    int rt[N];
    struct node{
      int ls, rs;
      int sz;
    } tr[N * 21 + M];
    int idx;
    int nd(int u) noexcept {
      tr[++idx] = tr[u];
      tr[idx].sz++;
      return idx;
    }
    int build(int u, int l, int r) noexcept {
      u = ++idx;
      if (l == r) return idx;
      int mid = (l + r) >> 1;
      tr[u].ls = build(tr[u].ls, l, mid);
      tr[u].rs = build(tr[u].rs, mid + 1, r);
      return u;
    }
    int update(int u, int l, int r, int p) noexcept {
      u = nd(u);
      if (l == r) return u;
      int mid = (l + r) >> 1;
      if (p <= mid) tr[u].ls = update(tr[u].ls, l, mid, p);
      else          tr[u].rs = update(tr[u].rs, mid + 1, r, p);
      return u;
    }
    int query(int u, int v, int l, int r, int p) const noexcept {
      if (l == r)   return (tr[v].sz - tr[u].sz);
      int mid = (l + r) >> 1;
      if (p <= mid) return query(tr[u].ls, tr[v].ls, l, mid, p);
      else          return (tr[tr[v].ls].sz - tr[tr[u].ls].sz) + query(tr[u].rs, tr[v].rs, mid + 1, r, p);
    }
  } tr;
  inline void main() noexcept {
    read(n), read(m);
    // cin >> n >> m;
    tr.rt[0] = tr.build(1, 1, N - 10);
    int p, l, r, x;
    REP(i, 1, n) {
      read(p);
      // cin >> p;
      tr.rt[i] = tr.update(tr.rt[i - 1], 1, N - 10, p);
    }
    while(m--) {
      read(l), read(r), read(x);
      // cin >> l >> r >> x;
      //printf("%d\n", tr.query(tr.rt[l - 1], tr.rt[r], 1, N - 10, x));
      // cout << tr.query(tr.rt[l - 1], tr.rt[r], 1, N - 10, x) << "\n";
      write(tr.query(tr.rt[l - 1], tr.rt[r], 1, N - 10, x));
      write('\n');
    }
    return;
  }
}


signed main() noexcept {
  // freopen("paint.in", "r", stdin);
  // freopen("paint.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
  // read(T);
  //ios::sync_with_stdio(0);
  //cin.tie(0);cout.tie(0);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);

  return 0;
}

