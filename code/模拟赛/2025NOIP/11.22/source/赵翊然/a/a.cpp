#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n[10]={0,2,3,6,7,8,9};
signed main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        x-=1;
        if(x==0){
            cout<<"0\n";
            continue;
        }
        else{
            vector<int>d;
            int tmp=x;
            while(tmp>0){
                d.push_back(tmp%7);
                tmp/=7;
            }
            int ans=0;
            reverse(d.begin(),d.end());
            for(int i:d){
                // cout<<i<<"\n";
                ans=(ans*10+n[i])%998244353;
            }
            cout<<ans<<"\n";
        }
    }
}