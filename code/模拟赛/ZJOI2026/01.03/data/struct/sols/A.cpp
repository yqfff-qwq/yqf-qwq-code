#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n , m , tot , a[N];
int mn[N] , mx[N] , pre[N] , pos[N];
struct U{int p , l , r , v;}upd[N * 4];
bool operator < (const U &a , const U &b){return a.p < b.p;}
struct BIT
{
    int c[N];
    void add(int x , int v)
    {
        for(int i = x ; i <= n ; i += i & -i)
            c[i] += v;
    }
    int ask(int x)
    {
        int sum = 0;
        for(int i = x ; i ; i -= i & -i)
            sum += c[i];
        return sum;
    }
    void update(int l , int r , int v)
    {
        if(l > r)return ;
        add(l , v) , add(r + 1 , -v);
    }
}bit;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    memset(mn , 0x3f , sizeof(int) * (n + 1));
    for(int i = 1 ; i <= n ; i++)
    {
        pre[i] = pos[a[i]];
        pos[a[i]] = i;
        mn[a[i]] = min(mn[a[i]] , i);
        mx[a[i]] = max(mx[a[i]] , i);
    }
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++)
        upd[++tot] = {i , pre[i] + 1 , i , 1};
    for(int i = 1 ; i <= n ; i++)
    {
        if(mn[i] <= mx[i])
        {
            upd[++tot] = {mx[i] , 1 , mn[i] , -1};
            cnt++;
        }
    }
    sort(upd + 1 , upd + tot + 1);
    for(int i = 1 , j = 1 ; i <= m ; i++)
    {
        int l , r; cin >> l >> r;
        for(; j <= tot && upd[j].p <= r ; j++)
            bit.update(upd[j].l , upd[j].r , upd[j].v);
        cout << cnt + bit.ask(l) << "\n";
    }
    return 0;
}