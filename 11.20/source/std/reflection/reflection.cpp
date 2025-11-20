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
mt19937 mt(chrono::system_clock().now().time_since_epoch().count());
cint N=2e5,Q=2e5,V=2e5;
int n,q;
int a[N+1];
int ql[Q+1],qr[Q+1],qx[Q+1];
int ans[Q+1];
vector<int>mdf[N+1],qry[N+1];
#define pair pair<int,int>
#define x first
#define y second
int f[Q+1];
int find(cint u)
{
    return (f[u]==u?u:f[u]=find(f[u]));
}
struct FHQ_Treap{
    int rt;
    struct node{
        int fa;
        int val;
        int atag;
        bool ftag;
        uint w;
        int ls,rs;
    }t[Q+1];
    inline void flip(cint p)
    {
        if(!p)return;
        t[p].ftag^=1;
        t[p].atag=-t[p].atag;
        t[p].val=-t[p].val;
        swap(t[p].ls,t[p].rs);
    }
    inline void adp(cint p,cint x)
    {
        if(!p)return;
        t[p].val+=x;
        t[p].atag+=x;
    }
    void push_down(cint p)
    {
        if(t[p].ftag)
        {
            flip(t[p].ls);
            flip(t[p].rs);
            t[p].ftag=0;
        }
        if(t[p].atag)
        {
            adp(t[p].ls,t[p].atag);
            adp(t[p].rs,t[p].atag);
            t[p].atag=0;
        }
    }
    inline void push_up(cint p)
    {
        t[t[p].ls].fa=t[t[p].rs].fa=p;
    }
    pair split(cint p,cint k)
    {
        if(!p)return {0,0};
        push_down(p);
        if(t[p].val<=k)
        {
            pair res=split(t[p].rs,k);
            t[p].rs=res.x;
            res.x=p;
            push_up(p);
            return res;
        }
        else
        {
            pair res=split(t[p].ls,k);
            t[p].ls=res.y;
            res.y=p;
            push_up(p);
            return res;
        }
    }
    inline int merge(int p,int q)
    {
        if(!p||!q)return (p|q);
        if(t[p].w<t[q].w)swap(p,q);
        push_down(p);
        push_down(q);
        if(t[p].val==t[q].val)
        {
            f[find(q)]=p;
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
    int ask(cint p)
    {
        vector<int>ver;
        for(int i=p;i;i=t[i].fa)
        {
            ver.push_back(i);
        }
        reverse(ver.begin(),ver.end());
        for(int v:ver)push_down(v);
        return t[p].val;
    }
    void solve(cint x)
    {
        adp(rt,-x);
        pair res=split(rt,0);
        flip(res.x);
        rt=merge(res.x,res.y);
        t[rt].fa=0;
    }
    void insert(cint p,cint x)
    {
        t[p]={0,x,0,0,(uint)mt(),0,0};
        rt=merge(rt,p);
        t[rt].fa=0;
    }
}T;
int main()
{
    freopen("reflection.in","r",stdin);
    freopen("reflection.out","w",stdout);
    n=read();
    q=read();
    read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=q;++i)
    {
        ql[i]=read();
        qr[i]=read();
        qx[i]=read();
        mdf[ql[i]].push_back(i);
        qry[qr[i]].push_back(i);
        f[i]=i;
    }
    for(int i=1;i<=n;++i)
    {
        for(int p:mdf[i])
        {
            T.insert(p,qx[p]);
        }
        T.solve(a[i]);
        for(int p:qry[i])
        {
            ans[p]=T.ask(find(p));
        }
    }
    for(int i=1;i<=q;++i)
    {
        princh(ans[i],'\n');
    }
    return 0;
}