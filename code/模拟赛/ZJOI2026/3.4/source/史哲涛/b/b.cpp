#include <bits/stdc++.h>
using namespace std;
int n, tl[1010], tr[1010];
namespace S1 {
    void sol1(){
        cout << tl[1] - 1 << endl;
        exit(0);
    }
}
int main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> tl[1];
    for (int i = 2; i <= n; ++i)cin >> tr[i - 1] >> tl[i];
    if (count(tr + 1, tr + n, 1) == n - 1 && count(tl + 2, tl + n + 1, 1) == n - 1)S1::sol1();
    return 0;
}
/*
cd 史哲涛
cd b
g++ b.cpp -o b -std=c++11 -O2
./b <fp.01.in >.out
diff .out fp.01.ans -w
./b <fp.02.in >.out
diff .out fp.02.ans -w
./b <fp.03.in >.out
diff .out fp.03.ans -w
./b <fp.10.in >.out
diff .out fp.10.ans -w
./b <fp.24.in >.out
diff .out fp.24.ans -w
*/