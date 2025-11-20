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
cint N=2e6;
cint inf=1e9+1;
int n,kl,kr,a[N+1],b[N+1];
inline int amin(cint x,cint y)
{
    return (a[x]<a[y]?x:y);
}
inline int bmin(cint x,cint y)
{
    return (b[x]<b[y]?x:y);
}
struct dat{
    int x,y;
};
inline bool operator<(dat x,dat y)
{
    return (a[x.x]+b[x.y]<a[y.x]+b[y.y]);
}
struct info{
    int ma,mb,la,lb,mn;
    dat va,vb,vc;
};
inline info operator+(info x,info y)
{
    info res;
    res.ma=amin(x.ma,y.ma);
    res.mb=bmin(x.mb,y.mb);
    res.mn=min(x.mn,y.mn);
    res.va=min({x.va,y.va,{x.ma,y.mb}});
    res.vc=min({x.vc,y.vc,{y.ma,x.mb}});
    res.vb=min(x.vb,y.vb);
    if(x.mn>y.mn)
    {
        res.vb=min({res.vb,x.vc,{y.la,x.mb}});
        res.la=amin(x.ma,y.la);
        res.lb=y.lb;
    }
    else if(y.mn>x.mn)
    {
        res.vb=min({res.vb,y.vc,{y.ma,x.lb}});
        res.la=x.la;
        res.lb=bmin(y.mb,x.lb);
    }
    else
    {
        res.la=x.la;
        res.lb=y.lb;
        res.vb=min(res.vb,{y.la,x.lb});
    }
    return res;
}
struct Segment_Tree{
    struct node{
        int l,r;
        info x;
        int tag;
    }t[(N<<2)+5];
    inline void push_up(cint p)
    {
        t[p].x=t[p<<1].x+t[p<<1|1].x;
    }
    inline void adp(cint p,cint x)
    {
        t[p].tag+=x;
        t[p].x.mn+=x;
    }
    inline void push_down(cint p)
    {
        if(t[p].tag)
        {
            adp(p<<1,t[p].tag);
            adp(p<<1|1,t[p].tag);
            t[p].tag=0;
        }
    }
    void Build(cint p,cint l,cint r)
    {
        t[p].l=l;
        t[p].r=r;
        t[p].tag=0;
        if(l==r)
        {
            t[p].x=info{l,l,l,0,0,{l,l},{0,0},{l,l}};
            return;
        }
        cint mid=l+r>>1;
        Build(p<<1,l,mid);
        Build(p<<1|1,mid+1,r);
        push_up(p);
    }
    void build()
    {
        Build(1,0,n);
    }
    void Update(cint p,cint l,cint r,cint x)
    {
        if(t[p].l>r||t[p].r<l)return;
        if(t[p].l>=l&&t[p].r<=r)
        {
            adp(p,x);
            return;
        }
        push_down(p);
        Update(p<<1,l,r,x);
        Update(p<<1|1,l,r,x);
        push_up(p);
    }
    void update(cint l,cint r,cint x)
    {
        Update(1,l,r,x);
    }
    void Modify(cint p,cint x)
    {
        if(t[p].l>x||t[p].r<x||t[p].l==t[p].r)return;
        push_down(p);
        Modify(p<<1,x);
        Modify(p<<1|1,x);
        push_up(p);
    }
    void modify(cint x)
    {
        Modify(1,x);
    }
    info ask()
    {
        return t[1].x;
    }
}T;
ll ans;
void solve()
{
    n=read();
    kl=read();
    kr=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)b[i]=read();
    a[0]=b[0]=inf;
    ans=0;
    T.build();
    for(int i=1;i<=kr;++i)
    {
        info p=T.ask();
        int l,r,x;
        if(p.va<p.vb)
        {
            l=p.va.x,r=p.va.y,x=1;
        }
        else
        {
            l=p.vb.x,r=p.vb.y,x=-1;
        }
        ans+=a[l]+b[r];
        a[l]=b[r]=inf;
        if(l>r)swap(l,r);
        T.modify(l);
        T.modify(r);
        T.update(l,r-1,x);
        if(i>=kl)princh(ans,' ');
    }
    putchar('\n');
}
int main()
{
    freopen("summit.in","r",stdin);
    freopen("summit.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}