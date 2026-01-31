#include <bits/stdc++.h>
// #define Local
#define Judge
using namespace std;
namespace IO {
inline void Init_IO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return;
}
} // namespace IO
using namespace IO;
namespace FILE_IO {
const string Insuffix = ".in";
const string Outsuffix = ".out";
const string Anssuffix = ".ans";
inline void Judge_File(string File_Name) {
    freopen((File_Name + Insuffix).c_str(), "r", stdin);
    freopen((File_Name + Outsuffix).c_str(), "w", stdout);
    return;
}
inline void Local_File(string File_Name, int File_Idx) {
    freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin);
    freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout);
    return;
}
} // namespace FILE_IO
using namespace FILE_IO;
namespace TIME {
clock_t Start_Time, End_Time;
inline void Start_Time_Count() {
    Start_Time = clock();
    return;
}
inline void End_Time_Count() {
    End_Time = clock();
    return;
}
inline double Time_Count() {
    double Time = (double)(End_Time - Start_Time) / CLOCKS_PER_SEC;
    return Time;
}
inline void Print_Time_Count(string Programe_Name) {
    cerr << fixed << setprecision(4) << "\n" << Programe_Name << " Time: " << Time_Count() << "s\n";
    return;
}
} // namespace TIME
using namespace TIME;
const int N = 2e6 + 5, inf = 2e9;
int T, n, l, a[N], ans, b[N], c[N];
namespace Tangyixiao {
inline void dfs(int cnt, int maxn, int minn) {
    /*

    if (maxn - minn >= ans) {
        return;
    }
    */
    if (cnt == n) {
        b[cnt] = l;
        maxn = max(b[cnt] - b[cnt - 1], maxn);
        minn = min(b[cnt] - b[cnt - 1], minn);
        if (maxn - minn < ans) {
            for (int i = 0; i <= n; i++) {
                c[i] = b[i];
            }
            ans = maxn - minn;
        }
        return;
    }

    for (int i = a[cnt]; i <= a[cnt + 1]; i++) {
        if (i != b[cnt - 1]) {
            b[cnt] = i;
            dfs(cnt + 1, max(b[cnt] - b[cnt - 1], maxn), min(b[cnt] - b[cnt - 1], minn));
        }
    }
    return;
}
inline void solve(int id) {
    ans = inf + 1;
    cin >> l >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = b[n + 1] = c[n + 1] = l;
    dfs(1, 0, inf);
    for (int i = 0; i <= n; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
    return;
}
} // namespace Tangyixiao
using namespace Tangyixiao;
signed main() {
    Init_IO();
#ifdef Local
    Local_File("synapse", 2);
#endif

#ifdef Judge
    Judge_File("synapse");
#endif
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        solve(_);
    }
    return 0;
}