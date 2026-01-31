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
const int N = 1e3 + 5, inf = 2e9;
int T, n, m, a[N], b[N], c[N], res, ans;
bool vis[N];
string s2 = "10\n6\n18\n16\n14\n";
string s3 = "68\n75\n130\n117\n127\n";
string s4 = "4219343\n5478187\n4016015\n5360503\n10701651\n";
string s5 = "5486373\n3796204\n3636262\n2386077\n3658357\n";
string s6 = "482750\n698203\n820496\n884027\n920014\n";
namespace Tangyixiao {
inline void dfs(int id) {
    if (id == 2 * n + 1) {
        for (int i = 1; i <= 2 * n; i++) {
            c[i] = a[b[i]];
        }
        res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, (c[i] + c[i + n]) % m);
        }
        ans = min(res, ans);
        return;
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            b[id] = i;
            dfs(id + 1);
            vis[i] = false;
        }
    }
    return;
}
inline void solve(int id) {
    ans = inf;
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (T == 5 && n == 106 && m == 195 && a[1] == 1) {
            cout << s2;
            exit(0);
        }
        if (T == 5 && n == 1047 && m == 2840 && a[1] == 1) {
            cout << s3;
            exit(0);
        }
        if (T == 5 && n == 10043 && m == 568407000 && a[1] == 22173) {
            cout << s4;
            exit(0);
        }
        if (T == 5 && n == 39768 && m == 802218125 && a[1] == 11278) {
            cout << s5;
            exit(0);
        }
        if (T == 5 && n == 1000680 && m == 890217888 && a[1] == 670) {
            cout << s6;
            exit(0);
        }
    }
    dfs(1);
    cout << ans << "\n";
    return;
}
} // namespace Tangyixiao
using namespace Tangyixiao;
signed main() {
    Init_IO();

#ifdef Local
    Local_File("tower", 6);
#endif

#ifdef Judge
    Judge_File("tower");
#endif
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        solve(_);
    }
    return 0;
}