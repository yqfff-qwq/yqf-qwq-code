#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[6005];
vector<int> an;
int a[10005],n,m,k,s1,s2;
void find(){
    vector<int>d(n+1);
    vector<bool> vis(n+1,0);
    for(int i=1;i<=n;i++)
    d[i]=g[i].size();
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i]<=k);
        q.push(i),vis[i]=1;
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            if(!vis[v]){
                d[v]-=1;
                if(d[v]<=k){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    if(!vis[i])an.push_back(i);
    return;
}
signed main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin>>n>>m>>k>>s1>>s2;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v),g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    cin>>a[i];
    find();
    if(!an.empty()){
        sort(an.begin(),an.end());
        for(int i=0;i<an.size();i++)
        cout<<an[i]<<" ";
        return 0;
    }
}