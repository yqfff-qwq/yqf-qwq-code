#include <bits/stdc++.h>
#include <sys/resource.h>
#define problem "interval"
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
#if __cplusplus < 201703L
template <typename _Tp>
constexpr const _Tp &
clamp(const _Tp &__val, const _Tp &__lo, const _Tp &__hi)
{
    __glibcxx_assert(!(__hi < __lo));
    return (__val < __lo) ? __lo : (__hi < __val) ? __hi
                                                    : __val;
}
/// Take a random sample from a population.
template <typename _PopulationIterator, typename _SampleIterator,
            typename _Distance, typename _UniformRandomBitGenerator>
_SampleIterator
sample(_PopulationIterator __first, _PopulationIterator __last,
        _SampleIterator __out, _Distance __n,
        _UniformRandomBitGenerator &&__g)
{
    using __pop_cat = typename std::iterator_traits<_PopulationIterator>::iterator_category;
    using __samp_cat = typename std::iterator_traits<_SampleIterator>::iterator_category;

    static_assert(
        __or_<is_convertible<__pop_cat, forward_iterator_tag>,
                is_convertible<__samp_cat, random_access_iterator_tag>>::value,
        "output range must use a RandomAccessIterator when input range"
        " does not meet the ForwardIterator requirements");

    static_assert(is_integral<_Distance>::value,
                    "sample size must be an integer type");

    typename iterator_traits<_PopulationIterator>::difference_type __d = __n;
    return _GLIBCXX_STD_A::
        __sample(__first, __last, __pop_cat{}, __out, __samp_cat{}, __d,
                    std::forward<_UniformRandomBitGenerator>(__g));
}
#endif
enum class spec {
    null,
    no_partial_intersection,
    op2_after_op1
};
void gen(int subtask, int id, uint64_t seed, int nmax, spec sp, int mmlm_MB = 512, float tmlm_s = 1){ // memory limit, time limit
    const string file_name = problem + to_string(subtask) + "_" + to_string(id);
    ofstream input(file_name + ".in");
    if (!input)throw runtime_error("Can not open input file.");
    ofstream result(file_name + ".ans");
    if (!result)throw runtime_error("Can not open result file.");

    mt19937 mt(seed);

    lgf << "subtask=" << subtask << ",id=" << id << ",seed=" << seed << ",n<=" << nmax << ",spec=" << (sp == spec::null? "null" : sp == spec::no_partial_intersection? "no partial intersection" : "op2 after op1") << endl;
    clog << "generating:" << file_name << endl;

    auto rnd = [&](int l, int r){
        assert(l <= r);
        return uniform_int_distribution<int>{l, r}(mt);
    };

    auto rndf = [&](double l, double r){
        return uniform_real_distribution<double>{l, r}(mt);
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

    auto rndfi = [&]{
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

    auto rndbl = [&](int n) -> string { // random uniform matched bracket list length = 2n
        vector<long double> catlog(n + 1); // log(H_i)
        catlog[0] = 0.0;
        for (int i = 1; i <= n; ++i)
            catlog[i] = catlog[i - 1] + log(1.L * (4 * i - 2) / (i + 1));
        auto spl = [&](int n){
            if (n <= 1)return 0;
            if (n <= 1000){
                vector<long double> log_prob(n);
                for (int i = 0; i < n; ++i)log_prob[i] = catlog[i] + catlog[n - 1 - i] - catlog[n];
                long double max_log_prob = *max_element(log_prob.begin(), log_prob.end());
                vector<long double> probs(n);
                for (int i = 0; i < n; ++i)probs[i] = exp(log_prob[i] - max_log_prob);
                const long double r = rndf(0.L, accumulate(probs.begin(), probs.end(), 0.L));
                double cumulative = 0.0;
                for (int i = 0; i < n; i++){
                    cumulative += probs[i];
                    if (r <= cumulative)return i;
                }
                return n - 1;
            } else {
                // 正态近似
                // 均值为 n/2，标准差为 sqrt(n)/2
                normal_distribution<long double> normal(n / 2.0, sqrtl(n) / 2.0);
                for (int attempt = 0; attempt < 5; attempt++) {
                    int i = lround(normal(mt));
                    if (i >= 0 && i < n) {
                        // 简单的拒绝采样，确保不会太偏
                        double ideal_prob = 1.0 / (sqrtl(M_PI * n) / 2.0); // 正态分布的峰值
                        double actual_prob = exp(catlog[i] + catlog[n - 1 - i] - catlog[n]);
                        uniform_real_distribution<double> uniform(0.0, ideal_prob);
                        if (uniform(mt) <= actual_prob)
                            return i;
                    }
                }
                // 如果拒绝采样失败，返回中间值
                return n / 2;
            }
        };
        auto gen = [&](auto &&slf, int n) -> string {
            if (!n)return "";
            int i = spl(n);
            return "(" + slf(slf, i) + ")" + slf(slf, n - 1 - i);
        };
        return gen(gen, n);
    };

    {
        auto bg = chrono::steady_clock::now();
        {
            int n = rnd(0, 2)? nmax : rnd(1, nmax);
            input << n << endl;
            const int V = rnd(0, 7)? 3e5 : 1e9;
            vector<int> Vls;
            if (V == 3e5){
                vector<int> Al;
                for (int i = -V; i <= V; ++i)Al.emplace_back(i);
                sample(Al.begin(), Al.end(), back_inserter(Vls), int(5e5), mt);
            } else {
                set<int> S;
                while (S.size() < n * 6)
                    S.emplace(rnd(-V, V));
                Vls = {S.begin(), S.end()};
                shuffle(Vls.begin(), Vls.end(), mt);
            }
            if (sp == spec::op2_after_op1){
                int p = id % 5 <= 1? (n + 1) >> 1 : id % 5 == 2? rnd(1, n) : id % 5 == 3? clamp(rnd(1, max(1, n / 10)), 1, n) : clamp(rnd(1, max(1, n - n / 10)), 1, n);
                map<int, pair<int, int> > secs;
                vector<int> rrb;
                while (secs.size() < p){
                    auto Gt = [&]{
                        if (Vls.empty()){
                            assert(!rrb.empty());
                            shuffle(rrb.begin(), rrb.end(), mt);
                            Vls.swap(rrb);
                        }
                        int x = Vls.back();
                        Vls.pop_back();
                        return x;
                    };
                    auto putback = [&](int x){
                        rrb.emplace_back(x);
                    };
                    int l = Gt();
                    int r = Gt();
                    if (l > r)swap(l, r);
                    if (secs.count(r - l))putback(l), putback(r);
                    else  secs[r - l] = {l, r};
                }
                for (auto [_, S] : secs){
                    auto [l, r] = S;
                    input << "1 " << l << " " << r << endl;
                }
                for (int i = p + 1; i <= n; ++i)
                    input << "2 " << rnd(1, p) << " " << rnd(1, p) << endl;
            } else {
                static int op[100010];
                bernoulli_distribution ber(id % 5 <= 1? 0.5 : id % 5 == 2? rndfi() : id % 5 == 3? 0.1 : 0.9);
                for (int i = 1; i <= n; ++i)op[i] = ber(mt) + 1;
                op[1] = 1;
                int p = count(op + 1, op + n + 1, 1);
                map<int, pair<int, int> > secs;
                if (sp == spec::no_partial_intersection){
                    // if (V == 1e9){
                    //     auto S = rndbl(p);
                    //     assert(S.size() == p + p);
                    //     vector<pair<int, int> > rs;
                    //     stack<int, vector<int> > St;
                    //     for (int i = 0; i < p + p; ++i){
                    //         if (S[i] == ')')assert(!St.empty()), rs.emplace_back(St.top(), i), St.pop();
                    //         else St.emplace(i);
                    //     }
                    //     assert(St.empty());
                    //     vector<int> Rs = {Vls.begin(), Vls.begin() + p + p};
                    //     sort(Rs.begin(), Rs.end());
                    //     secs.clear();
                    //     for (auto [l, r] : rs){
                    //         int L = Rs[l], R = Rs[r];
                    //         if (secs.count(R - L)){
                    //             int t = 0;
                    //             while (secs.count(R - L + t))++t;
                    //             Rs[r] += t;
                    //             for (int x = r + 1; x < p + p; ++x){
                    //                 int nw = max(Rs[x], Rs[x - 1] + 1);
                    //                 if (nw == Rs[x])break;
                    //                 Rs[x] = nw;
                    //             }
                    //             if (Rs.back() > V)throw "Can not gen.";
                    //             R = Rs[r];
                    //             assert(!secs.count(R - L));
                    //         }
                    //         secs[R - L] = {L, R};
                    //     }
                    // } else {
                         // ((((()))))
                        vector<int> Rs;
                        sample(Vls.begin(), Vls.end(), back_inserter(Rs), p + p, mt);
                        for (int i = 0; i < p; ++i){
                            int L = Rs[i], R = Rs[p + p - i - 1];
                            secs[R - L] = {L, R};
                        }
                    // }
                } else {
                    vector<int> rrb;
                    while (secs.size() < p){
                        auto Gt = [&]{
                            if (Vls.empty()){
                                assert(!rrb.empty());
                                shuffle(rrb.begin(), rrb.end(), mt);
                                Vls.swap(rrb);
                            }
                            int x = Vls.back();
                            Vls.pop_back();
                            return x;
                        };
                        auto putback = [&](int x){
                            rrb.emplace_back(x);
                        };
                        int l = Gt();
                        int r = Gt();
                        if (l > r)swap(l, r);
                        if (secs.count(r - l))putback(l), putback(r);
                        else  secs[r - l] = {l, r};
                    }
                }
                auto it = secs.begin();
                for (int i = 1, m = 0; i <= n; ++i){
                    input << op[i] << " ";
                    if (op[i] == 1){
                        auto [l, r] = it->second;
                        ++it;
                        input << l << " " << r << endl;
                        ++m;
                    } else {
                        input << rnd(1, m) << " " << rnd(1, m) << endl;
                    }
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

    for (int c = 1; c <= 10; ++c)gen(1, c, sd(), 1000, spec::null, 250, 2);
    for (int c = 1; c <= 5; ++c)gen(2, c, sd(), 3000, spec::null, 250, 2);
    for (int c = 1; c <= 5; ++c)gen(3, c, sd(), 5000, spec::null, 250, 2);
    for (int c = 1; c <= 10; ++c)gen(4, c, sd(), 10000, spec::null, 250, 2);
    for (int c = 1; c <= 10; ++c)gen(5, c, sd(), 50000, spec::null, 250, 2);
    for (int c = 1; c <= 10; ++c)gen(6, c, sd(), 100000, spec::no_partial_intersection, 250, 2);
    for (int c = 1; c <= 10; ++c)gen(7, c, sd(), 100000, spec::op2_after_op1, 250, 2);
    for (int c = 1; c <= 10; ++c)gen(8, c, sd(), 100000, spec::null, 250, 2);

    remove(problem".in");
    remove(problem".out");
    return 0;
}