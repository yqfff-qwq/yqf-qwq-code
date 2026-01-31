#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T, n, m;
ll ans;
vector<ll> a;
vector<ll> st;
vector<bool> vis;
inline ll read(){
    ll res = 0;
    char c = getchar();
    while (c<'0'||c>'9')
        c = getchar();
    while(c>='0'&&c<='9')
        res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
    return res;
}
inline void dfs(int step,ll maxn){
    if(maxn>=ans)
        return;
    if(step>2*n){
        ans = maxn;
        return;
    }
    for (int i = 1; i <= 2 * n;i++){
        ll t=maxn;
        if(step>n)
            t = max(t, (a[i] + st[step - n]) % m);
        if(!vis[i]){
            vis[i] = 1;
            st[step] = a[i];
            dfs(step + 1, t);
            vis[i] = 0;
        }
    }
}
signed main(){
    // freopen("tower.in", "r", stdin);
    // freopen("tower.out", "w", stdout);
    cin >> T;
    while(T--){
        ans = 10086114514;
        n = read(), m = read();
        a.clear();
        vis.clear();
        st.clear();
        a.push_back(0);
        vis.push_back(0);
        st.push_back(0);
        for (int i = 1; i <= 2 * n;i++){
            ll x = read();
            a.push_back(x);
            vis.push_back(0);
            st.push_back(0);
        }
        dfs(1, -1);
        cout << ans << endl;
    }
    return 0;
}