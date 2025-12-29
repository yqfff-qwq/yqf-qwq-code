#include <bits/stdc++.h>
#define problem "couple"
using namespace std;
uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 sd(seed);
ofstream lgf("log.txt");
int system(const string &s){
    return system(s.c_str());
}
void gen(int subtask, int id, uint64_t seed, int T, int N, int R, int C){
    const string file_name = problem + to_string(subtask) + "_" + to_string(id);
    ofstream input(file_name + ".in");
    if (!input)throw runtime_error("Can not open input file.");
    ofstream result(file_name + ".ans");
    if (!result)throw runtime_error("Can not open result file.");

    mt19937 mt(seed);

    lgf << "subtask=" << subtask << ",id=" << id << ",seed=" << seed << ",t<=" << T << ",n<=" << N << ",r_i<=" << R << ",c_i<=" << C << endl;
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

    {
        auto bg = chrono::steady_clock::now();
        {

            input << T << endl;
            while (T--){
                if (mt() % 3 == 0){
                    int n = N;
                    input << n << endl;
                    input << R << " " << C << endl;
                    while (--n)input << rnd(1, R) << " " << (mt() % 3? rnd(1, C) : C) << "\n";
                } else if (mt() & 1){
                    int n = mt() % 4? N : rnd(1, N);
                    input << n << endl;
                    while (n--)input << rnd(1, R) << " " << rnd(1, C) << "\n";
                } else {
                    int n = mt() % 3? N : rnd(1, N);
                    int h = rnd(1, R);
                    for (int i = min(10, n / 2); i; --i)input << rnd(max(1, h - 1), min(h + 1, R)) << " " << rnd(1, C) << "\n";
                    for (int i = n - min(10, n / 2); i; --i)
                        input << rnd(1, R) << " " << (mt() % 10 == 0? rnd(1, C) : rnd(1, min(C, 5))) << "\n";
                }
            }
        }
        auto ed = chrono::steady_clock::now();
        clog << "use " << chrono::duration_cast<chrono::milliseconds>(ed - bg).count() << "ms" << endl;
    }

    input.flush(); input.close();

    {
        system("cat " + file_name + ".in >"problem".in");
        clog << "std running" << endl;
        auto bg = chrono::steady_clock::now();
        int ret = system("./"problem);
        auto ed = chrono::steady_clock::now();
        if (ret)throw runtime_error("RE");
        clog << "use " << chrono::duration_cast<chrono::milliseconds>(ed - bg).count() << "ms" << endl;
        system("cat "problem".out >" + file_name + ".ans");
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    if (!lgf)throw runtime_error("Can not open log file.");
    if (system("g++ "problem".cpp -o "problem" -O2 -std=c++14 -static -Wall -Wextra -pedantic"))
        throw runtime_error("Can not compiler file.");
    lgf << "global seed=" << seed << endl;

    for (int i = 1; i <= 5; ++i)gen(1, i, sd(), 5, 10, 10, 10);//7pts
    for (int i = 1; i <= 5; ++i)gen(2, i, sd(), 5, 100, 100, 2);//8pts
    for (int i = 1; i <= 10; ++i)gen(3, i, sd(), 5, 100, 100, 100);//14pts
    for (int i = 1; i <= 10; ++i)gen(4, i, sd(), 5, 100000, 100, 2);//15pts
    for (int i = 1; i <= 15; ++i)gen(5, i, sd(), 5, 100000, 100, 100);//21pts
    for (int i = 1; i <= 25; ++i)gen(6, i, sd(), 1, 100000, 500, 500);//35pts

    remove(problem".in");
    remove(problem".out");
    return 0;
}