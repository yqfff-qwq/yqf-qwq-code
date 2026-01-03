#include <bits/stdc++.h>
#define ll long long
//#define re register
#define inf 0x3f3f3f3f
#define il inline
#define db double
//#define F(i,p,b) for(re int i=(p);i<=(b);i++)
//#define f(i,p,b) for(re int i=(p);i>=(b);i--)
#define F(i,p,b) for(int i=(p);i<=(b);i++)
#define f(i,p,b) for(int i=(p);i>=(b);i--)//虚拟评测用这个
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
il int read() {
    int w = 1, c = 0;
    char ch = getchar();

    for (; ch > '9' || ch < '0'; ch = getchar())
        if (ch == '-')
            w = -1;

    for (; ch >= '0' && ch <= '9'; ch = getchar())
        c = (c << 3) + (c << 1) + ch - 48;

    return w * c;
}
void printt(int x) {
    if (x > 9)
        printt(x / 10);

    putchar(x % 10 + 48);
}
il void print(int x) {
    if (x < 0)
        putchar('-'), printt(-x);
    else
        printt(x);
}
il void put(int x) {
    print(x);
    putchar('\n');
}
const int N = 1e3 + 10;
int n;
int p[N];
char ans[N];
void dfs(int u, int x) {
    if (u == n + 1) {
        if (!x) {
            puts(ans + 1);
            exit(0);
        }

        return;
    }

    if (ans[u]) {
        if (ans[u]^')')
            return dfs(u + 1, x + 1);

        if (x)
            return dfs(u + 1, x - 1);

        return;
    }

    if (p[u] > u || ans[p[u]]^'(')
        ans[u] = '(', ans[p[u]] = ')', dfs(u + 1, x + 1), ans[u] = ans[p[u]] = ' ';

    if (x)
        ans[u] = ')', dfs(u + 1, x - 1), ans[u] = ' ';
}
il void solve() {
    n = read();
    F(i, 1, n) p[i] = read();
    dfs(1, 0);
}
int main() {
    int T = 1;

    //  T=read();
    while (T--)
        solve();

    return 0;
}