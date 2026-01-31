#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
vector<int> vec[N];
int t,n,m,flag[N],tp,ans;
void dfs(int now){
    for(int i=0;i<vec[now].size();i++){
        int ne=vec[now][i];
        if(flag[ne]!=tp)
            ans++,flag[ne]=tp;
    }
}
signed main(){
    freopen("void.in","r",stdin);
    freopen("void.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            vec[i].clear();
        for(int i=1,x,y;i<=m;i++){
            cin>>x>>y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        for(int i=1;i<n;i++){
            int fl=1;
            for(int j=i+1;j<=n;j++){
                if(i==j)continue;
                tp++,ans=0;
                dfs(i),dfs(j);
                if(!(ans&1)){
                    cout<<i<<" "<<j<<'\n';
                    fl=0;
                    break;
                }
            }
            if(!fl)break;
        }
    }
    return 0;
}