#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 50 , M = 6.7e6;
int m , pr[M];
bitset<N>b , vis , vi;// vi[x] means "is x without all of its minimal prime factor valid?"
void Sieve(int n = N - 5)
{
    vis[1] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        if(!b[i])pr[++m] = i , vis[i] = 0 , vi[i] = 1;
        for(int j = 1 ; j <= m && (ll)pr[j] * i <= n ; j++)
        {
            int x = pr[j] * i;
            b[x] = 1 , vi[x] = vis[i];
            if(i % pr[j] == 0)
            {
                vi[x] = vis[x] = vi[i];
                break ;
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
    Sieve(); int T; cin >> T;
    while(T--)Solve();
    return 0;
}