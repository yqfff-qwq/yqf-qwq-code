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
inline ll read()
{
    ll x=0;
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
void print(cll x)
{
    if(x==0)
    {
        putchar('0');
        return;
    }
    char buf[20];
    int len=0;
    ll y=x;
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
inline void princh(cll x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=1e6,M=1e6,H=59;
int n,m,s,t;
struct Basis{
    ll b[H+1];
    int t[H+1];
    void clear()
    {
        for(int i=H;i>=0;--i)b[i]=t[i]=0;
    }
    void insert(ll x,int tm)
    {
        for(int i=H;i>=0;--i)
        {
            if(!(x>>i))continue;
            if(tm>t[i])
            {
                swap(x,b[i]);
                swap(tm,t[i]);
            }
            x^=b[i];
        }
    }
    ll ask(ll x,cint tm)
    {
        for(int i=H;i>=0;--i)
        {
            if(t[i]>tm)x=min(x,x^b[i]);
        }
        return x;
    }
}B;
int lst[N+1];
ll val[N+1];
int u[M+1],v[M+1],nxtu[M+1],nxtv[M+1];
ll w[M+1];
void solve()
{
    n=read();
    m=read();
    s=read();
    t=read();
    for(int i=1;i<=m;++i)
    {
        u[i]=read();
        v[i]=read();
        w[i]=read();
    }
    for(int i=1;i<=n;++i)lst[i]=m+1,val[i]=0;
    for(int i=m;i>=1;--i)
    {
        nxtu[i]=lst[u[i]];
        lst[u[i]]=i;
        nxtv[i]=lst[v[i]];
        lst[v[i]]=i;
    }
    B.clear();
    for(int i=1;i<=m;++i)
    {
        val[u[i]]^=w[i];
        val[v[i]]^=w[i];
        if(u[i]!=s&&u[i]!=t)B.insert(val[u[i]],nxtu[i]);
        if(v[i]!=s&&v[i]!=t)B.insert(val[v[i]],nxtv[i]);
        princh(B.ask(val[s],i),'\n');
    }
}
int main()
{
    freopen("mincut.in","r",stdin);
    freopen("mincut.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}