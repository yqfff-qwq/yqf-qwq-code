#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],n,t,l,ans,num[N],tmp[N];
void dfs(int now,int las,int sum,int msum){
    if(now==n){
        sum=max(sum,l-las);
        msum=min(msum,l-las);
        if(ans>(sum-msum)){
            for(int i=1;i<n;i++)num[i]=tmp[i];
            ans=sum-msum;
        }
        return ;
    }
    for(int i=max(las,a[now]);i<=min(l,a[now+1]);i++){
        tmp[now]=i;
        dfs(now+1,i,max(sum,i-las),min(msum,i-las));
        tmp[now]=0;
    }
}
signed main(){
    freopen("synapse.in","r",stdin);
    freopen("synapse.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t,num[0]=0;
    while(t--){
        cin>>l>>n,ans=INT_MAX;
        num[n]=l;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        dfs(1,0,0,INT_MAX);
        // cout<<ans<<'\n';
        for(int i=0;i<=n;i++)  
            cout<<num[i]<<' ';
        cout<<'\n';
    }
    return 0;
}