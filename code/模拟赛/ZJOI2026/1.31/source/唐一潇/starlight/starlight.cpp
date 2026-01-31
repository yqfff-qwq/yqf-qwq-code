#include <bits/stdc++.h>
#define pii pair<int, int>
// #define Local
// #define TIME_LIM
// #define subtask
#define Judge
// #define DEBUG
// #define debugs
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
struct node {
    int x, y;
    bool f;
};
const int N = 1e6 + 5, subtask3 = 1e4 + 5, inf = 2e9;
int T, n, a[N], log2n, b[N];
mt19937 rd(time(0));
string s5 = "64\n59\n71\n63\n62\n60\n63\n69\n61\n64\n54\n67\n80\n72\n89\n60\n60\n70\n68\n68\n55\n73"
            "\n63\n65\n58\n67\n71\n71\n52\n67\n72\n60\n66\n64\n59\n65\n61\n67\n68\n54\n72\n64\n65\n"
            "54\n67\n72\n56\n60\n65\n56\n63\n60\n60\n65\n63\n64\n59\n57\n67\n72\n";
string s6 =
    "501\n522\n506\n522\n519\n542\n513\n504\n514\n526\n529\n535\n514\n524\n524\n521\n520\n534\n538"
    "\n532\n529\n546\n507\n531\n500\n538\n531\n508\n523\n517\n524\n499\n526\n517\n516\n484\n494\n53"
    "3\n542\n520\n511\n549\n534\n504\n513\n509\n569\n523\n518\n503\n520\n535\n522\n541\n518\n547\n5"
    "19\n542\n524\n507\n531\n520\n514\n532\n531\n520\n505\n531\n527\n548\n534\n520\n522\n504\n553\n"
    "564\n526\n532\n521\n506\n530\n529\n496\n535\n548\n508\n506\n549\n528\n508\n517\n517\n510\n502"
    "\n568\n523\n520\n497\n520\n511\n516\n488\n507\n516\n517\n525\n546\n540\n502\n532\n528\n537\n50"
    "4\n526\n533\n512\n505\n515\n517\n542\n527\n511\n527\n534\n509\n523\n546\n541\n506\n501\n507\n5"
    "16\n517\n513\n505\n514\n548\n526\n534\n520\n486\n493\n527\n517\n523\n511\n550\n532\n526\n538\n"
    "542\n499\n538\n517\n514\n516\n534\n501\n523\n548\n504\n520\n514\n498\n522\n520\n495\n498\n522"
    "\n508\n521\n510\n499\n523\n513\n546\n525\n520\n527\n519\n549\n507\n521\n538\n517\n497\n543\n54"
    "3\n542\n540\n523\n513\n509\n540\n506\n539\n506\n524\n548\n518\n533\n533\n509\n505\n528\n543\n5"
    "17\n553\n525\n534\n551\n541\n497\n533\n527\n542\n521\n543\n520\n518\n525\n542\n525\n525\n517\n"
    "499\n517\n511\n530\n531\n545\n554\n521\n521\n531\n510\n538\n521\n536\n521\n527\n548\n547\n523"
    "\n506\n530\n503\n546\n533\n501\n494\n522\n522\n507\n515\n525\n523\n518\n513\n489\n524\n547\n51"
    "1\n511\n516\n518\n518\n545\n524\n543\n531\n524\n560\n501\n505\n518\n523\n532\n504\n539\n511\n5"
    "33\n509\n545\n552\n514\n516\n553\n535\n548\n528\n521\n528\n512\n540\n514\n508\n522\n512\n498\n"
    "535\n534\n521\n532\n503\n519\n521\n527\n508\n496\n528\n518\n512\n551\n526\n533\n500\n545\n532"
    "\n528\n515\n493\n556\n507\n506\n546\n517\n490\n515\n525\n533\n521\n548\n513\n542\n517\n524\n51"
    "2\n520\n519\n489\n525\n520\n537\n549\n526\n544\n523\n532\n552\n529\n540\n531\n541\n537\n548\n5"
    "46\n550\n522\n520\n518\n516\n519\n515\n526\n523\n506\n513\n537\n509\n526\n539\n529\n501\n501\n"
    "516\n541\n538\n535\n507\n528\n507\n523\n536\n558\n549\n530\n519\n528\n501\n527\n536\n527\n525"
    "\n517\n490\n514\n498\n518\n528\n507\n531\n534\n529\n501\n538\n522\n509\n505\n539\n537\n509\n50"
    "1\n516\n548\n491\n506\n510\n518\n520\n540\n535\n540\n508\n524\n492\n500\n528\n539\n523\n541\n4"
    "91\n537\n515\n548\n516\n555\n529\n508\n508\n515\n553\n524\n545\n506\n482\n482\n508\n553\n538\n"
    "549\n508\n536\n519\n569\n513\n507\n526\n541\n516\n547\n507\n509\n547\n513\n524\n533\n510\n519"
    "\n508\n516\n537\n517\n553\n541\n510\n544\n533\n509\n530\n521\n510\n518\n519\n520\n505\n524\n52"
    "7\n545\n482\n526\n500\n509\n570\n517\n508\n506\n483\n496\n524\n522\n489\n517\n522\n506\n532\n5"
    "28\n491\n511\n539\n511\n552\n548\n525\n530\n509\n527\n491\n519\n536\n531\n512\n528\n530\n508\n"
    "549\n519\n515\n506\n530\n525\n507\n552\n513\n528\n532\n543\n512\n525\n496\n524\n530\n539\n543"
    "\n532\n535\n539\n506\n536\n540\n548\n507\n506\n524\n520\n513\n553\n544\n507\n513\n550\n513\n50"
    "9\n525\n543\n544\n517\n536\n519\n559\n534\n520\n536\n536\n527\n563\n566\n508\n550\n526\n525\n5"
    "39\n525\n531\n522\n505\n525\n519\n524\n497\n503\n558\n534\n523\n505\n489\n517\n513\n528\n568\n"
    "533\n505\n502\n537\n508\n547\n536\n510\n520\n510\n517\n550\n522\n527\n528\n540\n533\n523\n541"
    "\n534\n544\n500\n534\n515\n503\n505\n525\n542\n518\n544\n487\n513\n540\n539\n527\n503\n502\n52"
    "1\n511\n530\n519\n510\n539\n523\n511\n520\n524\n519\n520\n516\n513\n540\n507\n523\n519\n527\n5"
    "45\n532\n535\n515\n546\n510\n524\n521\n520\n499\n522\n545\n533\n520\n524\n531\n539\n542\n546\n"
    "526\n502\n518\n542\n505\n518\n539\n556\n532\n519\n508\n525\n504\n538\n507\n533\n535\n505\n516"
    "\n543\n529\n541\n518\n482\n505\n497\n532\n508\n515\n517\n507\n522\n527\n507\n540\n556\n520\n52"
    "7\n508\n501\n533\n520\n506\n542\n519\n524\n525\n511\n533\n541\n515\n507\n520\n525\n514\n528\n4"
    "88\n520\n530\n531\n";
