#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define SZ(a) ((int)(a).size())
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define gc getchar
#define pc putchar
#define cint const int

cint mod = 998244353;
cint INF = 1e18;

inline void cmx(int &a,int b){
    a=max(a,b);
}

inline void cmn(int &a,int b){
    a=min(a,b);
}

inline void add(int &a,int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
    if(a<mod){
        a+=mod;
    }
}

inline int rd(){
    int x=0,y=1;
    char c=gc();
    for(;!isdigit(c);c=gc()){
        if(c=='-'){
            y=-1;
        }
    }
    for(;isdigit(c);c=gc()){
        x=(x<<3)+(x<<1)+(c^48);
    }
    return x*y;
}

namespace Day_Tao{
    cint N = 1e5 + 5;
    vector<pii>G[N];
    vector<int>pre[N];
    int S,T,U,V,n,m;
    int dis[N],dis1[N],dis2[N],ans=INF,f[N],g[N],in[N];
    bool vis[N],fl[N];
    void dij(int S,int fl){
        priority_queue<pii,vector<pii>,greater<pii>>q;
        F(i,1,n){
            dis[i]=INF;
            vis[i]=0;
        }
        dis[S]=0;
        q.push(mp(0,S));
        while(!q.empty()){
            int u=q.top().se;
            q.pop();
            if(vis[u]){
                continue;
            }
            vis[u]=1;
            for(pii i:G[u]){
                int v=i.fi,w=i.se;
                if(!fl){
                    if(dis[v]>dis[u]+w){
                        dis[v]=dis[u]+w;
                        if(!vis[v]){
                            q.push(mp(dis[v],v));
                        }
                    }
                }else{
                    if(dis[v]>dis[u]+w){
                        dis[v]=dis[u]+w;
                        pre[v].clear();
                        pre[v].pb(u);
                        if(!vis[v]){
                            q.push(mp(dis[v],v));
                        }
                    }else if(dis[v]==dis[u]+w){
                        pre[v].pb(u);
                    }
                }
            }
        }
    }

    void dfs(int u){
        fl[u]=1;
        for(int v:pre[u]){
            if(!fl[v]){
                dfs(v);
            }
        }
    }

    void SOLVE(){
        n=rd(),m=rd();
        S=rd(),T=rd();
        U=rd(),V=rd();
        F(i,1,m){
            int u=rd(),v=rd(),w=rd();
            G[u].pb(mp(v,w));
            G[v].pb(mp(u,w));
        }
        dij(U,0);
        F(i,1,n){
            dis1[i]=dis[i];
        }
        dij(V,0);
        F(i,1,n){
            dis2[i]=dis[i];
        }
        dij(S,1);
        dfs(T);
        F(i,1,n){
            f[i]=dis1[i];
            g[i]=dis2[i];
            if(fl[i]){
                for(int j:pre[i]){
                    ++in[j];
                }
            }
        }
        queue<int>q;
        F(i,1,n){
            if(!in[i]&&fl[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            // cerr<<u<<' '<<dis1[u]<<' '<<g[u]<<' '<<dis2[u]<<' '<<f[u]<<'\n';
            cmn(ans,min(dis1[u]+g[u],dis2[u]+f[u]));
            for(int v:pre[u]){
                in[v]--;
                cmn(f[v],f[u]);
                cmn(g[v],g[u]);
                if(in[v]==0){
                    q.push(v);
                }
            }
        }
        printf("%lld\n",min(ans,dis1[V]));
        return ;
    }
}

signed main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T=1;
    // T=rd();
    while(T--){
        Day_Tao::SOLVE();
    }
    return 0;
}