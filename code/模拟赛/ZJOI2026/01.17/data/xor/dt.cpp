#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int V=(1<<18);
int rn(int l,int r){return l+rnd()%(r-l+1);}
int n=1e5,m=1e5,a[V];
int main(){
    printf("%d %d\n",n,m);
    for(int i=0;i<V;i++)a[i]=i;
    shuffle(a,a+V,rnd);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    return 0;
}