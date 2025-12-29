#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;

const int N=5e5+3;
int n,m;

namespace sub1{
    const int M=1e4+3;
    pii a[N];
    int f[M];
    void main(){
        for (int i=1;i<=n;i++){
            cin>>a[i].se>>a[i].fi;
        }
        for (int i=1;i<=n;i++){
            for (int j=m;j>=a[i].fi;j--){
                f[j]=max(f[j],f[j-a[i].fi]+a[i].se);
            }
        }

        // for (int i=m;i>=1;i--){
        //     if (i==1 || f[i]!=f[i-1]){
        //         cerr<<m<<" "<<i<<"\n";
        //         break;
        //     }
        // }

        cout<<f[m];
    }
}

namespace sub2{
    int n1,n2,a[N],a1,a2;
    int b1[N],b2[N];
    int s[N];
    bool cmp(int a,int b){
        return a>b;
    }
    void main(){
        for (int i=1;i<=n;i++){
            int t;
            cin>>t>>a[i];
            if (a[i]==a[1]){
                b1[++n1]=t;
            }
            else{
                b2[++n2]=t;
                a2=a[i];
            }
        }
        a1=a[1];
        sort(b1+1,b1+n1+1,cmp);
        sort(b2+1,b2+n2+1,cmp);
        // cerr<<a1<<" "<<a2<<"\n";
        // cerr<<n1<<" "<<n2<<"\n";
        if (!n2){
            int cnt=min(n1,m/a1),ans=0;
            for (int i=1;i<=cnt;i++){
                ans+=b1[i];
            }
            cout<<ans;
        }
        else{
            int up=min(n1,m/a1),ans=0;
            for (int i=1;i<=n2;i++){
                s[i]=s[i-1]+b2[i];
            }
            int sum=0;
            for (int i=0;i<=up;i++){
                sum+=b1[i];
                ans=max(ans,sum+s[min(n2,(m-i*a1)/a2)]);
            }
            cout<<ans;
        }
    }
}

signed main(){
    freopen("knapsack.in","r",stdin);
    freopen("knapsack.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    if (n*m<=1e8) sub1::main();
    else sub2::main();

    return 0;
}