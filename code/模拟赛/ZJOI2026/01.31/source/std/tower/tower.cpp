#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
using namespace std;
int read()
{
    int x=0;
    bool zf=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')zf=0;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch-'0');
        ch=getchar();
    }
    return (zf?x:-x);
}
void print(cint x)
{
    if(x<10)
    {
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
void princh(cint x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=2e7;
int n,m;
int a[N+1],b[N+1];
int ans;
void solve()
{
    n=read()<<1;
    m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)
    {
        b[i]=a[i];
        a[i]-=m;
    }
    for(int i=1;i<=n;++i)
    {
        a[i+n]=b[i];
    }
    int pl=n+1,pr=n;
    for(int i=1;i<=(n>>1);++i)
    {
        --pl;
        ++pr;
        if(a[pl]+a[pr]<0)
        {
            ++pl;
            ++pr;
        }
    }
    ans=0;
    for(int i=1;i<=(n>>1);++i)
    {
        ans=max(ans,a[pl]+a[pr]);
        ++pl;
        --pr;
    }
    princh(ans,'\n');
}
int main()
{
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}