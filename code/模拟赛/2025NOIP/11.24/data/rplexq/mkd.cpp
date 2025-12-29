#include <bits/stdc++.h>
#include <sys/resource.h>
#define problem "rplexq"
using namespace std;
uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 sd(seed);
ofstream lgf("log.txt");
int system(const string &s){
    return system(s.c_str());
}
enum class spec { null, list, star, d100 };
const string green = "\x1b[32m";
const string reset = "\x1b[0m";
const string red = "\x1b[31m";
const string cyan = "\x1b[36m";
void gen(int subtask, int id, uint64_t seed, int nmmax, int mmlm_MB, float tmlm_s, spec sp = spec::null){
    const string file_name = problem + to_string(subtask) + "_" + to_string(id);
    ofstream input(file_name + ".in");
    if (!input)throw runtime_error("Can not open input file.");
    ofstream result(file_name + ".ans");
    if (!result)throw runtime_error("Can not open result file.");

    mt19937 mt(seed);

    lgf << "subtask=" << subtask << ",id=" << id << ",seed=" << seed << ",n,m<=" << nmmax << endl;
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
            int n, m, r;
            n = (mt() & 1? nmmax : mt() & 1? rnd(1, nmmax) : rnd(nmmax + 1 >> 1, nmmax));
            m = (mt() & 1? nmmax : mt() & 1? rnd(1, nmmax) : rnd(nmmax + 1 >> 1, nmmax));
            r = rnd(1, n);
            input << n << " " << m << " " << r << endl;
            auto prttree = [&](vector<pair<int, int> > &E){
                assert(E.size() == n - 1);
                shuffle(E.begin(), E.end(), mt);
                for (int i = 0; i < n - 1; ++i)
                    if (mt() & 1)swap(E[i].first, E[i].second);
                for (auto [u, v] : E)input << u << " " << v << "\n";
            };
            if (sp == spec::list || sp == spec::null && id == 1){
                vector<int> pts = rndperm(n);
                vector<pair<int, int> > E;
                for (int i = 1; i < n; ++i)
                    E.emplace_back(pts[i - 1], pts[i]);
                prttree(E);
                while (m--){
                    auto [l, r] = mt() % 3 == 0? make_pair(1, n) : rndsec(1, n);
                    int x = rnd(1, n);
                    input << l << " " << r << " " << x << "\n";
                }
            } else if (sp == spec::star || sp == spec::null && id == 2){
                vector<pair<int, int> > E;
                int x = rnd(1, n);
                for (int i = 1; i <= n; ++i)
                    if (i != x)E.emplace_back(i, x);
                prttree(E);
                while (m--){
                    int l, r;
                    if (mt() % 5 == 0){
                        tie(l, r) = rndsec(1, n);
                    } else switch (mt() % 3){
                        case 0 : l = r = rnd(1, n); break;
                        case 1 : l = 1, r = rnd(1, n); break;
                        case 2 : l = rnd(1, n), r = n; break;
                    }
                    int x = (id % 3 == 0? r : mt() & 1? r : rnd(1, n));
                    input << l << " " << r << " " << x << "\n";
                }
            } else {
                vector<int> dg = split(n - 1, sp == spec::d100 || id == 3? 100 : mt() % 3 == 0? n / 2 : mt() & 1? n - 1 : n / 5);
                static int d[200010];
                vector<int> p = rndperm(n);
                if (p[0] != r)swap(p[0], *find(p.begin(), p.end(), r));
                int l = dg.size();
                fill_n(d + 1, n, 0);
                for (int i = 0; i < l; ++i)d[p[i]] = dg[i];
                // d : count son
                for (int i = 1; i <= n; ++i)assert(0 <= d[i] && d[i] <= (sp == spec::d100? 100 : n - 1));
                assert(accumulate(d + 1, d + n + 1, 0) == n - 1);
                queue<int> Q;
                Q.emplace(0);
                vector<pair<int, int> > E;
                for (int u : p){
                    assert(!Q.empty());
                    int x = Q.front(); Q.pop();
                    if (x)E.emplace_back(x, u);
                    assert(d[u] >= 0);
                    while (d[u]--)Q.emplace(u);
                }
                prttree(E);
                while (m--){
                    int x = l && (mt() & 1)? p[rnd(0, l - 1)] : p[rnd(0, n - 1)];
                    int l, r;
                    if (mt() % 5 == 0){
                        tie(l, r) = rndsec(1, n);
                    } else switch (mt() % 3){
                        case 0 : l = r = rnd(1, n); break;
                        case 1 : l = 1, r = rnd(1, n); break;
                        case 2 : l = rnd(1, n), r = n; break;
                    }
                    input << l << " " << r << " " << x << "\n";
                }
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

    for (int i = 1; i <= 5; ++i)gen(1, i, sd(), 100, 2048, 3);//3s, 2048M
    for (int i = 1; i <= 5; ++i)gen(2, i, sd(), 700, 2048, 3);//3s, 2048M
    for (int i = 1; i <= 10; ++i)gen(3, i, sd(), 2000, 2048, 3);//3s, 2048M
    for (int i = 1; i <= 10; ++i)gen(4, i, sd(), 4000, 2048, 3);//3s, 2048M
    for (int i = 1; i <= 20; ++i)gen(5, i, sd(), 50000, 2048, 3);//3s, 2048M
    for (int i = 1; i <= 15; ++i)gen(6, i, sd(), 100000, 2048, 3);//3s, 2048M
    for (int i = 1; i <= 10; ++i)gen(7, i, sd(), 200000, 2048, 3, spec::list);//3s, 2048M
    for (int i = 1; i <= 10; ++i)gen(8, i, sd(), 200000, 2048, 3, spec::star);//3s, 2048M
    for (int i = 1; i <= 10; ++i)gen(9, i, sd(), 200000, 2048, 3, spec::d100);//3s, 2048M
    for (int i = 1; i <= 10; ++i)gen(10, i, sd(), 200000, 2048, 3);//3s, 2048M
    for (int i = 1; i <= 10; ++i)gen(11, i, sd(), 200000, 2048, 1);//1s, 2048M
    for (int i = 1; i <= 10; ++i)gen(12, i, sd(), 200000, 128, 3);//3s, 128M
    for (int i = 1; i <= 10; ++i)gen(13, i, sd(), 200000, 128, 1);//1s, 128M

    remove(problem".in");
    remove(problem".out");
    return 0;
}