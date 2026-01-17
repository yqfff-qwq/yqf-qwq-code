#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int rn(int l,int r){return l+rnd()%(r-l+1);}
const int N=5e5,V=1e9;
int n;
int main(){
    n=rn(N-4,N);
    printf("%d\n",n);
    for(int i=2;i<=n;i++)printf("%d %d\n",rn(1,i-1),i);
    for(int i=1;i<=n;i++){
        int z=rn(0,1);
        if(z)putchar('?');else putchar(rn(0,1)+'0');
    }
    puts("");
    for(int i=1;i<=n;i++){
        int z=rn(0,1);
        if(z)putchar('?');else putchar(rn(0,1)+'0');
    }
    return 0;
}