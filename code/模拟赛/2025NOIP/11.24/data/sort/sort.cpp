#include <bits/stdc++.h>
using namespace std;
int n, p[1010];
bool vs[1010];
vector<vector<int> > fndcir(){
    vector<vector<int> > cir;
    fill_n(vs + 1, n, 0);
    for (int i = 1; i <= n; ++i)if (p[i] ^ i && !vs[i]){
        cir.emplace_back();
        for (int u = i; !vs[u]; u = p[u])
            cir.back().emplace_back(u), vs[u] = 1;
    }
    return cir;
}
int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)cin >> p[i];
    vector<vector<int> > cir = fndcir();
    if (cir.size() <= 2){
        cout << cir.size() << endl;
        for (auto &R : cir){
            cout << R.size() << " ";
            for (int u : R)cout << u << " ";
            cout << endl;
        }
        return 0;
    }
    vector<int> V;
    for (auto &R : cir)V.insert(V.end(), R.begin(), R.end());
    cout << 2 << endl;
    cout << V.size() << " ";
    for (int u : V)cout << u << " ";
    cout << endl;
    vector<int> P;
    for (int u : V)P.emplace_back(p[u]);
    for (int i = 0, _ = V.size(); i < _; ++i)
        p[V[(i + 1) % _]] = P[i];
    cir = fndcir();
    assert(cir.size() == 1);
    cout << cir[0].size() << " ";
    for (int u : cir[0])cout << u << " ";
    cout << endl;
    return 0;
}