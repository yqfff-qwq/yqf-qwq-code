#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=303;
int n,K,h[N],c[N],mnh=N,a[N],ans=1e18;

namespace sub1{
    void main(){
        int cnt=0;
        for (int i=1;i<=n;i++){
            if (mnh!=h[i]) continue;
            cnt++;
        }
        for (int i=1;i<=n;i++){
            if (mnh!=h[i]) continue;
            for (int j=1;j<=n;j++){
                a[j]=0;
            }
            int res=(cnt-1)*K;
            for (int j=1;j<=n;j++){
                if (i==j) continue;
                int fl=0;
                if (h[i]==mnh) fl=1,h[i]++;
                int mn=0;
                for (int k=1;k<=n;k++){
                    if (h[k]<h[j] && (!mn || a[k]<a[mn])){
                        mn=k;
                    }
                }
                res+=a[mn];
                a[mn]=c[mn];
                if (fl) h[i]--;
            }
            ans=min(ans,res);
        }
        cout<<ans;
    }
}

signed main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>K;
    for (int i=1;i<=n;i++){
        cin>>h[i]>>c[i];
        mnh=min(mnh,h[i]);
    }
    sub1::main();

    return 0;
}