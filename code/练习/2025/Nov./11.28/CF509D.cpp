#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

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
	const int N = 1e2 + 10;
  int n, m;
  int d[N][N];
  int k = 0;
  int a[N], b[N];
  void main() {
    read(n, m);
    REP(i, 1, n)
      REP(j, 1, m)  read(d[i][j]);
    REP(i, 1, m)  b[i] = d[1][i];
    REP(i, 1, n)  a[i] = d[i][1] - b[1];
    auto gcd = [&] (auto &&self, int x, int y) -> int
    { return y == 0 ? x : self(self, y, x % y); };
		
    REP(i, 1, n) {
      REP(j, 1, m) {
        int s = abs(a[i] + b[j] - d[i][j]);
        k = gcd(gcd, s, k);
      }
    }
    if (k == 0) k = 1e9 + 7;
    REP(i, 1, n) {
      REP(j, 1, m) {
        if (d[i][j] >= k) return puts("NO"), void();
      }
    }
    REP(i, 1, n)  a[i] = (a[i] + k) % k;
    REP(i, 1, m)  b[i] = (b[i] + k) % k;
    puts("YES");
    cout << k << "\n";
    REP(i, 1, n)  cout << a[i] << " ";
    puts("");
    REP(i, 1, m)  cout << b[i] << " ";
    return;
  }
}

signed main()
{
    // freopen("XXX.in","r",stdin);
    // freopen("XXX.out","w",stdout);

    int T=1;
    // read(T);
    while(T--)
    {
        YZLK::main();
    }

//    fclose(stdin);
//    fclose(stdout);
    return 0;
}