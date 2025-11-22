#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define MP make_pair
#define pii pair<int,int>
using namespace std;

namespace annika{
    const int N=1e5+3;
    int n,base,mod,a[N],q;
    int Next[N<<1],ver[N<<1],head[N],tot;
    bitset<N> b[N];

    void add(int u,int v){
        ver[++tot]=v;
        Next[tot]=head[u],head[u]=tot;
    }

    int eul[N<<1],idx,dfn[N],dep[N];
    void dfs(int u,int fa){
        eul[++idx]=u;
        dfn[u]=idx;
        for (int i=head[u];i;i=Next[i]){
            int v=ver[i];
            if (v==fa) continue;
            b[v]^=b[u];
            dep[v]=dep[u]+1;
            dfs(v,u);
            eul[++idx]=u;
        }
    }

    int st[23][N<<1];
    int lca(int u,int v){
        int l=dfn[u],r=dfn[v];
        if (l>r) swap(l,r);
        int t=__lg(r-l+1);
        return (dep[st[t][l]]<dep[st[t][r-(1<<t)+1]])?st[t][l]:st[t][r-(1<<t)+1];
    }

    void main(){
        cin>>n>>base>>mod;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            b[i][a[i]]=1;
        }
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        // for (int i=1;i<=n;i++){
        //     cerr<<"b["<<i<<"] "<<b[i].count()<<"\n";
        // }
        for (int i=1;i<=idx;i++){
            st[0][i]=eul[i];
        }
        for (int i=1;i<=__lg(idx);i++){
            for (int j=1;j<=idx-(1<<i)+1;j++){
                st[i][j]=(dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]])?st[i-1][j]:st[i-1][j+(1<<(i-1))];
            }
        }
        cin>>q;
        while (q--){
            int u,v;
            cin>>u>>v;
            int t=lca(u,v);
            // cerr<<u<<" "<<v<<":"<<t<<"\n";
            // cerr<<((b[u]^b[v]^((bitset<N>)(1<<a[t]))).count())<<"\n";
            // cerr<<dep[u]+dep[v]-2*dep[t]+1<<"\n";
            bitset<N> tmp; tmp[a[t]]=1;
            if ((b[u]^b[v]^tmp).count()==(dep[u]+dep[v]-2*dep[t]+1)){
                cout<<"No\n";
            }
            else{
                cout<<"Yes\n";
            }
        }
    }
}

signed main(){
    freopen("temple.in","r",stdin);
    freopen("temple.out","w",stdout);

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    annika::main();

    return 0;
}