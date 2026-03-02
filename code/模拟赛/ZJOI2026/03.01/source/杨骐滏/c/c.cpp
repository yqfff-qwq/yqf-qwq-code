#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;

#define REP(i,l,r)  for(int i = l;i <= r;i++)
#define DEP(i,r,l)  for(int i = r;i >= l;i--)
#define ll long long
#define pii std::pair<int, int>
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
  int n, m, len;
  int cnt = 0;
  struct node{
    int x, y;
  }a[N];
  void main() {
    read(n, len);
    REP(i, 1, len) {
      int x, y, z;
      read(x, y, z);
      cnt += z / 2;
      if (z & 1)  a[++m] = {x, y};
    }
    
    std::cout << cnt + m << '\n';
    return;
  }
}

signed main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}