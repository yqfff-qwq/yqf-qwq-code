#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
using namespace std;
namespace FastIO
{
    const int BUF_SIZE=1<<20;
    char in_buf[BUF_SIZE],out_buf[BUF_SIZE];
    char* in_ptr=in_buf+BUF_SIZE;
    char* out_ptr=out_buf;
    char get_char()
    {
        if(in_ptr==in_buf+BUF_SIZE)
        {
            in_ptr=in_buf;
            fread(in_buf,1,BUF_SIZE,stdin);
        }
        return *in_ptr++;
    }
    void put_char(char c)
    {
        if(out_ptr==out_buf+BUF_SIZE)
        {
            fwrite(out_buf,1,BUF_SIZE,stdout);
            out_ptr=out_buf;
        }
        *out_ptr++=c;
    }
    struct Flusher
    {
        ~Flusher()
        {
            if(out_ptr!=out_buf)
            {
                fwrite(out_buf,1,out_ptr-out_buf,stdout);
            }
        }
    } flusher;
}
#define getchar FastIO::get_char
#define putchar FastIO::put_char
inline int read()
{
    int x=0;
    bool zf=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
        {
            zf=0;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return zf?x:-x;
}
void print(cint x)
{
    if(x==0)
    {
        putchar('0');
        return;
    }
    char buf[12];
    int len=0,y=x;
    if(y<0)
    {
        putchar('-');
        y=-y;
    }
    while(y)
    {
        buf[len++]=(y%10)+'0';
        y/=10;
    }
    while(len--)
    {
        putchar(buf[len]);
    }
}
inline void princh(cint x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=1e3,V=2e4;
int n;
int lim,a[N+1],b[N+1];
int MX;
int f[V+1],g[V+1];
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    n=read();
    lim=read();
    MX=lim;
    for(int i=1;i<n;++i)
    {
        a[i]=read();
        b[i]=read();
        MX=max({MX,a[i]+b[i]});
    }
    for(int i=0;i<lim;++i)f[i]=i;
    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<=MX;++j)g[j]=0;
        int mx=0;
        for(int j=0;j<a[i-1];++j)mx=max(f[j],mx);
        for(int j=0;j<b[i-1];++j)g[j]=mx+j;
        for(int j=0;j<a[i-1];++j)g[j+b[i-1]]=max(g[j+b[i-1]],f[j]+b[i-1]);
        for(int j=a[i-1];j<min(MX+1,a[i-1]+b[i-1]);++j)g[j-a[i-1]]=max(g[j-a[i-1]],f[j]);
        for(int j=a[i-1]+b[i-1];j<=MX;++j)g[j]=max(g[j],f[j]);
        for(int j=0;j<=MX;++j)f[j]=g[j];
        // for(int j=0;j<=MX;++j)printf("f[%d][%d]=%d\n",i,j,f[j]);
    }
    int ans=0;
    for(int i=0;i<=MX;++i)
    {
        ans=max(ans,f[i]);
    }
    print(ans);
    return 0;
}