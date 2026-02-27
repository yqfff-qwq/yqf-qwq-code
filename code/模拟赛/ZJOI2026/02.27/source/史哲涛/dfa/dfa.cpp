#include <bits/stdc++.h>
#define file_name "dfa"
struct prg_timer {
    using csc = std::chrono::steady_clock;const csc::time_point bg;static auto now(){ return csc::now(); } prg_timer() : bg(now()) { }
    void prttm(){ std::clog << "time use = " << std::chrono::duration_cast<std::chrono::milliseconds>(now() - bg).count() << "ms" << std::endl; }
    ~prg_timer(){ prttm(); }
} tmr;
using namespace std;bool SZT_MEM_BG;

int n, m;
string s[1000010];
namespace S1 {
    void sol1(){
        map<pair<string, string>, int> mp;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j){
                string a = s[i], b = s[j];
                auto rev = [](string s){
                    reverse(s.begin(), s.end());
                    return s;
                };
                auto flp = [](string s){
                    for (char &c : s)if (c == 'a')c = 'b'; else c = 'a';
                    return s;
                };
                tie(a, b) = min({
                    make_pair(a, b),
                    make_pair(flp(a), flp(b)),
                    make_pair(rev(a), rev(b)),
                    make_pair(rev(flp(a)), rev(flp(b))),
                    make_pair(b, a),
                    make_pair(flp(b), flp(a)),
                    make_pair(rev(b), rev(a)),
                    make_pair(rev(flp(b)), rev(flp(a)))
                });
                if (a.find(b) != string::npos || b.find(a) != string::npos)continue;
                ++mp[{a, b}];
            }
        for (auto it = mp.begin(); it != mp.end(); )
            if (it->second > 1767)it = mp.erase(it);
            else ++it;
        vector<pair<pair<string, string>, int> > vec{mp.begin(), mp.end()};
        int ct = 0;
        for (int s = 1; s < 1 << vec.size(); ++s){
            int sm = 0;
            for (int i = 0; i < vec.size(); ++i)if (s >> i & 1)sm += vec[i].second;
            if (sm == 1767){
                for (int i = 0; i < vec.size(); ++i)if (s >> i & 1){
                    cout << vec[i].first.first << "," << vec[i].first.second << "," << vec[i].second << " ";
                }
                cout << endl;
                ++ct;
                if (ct > 100)break;
            }
        }
        int rs = 0;
        for (auto [ss, c] : mp){
            auto [a, b] = ss;
            cout << a << "," << b << ":" << c << endl;
        }
        cout << rs << endl; // +1767
        exit(0);
    }
}

bool SZT_MEM_ED;int main(){
    // freopen(file_name".in", "r", stdin);
    // freopen(file_name".out", "w", stdout);
    freopen("ex_dfa2.in", "r", stdin);
    freopen(".out", "w", stdout);
    const double static_local_mem_use = fabs(&SZT_MEM_ED - &SZT_MEM_BG) / 1024 / 1024;
    clog << "static local mem use = " << static_local_mem_use << "M" << endl;
    assert(static_local_mem_use < 64);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)cin >> s[i];
    if (n <= 1000)S1::sol1();

    return 0;
}