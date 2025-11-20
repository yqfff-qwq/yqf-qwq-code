#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();i++)
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=((a)-(b)+mod)%mod
#define MUL(a,b) (a)=(((a)%mod)*((b)%mod))%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)a.size())
#define ppc(x)   __builtin_popcount(x)
#define DBG(x)   cerr<<#x<<' '<<(x)<<'\n'
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int N = 5e5 + 5, Q = 1e5 + 5;
    int n, base, mod, hashans, a[N], x, y, q, u1, v1;
    struct Que { int l, r, id; } b[Q]; int ans[Q];
    vector<int> edge[N];

    int dep[N], tot, eular[2 * N], a2[2 * N], dep2[2 * N], l[N], r[N];
    void dfs(int u, int fa) {
        dep[u] = dep[fa] + 1;
        eular[++tot] = u, l[u] = r[u] = tot;
        a2[tot] = a[u];
        dep2[tot] = dep[u];
        for (auto v : edge[u]) {
            if (v != fa) {
                dfs(v, u);
                eular[++tot] = u, r[u] = tot;
                a2[tot] = a[u];
                dep2[tot] = dep[u];
            }
        }
    }

    struct ST_map {
        int st[21][2 * N], lg[2 * N];
        void init(int len) {
            REP(i, 2, len) lg[i] = lg[i >> 1] + 1;
            REP(i, 1, len) st[0][i] = dep2[i];
            REP(j, 1, 20) {
                REP(i, 1, len) {
                    st[j][i] = min(st[j - 1][i], st[j - 1][min(i + (1 << (j - 1)), len)]);
                }
            }
        }
        int qdep(int l, int r) {
            int j = lg[r - l + 1];
            return min(st[j][l], st[j][r - (1 << j) + 1]);
        }
    } lca;

    int sum[N], doub;
    void sub(int x) { doub -= ((--sum[x]) == 1); }
    void add(int x) { doub += ((++sum[x]) == 2); }
    void changel(int l, int r, int l2) {
        int gendis = dep2[l]  + dep2[r] - 2 * lca.qdep(l, r);
        int newdis = dep2[l2] + dep2[r] - 2 * lca.qdep(l2, r);
        if (newdis > gendis) add(a2[l2]);
        else                 sub(a2[l]);
    }
    void changer(int l, int r, int r2) {
        int gendis = dep2[l] + dep2[r]  - 2 * lca.qdep(l, r);
        int newdis = dep2[l] + dep2[r2] - 2 * lca.qdep(l, r2);
        if (newdis > gendis) add(a2[r2]);
        else                 sub(a2[r]);
    }

    void main() {
        cin >> n >> base >> mod;
        if (mod == 1) {
            REP(i, 1, n) cin >> a[i];
            REP(i, 1, n - 1) {
                cin >> x >> y;
                edge[x].pb(y);
                edge[y].pb(x);
            }
            dfs(1, 1);
            lca.init(tot);
            cin >> q;
            REP(i, 1, q) {
                cin >> u1 >> v1;
                u1 = l[u1], v1 = l[v1];
                b[i] = {min(u1, v1), max(u1, v1), i};
            }
            int B = sqrt(tot);
            sort(b + 1, b + 1 + q, [&](Que a, Que b) {
                int id1 = a.l / B, id2 = b.l / B;
                if (id1 != id2) {
                    return id1 < id2;
                } else {
                    return id1 % 2 == 0 ? a.r < b.r : a.r > b.r;
                }
            });
            int l = 1, r = 1; sum[a2[1]] = 1;
            REP(i, 1, q) {
                while (l > b[i].l) changel(l, r, l - 1), l--;
                while (r < b[i].r) changer(l, r, r + 1), r++;
                while (r > b[i].r) changer(l, r, r - 1), r--;
                while (l < b[i].l) changel(l, r, l + 1), l++;
                ans[b[i].id] = (doub != 0);
            }
            REP(i, 1, q) cout << (ans[i] ? "Yes" : "No") << '\n';
        }
    }

    /*
    1. 对原树做 dfs 求出 dep, eular, l, r
    2. 预处理 ST 表维护 O(1) LCA
    3. 对询问离线，找到两个点在 eular 上的 l
    4. 做莫队，对于一个点的移动：
        * 向下移动，lca (dep) 改变：删除这个点
        * 向上移动，lca (dep) 不变：删除这个点
        * 其他情况：加入这个点
    */

}

signed main() {
    freopen("temple.in", "r", stdin);
    freopen("temple.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
