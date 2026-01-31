#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5;
int T, l, n, tmp;
int a[N],b[N],ans[N];
inline int read(){
    int res = 0;
    char c = getchar();
    while(c<'0'||c>'9')
        c = getchar();
    while(c>='0'&&c<='9')
        res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
    return res;
}
inline void dfs(int step,int maxn,int minn){
    if(maxn-minn>=tmp)
        return;
    if(step>n){
        if(maxn-minn<tmp){
            tmp = maxn - minn;
            for (int i = 1; i < n;i++)
                ans[i] = b[i];
        }
        return;
    }
    if(step==n){
        for (int i = a[step]; i <= l; i++){
            dfs(step + 1, max(maxn, b[step] - b[step - 1]), min(minn, b[step] - b[step - 1]));
        }
    }else{
        for (int i = a[step]; i <= a[step + 1];i++){
            b[step] = i;
            dfs(step + 1, max(maxn, b[step] - b[step - 1]), min(minn, b[step] - b[step - 1]));
        }
    }
}
signed main(){
    freopen("synapse.in", "r", stdin);
    freopen("synapse.out", "w", stdout);
    cin >> T;
    while(T--){
        tmp = INT_MAX;
        l=read(),n=read();
        for (int i = 1; i <= n;i++){
            a[i] = read();
        }
        ans[0] = 0, ans[n] = l;
        b[0] = 0, b[n] = l;
        dfs(1, -1, 100861145);
        for (int i = 0;i<=n;i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}