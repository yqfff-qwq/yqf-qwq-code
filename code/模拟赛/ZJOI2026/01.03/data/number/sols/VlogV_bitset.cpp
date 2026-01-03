#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e9 + 50;
bitset<N>vis;
void Init(int n = N - 50)
{
    vis[1] = 1;
    for(int y = 2 ; y <= 30 ; y++)
    {
        for(int x = 2 ; powl(x , y) <= n ; x++)
            vis[(ll)powl(x , y)] = 1;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        if(!vis[i])continue ;
        for(int j = i ; (ll)i * j <= n ; j++)
            if(vis[j])vis[i * j] = 1;
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