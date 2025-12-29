#include <bits/stdc++.h>
#include "testlib_for_lemons.h"
using namespace std;
int main(int argc, char** argv){
    registerLemonChecker(argc, argv);
    int n = inf.readInt(1, 1000, "n");
    static int p[1010];
    static bool md[1010];
    fill_n(md + 1, n, 0);
    for (int i = 1; i <= n; ++i)
        p[i] = inf.readInt(1, n, "p[i]"), ensure(!md[p[i]]), md[p[i]] = 1;
    int x = ans.readInt(0, 1000, "x");
    int ix = ouf.readInt(x, 1000);
    for (int c = 1; c <= ix; ++c){
        vector<int> k(ouf.readInt(1, n));
        for (int &x : k)x = ouf.readInt(1, n);
        if (set<int>(k.begin(), k.end()).size() < k.size())quitf(_wa, "");
        int l = k.size();
        vector<int> v;
        for (int i = 0; i < l; ++i)v.emplace_back(p[k[i]]);
        for (int i = 0; i < l; ++i)p[k[(i + 1) % l]] = v[i];
    }
    for (int i = 1; i <= n; ++i)
        if (p[i] != i)quitf(_wa, "");
    if (x == ix)quitf(_ok, "");
    else quitp(0.5, "");
    return 0;
}