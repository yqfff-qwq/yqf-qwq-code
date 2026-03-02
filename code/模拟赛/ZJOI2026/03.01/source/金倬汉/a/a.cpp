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
cint N=3e5,M=3e5,LGM=19,Q=4e5;
cint inf=1e9+1;
int n,m,q;
struct info{
    int id,val;
}c[M+1];
int mxl[M+1],len[M+1];
int a[N+1];
struct Deletable_Heap{
    priority_queue<int,vector<int>,greater<int>>p,q;
    inline void insert(cint x)
    {
        q.push(x);
    }
    inline void erase(cint x)
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
    inline int top()
    {
        D();
        return q.top();
    }
    inline bool empty()
    {
        D();
        return q.empty();
    }
}H;
struct Spare_Table{
    int st[LGM+1][M+1];
    void init()
    {
        for(int i=1;i<=m;++i)st[0][i]=len[i];
        for(int k=1;k<=__lg(m);++k)
        {
            for(int i=1;i<=m-(1<<k)+1;++i)
            {
                st[k][i]=min(st[k-1][i],st[k-1][i+(1<<k-1)]);
            }
        }
    }
    inline int ask(cint l,cint r)
    {
        cint p=__lg(r-l+1);
        return min(st[p][l],st[p][r-(1<<p)+1]);
    }
}ST;
inline bool check(int L,int R,int lim)
{
    int l,r,pl,pr;
    if(c[1].val<=L)
    {
        l=1,r=m;
        while(l<r)
        {
            cint mid=l+r+1>>1;
            if(c[mid].val<=L)l=mid;
            else r=mid-1;
        }
        if(mxl[l]>=L-lim+1)return 1;
    }
    if(c[m].val<L||c[1].val>R)return 0;
    l=1,r=m;
    while(l<r)
    {
        cint mid=l+r>>1;
        if(c[mid].val<L)l=mid+1;
        else r=mid;
    }
    pl=l;
    l=1,r=m;
    while(l<r)
    {
        cint mid=l+r+1>>1;
        if(c[mid].val>R)r=mid-1;
        else l=mid;
    }
    pr=r;
    if(pl>pr)return 0;
    return (ST.ask(pl,pr)<=lim);
}
#define YES putchar('Y'),putchar('e'),putchar('s'),putchar('\n')
#define NO putchar('N'),putchar('o'),putchar('\n')
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    n=read();
    m=read();
    read();
    for(int i=1;i<=m;++i)
    {
        read();
        c[i].id=read();
        c[i].val=read();
    }
    sort(c+1,c+m+1,[&](info p,info q){return p.val<q.val;});
    c[0].val=-inf;
    for(int i=2;i<=n;++i)H.insert(-inf);
    for(int i=1;i<=m;++i)
    {
        H.erase(c[a[c[i].id]].val);
        H.insert(c[a[c[i].id]=i].val);
        mxl[i]=H.top();
        len[i]=c[i].val-mxl[i]+1;
    }
    ST.init();
    q=read();
    while(q--)
    {
        int l=read(),r=read(),lim=read();
        cint len=r-l+1;
        l=r;
        r+=lim;
        lim+=len;
        if(check(l,r,lim))YES;
        else NO;
    }
    return 0;
}