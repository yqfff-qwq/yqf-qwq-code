#include <iostream>
#include <algorithm>

// using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define REP(i, l, r)  for(int i = (l);i <= (r);i++)
#define DEP(i, r, l)  for(int i = (r);i >= (l);i--)

void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while(ch < '0' or '9' < ch) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while('0' <= ch and ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  if(f) x = -x;
  read(oth...);
  return;
}

namespace YZLK{
  const int N = 1e5 + 10;
  int n, q;
  int a[N];
  int c[N];
  int b = 0;
	void main() {
    read(n);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, n)  c[i] = a[i] - a[i - 1];
    REP(i, 1, n) {
      if (c[i] > 0)  b += c[i];
    }
    auto qy = [&](int x) -> int{
      if (x >= 0) return (x + 1) / 2;
      return x / 2;
    };
    std::cout << qy(b + (c[1] < 0 ? c[1] : 0))<< "\n";
    // REP(j, 1, n)  std::cout << c[j] << " ";
    //   puts("");
    
    read(q);
    REP(i, 1, q) {
      int l, r, x;
      read(l, r, x);
      if (c[l] > 0) b -= c[l];
      c[l] += x;
      if (c[l] > 0) b += c[l];
      
      
      if (r + 1 <= n) {
        if (c[r + 1] > 0) b -= c[r + 1];
        c[r + 1] -= x;
        if (c[r + 1] > 0) b += c[r + 1];
      }
      std::cout << qy(b + (c[1] < 0 ? c[1] : 0))<< "\n";
      // REP(j, 1, n)  std::cout << c[j] << " ";
      // puts("");
    }
    return;
  }
}

signed main() {
//   freopen("knapsack.in", "r", stdin);
//   freopen("knapsack.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);

  return 0;
}