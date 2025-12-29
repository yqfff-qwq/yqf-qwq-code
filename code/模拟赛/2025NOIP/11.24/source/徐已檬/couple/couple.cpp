#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define MP make_pair
using namespace std;

namespace annika{
    const int N=103;
    int n,ans;
    int x[N],y[N];
    void main(){
        cin>>n;
        ans=2e9;
        for (int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        for (int S=0;S<(1<<n);S++){
            int mx1=0,mx2=0;
            int max1=0,max2=0;
            int sum1=0,sum2=0;
            for (int i=0;i<n;i++){
                if (S>>i&1){
                    mx1=max(mx1,x[i]);
                    sum1+=2*y[i];
                    max1=max(max1,x[i]+y[i]);
                }
                else{
                    mx2=max(mx2,x[i]);
                    sum2+=2*y[i];
                    max2=max(max2,x[i]+y[i]);
                }
            }
            sum1+=2*mx1-max1;
            sum2+=2*mx2-max2;
            ans=min(ans,max(sum1,sum2));
        }
        cout<<ans<<"\n";
    }
}

signed main(){
    freopen("couple.in","r",stdin);
    freopen("couple.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T;
    cin>>T;
    while (T--) annika::main();

    return 0;
}