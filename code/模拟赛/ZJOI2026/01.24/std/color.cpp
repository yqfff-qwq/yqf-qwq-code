#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;

const int N = 5000 + 8, P = 1e9 + 7;

int n, m, a[N][N], sum[N], col[N], L[N], R[N], p1[N], p2[N], p3[N], p4[N];

inline void inc(int& a, int b) {
    if((a += b) >= P) a -= P;
}
inline void dec(int& a, int b) {
    if((a -= b) < 0) a += P;
}
inline int add(int a, int b) {
    return (a += b) < P ? a : a - P;
}
inline void reduce(int i, int l, int r) {
    l = min(l, R[i] + 1);
    while(L[i] < l) {
        int v = a[i][L[i]];
        dec(sum[i], v), dec(sum[L[i]], v), a[i][L[i]++] = 0;
    }
    r = max(r, L[i]);
    while(R[i] >= r) {
        int v = a[i][R[i]];
        dec(sum[i], v), dec(sum[R[i]], v), a[i][R[i]--] = 0;
    }
} 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        int l, r, x;
        rep(i, 0, n) sum[i] = p2[i] = p4[i] = L[i] = 0, p1[i] = p3[i] = R[i] = i;
        while(m--) {
            cin >> l >> r >> x;
            if(x == 1) p1[r] = min(p1[r], l);
            if(x == 2) p2[r] = max(p2[r], l), p3[r] = min(p3[r], l);
            if(x == 3) p4[r] = max(p4[r], l);
        }
        rep(i, 0, n) rep(j, 0, n) a[i][j] = 0;
        a[0][0] = 3, sum[0] = 6;
        rep(i, 1, n) {
            rep(j, 0, i - 2) a[i - 1][j] = sum[j], inc(sum[i - 1], sum[j]), inc(sum[j], sum[j]);
            For(j, 0, p2[i]) reduce(j, 0, 0);
            For(j, p2[i], p1[i]) reduce(j, p4[i], p3[i]);
            For(j, p1[i], i) reduce(j, 0, 0);
        }
        int ans = 0;
        rep(i, 0, n) rep(j, 0, n) inc(ans, a[i][j]);
        cout << ans << '\n';
    }
}
