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
cint N=4e3,Q=4e3;
cll inf=1e18;
int n,q;
struct edge{
    int to,val;
};
vector<edge>son[N+1];
int dep[N+1];
ll dp[N+1][Q+1],tmp[Q+1];
int cnt[N+1];
vector<int>px[N+1],py[N+1];
void dfs(cint u)
{
    for(edge e:son[u])
    {
        dep[e.to]=dep[u]+e.val;
        dfs(e.to);
    }
}
void DP(cint u)
{
    cnt[u]=0;
    for(int i=0;i<=q;++i)dp[u][i]=0;
    for(edge e:son[u])
    {
        cint v=e.to;
        dfs(v);
        for(int i=0;i<=cnt[u]+cnt[v];++i)tmp[i]=0;
        for(int i=0;i<=cnt[u];++i)
        {
            for(int j=0;j<=cnt[v];++j)
            {
                tmp[i+j]=max(tmp[i+j],dp[u][i]+dp[v][j]);
            }
        }
        cnt[u]+=cnt[v];
        for(int i=0;i<=cnt[u];++i)dp[u][i]=tmp[i];
    }
    for(int x:py[u])
    {
        dp[u][++cnt[u]]=-inf;
        for(int i=cnt[u];i>=1;--i)
        {
            dp[u][i]=max(dp[u][i],dp[u][i-1]+x);
        }
    }
    for(int x:px[u])
    {
        for(int i=0;i<cnt[u];++i)
        {
            dp[u][i]=max(dp[u][i],dp[u][i+1]+x);
        }
    }
}
int rt;
bool flag[N+1];
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    n=read();
    q=read();
    for(int i=1;i<n;++i)
    {
        cint u=read(),v=read(),w=read();
        flag[v]=1;
        son[u].push_back({v,w});
    }
    for(int i=1;i<=n;++i)if(!flag[i])rt=i;
    dfs(rt);
    for(int i=1;i<=q;++i)
    {
        cint op=read(),u=read(),x=read();
        if(op==1)
        {
            px[u].push_back(x-dep[u]);
        }
        else
        {
            py[u].push_back(x+dep[u]);
        }
        DP(rt);
        princh(dp[rt][0],'\n');
    }
    return 0;
}