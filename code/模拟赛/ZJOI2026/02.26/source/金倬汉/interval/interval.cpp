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
cint N=1e5;
int n,m;
int cl[N+1],cr[N+1],c[N<<1|1];
int op[N+1],qx[N+1],qy[N+1];
int f[N+1],fmx[N+1],fmn[N+1];
int find(cint x){return (f[x]==x?x:f[x]=find(f[x]));}
void merge(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y)return;
    f[x]=y;
    fmx[y]=max(fmx[y],fmx[x]);
    fmn[y]=min(fmn[y],fmn[x]);
}
map<int,int>mp;
#define YES putchar('Y'),putchar('E'),putchar('S'),putchar('\n')
#define NO putchar('N'),putchar('O'),putchar('\n')
struct segr{
    int idx,val;
};
bool operator<(segr x,segr y)
{
    return (x.val==y.val?x.idx<y.idx:x.val<y.val);
}
bool operator==(segr x,segr y)
{
    return (x.val==y.val&&x.idx==y.idx);
}
segr rmax(segr x,segr y)
{
    return (x<y?y:x);
}
struct Segment_TreeMX{
    struct node{
        int l,r;
        segr val;
    }t[N<<3|1];
    struct Deletable_Heap{
        priority_queue<segr>p,q;
        inline void insert(segr x)
        {
            q.push(x);
        }
        inline void erase(segr x)
        {
            p.push(x);
        }
        void D()
        {
            while(!p.empty()&&p.top()==q.top())
            {
                p.pop();
                q.pop();
            }
        }
        segr top()
        {
            D();
            return q.top();
        }
        bool empty()
        {
            D();
            return q.empty();
        }
    }q[N<<1|1];
    int tid[N<<1|1];
    inline void push_up(cint p)
    {
        t[p].val=rmax(t[p<<1].val,t[p<<1|1].val);
    }
    void Build(cint p,cint l,cint r)
    {
        t[p].l=l;
        t[p].r=r;
        if(l==r)
        {
            tid[l]=p;
            return;
        }
        cint mid=(l+r)>>1;
        Build(p<<1,l,mid);
        Build(p<<1|1,mid+1,r);
    }
    void build()
    {
        Build(1,1,m<<1);
    }
    void insert(int p,segr x)
    {
        q[p].insert(x);
        t[tid[p]].val=rmax(t[tid[p]].val,x);
        p=tid[p];
        while(p>>=1)push_up(p);
    }
    void erase(int p,segr x)
    {
        q[p].erase(x);
        t[tid[p]].val=q[p].empty()?(segr){0,0}:q[p].top();
        p=tid[p];
        while(p>>=1)push_up(p);
    }
    segr Ask(cint p,cint l,cint r)
    {
        if(t[p].l>r||t[p].r<l)return (segr){0,0};
        if(t[p].l>=l&&t[p].r<=r)return t[p].val;
        return rmax(Ask(p<<1,l,r),Ask(p<<1|1,l,r));
    }
    segr ask(cint l,cint r)
    {
        return Ask(1,l,r);
    }
}TMX;
struct segl{
    int idx,val;
};
bool operator<(segl x,segl y)
{
    return (x.val==y.val?x.idx<y.idx:x.val>y.val);
}
bool operator==(segl x,segl y)
{
    return (x.val==y.val&&x.idx==y.idx);
}
segl rmin(segl x,segl y)
{
    return (x<y?y:x);
}
struct Segment_TreeMN{
    struct node{
        int l,r;
        segl val;
    }t[N<<3|1];
    struct Deletable_Heap{
        priority_queue<segl>p,q;
        inline void insert(segl x)
        {
            q.push(x);
        }
        inline void erase(segl x)
        {
            p.push(x);
        }
        void D()
        {
            while(!p.empty()&&p.top()==q.top())
            {
                p.pop();
                q.pop();
            }
        }
        segl top()
        {
            D();
            return q.top();
        }
        bool empty()
        {
            D();
            return q.empty();
        }
    }q[N<<1|1];
    int tid[N<<1|1];
    inline void push_up(cint p)
    {
        t[p].val=rmin(t[p<<1].val,t[p<<1|1].val);
    }
    void Build(cint p,cint l,cint r)
    {
        t[p].l=l;
        t[p].r=r;
        t[p].val=(segl){0,m<<1|1};
        if(l==r)
        {
            tid[l]=p;
            return;
        }
        cint mid=(l+r)>>1;
        Build(p<<1,l,mid);
        Build(p<<1|1,mid+1,r);
    }
    void build()
    {
        Build(1,1,m<<1);
    }
    void insert(int p,segl x)
    {
        q[p].insert(x);
        t[tid[p]].val=rmin(t[tid[p]].val,x);
        p=tid[p];
        while(p>>=1)push_up(p);
    }
    void erase(int p,segl x)
    {
        q[p].erase(x);
        t[tid[p]].val=q[p].empty()?(segl){0,m<<1|1}:q[p].top();
        p=tid[p];
        while(p>>=1)push_up(p);
    }
    segl Ask(cint p,cint l,cint r)
    {
        if(t[p].l>r||t[p].r<l)return (segl){0,m<<1|1};
        if(t[p].l>=l&&t[p].r<=r)return t[p].val;
        return rmin(Ask(p<<1,l,r),Ask(p<<1|1,l,r));
    }
    segl ask(cint l,cint r)
    {
        return Ask(1,l,r);
    }
}TMN;
int main()
{
    freopen("interval.in","r",stdin);
    freopen("interval.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)
    {
        op[i]=read();
        qx[i]=read();
        qy[i]=read();
        if(op[i]==1)
        {
            c[++m]=qx[i];
            c[++m]=qy[i];
        }
    }
    sort(c+1,c+m+1);
    for(int i=1;i<=m;++i)
    {
        mp[c[i]]=i;
    }
    for(int i=1;i<=n;++i)
    {
        if(op[i]==1)
        {
            qx[i]=mp[qx[i]];
            qy[i]=mp[qy[i]];
        }
    }
    m=0;
    for(int i=1;i<=n;++i)if(op[i]==1)c[++m]=i;
    sort(c+1,c+m+1,[&](cint p,cint q){return (qx[p]==qx[q]?qy[p]>qy[q]:qx[p]<qx[q]);});
    for(int i=1;i<=m;++i)
    {
        cl[i]=qx[c[i]];
        cr[i]=qy[c[i]];
        qx[c[i]]=i;
    }
    m=0;
    for(int i=1;i<=n;++i)if(op[i]==1)c[++m]=qx[i];
    for(int i=1;i<=n;++i)if(op[i]==2)qx[i]=c[qx[i]],qy[i]=c[qy[i]];
    for(int i=1;i<=m;++i)
    {
        f[i]=i;
    }
    TMN.build();
    TMX.build();
    for(int i=1;i<=n;++i)
    {
        if(op[i]==1)
        {
            int p=qx[i];
            fmx[p]=cr[p];
            fmn[p]=cl[p];
            while(1)
            {
                segr res=TMX.ask(1,cr[p]-1);
                if(res.val<=cr[p])break;
                TMX.erase(fmn[res.idx],res);
                TMN.erase(fmx[res.idx],(segl){res.idx,fmn[res.idx]});
                merge(p,res.idx);
            }
            while(1)
            {
                segl res=TMN.ask(cl[p]+1,m<<1);
                if(res.val>=cl[p])break;
                TMX.erase(fmn[res.idx],(segr){res.idx,fmx[res.idx]});
                TMN.erase(fmx[res.idx],res);
                merge(p,res.idx);
            }
            p=find(p);
            TMX.insert(fmn[p],(segr){p,fmx[p]});
            TMN.insert(fmx[p],(segl){p,fmn[p]});
        }
        else
        {
            cint x=find(qx[i]),y=find(qy[i]);
            if(x==y)
            {
                YES;
            }
            else
            {
                if(fmn[x]<fmn[y]||fmx[x]>fmx[y])
                {
                    NO;
                }
                else
                {
                    YES;
                }
            }
        }
    }
    return 0;
}