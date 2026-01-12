#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
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
  const int mod = 998244353;
  const int N = 1e3 + 10;
  
  int n, p, m;
	int fac[N], inv[N];
  int s1[N], s2[N];
  int is[N], id[N], v[N], ct[N];
  int ans[52][N];
  int dp[51][N][51];
	int M;
  
	int ksm(int a, int b) {
		int s = 1;
		while(b) { 
			if (b & 1)	s = s * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return s;
	}
  void pred(int n) {
    M = n;
    s1[0] = 1;
    REP(i, 1, N - 10) s1[i] = 1ll * s1[i-1] * (n - i + 1) % mod;
  }
  int Cd(int m) {
    if(m > M) return 0;
    return s1[m] * inv[m] % mod;
  }
  void preu(int n) {
		M = n;
    s2[0] = 1;
    REP(i, 1, N - 10) s2[i] = 1ll * s2[i-1] * (n + i - 1) % mod;
  }
  int Cu(int m) {
    return 1ll * s2[m] * inv[m] % mod;
  }
  int C(int x, int y) {
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
  }
  void main(){
    read(n, p, m);
    
		fac[0] = inv[0] = 1;
		REP(i, 1, N - 10)	fac[i] = fac[i - 1] * i % mod;
		inv[N - 10] = ksm(fac[N - 10], mod - 2);
		DEP(i, N - 11, 1)	inv[i] = inv[i + 1] * (i + 1) % mod;
    
    int res = 1, t = 0, L = 0, R = -1;
    REP(i, 1, n){
      res %= p;
      if(is[res]){
        L = id[res];
        R = i - 1;
        break;
      }
      ++ct[res];
      id[res] = ++t;
      v[t] = res;
      is[res] = 1;
      res *= 10;
      res %= p;
    }
    
    if(R != -1){
      int k = (n - R) / (R - L + 1);
      REP(i, L, R) ct[v[i]] += k;
      res = v[R] * 10 % p;
      REP(i, R + k * (R - L + 1) + 1, n){
        res %= p;
        ++ct[res];
        id[res] = ++t;
        v[t] = res;
        is[res] = 1;
        res *= 10;
        res %= p;
      }
    }
    
    REP(i, 0, p - 1){
      preu(ct[i]);
      pred(ct[i]);
      REP(j, 0, m){
        int sum = 0;
        for(int k = 0;;k++) {
          if(j - 10 * k < 0) break;
          if(k & 1) sum = (sum - 1ll * Cd(k) * Cu(j - 10 * k) % mod + mod) % mod;
          else sum = (sum + Cd(k) * Cu(j - 10 * k) % mod) % mod;
        }
        ans[i][j] = sum;
      }
    }
    
    dp[0][0][0] = 1;
    REP(j, 0, p - 1) {
      REP(i, 0, m) {
        REP(k, 0, p - 1) {
          if (!dp[j][i][k])	continue;
          int v = dp[j][i][k];
          REP(w, 0, min(m - i, ct[j] * 9)){
            dp[j + 1][i + w][(k + w * j) % p] = (dp[j + 1][i + w][(k + w * j) % p] + 1ll * v * ans[j][w] % mod) % mod;
          }
        }
      }
    }
    
    REP(i, 1, m)	dp[p][i][0] = (dp[p][i][0] + dp[p][i-1][0]) % mod;
    REP(i, 0, m)	std::cout << dp[p][i][0] << ' ';
    return;
  }
}

signed main(){
  freopen("probability.in","r",stdin);
  freopen("probability.out","w",stdout);
  
  int T = 1;
  // read(T);
  while(T--){
    YZLK::main();
  }
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}