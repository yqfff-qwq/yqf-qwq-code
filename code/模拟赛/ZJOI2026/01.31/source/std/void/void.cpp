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
    int len=0;
    int y=x;
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
cint N=2e6,M=5e6;
int n,m;
int deg[N+1],head[N+1],c[N+1],s[N+1];
struct edge{
    int to,nxt;
}E[M<<1|1];
int tot;
inline void add_edge(cint u,cint v)
{
    E[++tot]=edge{u,head[v]};
    head[v]=tot;
    E[++tot]=edge{v,head[u]};
    head[u]=tot;
    ++deg[u],++deg[v];
}
void doit(cint u)
{
    for(int i=1;i<=n;++i)c[i]=s[i]=0;
    for(int i=head[u];i;i=E[i].nxt)
    {
        ++c[E[i].to];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=head[i];j;j=E[j].nxt)
        {
            s[i]+=c[E[j].to];
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(i==u)continue;
        if(!(s[i]&1))
        {
            princh(u,' ');
            princh(i,'\n');
            return;
        }
    }
}
void solve()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i)
    {
        deg[i]=head[i]=0;
    }
    tot=0;
    for(int i=1;i<=m;++i)add_edge(read(),read());
    for(int i=1;i<=n;++i)if(deg[i]&1)
    {
        doit(i);
        return;
    }
    doit(1);
    return;
}
int main()
{
    freopen("void.in","r",stdin);
    freopen("void.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}