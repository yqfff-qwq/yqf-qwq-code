#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;

namespace annika{
    const int N=1e5+3,M=2e5+3,inf=1e18;
    int n,m,S,T,U,V,ans=inf;
    int dist[N],vis[N];
    int dU[N],dV[N];
    int preU[N],preV[N],sufU[N],sufV[N];

    int Next[M<<1],ver[M<<1],head[N],edge[M<<1],tot;
    void add(int u,int v,int w){
        ver[++tot]=v,edge[tot]=w;
        Next[tot]=head[u],head[u]=tot;
    }

    void dij(int st){
        priority_queue <pii> q;
        while (q.size()) q.pop();
        for (int i=1;i<=n;i++){
            dist[i]=inf;
            vis[i]=0;
        }
        dist[st]=0;
        q.push(MP(0,st));
        while (q.size()){
            int u=q.top().se; q.pop();
            if (vis[u]) continue;
            vis[u]=1;
            for (int i=head[u];i;i=Next[i]){
                int v=ver[i],w=edge[i];
                if (dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    q.push(MP(-dist[v],v));
                }
            }
        }
    }

    void main(){
        cin>>n>>m>>S>>T>>U>>V;
        for (int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }

        dij(U);
        for (int i=1;i<=n;i++) dU[i]=dist[i];
        ans=dist[V];

        // cerr<<"initial answer="<<ans<<"\n"; //
        // exit(0); //

        dij(V);
        for (int i=1;i<=n;i++) dV[i]=dist[i];

        dij(S);
        for (int i=1;i<=n;i++){
            preU[i]=sufU[i]=dU[i];
            preV[i]=sufV[i]=dV[i];
            vis[i]=0;
        }
        queue <int> q;
        while (q.size()) q.pop();
        q.push(S);
        while (q.size()){
            int u=q.front(); q.pop();
            if (vis[u]) continue;
            vis[u]=1;
            for (int i=head[u];i;i=Next[i]){
                int v=ver[i],w=edge[i];
                if (dist[u]+w==dist[v]){
                    q.push(v);
                    preU[v]=min(preU[v],preU[u]);
                    preV[v]=min(preV[v],preV[u]);
                }
            }
        }
        for (int i=1;i<=n;i++){
            vis[i]=0;
        }
        q.push(T);
        while (q.size()){
            int u=q.front(); q.pop();
            if (vis[u]) continue;
            vis[u]=1;
            ans=min(ans,preU[u]+sufV[u]);
            ans=min(ans,preV[u]+sufU[u]);

            // cerr<<u<<":\n"; //
            // cerr<<"preU["<<u<<"]="<<preU[u]<<"\n";
            // cerr<<"sufU["<<u<<"]="<<sufU[u]<<"\n";
            // cerr<<"preV["<<u<<"]="<<preV[u]<<"\n";
            // cerr<<"sufV["<<u<<"]="<<sufV[u]<<"\n";

            for (int i=head[u];i;i=Next[i]){
                int v=ver[i],w=edge[i];
                if (dist[v]+w==dist[u]){
                    q.push(v);
                    sufU[v]=min(sufU[v],sufU[u]);
                    sufV[v]=min(sufV[v],sufV[u]);
                }
            }
        }
        cout<<ans;
    }
}

signed main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    annika::main();

    return 0;
}