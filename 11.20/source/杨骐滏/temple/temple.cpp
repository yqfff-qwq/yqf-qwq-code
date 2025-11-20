#include<bits/stdc++.h>
using namespace std;

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
    const int N = 1e5 + 10;
    int n, base, mod;
    int q;
    struct node{
        int u, v;
    }qy[N];
    int a[N];
    vector<int> ve[N];
    int idx;
    int f[N];
    int dep[N];
    int vis[N];
    bool dfs(int u, int v) {
        if (u == v) return 0;
        vis[a[u]] = idx;
        if (vis[a[v]] == idx)   return 1;
        vis[a[v]] = idx;
        while(u != v) {
            // cout << u << " " << v << "\n";
            // REP(i, 1, 100000000);
            if (dep[u] < dep[v])    swap(u, v);
            u = f[u];
            if (u == v) break;
            if (vis[a[u]] == idx)   return 1;
            vis[a[u]] = idx;
        }
        return 0;
    }
    void ds(int u, int fa) {
        f[u] = fa;
        dep[u] = dep[fa] + 1;
        for(auto it:ve[u]) {
            if (it == fa)   continue;
            ds(it, u);
        }
        return;
    }
    void solve() {
        ds(1, 0);
        REP(i, 1, q) {
            idx++;
            if (dfs(qy[i].u, qy[i].v))  puts("Yes");
            else                        puts("No");
        }
        return;
    }
    void main() {
        read(n, base, mod);
        REP(i, 1, n)    read(a[i]);
        REP(i, 1, n - 1) {
            int u, v;
            read(u, v);
            ve[u].pb(v);
            ve[v].pb(u);
        }
        read(q);
        REP(i, 1, q)    read(qy[i].u, qy[i].v);
        if (n <= 5000) {
            solve();
            return;
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