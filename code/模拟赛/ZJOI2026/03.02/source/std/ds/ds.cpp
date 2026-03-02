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
    char buf[25];
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
cint N=(1<<18)+5;
cint inf=1e9;
int m,n,q;
struct Trie{
    int N,lo,*f,*s;
    array<int,2>* mn;
    void push_up(cint p)
    {
        mn[p]=min(mn[p<<1],mn[p<<1|1]);
        f[p]=max(f[p<<1],f[p<<1|1]);
        if(f[p]==s[p]/2)
        {
            f[p]=f[p<<1]+f[p<<1|1];
        }
    }
    void build(cint l,cint r)
    {
        N=r-l+1;
        lo=l;
        f=new int[2*N];
        s=new int[2*N];
        mn=new array<int,2>[2*N];
        for(int i=N;i<2*N;++i)
        {
            s[i]=1;
            f[i]=0;
            mn[i]={inf,i};
        }
        for(int i=N-1;i;--i)
        {
            push_up(i);
            s[i]=s[i<<1]+s[i<<1|1];
        }
    }
    void insert(int p,cint t)
    {
        p=p-lo+N;
        f[p]=1;
        mn[p]={t,p};
        for(p>>=1;p;p>>=1)
        {
            push_up(p);
        }
    }
    void pop()
    {
        int p=mn[1][1];
        f[p]=0;
        mn[p]={inf,p};
        for(p>>=1;p;p>>=1)
        {
            push_up(p);
        }
    }
}tr[N*2];
struct Segment_Tree{
    int mn[N*2],mx[N*2],tg[N*2],len[N*2],ct[N*2];
    ll su[N*2],hs[N*2],ht[N*2];
    void addt(cint p,cint k)
    {
        hs[p]+=1ll*k*su[p];
        if(~tg[p])
        {
            ht[p]+=1ll*tg[p]*k;
        }
        else
        {
            ct[p]+=k;
        }
    }
    void cover(cint p,cint k)
    {
        mn[p]=mx[p]=tg[p]=k;
        su[p]=1ll*len[p]*k;
    }
    void addh(cint p,cll h)
    {
        hs[p]+=h*len[p];
        ht[p]+=h;
    }
    void push_down(cint p)
    {
        if(ct[p])
        {
            addt(p<<1,ct[p]);
            addt(p<<1|1,ct[p]);
            ct[p]=0;
        }
        if(~tg[p])
        {
            cover(p<<1,tg[p]);
            cover(p<<1|1,tg[p]);
            tg[p]=-1;
        }
        if(ht[p])
        {
            addh(p<<1,ht[p]);
            addh(p<<1|1,ht[p]);
            ht[p]=0;
        }
    }
    void push_up(cint p)
    {
        su[p]=su[p<<1]+su[p<<1|1];
        hs[p]=hs[p<<1]+hs[p<<1|1];
        mn[p]=min(mn[p<<1],mn[p<<1|1]);
        mx[p]=max(mx[p<<1],mx[p<<1|1]);
    }
    void Build(cint l,cint r,cint p)
    {
        tg[p]=-1;
        len[p]=r-l+1;
        tr[p].build(l,r);
        if(l==r)
        {
            return;
        }
        cint mid=(l+r)>>1;
        Build(l,mid,p<<1);
        Build(mid+1,r,p<<1|1);
    }
    void build()
    {
        Build(0,n-1,1);
    }
    void Update(cint ul,cint ur,cint v,cint l,cint r,cint p)
    {
        if(mn[p]>=v)
        {
            return;
        }
        if(ul<=l&&r<=ur&&mx[p]<=v)
        {
            cover(p,v);
            return;
        }
        cint mid=(l+r)>>1;
        push_down(p);
        if(ul<=mid)
        {
            Update(ul,ur,v,l,mid,p<<1);
        }
        if(mid<ur)
        {
            Update(ul,ur,v,mid+1,r,p<<1|1);
        }
        push_up(p);
    }
    void update(cint ul,cint ur,cint v)
    {
        Update(ul,ur,v,0,n-1,1);
    }
    ll Askh(cint ul,cint ur,cint l,cint r,cint p)
    {
        if(ul<=l&&r<=ur)
        {
            return hs[p];
        }
        cint mid=(l+r)>>1;
        ll s=0;
        push_down(p);
        if(ul<=mid)
        {
            s+=Askh(ul,ur,l,mid,p<<1);
        }
        if(mid<ur)
        {
            s+=Askh(ul,ur,mid+1,r,p<<1|1);
        }
        return s;
    }
    ll askh(cint ul,cint ur)
    {
        return Askh(ul,ur,0,n-1,1);
    }
}T;
int a[N],mn[N*2];
struct Query{
    int l,r,id,sign;
};
vector<Query>qy[N];
ll ans[1000005];
struct info{
    int d,w,t,o;
};
void upd(cint x,cint t)
{
    vector<info>op;
    op.push_back({0,1,t,0});
    for(int d=0;d<m;++d)
    {
        int p=(x+n)>>d,lst=mn[p];
        tr[p].insert(x,t);
        mn[p]=(d?min(mn[p<<1],mn[p<<1|1]):t);
        if(mn[p^1]>=0)
        {
            op.push_back({d+1,1<<d,mn[p^1],1});
        }
        if(mn[p]==lst)
        {
            continue;
        }
        for(;tr[p^1].mn[1][0]<=mn[p];tr[p^1].pop())
        {
            op.push_back({d+1,tr[p^1].f[1]+(1<<d),tr[p^1].mn[1][0],0});
        }
        if(tr[p^1].mn[1][0]<=t)
        {
            op.push_back({d+1,tr[p^1].f[1]+(1<<d),mn[p],0});
        }
    }
    sort(op.begin(),op.end(),[&](info i,info j){return (i.t>j.t);});
    static int f[20],w[20];
    memset(f,0,sizeof(f));
    memset(w,0,sizeof(w));
    for(auto e:op)
    {
        if(e.o)
        {
            for(int i=0;i<e.d;++i)
            {
                w[i]+=e.w;
            }
        }
        else
        {
            f[e.d]=max(f[e.d],e.w);
        }
        int z=0;
        for(int i=0;i<=m;++i)
        {
            z=max(z,f[i]+w[i]);
        }
        T.update(0,e.t,z);
    }
}
int main()
{
    freopen("ds.in","r",stdin);
    freopen("ds.out","w",stdout);
    m=read();
    n=1<<m;
    q=read();
    T.build();
    for(int i=0;i<n;++i)
    {
        a[i]=read();
    }
    for(int i=1;i<=q;++i)
    {
        int l1=read();
        int r1=read();
        int l2=read();
        int r2=read();
        qy[r2-1].push_back({l1-1,r1-1,i,1});
        if(l2-1>0)
        {
            qy[l2-2].push_back({l1-1,r1-1,i,-1});
        }
    }
    memset(mn,-0x3f,sizeof(mn));
    for(int i=0;i<n;++i)
    {
        upd(a[i],i);
        T.addt(1,1);
        for(auto o:qy[i])
        {
            ans[o.id]+=o.sign*T.askh(o.l, o.r);
        }
    }
    for(int i=1;i<=q;++i)
    {
        princh(ans[i],'\n');
    }
    return 0;
}