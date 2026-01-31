#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int T, n, m;
vector<int> G[N];
inline int read(){
    int res = 0;
    char c = getchar();
    while(c<'0'||c>'9')
        c = getchar();
    while(c>='0'&&c<='9')
        res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
    return res;
}
inline bool check(int x,int y){
    set<int> st;
    for(int v:G[x])
        st.insert(v);
    for(int v:G[y])
        st.insert(v);
    return !(st.size() % 2);
}
signed main(){
    freopen("void.in", "r", stdin);
    freopen("void.out", "w", stdout);
    cin>>T;
    while(T--){
        n = read(), m = read();
        for (int i = 1; i <= n;i++)
            G[i].clear();
        for (int i = 1; i <= m; i++){
            int u = read(), v = read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool flag = 0;
        for (int i = 1; i <= n;i++){
            if(flag)
                break;
            for (int j = i + 1; j <= n;j++){
                if(check(i,j)){
                    cout << i << " " << j << endl;
                    flag = 1;
                    break;
                }
            }
        }
    }
    return 0;
}