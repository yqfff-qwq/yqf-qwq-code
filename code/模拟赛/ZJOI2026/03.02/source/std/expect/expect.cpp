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
cint N=20,mod=998244353;
int n,e[1<<N],p[1<<N],sum;
int qpow(cint x,cint y)
{
    if(!y)return 1;
    cint t=qpow(x,y>>1);
    if(y&1)return 1ll*t*t%mod*x%mod;
    return 1ll*t*t%mod;
}
inline void XOR(int *a,cint x)
{
    for(int o=2,k=1;o<=(1<<n);o<<=1,k<<=1)
    {
        for(int i=0;i<(1<<n);i+=o)
        {
            for(int j=0;j<k;++j)
            {
                a[i+j]+=a[i+j+k];
                a[i+j+k]=(1ll*a[i+j]-(a[i+j+k]<<1)+(mod<<1))%mod;
                a[i+j]=1ll*x*a[i+j]%mod;
                a[i+j+k]=1ll*x*a[i+j+k]%mod;
            }
        }
    }
}
int main()
{
    freopen("expect.in","r",stdin);
    freopen("expect.out","w",stdout);
    n=read();
    for(int i=0;i<(1<<n);++i)(sum+=(p[i]=read()))>=mod?(sum-=mod):0;
    sum=qpow(sum,mod-2);
    for(int i=0;i<(1<<n);++i)p[i]=1ll*p[i]*sum%mod;
    XOR(p,1);
    for(int i=1;i<(1<<n);++i)e[i]=1ll*(1<<n)*qpow((p[i]?p[i]-1:mod-1),mod-2)%mod;
    sum=0;
    for(int i=1;i<(1<<n);++i)(sum+=e[i])>=mod?(sum-=mod):0;
    e[0]=(sum==0?0:mod-sum);
    XOR(e,mod+1>>1);
    for(int i=0;i<(1<<n);++i)princh(e[i],'\n');
    return 0;
}