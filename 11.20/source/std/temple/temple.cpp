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
cint N=1e5,Q=1e5,LGN=17;
int n,q;
vector<int>to[N+1];
inline void add_edge(cint u,cint v)
{
    to[u].push_back(v);
    to[v].push_back(u);
}
int a[N+1];
bitset<N+1>S[N+1],res;
int f[N+1],dep[N+1];
int dfn[N+1],idx[N+1];
struct Spare_Table{
    int st[LGN+1][N+1];
    inline int cmin(cint x,cint y)
    {
        return (dep[x]<dep[y]?x:y);
    }
    void init()
    {
        for(int i=1;i<=n;++i)st[0][i]=dfn[i];
        for(int k=1;k<=__lg(n);++k)
        {
            for(int i=1;i<=n-(1<<k)+1;++i)
            {
                st[k][i]=cmin(st[k-1][i],st[k-1][i+(1<<k-1)]);
            }
        }
    }
    inline int ask(cint l,cint r)
    {
        cint p=__lg(r-l+1);
        return cmin(st[p][l],st[p][r-(1<<p)+1]);
    }
}ST;
inline int lca(cint u,cint v)
{
    if(u==v)return u;
    return f[ST.ask(min(idx[u],idx[v])+1,max(idx[u],idx[v]))];
}
inline int dis(cint u,cint v)
{
    return (dep[u]+dep[v]-(dep[lca(u,v)]<<1)+1);
}
void dfs(cint u,cint fa)
{
    f[u]=fa;
    dep[u]=dep[fa]+1;
    dfn[(idx[u]=++n)]=u;
    S[u]=S[fa];
    S[u][a[u]].flip();
    for(int v:to[u])
    {
        if(v==fa)continue;
        dfs(v,u);
    }
}
int main()
{
    freopen("temple.in","r",stdin);
    freopen("temple.out","w",stdout);
    n=read();
    read();read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
    }
    for(int i=1;i<n;++i)
    {
        add_edge(read(),read());
    }
    n=0;
    dfs(1,0);
    ST.init();
    q=read();
    while(q--)
    {
        cint u=read(),v=read(),c=lca(u,v);
        // printf("lca(%d,%d)=%d\n",u,v,c);
        res=S[u]^S[v];
        res[a[c]].flip();
        puts((res.count()==dis(u,v)?"No":"Yes"));
    }
    return 0;
}