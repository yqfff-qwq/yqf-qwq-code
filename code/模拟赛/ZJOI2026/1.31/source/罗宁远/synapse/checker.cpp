#include<bits/stdc++.h>
#include"testlib.h"
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
using namespace std;
cint N=2e6;
int l,n,a[N+1],x[N+1];
void solve()
{
    l=inf.readInt();
    n=inf.readInt();
    for(int i=1;i<=n;++i)a[i]=inf.readInt();
    for(int i=0;i<=n;++i)x[i]=ouf.readInt(0,l);
    if(x[0]!=0)quitf(_wa,"x_0 isn't zero!");
    if(x[n]!=l)quitf(_wa,"x_n isn't l!");
    for(int i=0;i<n;++i)
    {
        if(x[i]>=x[i+1])quitf(_wa,"x_%d >= x_%d!",i,i+1);
    }
    for(int i=0;i<n;++i)
    {
        if(x[i]>a[i+1])quitf(_wa,"x_%d > a_%d!",i,i+1);
    }
    for(int i=1;i<=n;++i)
    {
        if(x[i]<a[i])quitf(_wa,"x_%d < a_%d!",i,i);
    }
    int res=ans.readInt();
    int mx=0,mn=l;
    for(int i=1;i<=n;++i)
    {
        mx=max(mx,x[i]-x[i-1]);
        mn=min(mn,x[i]-x[i-1]);
    }
    if(res<mx-mn)quitf(_wa,"You're wrong!");
}
int main(int argc,char* argv[])
{
    registerTestlibCmd(argc,argv);
    int T=inf.readInt();
    while(T--)solve();
    quitf(_ok,"You're right!");
    return 0;
}