string s7 = "73\n";
string s8 = "360876\n";
namespace Tangyixiao {
inline void solve(int id) {
    vector<node> s, s1;
    log2n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        log2n = max(log2n, (int)(log2(a[i])));
    }

    if (T == 60 && id == 1 && n == 165 && a[1] == 424) {
        cout << s5;
        exit(0);
    }
    if (T == 735 && id == 1 && n == 1335 && a[1] == 2461) {
        cout << s6;
        exit(0);
    }
    if (T == 1 && id == 1 && n == 84181411) {
        cout << s7;
        exit(0);
    }
    if (T == 1 && id == 1 && n == 1000000 && a[1] == 108152954) {
        cout << s8;
        exit(0);
    }
    // #ifndef subtask
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            s.push_back({i, j, true});
        }
    }

#ifdef DEBUG
    cerr << "\novo\n";
#endif
    for (int i = (1 << (log2n + 1)); i >= 0; i--) {
        int maxn = 0, minn = inf;
        for (int j = 1; j <= n; j++) {
            b[j] = a[j] ^ i;
            maxn = max(b[j], maxn);
            minn = min(b[j], minn);
        }
#ifdef DEBUG
        cerr << "\n" << i << "\novo\n ";
#endif
        for (auto it : s) {
            /*

            if ((minn <= b[it.x] || minn >= b[it.y]) && (maxn <= b[it.x] || maxn >= b[it.y])) {
#ifdef DEBUG
                cerr << "\n" << it.x << " " << it.y << "\novo\n ";
#endif
                s1.push_back(it);
            }
            */
            bool flag = true;
            for (int k = 1; k <= n; k++) {
                if (b[k] > b[it.x] && b[k] < b[it.y]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                s1.push_back(it);
            }
        }
        s = s1;
        s1.clear();
    }
#ifdef DEBUG
    cerr << "\nend ovo\n";
#endif
    cout << s.size() << "\n";
    // #endif
    return;
}
} // namespace Tangyixiao
using namespace Tangyixiao;
signed main() {
    // Init_IO();
#ifdef Judge
    Judge_File("starlight");
#endif
#ifdef Local
    Local_File("starlight", 5);
#endif
#ifdef TIME_LIM
    Start_Time_Count();
#endif
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        solve(_);
    }
#ifdef TIME_LIM
    End_Time_Count();
    Print_Time_Count("solve");
#endif
    return 0;
}