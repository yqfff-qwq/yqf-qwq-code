#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;
bitset<N>vis;
void Init(int n = N - 5)
{
    vis[1] = 1;
    for(int y = 2 ; y <= 20 ; y++)
    {
        for(int yy = 2 ; yy <= 20 ; yy++)
        {
            for(int x = 2 ; powl(x , y) <= n ; x++)
            {
                for(int xx = 1 ; powl(xx , yy) * powl(x , y) <= n ; xx++)
                    vis[powl(xx , yy) * powl(x , y)] = 1;
            }
        }
    }
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