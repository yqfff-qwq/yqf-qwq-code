#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int tp,t,n,m,a[N],ans,flag[N];
void dfs(int now,int sum,int las1,int las2){
    if(!(now&1)&&now!=0)
        sum=max(sum,(las1+las2)%m);
    if(now==n){
        ans=min(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==tp)continue;
        flag[i]=tp;
        dfs(now+1,sum,a[i],las1);
        flag[i]=0;
    }
}
signed main(){
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m,n*=2,ans=INT_MAX;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        tp++,dfs(0,0,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}