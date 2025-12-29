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
    const int M = 1e6 + 10;
	const int mod = 998244353;
    int n, m, k, s1, s2;
    int a[N];
    int d[N];
    int he[M], to[M << 1], ne[M << 1], tot;
    vector<int> ve[N];
    void add(int u, int v) {
        ne[++tot] = he[u];
        he[u] = tot;
        to[tot] = v;
        return;
    }
    void ADD(int &x, int y) {
        x += y;
        if (x >= mod)   x -= mod;
        if (x < 0)      x += mod;
    }
    bool vis[N];
    queue<int> q;
    int dp[N][N];
	int f[N];
	void upd(int u, int x) {
		DEP(i, N - 10, x)	ADD(dp[u][i], dp[u][i - x]);
		return;
	}
	void del(int u, int x) {
		REP(i, x, N - 10)	ADD(dp[u][i], -dp[u][i - x]);
		return;
	}
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
            if (d[i] <= k)  q.push(i);
        }
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for(int i = he[u];i;i = ne[i]) {
                int v = to[i];
                if (vis[v]) continue;
                d[v]--;
                ve[u].pb(v);
                if (d[v] <= k)  q.push(v);
            }
        }
        bool flag = 0;
        REP(i, 1, n) {
            if (!vis[i]) {
                cout << i << " ";
                flag = 1;
            }
            dp[i][0] = 1;
        }
        if (flag)   return;
		
		REP(i, 1, n) {
			for(auto v:ve[i])	upd(v, a[i]);
		}
		REP(T, 1, s1 + s2) {
			int op, x, y;
			read(op, x, y);
			if (op == 1) {
				for(auto v:ve[x]) { 
					del(v, a[x]);
					upd(v, y);
				}
				a[x] = y;
			}
			else {
				int sz = ve[x].size(), ans = 0;
				REP(st, 0, (1 << sz) - 1) {
					if (st)	f[st] = f[st ^ (st & (-st))] + (a[ve[x][__lg(st & (-st))]]);
					if (y >= f[st])	ADD(ans, dp[x][y - f[st]]);
				}
				
				cout << ans << "\n";
			}
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
