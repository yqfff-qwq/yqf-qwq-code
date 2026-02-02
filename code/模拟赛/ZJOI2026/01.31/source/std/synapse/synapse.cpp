#include<bits/stdc++.h>
#define int unsigned
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
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
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
cint N=2e6+1;
int n,len;
int a[N+1];
int l[N+1],r[N+1];
signed p[N+1];
bool calc(cint L,cint R)
{
    for(int i=1;i<=n;++i)
    {
        l[i]=max(a[i],l[i-1]+L);
        r[i]=min(a[i+1],r[i-1]+R);
        if(r[i]<a[i]||l[i]>a[i+1])return 0;
    }
    return (r[n]==len?1:0);
}
signed al,ar;
void solve()
{
    len=read();
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    a[n+1]=len;
    int l=0,r=1e9,mid;
    while(l<r)
    {
        mid=l+r+1>>1;
        if(!calc(mid,1e9))r=mid-1;
        else l=mid;
    }
    al=l;
    l=0,r=1e9;
    while(l<r)
    {
        mid=l+r>>1;
        if(!calc(al,mid))l=mid+1;
        else r=mid;
    }
    ar=r;
    calc(al,ar);
    p[n]=len;
    for(int i=n-1;i>=1;--i)
    {
        p[i]=max((signed)::l[i],p[i+1]-ar);
    }
    for(int i=0;i<=n;++i)princh(p[i],' ');
    putchar('\n');
}
signed main()
{
    freopen("synapse.in","r",stdin);
    freopen("synapse.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}