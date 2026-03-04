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
cint N=1e5,M=1e5,Q=2e5;
int n,m,q;
int f[N+1];
ll sum;
set<int>S[N+1];
vector<int>ver[N+1];
struct info{
    int id,l;
};
vector<info>mdf[N+1];
int eu[M+1],ev[M+1],ew[M+1],lst[M+1];
vector<int>idx;
int ql[Q+1],qr[Q+1];
vector<int>qry[N+1];
ll ans[Q+1];
int find(cint u){return (f[u]==u?u:f[u]=find(f[u]));}
struct Binary_Index_Tree{
    ll a[N+1];
    inline void add(cint p,cint x)
    {
        if(!p)return;
        for(int i=p;i<=n;i+=(i&-i))a[i]+=x;
    }
    inline ll ask(cint p)
    {
        ll s=0;
        for(int i=p;i;i-=(i&-i))s+=a[i];
        return s;
    }
    inline ll ask(cint l,cint r)
    {
        return ask(r)-ask(l-1);
    }
}T;
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    n=read();
    m=read();
    q=read();
    for(int i=1;i<=m;++i)
    {
        eu[i]=read()+1;
        ev[i]=read()+1;
        ew[i]=read();
        idx.push_back(i);
    }
    for(int i=1;i<=n;++i)
    {
        f[i]=i;
        S[i].insert(i);
        ver[i].push_back(i);
    }
    sort(idx.begin(),idx.end(),[&](cint p,cint q){return ew[p]<ew[q];});
    for(int i=1;i<=q;++i)
    {
        ql[i]=read()+1;
        qr[i]=read()+1;
        qry[qr[i]].push_back(i);
    }
    for(int i:idx)
    {
        int u=find(eu[i]),v=find(ev[i]);
        if(u==v)continue;
        sum+=ew[i];
        if(ver[u].size()>ver[v].size())swap(u,v);
        for(int x:ver[u])
        {
            set<int>::iterator it=S[v].upper_bound(x);
            if(it!=S[v].end())
            {
                mdf[*it].push_back({i,x});
            }
            if(it!=S[v].begin())
            {
                --it;
                mdf[x].push_back({i,*it});
            }
        }
        for(int x:ver[u])
        {
            S[v].insert(x);
            ver[v].push_back(x);
        }
        f[u]=v;
        set<int>().swap(S[u]);
        vector<int>().swap(ver[u]);
    }
    for(int i=1;i<=n;++i)
    {
        for(info p:mdf[i])
        {
            if(lst[p.id]>=p.l)continue;
            T.add(lst[p.id],-ew[p.id]);
            lst[p.id]=p.l;
            T.add(lst[p.id],ew[p.id]);
        }
        for(int p:qry[i])
        {
            ans[p]=sum-T.ask(ql[p],qr[p]);
        }
    }
    for(int i=1;i<=q;++i)
    {
        princh(ans[i],'\n');
    }
    return 0;
}