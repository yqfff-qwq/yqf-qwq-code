// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <cstring>


// #define int long long
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define REP(i, l, r)    for(int i = (l);i <= (r);i++)
#define DEP(i, r, l)    for(int i = (r);i >= (l);i--)

void read() {}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
    x = 0;
    int ch = getchar(), f = 0;
    while(ch < '0' or '9' < ch) {
        if (ch == '-')  f = 1;
        ch = getchar();
    }
    while('0' <= ch and ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    if (f)  x = -x;
    read(oth...);
    return;
}

namespace YZLK{
  const int N = 2e5 + 10;
  char c[N];
  int n;
  std::stack<char> st;
  void main() {
    scanf("%s", c + 1);
    n = strlen(c + 1);
    st.push(c[n]);
    DEP(i, n - 1, 1) {
      while(!st.empty() and st.top() != c[i]) st.pop();
      st.push(c[i]);
    }
    std::cout << st.size() << "\n";
    return;
  }
}

signed main() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);

  // std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}



/*
不要忘记longlong

*/