#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
const int N = 3.2e6 + 50 , M = N , T = 7e6 + 5;
ll n , t , tot , pn[T];
int m , mm , pr[M]; bitset<N>b;
void Dfs(int x , ll v)
{
    if(x == mm)return ;
    ll p = pr[x]; i128 pk = p * p;
    if((i128)v * pk <= n)Dfs(x + 1 , v);
    for(int i = 2 ; (i128)v * pk <= n ; i++ , pk *= p)
    {
        tot++ , pn[tot] = v * pk;
        Dfs(x + 1 , v * pk);
    }
}
void Sieve(const int n = N - 5)
{
    for(int i = 2 ; i <= n ; i++)
    {
        if(!b[i])pr[++m] = i;
        for(int j = 1 ; j <= m && (ll)pr[j] * i <= n ; j++)
        {
            int x = pr[j] * i;
            b[x] = 1;
            if(i % pr[j] == 0)
                break ;
        }
    }
}
void Init()
{
    Sieve(); 
    n = 1e13L; t = sqrt(n);
    for(mm = 1 ; pr[mm] <= t ; mm++);
    pn[1] = tot = 1; Dfs(1 , 1);
    sort(pn + 1 , pn + tot + 1);
}  
ll Solve()
{
    ll a; cin >> a;
    cout << (a == *lower_bound(pn + 1 , pn + tot + 1 , a)
             ? "yes\n" : "no\n");
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