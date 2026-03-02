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
cint N=2e5,M=1e5;
int n,m;
int ans;
int al[M+1],ar[M+1];
bool flag[M+1];
int calc()
{
    int mx=0,cnt;
    for(int i=1;i<=n;++i)
    {
        cnt=0;
        for(int j=1;j<=m;++j)
        {
            cnt+=((al[j]<=i&&i<ar[j])^flag[j]);
        }
        mx=max(mx,cnt);
    }
    return mx;
}
void dfs(cint x)
{
    if(x>n)
    {
        ans=min(ans,calc());
        return;
    }
    flag[x]=0;
    dfs(x+1);
    flag[x]=1;
    dfs(x+1);
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    n=read();
    ans=m=read();
    for(int i=1;i<=m;++i)
    {
        al[i]=read();
        ar[i]=read();
        if(al[i]>ar[i])swap(al[i],ar[i]);
        read();
    }
    dfs(1);
    print(ans);
    return 0;
}