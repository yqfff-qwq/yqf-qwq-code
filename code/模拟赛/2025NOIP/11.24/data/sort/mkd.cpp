#include <bits/stdc++.h>
using namespace std;
uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 sd(seed);
ofstream lgf("log.txt");
int system(const string &s){
    return system(s.c_str());
}
void gen(int subtask, int id, int nmax, uint64_t seed, int alig = 0){
    const string file_name = "sort" + to_string(subtask) + "_" + to_string(id);
    ofstream input(file_name + ".in");
    if (!input)throw runtime_error("Can not open input file.");
    ofstream result(file_name + ".ans");
    if (!result)throw runtime_error("Can not open result file.");

    mt19937 mt(seed);

    lgf << "subtask=" << subtask << ",id=" << id << ",nmax=" << nmax << ",seed=" << seed << endl;
    clog << "generate:" << file_name << endl;

    auto G = [&](int l, int r){
        switch (mt() % 5){
            case 0: return uniform_int_distribution<int>{l, (l + r) >> 1}(mt);
            case 1: return uniform_int_distribution<int>{l, r}(mt);
            case 2: return uniform_int_distribution<int>{(l + r) >> 1, r}(mt);
            case 3: case 4: return r;
        }
        __builtin_unreachable();
    };
    int n = alig? G(1, nmax / alig) * alig : G(1, nmax);

    assert(n <= 1000 && n >= 1);
    static int p[1010];
    if (alig){
        for (int i = 1; i <= n; ++i)p[i] = (i + alig - 1) % n + 1;
    } else {
        switch (mt() % 6){
            case 0: {
                iota(p + 1, p + n + 1, 1);
            } break;
            case 1: case 2: { // 1 ring
                vector<int> k(n);
                iota(k.begin(), k.end(), 1);
                shuffle(k.begin(), k.end(), mt);
                for (int i = 0; i < n; ++i)p[k[i]] = k[(i + 1) % n];
            } break;
            case 3: if (n > 2){ // 2 ring
                vector<int> k(n);
                iota(k.begin(), k.end(), 1);
                shuffle(k.begin(), k.end(), mt);
                int t = uniform_int_distribution<int>{1, n - 1}(mt);
                for (int i = 0; i < t; ++i)p[k[i]] = k[(i + 1) % t];
                for (int i = t; i < n; ++i)p[k[i]] = k[(i + 1 - t) % (n - t) + t];
            } break;
            case 4: case 5: { // several rings
                iota(p + 1, p + n + 1, 1);
                shuffle(p + 1, p + n + 1, mt);
            } break;
        }
    }

    input << n << endl;
    for (int i = 1; i <= n; ++i)input << p[i] << " ";
    input.flush(); input.close();

    system("cat " + file_name + ".in >sort.in");
    int ret = system("./sort");
    if (ret)throw runtime_error("RE");
    system("cat sort.out >" + file_name + ".ans");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    if (!lgf)throw runtime_error("Can not open log file.");
    if (system("g++ sort.cpp -o sort -O2 -std=c++14 -static -Wall -Wextra -pedantic"))
        throw runtime_error("Can not compiler file.");
    lgf << "global seed=" << seed << endl;
    for (int i = 1; i <= 5; ++i)gen(1, i, 10, sd());//9pts
    for (int i = 1; i <= 10; ++i)gen(2, i, 20, sd());//18pts
    for (int i = 1; i <= 5; ++i)gen(3, i, 1000, sd(), 1);//6pts
    for (int i = 1; i <= 5; ++i)gen(4, i, 1000, sd(), 2);//8pts
    for (int i = 1; i <= 10; ++i)gen(5, i, 1000, sd(), 3);//14pts
    for (int i = 1; i <= 25; ++i)gen(6, i, 1000, sd());//45pts
    remove("sort.in");
    remove("sort.out");
    return 0;
}