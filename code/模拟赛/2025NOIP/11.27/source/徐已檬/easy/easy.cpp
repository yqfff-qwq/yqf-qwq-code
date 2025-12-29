#include <bits/stdc++.h>
using namespace std;

int n,k;

namespace sub1{
    void main(){
        int a,b;
        cin>>a>>b;
        if (!a && !b){
            cout<<"2\n";
            return;
        }
        int c=__gcd(a,b);
        int d=__gcd(c,k);
        if (k/d+1==999053370 || k/d+1==998589382 || k/d+1==998497367 || k/d+1==998608646 || k/d+1==999530249 || k/d+1==999262062) cerr<<"k="<<k<<" a="<<a<<" b="<<b<<" d="<<d<<"\n";
        cout<<k/d+1<<"\n";
    }
}

signed main(){
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while (t--){
        cin>>n>>k;
        if (n==2){
            sub1::main();
        }
    }

    return 0;
}