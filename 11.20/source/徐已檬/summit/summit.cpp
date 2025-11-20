#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define MP make_pair
#define pii pair<int,int>
using namespace std;

namespace annika{
    const int N=4e2+3;
    int n,m,f[2][N][N];
    int a[N],b[N];
    
    void cmn(int &a,int b){
        a=min(a,b);
    }

    void Main(){
        cin>>n>>m; cin>>m;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++){
            cin>>b[i];
        }
        int now=1,pre=0;
        memset(f,0x3f,sizeof(f));
        f[pre][0][0]=0;
        for (int i=1;i<=n;i++){
            for (int j=0;j<=n;j++){
                for (int k=0;k<=n;k++){
                    f[now][j][k]=f[pre][j][k];
                    if (k<j){
                        if (j) cmn(f[now][j][k],f[pre][j-1][k]+a[i]);
                    }
                    if (k<=j){
                        if (k) cmn(f[now][j][k],f[pre][j][k-1]+b[i]);
                        if (j && k) cmn(f[now][j][k],f[pre][j-1][k-1]+a[i]+b[i]);
                    }
                }
            }
            now^=1; pre^=1;
        }
        cout<<f[pre][m][m]<<"\n";
    }
}

signed main(){
    freopen("summit.in","r",stdin);
    freopen("summit.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T;
    cin>>T;
    while (T--){
        annika::Main();
    }

    return 0;
}