#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
#define sh short
#define csh const short
#define ush unsigned short
#define cush const unsigned short
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
cint N=3e5;
struct info{
    ll key;
    int cnt;
};
bool operator<(info x,info y)
{
    return ((x.key==y.key)?x.cnt<y.cnt:x.key>y.key);
}
int n,k;
int a[N+1],b[N+1];
priority_queue<info>q;
ll res;
int cnt;
void calc(cll x)
{
    res=cnt=0;
    while(!q.empty())q.pop();
    for(int i=1;i<=n;++i)
    {
        q.push({a[i],1});
        if((b[i]+x)+q.top().key<=0)
        {
            res+=(b[i]+x)+q.top().key;
            cnt+=q.top().cnt;
            q.pop();
            q.push({-(b[i]+x),0});
        }
    }
}
void solve()
{
    n=read();
    read();
    k=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)b[i]=read();
    ll l=-4e9,r=0;
    while(l<r)
    {
        cll mid=l+r+1>>1;
        calc(mid);
        if(cnt>=k)l=mid;
        else r=mid-1;
    }
    calc(l);
    princh(res-l*k,'\n');
}
int main()
{
    freopen("summit.in","r",stdin);
    freopen("summit.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}