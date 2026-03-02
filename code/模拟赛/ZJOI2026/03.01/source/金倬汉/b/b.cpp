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
cint N=161,M=10000;
int n,m,d;
int sc[N+1],dc[N+1];
int fa[N+1][M+1],fb[N+1][M+1],fc[N+1][M+1],fd[N+1][M+1];
int type[N+1];
int ax[N+1],ay[N+1];
bool solve()
{
    for(int i=0;i<=m;++i)fa[0][i]=fb[0][i]=fc[n+1][i]=fd[n+1][i]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            fa[i][j]=fa[i-1][j];
            fb[i][j]=fb[i-1][j];
        }
        int *dp,vx,vy;
        cint x=ax[dc[i]],y=ay[dc[i]];
        switch(type[dc[i]])
        {
            case 0:dp=fa[i],vx=x+y-2,vy=x-1+d-y;break;
            case 1:dp=fb[i],vx=x-1+d-y,vy=(d<<1)-x-y;break;
        }
        for(int j=m;j>=0;--j)
        {
            if(j>=vx)dp[j]=min(dp[j]+vy,dp[j-vx]);
            else dp[j]+=vy;
        }
    }
    for(int i=n;i>=1;--i)
    {
        for(int j=0;j<=m;++j)
        {
            fc[i][j]=fc[i+1][j];
            fd[i][j]=fd[i+1][j];
        }
        int *dp,vx,vy;
        cint x=ax[dc[i]],y=ay[dc[i]];
        switch(type[dc[i]])
        {
            case 1:dp=fc[i],vx=(d<<1)-x-y,vy=d-x+y-1;break;
            case 0:dp=fd[i],vx=d-x+y-1,vy=x+y-2;break;
        }
        for(int j=m;j>=0;--j)
        {
            if(j>=vx)dp[j]=min(dp[j]+vy,dp[j-vx]);
            else dp[j]+=vy;
        }
    }
    for(int p=0;p<=n;++p)
    {
        for(int i=0;i<=m;++i)
        {
            int now=i;
            now=m-fa[p][now];if(now<0)continue;
            now=m-fb[p][now];if(now<0)continue;
            now=m-fc[p+1][now];if(now<0)continue;
            now=m-fd[p+1][now];
            if(now>=i)return 1;
        }
    }
    return 0;
}
#define YES putchar('Y'),putchar('e'),putchar('s'),putchar('\n')
#define NO putchar('N'),putchar('o'),putchar('\n')
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    d=read();
    n=read();
    m=read()>>1;
    for(int i=1;i<=n;++i)
    {
        ax[i]=read();
        ay[i]=read();
        sc[i]=dc[i]=i;
    }
    sort(sc+1,sc+n+1,[&](cint p,cint q){return ax[p]+ay[p]<ax[q]+ay[q];});
    sort(dc+1,dc+n+1,[&](cint p,cint q){return ax[p]-ay[p]<ax[q]-ay[q];});
    for(int i=0;i<=n;++i)
    {
        for(int p=1;p<=n;++p)type[p]=0;
        for(int p=i+1;p<=n;++p)type[sc[p]]|=1;
        if(solve())
        {
            YES;
            return 0;
        }
    }
    NO;
    return 0;
}