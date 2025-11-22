#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
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
    const int N = 3e3 + 10;
    const int K = N;
    const int M = 1e6 + 10;
	const int mod = 998244353;
    int n, m, k, s1, s2;
    int a[N];
    int d[N], dg[N];
    int he[M], to[M << 1], ne[M << 1], tot;
    void add(int u, int v) {
        ne[++tot] = he[u];
        he[u] = tot;
        to[tot] = v;
        return;
    }
    void ADD(int &x, int y) {
        x += y;
        if (x >= mod)    x -= mod;
    }
    void SUB(int &x, int y) {
        x -= y;
        if (x < 0)  x += mod;
    }
    bool vis[N];
    queue<int> q;
    int dp[N][K];

    void main() {
		read(n, m, k, s1, s2);
        REP(i, 1, m) {
            int u, v;
            read(u, v);
            add(u, v);
            add(v, u);
            d[u]++, d[v]++;
        }
        REP(i, 1, n) {
            read(a[i]);
            dg[i] = d[i];
            if (d[i] <= k)  q.push(i), vis[i] = 1;
        }
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            for(int i = he[u];i;i = ne[i]) {
                int v = to[i];
                if (vis[v]) continue;
                d[v]--;
                if (d[v] <= k)  q.push(v), vis[v] = 1;
            }
        }
        bool flag = 0;
        REP(i, 1, n) {
            if (!vis[i]) {
                cout << i << " ";
                flag = 1;
            }
        }
        if (flag)   return;

        REP(i, 1, n) {
            dp[i][0] = 1;
            for(int j = he[i];j;j = ne[j]) {
                int v = to[j];
                DEP(q, K - 10, a[v])    ADD(dp[i][q], dp[i][q - a[v]]);
            }
        }

        REP(T, 1, s1 + s2) {
            int op, x, y;
            read(op, x, y);
            if (op == 1) {

                a[x] = y;

                for(int i = he[x];i;i = ne[i]) {
                    int v = to[i];
                    
                    REP(j, 0, N - 10)   dp[v][j] = 0;
                    dp[v][0] = 1;
                    for(int j = he[v];j;j = ne[j]) {
                        int vv = to[j];
                        DEP(q, N - 10, a[vv])   ADD(dp[v][q], dp[v][q - a[vv]]);
                    }
                    
                    // REP(j, a[x], K - 10)    SUB(dp[v][j], dp[v][j - a[x]]);
                    // a[x] = y;
                    // DEP(j, K - 10, a[x])    ADD(dp[v][j], dp[v][j - a[x]]);
                }
            } else  cout << dp[x][y] % mod << "\n";
        }
        return;
    }
}

signed main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

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

