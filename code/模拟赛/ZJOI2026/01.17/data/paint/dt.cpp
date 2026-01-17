#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int rn(int l,int r){return l+rnd()%(r-l+1);}
int n=22;
vector<array<int,4> >an;
int main(){
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)for(int x=0;x<3;x++)for(int y=0;y<3;y++)
    if(rn(0,60)==0)
    an.push_back({i,x,j,y});
    printf("%d %d\n",n,an.size());
    for(auto a:an)printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
    return 0;
}