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

const int N = 2e6 + 5;
int T, n, m;
vector<int> g[N];
bool flag;
namespace Tangyixiao {
inline bool check(int idx, int idy) {
    int cnt = 0;
    map<int, int> mp;
    for (auto it : g[idx]) {
        mp[it]++;
    }
    for (auto it : g[idy]) {
        mp[it]++;
    }
    for (auto it : mp) {
        cnt += (it.second >> 1);
    }
    return !(cnt & 1);
}
inline void solve(int id) {
    flag = false;
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (flag) {
            break;
        }
        for (int j = i + 1; j <= n; j++) {
            if (check(i, j)) {
                cout << i << " " << j << "\n";
                flag = true;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    return;
}
} // namespace Tangyixiao
using namespace Tangyixiao;
signed main() {
    Init_IO();
#ifdef Local
    Local_File("void", 11);
#endif

#ifdef Judge
    Judge_File("void");
#endif
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        solve(_);
    }
    return 0;
}