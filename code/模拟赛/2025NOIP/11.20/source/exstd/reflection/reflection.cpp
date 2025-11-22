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
cint N=2e5,Q=2e5,V=2e5,B=500,M=(N+B-1)/B;
int mask;
int n,m,q;
int a[N+1],L[M+1],R[M+1],block[N+1];
int to[M+1][V+1];
int f[V+1];
int find(cint u)
{
    return (f[u]==u?u:(f[u]=find(f[u])));
}
int k,vl,vr;
void init(cint b)
{
    for(int i=0;i<=V;++i)f[i]=i;
    k=0,vl=0,vr=V;
    for(int i=L[b];i<=R[b];++i)
    {
        if(k<=vl)k+=a[i];
        else k-=a[i];
        if(vl<k&&vr>k)
        {
            if(k-vl<vr-k)
            {
                for(int p=vl;p<k;++p)f[p]=(k<<1)-p;
                vl=k;
            }
            else
            {
                for(int p=vr;p>k;--p)f[p]=(k<<1)-p;
                vr=k;
            }
        }
    }
    for(int i=0;i<=V;++i)
    {
        to[b][i]=abs(k-find(i));
    }
}
int ans;
int main()
{
    freopen("reflection.in","r",stdin);
    freopen("reflection.out","w",stdout);
    n=read();
    m=(n+B-1)/B;
    q=read();
    mask=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)
    {
        L[i]=R[i-1]+1;
        R[i]=min(n,R[i-1]+B);
        for(int p=L[i];p<=R[i];++p)block[p]=i;
    }
    for(int i=1;i<=m;++i)init(i);
    while(q--)
    {
        int l=read()^ans,r=read()^ans,v=read()^ans;
        if(block[l]==block[r])
        {
            for(int i=l;i<=r;++i)v=abs(v-a[i]);
        }
        else
        {
            for(int i=l;i<=R[block[l]];++i)v=abs(v-a[i]);
            for(int i=block[l]+1;i<block[r];++i)v=to[i][v];
            for(int i=L[block[r]];i<=r;++i)v=abs(v-a[i]);
        }
        princh(ans=v,'\n');
        ans*=mask;
    }
    return 0;
}