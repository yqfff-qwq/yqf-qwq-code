#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace annika{
    int n,m,ans;
    void main(){
        cin>>n>>m;
        ans=0;
        int l=0,r=m/n,res=-1;
        while (l<=r){
            int mid=(l+r)>>1;
            int k=(mid<<1);
            if (((k*n+1)^(n-1))<=m){
                res=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        // cerr<<"res="<<res<<"\n";
        if (~res) ans+=(res+1);
        l=0; r=m/n; res=-1;
        while (l<=r){
            int mid=(l+r)>>1;
            int k=(mid<<1|1);
            if (((k*n+1)^(n-1))<=m){
                res=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if (~res) ans+=(res+1);
        cout<<ans<<"\n";
    }
}

signed main(){
    freopen("root.in","r",stdin);
    freopen("root.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; 
    cin>>T;
    while (T--){
        annika::main();
    }

    return 0;
}