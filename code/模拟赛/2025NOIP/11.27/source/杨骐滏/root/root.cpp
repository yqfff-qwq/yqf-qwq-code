// #include <bits/stdc++.h>
#include <iostream>

#define int long long
#define ll long long
#define pii pair<int, int>
#define REP(i, l, r)    for(int i = (l);i <= (r);i++)
#define DEP(i, r, l)    for(int i = (r);i >= (l);i--)
#define pb push_back
#define fi first
#define se second

void read() {}
template <typename T1, typename ...T2> inline void read(T1 &x, T2 &...oth) {
    x = 0;
    int ch = getchar(), f = 0;
    while(ch < '0' or ch > '9') {
        if (ch == '-')  f = 1;
        ch = getchar();
    }
    while('0' <= ch and ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    if (f)  x = -x;
    read(oth...);
    return;
}

namespace YZLK{
    const int inf = 1e18;
    int n, m;
    void main() {
        read(n, m);
        int cnt = 0;
        int L, R;
        int l = 0, r = m / n + 10;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (mid <= (m - n - 1) / n) {
                l = mid;
            }
            else    r = mid - 1;
        }
        L = l;
        cnt += (l + 1);
        l = 0, r = m / n + 10;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (mid <= (m + n - 1) / n) {
                l = mid;
            }
            else    r = mid - 1;
        }
        R = l;
        // std::cout << L << " " << R << " " << cnt << "\n";
        REP(i, L + 1, R) {
            if ((((i * n) + 1) ^ (n - 1)) <= m)   cnt++;
            // std::cout << (((i * n) + 1) ^ (n - 1)) << "\n";
        }
        std::cout << cnt << "\n";
        return;
    }
 }

signed main() {
    freopen("root.in","r",stdin);
    freopen("root.out","w",stdout);
    // std::cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    read(T);
    while(T--) {
        YZLK::main();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}