#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],n,t,l,ans,num[N],tmp[N];
void dfs(int now,int las,int sum,int msum){
    if(now==n){
        if((l&las)>=a[now-1]&&(l&las)<l){
            if(ans>(sum-msum)){
                for(int i=2;i<n;i++)num[i]=tmp[i];
                ans=sum-msum;
            }
        }
        return ;
    }
    for(int i=max(las,a[now]+1);i<=min(l,a[now+1]);i++){
        if((i&las)<i&&(i&las)>=a[now]){
            tmp[now]=i;
            dfs(now+1,i,max(sum,i-las),min(msum,i-las));
            tmp[now]=0;
        }
    }
}
signed main(){
    freopen("synapse1.in","r",stdin);
    cin>>t;
    while(t--){
        cin>>n>>l,ans=INT_MAX;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        dfs(1,0,0,INT_MAX);
        cout<<ans<<'\n';
    }
    return 0;
}