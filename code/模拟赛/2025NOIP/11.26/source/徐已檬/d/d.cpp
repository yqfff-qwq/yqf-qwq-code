#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace annika{
    const int N=3003;
    int n,q,a[N],b[N],nxt[N],s[N];
    void main(){
        cin>>n>>q;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++){
            cin>>b[i];
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n+1;j++){
                if (j==n+1 || b[j]<=b[i]){
                    nxt[i]=j;
                    break;
                }
            }
            // cout<<"nxt["<<i<<"]="<<nxt[i]<<"\n";
        }
        for (int i=n;i>=1;i--){
            s[i]=s[i+1]+a[i];
        }
        while (q--){
            int S,T,U,ans=0;
            cin>>S>>T>>U;
            int mx=0;
            for (int i=S;i<T;i++){
                mx=max(mx,a[i]);
            }
            if (mx>U){
                cout<<"-1\n";
                continue;
            }
            int now=0;
            for (int i=S;i<T;i++){
                int t=min(T,nxt[i]);
                // cerr<<i<<":\nnxt:"<<t<<"\n"; //
                int u=min(U-now,s[i]-s[t]-now);
                // cerr<<" "<<U-now<<" "<<s[i]-s[t]<<"\n";
                // cerr<<"coin number:"<<u<<"\n"; //
                if (u>0){
                    now+=u;
                    ans+=u*b[i];
                }
                // cerr<<"total coin number:"<<now<<"\n"; //
                now-=a[i];
            }
            // cerr<<"\n"; //
            cout<<ans<<"\n";
        }
    }
}

signed main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);

    annika::main();

    return 0;
}