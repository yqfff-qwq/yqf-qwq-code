#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int rn(int l,int r){return l+rnd()%(r-l+1);}
const int N=5e5,V=1e9;
int n;
int main(){
    n=rn(N-5,N);
    printf("%d\n",n);
    for(int i=1;i<=n;i++)
    printf("%d %d %d\n",rn(1,V),rn(1,V),rn(1,V));
    return 0;
}