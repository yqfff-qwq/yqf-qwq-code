#include <bits/stdc++.h>
using namespace std;

namespace annika{
    const int N=2e5+3;
    int n;
    char s[N];
    void main(){
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=1;i<=n;i++){
            if (i==n || s[i]!=s[i+1]){
                cout<<i;
                return;
            }
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    annika::main();

    return 0;
}