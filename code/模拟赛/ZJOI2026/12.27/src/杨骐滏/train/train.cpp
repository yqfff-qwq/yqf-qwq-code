#include <iostream>
#include <algorithm>
#include <cstring>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long

void read(){}
template<typename T1,typename ...T2>inline void read(T1 &x,T2 &...oth)
{
  x=0;
  int f=0,ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    {
      f=1;
    }
    ch=getchar();
  }
  while('0'<=ch&&ch<='9')
  {
    x=(x<<3)+(x<<1)+(ch^48);
    ch=getchar();
  }
  if(f)
  {
    x=-x;
  }
  read(oth...);
}

namespace YZLK{
  const int N = 5e5 + 10;
  int n;
  int a[N];
  char c[N];
  int ans[N];
  int ps[N];
  int ct[N], sm[N], ss[N], ln[N];
  void main() {
    read(n);
    scanf("%s", c + 1);
    int cnt = 0, sum = 0, len = 0;
    DEP(i, n, 1) {
      if (c[i] == 'O')  cnt = 1, sum += i, len++;
      if (c[i] == 'L')  cnt++, sum += i, len++;
      ct[i] = cnt, sm[len] = sum, ln[i] = len;
      // std::cout << i << ' ' << cnt << ' ' << sum << ' ' << len << '\n';
    }
    cnt = 0, sum = 0, len = 0;
    REP(i, 1, n) {
      if (c[i] == 'O')  {cnt = 1, len++, ps[len] = ps[len - 1] + i; continue;}
      if (c[i] == 'R') {
        int cl = cnt, cr = ct[i + 1];
        if (cl == 1 or cr == 1) {
          if (cr == 1) {
            ans[i] = sm[ln[i + 1]] - sm[ln[i + 1] - 1] - i;
          } else if (cl == 1) {
            ans[i] = (sm[ln[i + 1]] - sm[ln[i + 1] - 1] - i) * 2 + (i - (ps[len] - ps[len - 1]));
          }
          cnt++, ++len, ps[len] = ps[len - 1] + i;
          continue;
        }
        // std::cout << i << ' ' << cl << ' ' << cr << '\n';
        if (cr <= cl) {
          int as = sm[ln[i + 1]] - sm[ln[i + 1] - cr] - cr * i;
          // std::cout << as << '\n';
          as += (cr - 1) * i - (ps[len] - ps[len - cr + 1]);
          as = as * 2;
          as -= ((sm[ln[i + 1] - cr + 1] - sm[ln[i + 1] - cr]) - i);
          ans[i] = as;
        }
        else {
          // std::cout << i << ' ' << cl << ' ' << cr << '\n';
          int as = sm[ln[i + 1]] - sm[ln[i + 1] - cl] - cl * i;
          as += cl * i - (ps[len] - ps[len - cl]);
          as = as * 2;
          as -= i - (ps[len - cl + 1] - ps[len - cl]);
          ans[i] = as;
        }
        cnt++, ++len, ps[len] = ps[len - 1] + i;
      } else {
        int cl = cnt, cr = ct[i + 1];
        // std::cout << i << ' ' << cl << ' ' << cr << '\n';
        if (cl == 1 or cr == 1) {
          if (cl == 1) {
            ans[i] = i - (ps[len] - ps[len - 1]);
          } else if (cr == 1) {
            ans[i] = sm[ln[i + 1]] - sm[ln[i + 1] - 1] - i + (i - (ps[len] - ps[len - 1])) * 2;
          }
          continue;
        }
        if (cl <= cr) {
          int as = cl * i - (ps[len] - ps[len - cl]);
          as += sm[ln[i + 1]] - sm[ln[i + 1] - cl + 1] - (cl - 1) * i;
          as = as * 2;
          as -= i - (ps[len - cl + 1] - ps[len - cl]);
          ans[i] = as;
        }
        else {
          int as = cr * i - (ps[len] - ps[len - cr]);
          as += sm[ln[i + 1]] - sm[ln[i + 1] - cr] - cr * i;
          // std::cout << i << ' ' << as << '\n';
          as = as * 2;
          // std::cout << (sm[ln[i + 1] - cr + 1] - sm[ln[i + 1] - cr]) << '\n';
          as -= ((sm[ln[i + 1] - cr + 1] - sm[ln[i + 1] - cr]) - i);
          ans[i] = as;
        }
      }
      // std::cout << i << ' ' << cnt << ' ' << ps[len] << ' ' << len << '\n';
    }
    REP(i, 1, n)  std::cout << ans[i] << ' ';
    return ;
  }
}

signed main()
{
  freopen("train.in","r",stdin);
  freopen("train.out","w",stdout);
  int T=1;
  // read(T);
  while(T--)
  {
      YZLK::main();
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/

/*
int p;
    read(p);
    while(c[p] != 'O') {
      if (c[p] == 'L')  c[p] = 'R', p--;
      else              c[p] = 'L', p++;
      REP(i, 1, n)  std::cout << c[i];
      puts("");
      REP(i, 1, p - 1)  std::cout << " ";
      std::cout << "^\n";
    }


*/