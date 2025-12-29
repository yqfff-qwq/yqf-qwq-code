#include <bits/stdc++.h>
using namespace std;

namespace annika{
    const int N=3e3+3,M=1e6+3,mod=998244353;
    int n,m,k,s1,s2,s,a[N];
    int deg[N],f[N];
    int sum[1<<5];
    queue <int> q;
    vector <int> adj[N];
    
    int Next[M<<1],ver[M<<1],head[N],tot;
    void add_edge(int u,int v){
        ver[++tot]=v;
        Next[tot]=head[u],head[u]=tot;
    }

    int dp[N][N];
    void add(int &a,int b){
        a+=b;
        if (a>=mod) a-=mod;
        if (a<0) a+=mod;
    }
    void upd(int id,int x){
        for (int i=N-1;i>=x;i--){
            add(dp[id][i],dp[id][i-x]);
        }
    }
    void del(int id,int x){
        for (int i=x;i<N;i++){
            add(dp[id][i],-dp[id][i-x]);
        }
    }

    void Main(){
        cin>>n>>m>>k>>s1>>s2;
        s=s1+s2;
        for (int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            add_edge(u,v);
            add_edge(v,u);
            deg[u]++;
            deg[v]++;
        }
        for (int i=1;i<=n;i++){
            if (deg[i]<=k){
                q.push(i);
            }
        }
        while (q.size()){
            int u=q.front();
            q.pop();
            if (f[u]) continue;
            f[u]=1;
            for (int i=head[u];i;i=Next[i]){
                int v=ver[i];
                if (f[v]) continue;
                deg[v]--;
                adj[u].emplace_back(v);

                // cerr<<u<<"->"<<v<<"\n"; //

                if (deg[v]<=k){
                    q.push(v);
                }
            }
        }
        int fl=0;
        for (int i=1;i<=n;i++){
            if (!f[i]){
                cout<<i<<" ";
                fl=1;
            }
        }
        if (fl) return;
        
        for (int i=1;i<=n;i++){
            cin>>a[i];
            dp[i][0]=1;
        }
        for (int u=1;u<=n;u++){
            for (auto v:adj[u]){
                upd(v,a[u]);
            }
        }
        
        // for (int i=1;i<=n;i++){
        //     cerr<<i<<":\n";
        //     for (int j=0;j<=3;j++){
        //         cerr<<" "<<j<<" "<<dp[i][j]<<"\n";
        //     }
        // }

        while (s--){
            int op,u,y;
            cin>>op>>u>>y;

            if (op==1){
                for (auto v:adj[u]){
                    del(v,a[u]);
                    upd(v,y);
                }
                a[u]=y;
            }
            if (op==2){
                int sz=adj[u].size(),res=0;
                for (int S=0;S<(1<<sz);S++){
                    if (S) sum[S]=sum[S^(S&(-S))]+a[adj[u][__lg(S&(-S))]];
                    if (y>=sum[S]) add(res,dp[u][y-sum[S]]);
                }
                cout<<res<<"\n";
            }
        }
    }
}

signed main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    annika::Main();

    return 0;
}