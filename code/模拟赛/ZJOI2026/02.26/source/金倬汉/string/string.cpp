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
cint N=3e5;
int n;
string s,t;
int a[N+1],b[N+1];
int na,nb;
vector<int>S,T;
int ans;
bool check()
{
    S.clear();
    T.clear();
    for(char ch:s)
    {
        if(ch=='A')
        {
            for(int i=1;i<=na;++i)S.push_back(a[i]);
        }
        if(ch=='B')
        {
            for(int i=1;i<=nb;++i)S.push_back(b[i]);
        }
    }
    for(char ch:t)
    {
        if(ch=='A')
        {
            for(int i=1;i<=na;++i)T.push_back(a[i]);
        }
        if(ch=='B')
        {
            for(int i=1;i<=nb;++i)T.push_back(b[i]);
        }
    }
    return (S==T);
}
void dfsb(cint p)
{
    if(p>1)ans+=check();
    if(p>n)return;
    b[++nb]=0;
    dfsb(p+1);
    b[nb]=1;
    dfsb(p+1);
    --nb;
}
void dfsa(cint p)
{
    if(p>1)dfsb(1);
    if(p>n)return;
    a[++na]=0;
    dfsa(p+1);
    a[na]=1;
    dfsa(p+1);
    --na;
}
void dfst(cint p)
{
    if(p==t.size())
    {
        dfsa(1);
        return;
    }
    if(t[p]=='?')
    {
        t[p]='A';
        dfst(p+1);
        t[p]='B';
        dfst(p+1);
        t[p]='?';
    }
    else dfst(p+1);
}
void dfss(cint p)
{
    if(p==s.size())
    {
        dfst(0);
        return;
    }
    if(s[p]=='?')
    {
        s[p]='A';
        dfss(p+1);
        s[p]='B';
        dfss(p+1);
        s[p]='?';
    }
    else dfss(p+1);
}
void input()
{
    char ch=getchar();
    while(ch!='A'&&ch!='B'&&ch!='?')ch=getchar();
    while(ch=='A'||ch=='B'||ch=='?')s+=ch,ch=getchar();
    while(ch!='A'&&ch!='B'&&ch!='?')ch=getchar();
    while(ch=='A'||ch=='B'||ch=='?')t+=ch,ch=getchar();
    n=read();
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    input();
    dfss(0);
    print(ans);
    return 0;
}