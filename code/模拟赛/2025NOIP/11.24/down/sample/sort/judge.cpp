#include <bits/stdc++.h>
using namespace std;
const string red = "\x1b[31m";
const string green = "\x1b[32m";
const string yellow = "\x1b[33m";
const string reset = "\x1b[0m";
[[noreturn]] void error(const string what){
    cerr << red << "error" << reset << " " << what << endl;
    exit(-1);
}
[[noreturn]] void WA(){
    cerr << red << "Wrong Answer" << reset << endl;
    exit(0);
}
[[noreturn]] void PA(){
    cerr << yellow << "Partly Accepted" << reset << endl;
    exit(0);
}
[[noreturn]] void AC(){
    cerr << green << "Accepted" << reset << endl;
    exit(0);
}
int main(int argc, const char** argv){
    if (argc < 4)error("Invalid parameters.");
    ifstream input(argv[1]);
    if (!input)error("Can not open input file.");
    ifstream output(argv[2]);
    if (!output)error("Can not open output file.");
    ifstream result(argv[3]);
    if (!result)error("Can not open result file.");
    int n;
    input >> n;
    assert(1 <= n && n <= 1000);
    static int p[1010];
    static bool md[1010];
    fill_n(md + 1, n, 0);
    for (int i = 1; i <= n; ++i)
        input >> p[i], assert(1 <= p[i] && p[i] <= n && !md[p[i]]), md[p[i]] = 1;
    int x;
    result >> x;
    assert(0 <= x && x <= 1000);
    auto pkint = [&output](int l, int r) -> int {
        int x;
        output >> x;
        if (!output.good())error("Unexpected Format.");
        if (x < l || x > r)WA();
        return x;
    };
    int ix = pkint(x, 1000);
    for (int c = 1; c <= ix; ++c){
        vector<int> k(pkint(1, n));
        output.get();
        for (int &x : k)x = pkint(1, n);
        if (set<int>(k.begin(), k.end()).size() < k.size())WA();
        int l = k.size();
        vector<int> v;
        for (int i = 0; i < l; ++i)v.emplace_back(p[k[i]]);
        for (int i = 0; i < l; ++i)p[k[(i + 1) % l]] = v[i];
    }
    for (int i = 1; i <= n; ++i)
        if (p[i] != i)WA();
    if (x == ix)AC();
    else PA();
    return 0;
}