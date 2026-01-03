#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3.2e4 + 50 , M = N;
int m , pr[M]; bitset<N>b;
void Sieve(int n = N - 5)
{
    pr[++m] = 2;
    for(int i = 3 ; i <= n ; i += 2)
    {
        if(!b[i])pr[++m] = i;
        for(int j = 1 ; j <= m && pr[j] * i <= n ; j++)
        {
            int x = pr[j] * i;
            b[x] = 1;
            if(i % pr[j] == 0)
                break ;
        }
    }
}
ll Solve()
{
    ll a; cin >> a;
    for(int i = 1 ; (ll)pr[i] * pr[i] <= a ; i++)
        if(a % pr[i] == 0)
        {
            int c = 0;
            while(a % pr[i] == 0)a /= pr[i] , c++;
            if(c == 1)
            {
                cout << "no\n";
                return 0;
            }
        }
    cout << (a == 1 ? "yes\n" : "no\n");
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