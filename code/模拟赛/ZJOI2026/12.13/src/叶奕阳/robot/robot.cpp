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
#define int __int128
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    int read() {
        int x = 0, f = 1;
        char ch = getchar();
        while (!isdigit(ch)) {
            if (ch == '-') f = -f;
            ch = getchar();
        }
        while (isdigit(ch)) {
            x = x * 10 + (ch ^ 48);
            ch = getchar();
        }
        return x * f;
    }
    void print(int x) {
        if (x < 0) putchar('-'), x = -x;
        if (x > 9) print(x / 10);
        putchar('0' + x % 10);
    }
    int abs(int a) { return a >= 0 ? a : -a; }
    int max(int a, int b) { return a >= b ? a : b; }

    const int N = 4e5 + 5;
    struct M { int v1, v2, t; } move[N]; int n;
    int n1, n2, va[N], ta[N], vb[N], tb[N];

    #define mod2(x) (((x % 2) + 2) % 2)

    struct tree {
        int l[N], r[N], s[N], m, op;
        void init() { m = 0; }
        void add(int a, int b, int c) {
            if (a > b) swap(a, b);
            while (mod2(a) != mod2(op)) a++;
            while (mod2(b) != mod2(op)) b--;
            a = (a + op) / 2;
            b = (b + op) / 2;
            if (a <= b) m++, l[m] = a, r[m] = b, s[m] = c;
        }

        int b[N], tot;
        void discrete() {
            tot = 0;
            REP(i, 1, m) r[i]++;
            REP(i, 1, m) b[++tot] = l[i];
            REP(i, 1, m) b[++tot] = r[i];
            sort(b + 1, b + 1 + tot);
            tot = unique(b + 1, b + 1 + tot) - b - 1;
            REP(i, 1, m) l[i] = lower_bound(b + 1, b + 1 + tot, l[i]) - b;
            REP(i, 1, m) r[i] = lower_bound(b + 1, b + 1 + tot, r[i]) - b;
        }

        int k[N];
        int qmax() {
            int cnt = 0, res = 0, mxr = 0;
            REP(i, 1, m) k[l[i]] += s[i], MAX(mxr, l[i]);
            REP(i, 1, m) k[r[i]] -= s[i], MAX(mxr, r[i]);
            REP(i, 1, mxr) {
                cnt += k[i], k[i] = 0;
                MAX(res, cnt);
            }
            return res;
        }
    } tree0, tree1;

    void main() {
        n = 0;
        n1 = read(); REP(i, 1, n1) va[i] = read(), ta[i] = read(), ta[i] += ta[i - 1];
        n2 = read(); REP(i, 1, n2) vb[i] = read(), tb[i] = read(), tb[i] += tb[i - 1];
        int p1 = 1, p2 = 1, l = 1;
        while (p1 <= n1 && p2 <= n2) {
            int r = min(ta[p1], tb[p2]);
            move[++n] = {va[p1], vb[p2], r - l + 1};
            if (r == ta[p1]) p1++;
            if (r == tb[p2]) p2++;
            l = r + 1;
        }
        p1 = 0, p2 = 0;
        tree0.init(); tree0.op = 0;
        tree1.init(); tree1.op = 1;
        tree0.add(0, 0, 1);
        REP(i, 1, n) {
            int v1 = move[i].v1, v2 = move[i].v2, t = move[i].t;
            int q1 = p1 + v1 * t;
            int q2 = p2 + v2 * t;
            p1 = p1 + v1;
            p2 = p2 + v2;
            int dis1 = p1 - p2;
            int dis2 = q1 - q2;
            if (v1 == v2) {
                tree0.add(dis1, dis1, t);
                tree1.add(dis1, dis1, t);
            } else if (abs(v1 - v2) == 1) {
                tree0.add(dis1, dis2, 1);
                tree1.add(dis1, dis2, 1);
            } else {
                if (mod2(dis1) == 0) tree0.add(dis1, dis2, 1);
                if (mod2(dis1) == 1) tree1.add(dis1, dis2, 1);
            }
            p1 = q1;
            p2 = q2;
        }
        tree0.discrete();
        tree1.discrete();
        print(max(tree0.qmax(), tree1.qmax()));
        putchar('\n');
    }
}

signed main() {
    freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    // cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    _T = Yyydrasil::read();
    while (_T--) Yyydrasil::main();
    return 0;
}
