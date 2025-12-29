#include <bits/stdc++.h>
using namespace std;

namespace annika{
    const int N=1e3+3;
    int n,a[N],f[N];
    vector <vector <int> > ans;
    vector <int> tmp;
    void main(){
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++){
            int p=i;
            tmp.clear();
            while (!f[p]){
                tmp.emplace_back(p);
                f[p]=1; p=a[p];
            }
            if (tmp.size()>=2){
                ans.emplace_back(tmp);
            }
        }
        cout<<ans.size()<<"\n";
        for (auto u:ans){
            cout<<u.size()<<" ";
            for (auto v:u){
                cout<<v<<" ";
            }
            cout<<"\n";
        }
    }
}

signed main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    annika::main();

    return 0;
}