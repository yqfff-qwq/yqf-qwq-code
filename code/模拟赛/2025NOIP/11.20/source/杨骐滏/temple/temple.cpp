#include<bits/stdc++.h>
using namespace std;

// #define int long long
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
    const int N = 1e5 + 10;
    const int B = 1320;
    bitset<N> b[78][78], tt;
    int st[N][17];
    int dfn[N], tim;
    int base, mod;
    int dep[N], mxd[N], f[N];
    int n, m;
    int a[N];
    int F[N];
    int he[N], to[N << 1], ne[N << 1], tot;
    vector<int> vv;
    int sta[N], top;
    int id[N], idx;
    void add(int u, int v) {
        ne[++tot] = he[u];
        he[u] = tot;
        to[tot] = v;
        return;
    }
    int get(int x, int y) {
        return dfn[x] < dfn[y] ? x : y;
    }
    void dfs(int u, int fa) {
        st[dfn[u] = ++tim][0] = fa;
        f[u] = fa;
        dep[u] = dep[fa] + 1;
        mxd[u] = dep[u];
        for(int i = he[u];i;i = ne[i]) {
            int v = to[i];
            if (v == fa)    continue;
            dfs(v, u);
            mxd[u] = max(mxd[u], mxd[v]);
        }
        if (mxd[u] - dep[u] >= B)   id[u] = ++idx, mxd[u] = dep[u];
        return;
    }
    int lca(int u, int v) {
        if (u == v) return u;
        u = dfn[u], v = dfn[v];
        if (u > v)  swap(u, v);
        u++;
        int d = __lg(v - u + 1);
        return get(st[u][d], st[v - (1 << d) + 1][d]);
    }
    void dfs2(int u) {
        for(int i = he[u];i;i = ne[i]) {
            int v = to[i];
            if (v == f[u])  continue;
            if (id[v]) {
                int x = id[sta[top]], y = id[v];
                for(int d = v;d != sta[top];d = f[d])   b[x][y].set(a[d]);
                tt = b[x][y];
                for(int i = 1;i < top;i++) {
                    bitset<N> &bt = b[id[sta[i]]][y];
                    bt = b[id[sta[i]]][x];
                    bt |= tt;
                }
                F[v] = sta[top];
                sta[++top] = v;
            }
            dfs2(v);
            if (id[v])  top--;
        }
    }
    void main() {
        read(n, base, mod);
        REP(i, 1, n)    read(a[i]), vv.pb(a[i]);
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        REP(i, 1, n)    a[i] = lower_bound(vv.begin(), vv.end(), a[i]) - vv.begin();
        REP(i, 1, n - 1) {
            int u, v;
            read(u, v);
            add(u, v);
            add(v, u);
        }
        dfs(1, 0);
        REP(j, 1, 16) {
            for(int i = 1;i + (1 << j) - 1 <= n;i++)    st[i][j] = get(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
        if (!id[1]) id[1] = ++idx;
        top = 1;
        sta[top] = 1;
        dfs2(1);
        int ans = 0;
        read(m);
        while(m--) {
            int u, v;
            read(u, v);
            u ^= ans;
            v ^= ans;
            tt.reset();
            int lc = lca(u, v);
            int ss = dep[u] + dep[v] - 2 * dep[lc] + 1;
            while(u != lc and !id[u])   tt.set(a[u]), u = f[u];
            while(v != lc and !id[v])   tt.set(a[v]), v = f[v];
            if (u != lc) {
                int p = u;
                while(dep[F[p]] >= dep[lc])  p = F[p];
                if (u != p) tt |= b[id[p]][id[u]];
                while(p != lc)  tt.set(a[p]), p = f[p];
            }
            if (v != lc) {
                int p = v;
                while(dep[F[p]] >= dep[lc])  p = F[p];
                if (v != p) tt |= b[id[p]][id[v]];
                while(p != lc)  tt.set(a[p]), p = f[p];
            }
            tt.set(a[lc]);
            int sum = tt.count();
            // cout << sum << " " << ss << "\n";
            if (sum < ss) {
                puts("Yes");
                ans = (1ll*ans * base + 1) % mod;
            }
            else {
                puts("No");
                ans = (1ll*ans * base) % mod;
            }
        }
        return ;
    }
}

signed main()
{
    freopen("temple.in","r",stdin);
    freopen("temple.out","w",stdout);

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