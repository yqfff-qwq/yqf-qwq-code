#include <bits/stdc++.h>
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
  const int N = 3e5 + 10;
  string s, t;
  string a, b;
  // char s[N], t[N];
  // char a[N], b[N];
  int d1[N], d2[N];
  int n, l1, l2, c1, c2;
  void main() {
    // scanf("%s", s + 1);
    // scanf("%s", t + 1);
    std::cin >> s >> t;
    a = s, b = t;
    read(n);
    l1 = s.size(), l2 = t.size();
    // l1 = strlen(s + 1);
    // l2 = strlen(t + 1);
    REP(i, 0, l1 - 1) {
      if (s[i] == '?')  d1[++c1] = i;
    }
    REP(i, 0, l2 - 1) {
      if (t[i] == '?')  d2[++c2] = i;
    }
    int cnt = 0;
    REP(i, 0, (1ll << c1) - 1) {
      REP(j, 1, c1) {
        if ((i >> (j - 1)) & 1) a[d1[j]] = 'A';
        else                    a[d1[j]] = 'B';
      }
      REP(j, 0, (1ll << c2) - 1) {
        REP(k, 1, c2) {
          if ((j >> (k - 1)) & 1) b[d2[k]] = 'A';
          else                    b[d2[k]] = 'B';
        }
        string s1, s2;
        REP(k1, 1, n) {
          REP(p1, 0, (1ll << k1) -1) {
            s1 = "";
            REP(l, 0, k1 - 1) {
              if ((p1 >> l) & 1)  s1 += "1";
              else                s1 += "0";
            }
            REP(k2, 1, n) {
              REP(p2, 0, (1ll << k2) -1) {
                s2 = "";
                REP(l, 0, k2 - 1) {
                  if ((p2 >> l) & 1)  s2 += "1";
                  else                s2 += "0";
                }
                // std::cout << s1 << ' ' << s2 << '\n';
                string a1 = "", a2 = "";
                REP(w, 1, l1) {
                  if (a[w] == 'A')  a1 += s1;
                  else              a1 += s2;
                }
                REP(w, 1, l2) {
                  if (b[w] == 'A')  a2 += s1;
                  else              a2 += s2;
                }               
                if (a1 == a2) cnt++;
              }
            }
          }
        }
      }
    }
    std::cout << cnt << '\n';
    return;
  }
}

signed main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}