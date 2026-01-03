#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
bitset<N>vis;
void Init(int n = N - 5)
{
    vis[1] = 1;
    for(int x = 1 ; x <= n ; x++)
        for(int xx = 2 ; (ll)x * xx <= n ; xx++)
            for(int y = 2 ; x == 1 ? y <= 2 : powl(x , y) <= n ; y++)
                for(int yy = 2 ; powl(x , y) * powl(xx , yy) <= n ; yy++)
                    vis[powl(x , y) * powl(xx , yy)] = 1;
}
ll Solve()
{
    ll a; cin >> a;
    cout << (vis[a] ? "yes\n" : "no\n");
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    Init(); int T; cin >> T;
    while(T--)Solve();
    return 0;
}