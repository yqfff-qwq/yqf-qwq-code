#include <bits/stdc++.h>
using namespace std;

namespace annika{
    const int N=1e4+3;
    int n,t,ans[N];
    struct node{
        int l,r,id;
    }a[N];
    bool cmp(const node &a,const node &b){
        if (a.l!=b.l) return a.l<b.l;
        return a.r<b.r;
    }
    void main(){
        cin>>n>>t;
        for (int i=1;i<=n;i++){
            cin>>a[i].l>>a[i].r;
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        int lst=-1;
        for (int i=1;i<=n;i++){
            lst=max(lst+1,a[i].l);
            ans[a[i].id]=lst;
            if (lst+t>a[i].r){
                cout<<"no";
                return;
            }
        }
        cout<<"yes\n";
        for (int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
    }
}

signed main(){
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    annika::main();

    return 0;
}