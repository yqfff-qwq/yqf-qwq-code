#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace annika{
    const int N=2e5+3;
    int n,q,root,fa[N];
    ll ans[N];
    
    int Next[N<<1],ver[N<<1],head[N],tot;
    void add(int u,int v){
        ver[++tot]=v;
        Next[tot]=head[u],head[u]=tot;
    }

    struct qry{
        int id,v,l,r;
    };
    vector <qry> a[N];

    void init(int u,int F){
        fa[u]=F;
        for (int i=head[u];i;i=Next[i]){
            if (ver[i]!=F) init(ver[i],u);
        }
    }

    vector <int> b;
    void dfs(int u){
        b.emplace_back(u);
        for (int i=head[u];i;i=Next[i]){
            if (ver[i]!=fa[u]) dfs(ver[i]);
        }
    }

    void main(){
        cin>>n>>q>>root;
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        init(root,0);
        // for (int i=1;i<=n;i++) cout<<fa[i]<<" "; cout<<"\n";
        for (int i=1;i<=q;i++){
            int l,r,u;
            cin>>l>>r>>u;
            a[u].push_back({i,1,l,r});
            for (int j=head[u];j;j=Next[j]){
                if (ver[j]!=fa[u])
                    a[ver[j]].push_back({i,-1,l,r});
            }
        }
        for (int u=1;u<=n;u++){
            b.clear();
            dfs(u);
            sort(b.begin(),b.end());
            for (auto now:a[u]){
                int id=now.id,v=now.v,l=now.l,r=now.r;
                int sz=upper_bound(b.begin(),b.end(),r)-lower_bound(b.begin(),b.end(),l);
                ans[id]+=1ll*sz*(sz-1)/2*v;
            }
        }
        for (int i=1;i<=q;i++){
            cout<<ans[i]<<"\n";
        }
    }
}

signed main(){
    freopen("rplexq.in","r",stdin);
    freopen("rplexq.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    annika::main();

    return 0;
}