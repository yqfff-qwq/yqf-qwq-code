#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,q,c;

namespace sub1{
    const int N=1e4+3;
    int a[N];

    void Main(){
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        while (q--){
            int l,r,x;
            cin>>l>>r>>x;
            for (int i=l;i<=r;i++){
                x=abs(x-a[i]);
            }
            cout<<x<<"\n";
        }
        exit(0);
    }
}

// namespace sub2{
//     const int N=1e5+3,M=103;
//     int a[N],V,ans[N];
//     int nxt[N][23];
//     struct qry{
//         int l,r,id;
//     };
//     vector <qry> d[M];

//     void Main(){
//         for (int i=1;i<=n;i++){
//             cin>>a[i];
//             V=max(V,a[i]);
//         }
//         for (int i=1;i<=q;i++){
//             int l,r,x;
//             cin>>l>>r>>x;
//             d[x].push_back({l,r,i});
//         }
//         for (int i=0;i<=V;i++){
//             for (int j=1;j<=n;j++){
//                 nxt[j][0]=
//             }
//         }
//     }
// }

signed main(){
    freopen("reflection.in","r",stdin);
    freopen("reflection.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>q>>c;
    if (n<=10000 && q<=10000){
        sub1::Main();
    }
    // else{
    //     sub2::Main();
    // }
    return 0;
}