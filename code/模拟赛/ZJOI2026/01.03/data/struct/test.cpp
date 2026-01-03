#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
int n , m , tot , a[N];
int cnt[N] , ans[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for(int i = 1 ; i <= n ; i++)
    {
        int res = 0;
        auto add = [&](int v){if(!cnt[v]++)res++;};
        auto del = [&](int v){if(!--cnt[v])res--;};
        memset(cnt , 0 , sizeof cnt);
        for(int j = 1 ; j <= n ; j++)add(a[j]);
        for(int j = i ; j <= n ; j++)
        {
            del(a[j]) , add(a[j] + 1);
            ans[i][j] = res;
        }
    }
    for(int i = 1 ; i <= m ; i++)
    {
        int l , r; cin >> l >> r;
        cout << ans[l][r] << "\n";
    }
    return 0;
}