#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("berry.in","r",stdin);
    freopen("berry.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>x>>y;
        if(abs(x-y)>1) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}