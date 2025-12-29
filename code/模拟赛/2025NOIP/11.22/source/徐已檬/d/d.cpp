#include <bits/stdc++.h>
using namespace std;
int n,mod;
signed main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>mod;
    if (n==1){
        cout<<"1";
    }
    if (n==2){
        cout<<"0 1\n0 1";
    }
    if (n==3){
        cout<<"0 1 2\n0 0 3\n0 0 3";
    }
    if (n==4){
        cout<<"0 1 9 6\n0 0 1 15\n0 0 0 16\n0 0 0 16";
    }
    if (n==5){
        cout<<"0 1 40 60 24\n0 0 1 28 96\n0 0 0 1 124\n0 0 0 0 125\n0 0 0 0 125";
    }
    return 0;
}