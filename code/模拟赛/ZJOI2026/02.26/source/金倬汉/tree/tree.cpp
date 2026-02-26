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
    char buf[12];
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
mt19937 mt(chrono::system_clock().now().time_since_epoch().count());
cint N=3e5+1;
int n,fa[N+1],w[N+1];
vector<int>son[N+1];
ll sum[N+1];
int f[N+1];
int find(cint u){return f[u]==u?u:f[u]=find(f[u]);}
#define pair pair<int,int>
#define x first
#define y second
struct FHQ_Treap{
    struct node{
        uint w;
        ll mult,addt;
        ll val;
        int ls,rs;
        int fa;
    }t[N+1];
    int rt[N+1];
    inline void adp(cint p,cll x)
    {
        t[p].val+=x;
        t[p].addt+=x;
    }
    inline void mup(cint p,cull x)
    {
        t[p].val*=x;
        t[p].mult*=x;
        t[p].addt*=x;
    }
    inline void push_down(cint p)
    {
        if(t[p].mult!=1)
        {
            mup(t[p].ls,t[p].mult);
            mup(t[p].rs,t[p].mult);
            t[p].mult=1;
        }
        if(t[p].addt)
        {
            adp(t[p].ls,t[p].addt);
            adp(t[p].rs,t[p].addt);
            t[p].addt=0;
        }
    }
    inline void push_up(cint p)
    {
        t[t[p].ls].fa=t[t[p].rs].fa=p;
    }
    pair split(cint p,cll x)
    {
        if(!p)return pair(0,0);
        push_down(p);
        if(t[p].val<=x)
        {
            pair res=split(t[p].rs,x);
            t[p].rs=res.x;
            push_up(p);
            return pair(p,res.y);
        }
        else
        {
            pair res=split(t[p].ls,x);
            t[p].ls=res.y;
            push_up(p);
            return pair(res.x,p);
        }
    }
    int merge(int p,int q)
    {
        if(!p||!q)return (p|q);
        push_down(p);
        push_down(q);
        if(t[p].w<t[q].w)swap(p,q);
        if(t[p].val==t[q].val)
        {
            f[q]=p;
            t[p].ls=merge(t[p].ls,t[q].ls);
            t[p].rs=merge(t[p].rs,t[q].rs);
            push_up(p);
            return p;
        }
        pair res=split(q,t[p].val);
        t[p].ls=merge(t[p].ls,res.x);
        t[p].rs=merge(t[p].rs,res.y);
        push_up(p);
        return p;
    }
    void insert(cint p,cll x)
    {
        t[p].w=mt();
        t[p].val=x;
        t[p].mult=1;
        f[p]=p;
        rt[p]=merge(rt[p],p);
        t[rt[p]].fa=0;
    }
    void solve(int p,vector<ll>v,vector<ll>x)
    {
        cint rp=p;
        p=rt[p];
        vector<int>ver;
        for(int i=0;i<(int)v.size();i++)
        {
            pair res=split(p,v[i]);
            p=res.x;
            mup(p,v.size()-i);
            adp(p,x[i]);
            ver.push_back(p);
            p=res.y;
        }
        rt[p=rp]=0;
        for(int i=0;i<(int)v.size();i++)
        {
            rt[p]=merge(rt[p],ver[i]);
        }
    }
    void Down(cint p)
    {
        if(!p)return;
        push_down(p);
        Down(t[p].ls);
        Down(t[p].rs);
    }
    void down()
    {
        Down(rt[1]);
    }
    ll ask(cint p)
    {
        return t[find(p)].val;
    }
    void merge_to(cint p,cint q)
    {
        rt[q]=merge(rt[q],rt[p]);
    }
}T;
void dfs(cint u)
{
    for(int v:son[u])
    {
        dfs(v);
        T.merge_to(v,u);
    }
    sort(son[u].begin(),son[u].end(),[&](int x,int y){return sum[x]<sum[y];});
    vector<ll>val;
    vector<ll>x;
    for(int v:son[u])
    {
        val.push_back(sum[v]);
        x.push_back(sum[u]);
        sum[u]+=sum[v];
    }
    T.solve(u,val,x);
    sum[u]+=w[u];
    T.insert(u,sum[u]);
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read()+1;
    f[1]=1;
    for(int i=2;i<=n;++i)
    {
        f[i]=i;
        fa[i]=read()+1;
        son[fa[i]].push_back(i);
        w[i]=read();
    }
    dfs(1);
    T.down();
    for(int i=2;i<=n;++i)
    {
        princh(T.ask(i),'\n');
    }
    return 0;
}