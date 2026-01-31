#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int ans,a[N],n,t,sum;
signed main(){
    freopen("starlight.in","r",stdin);
    freopen("starlight.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n,sum=ans=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int flag=1;
                for(int k=0;k<=100;k++){
                    for(int q=1;q<=n;q++){
                        if((a[i]^k)<(a[q]^k)&&(a[j]^k)>(a[q]^k)){
                            flag=0;
                            break;
                        }
                    }
                    if(!flag)break;
                }
                if(flag)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}