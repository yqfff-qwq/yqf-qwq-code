#include "testlib.h"
#include <bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
using namespace std;
cint N = 2e6, M = 5e6;
int n, m;
int head[N + 1];
struct edge {
    int to, nxt;
} E[M << 1 | 1];
int tot;
int u, v, cnt;
bool fu[N + 1], fv[N + 1];
inline void add_edge(cint u, cint v) {
    E[++tot] = edge{u, head[v]};
    head[v] = tot;
    E[++tot] = edge{v, head[u]};
    head[u] = tot;
}
void solve() {
    n = inf.readInt();
    m = inf.readInt();
    tot = 0;
    for (int i = 1; i <= n; ++i)
        head[i] = fu[i] = fv[i] = 0;
    for (int i = 1; i <= m; ++i)
        add_edge(inf.readInt(), inf.readInt());
    cnt = 0;
    u = ouf.readInt(1, n), v = ouf.readInt(1, n);
    if (u == v)
        quitf(_wa, "u=v!");
    for (int i = head[u]; i; i = E[i].nxt)
        fu[E[i].to] = 1;
    for (int i = head[v]; i; i = E[i].nxt)
        fv[E[i].to] = 1;
    for (int i = 1; i <= n; ++i)
        cnt += (fu[i] && fv[i]);
    if (cnt & 1)
        quitf(_wa, "|N(u) cap N(v)|=%d!", cnt);
}
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int T = inf.readInt();
    while (T--)
        solve();
    quitf(_ok, "You're right!");
    return 0;
}