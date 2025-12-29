#include <bits/stdc++.h>
#include <sys/resource.h>
#define problem "paint"
using namespace std;
uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 sd(seed);
ofstream lgf("log.txt");
int system(const string &s){
    return system(s.c_str());
}
const string green = "\x1b[32m";
const string reset = "\x1b[0m";
const string red = "\x1b[31m";
const string cyan = "\x1b[36m";
void gen(int subtask, int id, uint64_t seed, int mmlm_MB, float tmlm_s, int nmmax, int qmax){
    const string file_name = problem + to_string(subtask) + "_" + to_string(id);
    ofstream input(file_name + ".in");
    if (!input)throw runtime_error("Can not open input file.");
    ofstream result(file_name + ".ans");
    if (!result)throw runtime_error("Can not open result file.");

    mt19937 mt(seed);

    lgf << "subtask=" << subtask << ",id=" << id << ",seed=" << seed << ",n,m<=" << nmmax << ",q<=" << qmax << endl;
    clog << "generating:" << file_name << endl;

    auto rnd = [&](int l, int r){
        assert(l <= r);
        return uniform_int_distribution<int>{l, r}(mt);
    };

    auto rndsec = [&](int l, int r) -> pair<int, int> {// equal probability random generation
        assert(l <= r);
        int L = r - l + 1;
        if (rnd(1, L + 1) == 1){
            int x = rnd(l, r);
            return make_pair(x, x);
        }
        int x = rnd(l, r), y = rnd(l, r);
        return minmax(x, y);
    };

    auto rndf = [&]{
        return generate_canonical<double, 12>(mt);
    };

    auto split = [&](int s, int l) -> vector<int> { // split s to several integers' sum, int <= l and >= 1 and approach to l
        assert(l >= 1);
        vector<int> ret;
        while (s){
            int t = normal_distribution<float>{0, 20}(mt);
            t = l - abs(t);
            t = max(1, min(t, s));
            s -= t;
            ret.emplace_back(t);
        }
        return ret;
    };

    auto rndperm = [&](int n) -> vector<int> {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end(), mt);
        return p;
    };

    {
        auto bg = chrono::steady_clock::now();
        {
            int n = mt() % 3? nmmax : rnd(1, nmmax), m = mt() % 3? nmmax : rnd(1, nmmax), q = mt() % 7? qmax : rnd(1, qmax);
            input << n << " " << m << " " << q << endl;
            static char c[4010][4010];
            switch (mt() % 6){//gen back
                case 0 : { // same
                    char ch = rnd('A', 'Z');
                    for (int i = 1; i <= n; ++i)
                        fill_n(c[i] + 1, m, ch);
                } break;
                case 1 : { // rand
                    for (int i = 1; i <= n; ++i)
                        for (int j = 1; j <= m; ++j)
                            c[i][j] = rnd('A', 'Z');
                } break;
                case 2 : { // svrl rnd
                    char c1 = rnd('A', 'Z'), c2 = rnd('A', 'Z');
                    for (int i = 1; i <= n; ++i)
                        for (int j = 1; j <= m; ++j)
                            c[i][j] = mt() & 1? c1 : c2;
                } break;
                case 3 : { // color area
                    int ct = rnd(5, 10);
                    vector<int> p(ct);
                    if (m == 1)ct = 0;
                    else for (int &x : p){
                        switch (mt() % 3){
                            case 0 : x = rnd(1, max(1, m / 4)); break;
                            case 1 : x = rnd(m - 1 - max(1, m / 4) + 1, m - 1); break;
                            case 2 : x = rnd(1, m - 1); break;
                        }
                    }
                    sort(p.begin(), p.end());
                    set<char> CC;
                    while (CC.size() <= ct)CC.emplace(rnd('A', 'Z'));
                    vector<char> C(CC.begin(), CC.end());
                    for (int i = 1; i <= n; ++i){
                        for (int &x : p){
                            vector<int> C{x, x};
                            for (int u = max(1, x - 3); u <= min(m, x + 3); ++u)
                                C.emplace_back(u);
                            x = C[rnd(0, C.size() - 1)];
                        }
                        sort(p.begin(), p.end());
                        vector<int> P;
                        P.emplace_back(0);
                        for (int u : p)P.emplace_back(u);
                        P.emplace_back(m);
                        assert(P.size() == ct + 2);
                        for (int j = 1; j <= ct + 1; ++j)
                            fill(c[i] + P[j - 1] + 1, c[i] + P[j] + 1, C[j - 1]);
                    }
                } break;
                case 4 : case 5 : {
                    int t = (n + m) << 1;
                    while (t--){
                        int o = rnd(0, 1);
                        char ch = rnd('A', 'Z');
                        if (o == 0){
                            auto [l, r] = rndsec(1, m);
                            int x = rnd(1, n);
                            for (int i = l; i <= r; ++i)c[x][i] = ch;
                        } else {
                            auto [l, r] = rndsec(1, n);
                            int x = rnd(1, m);
                            for (int i = l; i <= r; ++i)c[i][x] = ch;
                        }
                    }
                    for (int i = 1; i <= n; ++i)
                        for (int j = 1; j <= m; ++j)
                            if (!c[i][j])c[i][j] = rnd('A', 'Z');
                } break;
            }
            switch (mt() % 3){ // gen fore
                case 0 : { // diff point
                    int t = n * m / int(log(min(n, m)) + 1);
                    while (t--){
                        int x = rnd(1, n), y = rnd(1, m);
                        char ch = rnd('A', 'Z');
                        c[x][y] = ch;
                    }
                } break;
                case 1 : { // small color area
                    int t = n * m / log(n + m) / log(n + m);
                    while (t--){
                        int x = rnd(1, n), y = rnd(1, m);
                        char ch = rnd('A', 'Z');
                        int cnt = 0;
                        int tgt = sqrt(n + m) / log(n + m);
                        auto dfs = [&](auto &&slf, int x, int y) -> void {
                            if (cnt < tgt){
                                if (mt() % 4 == 0)return;
                            } else {
                                if (mt() % 8)return;
                            }
                            ++cnt;
                            c[x][y] = ch;
                            if (x > 1)slf(slf, x - 1, y);
                            if (x < n)slf(slf, x + 1, y);
                            if (y > 1)slf(slf, x, y - 1);
                            if (y < m)slf(slf, x, y + 1);
                        };
                        dfs(dfs, x, y);
                    }
                } break;
                case 2 : { // several diff and spread
                    int t = (n + m) * log(n + m);
                    while (t--){
                        int x = rnd(1, n), y = rnd(1, m);
                        char ch = rnd('A', 'Z');
                        c[x][y] = ch;
                    }
                    for (int i = 1; i <= n; ++i)
                        for (int j = 1; j <= m; ++j){
                            static pair<int, int> nr[6]; int tp = 0;
                            if (i > 1)nr[++tp] = make_pair(i - 1, j);
                            if (i < n)nr[++tp] = make_pair(i + 1, j);
                            if (j > 1)nr[++tp] = make_pair(i, j - 1);
                            if (j < m)nr[++tp] = make_pair(i, j + 1);
                            nr[++tp] = make_pair(i, j);
                            auto [x, y] = nr[rnd(1, tp)];
                            c[x][y] = c[i][j];
                        }
                } break;
            }
            for (int i = 1; i <= n; ++i, input << "\n")
                for (int j = 1; j <= m; ++j)input << c[i][j];
            auto rnds = [&](int t){
                if (mt() % 3 == 0){
                    int x = rnd(1, t);
                    int y = rnd(x, min(t, x + 10));
                    return make_pair(x, y);
                }
                return rndsec(1, t);
            };
            while (q--){
                auto [xl, xr] = rnds(n);
                auto [yl, yr] = rnds(m);
                input << xl << " " << yl << " " << xr << " " << yr << "\n";
            }
        }
        auto ed = chrono::steady_clock::now();
        clog << "use " << chrono::duration_cast<chrono::milliseconds>(ed - bg).count() << "ms" << endl;
    }

    input.flush(); input.close();

    {
        system("cat " + file_name + ".in >"problem".in");
        {//limit
            auto set_limit = [&](int resource_type, rlim_t soft_limit, rlim_t hard_limit){
                struct rlimit limit;
                limit.rlim_cur = soft_limit;  // 软限制
                limit.rlim_max = hard_limit; // 硬限制
                if (setrlimit(resource_type, &limit) == -1) {
                    perror("setrlimit failed");
                    throw runtime_error("set limit RE");
                }
            };
            // rlim_t timlim_s = (rlim_t)ceil(tmlm_s);
            // set_limit(RLIMIT_CPU, timlim_s, timlim_s);
            rlim_t memlim_b = (rlim_t)mmlm_MB << 20;
            set_limit(RLIMIT_STACK, memlim_b, memlim_b);
            // set_limit(RLIMIT_AS, memlim_b, memlim_b);
        }
        clog << "std running" << endl;
        auto bg = chrono::steady_clock::now();
        int ret = system("./"problem);
        auto ed = chrono::steady_clock::now();
        auto dur = chrono::duration_cast<chrono::milliseconds>(ed - bg);
        if (ret)throw runtime_error("RE");
        clog << "use " << green << dur.count() << "ms" << reset << endl;
        if (dur > chrono::duration<float>(tmlm_s))throw runtime_error("TLE");
        system("cat "problem".out >" + file_name + ".ans");
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    if (!lgf)throw runtime_error("Can not open log file.");
    if (system("g++ "problem".cpp -o "problem" -O2 -std=c++14 -static -Wall -Wextra -pedantic"))
        throw runtime_error("Can not compiler file.");
    lgf << "global seed=" << seed << endl;

    for (int i = 1; i <= 5; ++i)gen(1, i, sd(), 512, 3, 50, 5000);//5pts
    for (int i = 1; i <= 5; ++i)gen(2, i, sd(), 512, 3, 100, 5000);//4pts
    for (int i = 1; i <= 10; ++i)gen(3, i, sd(), 512, 3, 500, 500);//10pts
    for (int i = 1; i <= 10; ++i)gen(4, i, sd(), 512, 3, 500, 5000);//12pts
    for (int i = 1; i <= 10; ++i)gen(5, i, sd(), 512, 3, 700, 700);//8pts
    for (int i = 1; i <= 15; ++i)gen(6, i, sd(), 512, 3, 1000, 1000);//20pts
    for (int i = 1; i <= 10; ++i)gen(7, i, sd(), 512, 3, 1500, 2000);//12pts
    for (int i = 1; i <= 10; ++i)gen(8, i, sd(), 512, 3, 2000, 3000);//15pts
    for (int i = 1; i <= 10; ++i)gen(9, i, sd(), 512, 3, 3000, 5000);//7pts
    for (int i = 1; i <= 10; ++i)gen(10, i, sd(), 512, 3, 4000, 5000);//7pts

    remove(problem".in");
    remove(problem".out");
    return 0;
}