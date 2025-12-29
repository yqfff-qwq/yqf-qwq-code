#include <bits/stdc++.h>
#define N 400010
#define INF 0x3f3f3f3f
#define eps 1e-5
#define pi 3.141592653589793
#define mod 1000000007
#define P 1000000007
#define LL long long
#define pb push_back
#define fi first
#define se second
#define cl clear
#define si size
// #define lb lower_bound
#define ub upper_bound
#define bug(x) cerr << #x << "      :   " << x << endl
#define mem(x, y) memset(x, 0, sizeof(int) * (y + 3))
#define sc(x) scanf("%d", &x)
#define scc(x, y) scanf("%d%d", &x, &y)
#define sccc(x, y, z) scanf("%d%d%d", &x, &y, &z)
using namespace std;

int n, m;
struct node {
    LL x, y;
} A[N], B[N];
LL q[N], a[2][N], b[2][N], c[2][N], d[N], w[2][N];
int s[2], r[2];
void update(LL x, LL y, LL d, int k) {
    int t = x & 1;
    a[t][++s[t]] = x;
    b[t][s[t]] = y;
    w[t][++r[t]] = x;
    w[t][++r[t]] = y;
    if (d == 0)
        c[t][s[t]] = q[k + 1] - q[k];
    else
        c[t][s[t]] = 1;
}

int main() {
    freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    int T;
    sc(T);
    while (T--) {
        int cnt = 1;
        q[1] = 0;
        sc(n);
        for (int i = 1; i <= n; i++)
            scanf("%lld%lld", &A[i - 1].y, &A[i].x), A[i].x += A[i - 1].x, q[++cnt] = A[i].x;
        sc(m);
        for (int i = 1; i <= m; i++)
            scanf("%lld%lld", &B[i - 1].y, &B[i].x), B[i].x += B[i - 1].x, q[++cnt] = B[i].x;
        sort(q + 1, q + cnt + 1);
        cnt = unique(q + 1, q + cnt + 1) - q - 1;

        LL dis = 3e18;
        r[0] = r[1] = s[0] = s[1] = 0;
        int la = 0, lb = 0, fa, fb;

        A[cnt].y = B[cnt].y = 0;
        q[cnt + 1] = q[cnt] + 1;
        for (int i = 1; i <= cnt; i++) {
            if (A[la].x == q[i])
                fa = A[la++].y;
            else
                fa = A[la - 1].y;
            if (B[lb].x == q[i])
                fb = B[lb++].y;
            else
                fb = B[lb - 1].y;
            LL x, y, t = q[i + 1] - q[i];
            if (fa == fb)
                update(dis, dis + 2, 0, i);
            else if (fa - 1 == fb) {
                x = dis;
                y = dis + t;
                dis += t;
                update(x, (t & 1) + y, 1, i);
                update(x + 1, y + 1 - (t & 1), 1, i);
            } else if (fa + 1 == fb) {
                x = dis - (t - 1);
                y = dis + 1;
                dis -= t;
                update(x, (t & 1) + y, 1, i);
                update(x + 1, y + 1 - (t & 1), 1, i);
            } else if (fa - 2 == fb) {
                x = dis;
                y = dis + t * 2;
                dis += t * 2;
                update(x, y, 1, i);
            } else if (fa + 2 && fb) {
                x = dis - t * 2 + 2;
                y = dis + 2;
                dis -= t * 2;
                update(x, y, 1, i);
            }
        }
        LL ans = 0;
        for (int j = 0; j < 2; j++) {
            sort(w[j] + 1, w[j] + 1 + r[j]);
            r[j] = unique(w[j] + 1, w[j] + 1 + r[j]) - w[j] - 1;
            for (int i = 1; i <= r[j]; i++) d[i] = 0;
            for (int i = 1; i <= s[j]; i++) {
                int x = lower_bound(w[j] + 1, w[j] + r[j] + 1, a[j][i]) - w[j],
                    y = lower_bound(w[j] + 1, w[j] + r[j] + 1, b[j][i]) - w[j];
                d[x] += c[j][i];
                d[y] -= c[j][i];
            }
            for (int i = 1; i <= r[j]; i++) d[i] += d[i - 1], ans = max(ans, d[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
