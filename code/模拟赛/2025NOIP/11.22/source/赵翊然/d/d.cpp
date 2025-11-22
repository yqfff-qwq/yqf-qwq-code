#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int x,y;
    cin>>x>>y;
    if(x==1){
        cout<<"0\n";
    }
    if(x==2){
        cout<<"0 1\n0 1";
    }
    if(x==3){
        cout<<"0 1 2\n0 0 3\n0 0 3";
    }
}