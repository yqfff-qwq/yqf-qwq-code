#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],m,t[N];
long long C(int x){return 1ll*x*(x-1)/2;}
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(C(n)>=m*3+(1<<18)){printf("%d",m);return 0;}
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
    ans+=t[a[i]^a[j]],t[a[i]^a[j]]++;
    printf("%d\n",min(ans/3,m));
    return 0;
}