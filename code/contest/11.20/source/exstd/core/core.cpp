#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
using namespace std;
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
mt19937 mt(chrono::system_clock().now().time_since_epoch().count());
inline int ran(cint l,cint r)
{
    return l+mt()%(r-l+1);
}
bool check_prime(cint x)
{
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)return 0;
    }
    return 1;
}
int rand_prime(cint l,cint r)
{
    int x=ran(l,r);
    while(!check_prime(x))
    {
        x=ran(l,r);
    }
    return x;
}
cint N=1e6,L=1e7;
cint MOD=1e9+7;
cint B=3500;
int n,m,k;
string s[N+1],t[N+1];
cuint mod[2]={911128217,978490013};
uint base[2],num[2][2],pw[2][L+1];
int cts[2][N+1],ctt[2][N+1];
struct info{
    uint len,s,x1,x2;
};
struct Mod
{
    ull m, p;
    void init(int pp) { m = ((__int128)1 << 64) / pp; p = pp; }
    ull operator ()(ull x)
    {
        return x - ((__uint128_t(x) * m) >> 64) * p;
    }
}M[2],MM;
bool operator==(info p,info q)
{
    return (p.len==q.len&&p.s==q.s&&p.x1==q.x1&&p.x2==q.x2);
}
struct Hash_Table{
    uint mod=29947769;
    ull base;
    Mod M;
    static cuint LIM=3e7;
    void init()
    {
        M.init(mod);
        base=rand_prime(2,mod-1);
    }
    struct Linked_List{
        info x;
        uint val,nxt;
    }L[::L+1];
    uint tot;
    uint head[LIM];
    void add(const info x,cuint y)
    {
        cuint v=M(x.s*base+x.x1+x.x2+x.len);
        for(int i=head[v];i;i=L[i].nxt)
        {
            if(L[i].x==x)
            {
                L[i].val+=y;
                return;
            }
        }
        L[++tot]={x,y,head[v]};
        head[v]=tot;
    }
    int ask(info x)
    {
        cuint v=M(x.s*base+x.x1+x.x2+x.len);
        for(int i=head[v];i;i=L[i].nxt)
        {
            if(L[i].x==x)return L[i].val;
        }
        return 0;
    }
}HT;
int inv[L+1],fac[L+1],ifac[L+1];
void init()
{
    MM.init(MOD);
    inv[1]=fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    for(int i=2;i<=L;++i)
    {
        inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
        fac[i]=1ll*i*fac[i-1]%MOD;
        ifac[i]=1ll*inv[i]*ifac[i-1]%MOD;
    }
    for(int c=0;c<=1;++c)
    {
        M[c].init(mod[c]);
        base[c]=rand_prime(2,mod[c]-1);
        num[c][0]=ran(1,mod[c]-1);
        num[c][1]=ran(1,mod[c]-1);
        pw[c][0]=1;
        for(int i=1;i<=L;++i)
        {
            pw[c][i]=M[c](1ull*pw[c][i-1]*base[c]);
        }
    }
}
int ans;
bool insert(cint p)
{
    uint suf[2]={0,0};
    int sum=0;
    cts[0][p]=cts[1][p]=0;
    for(char ch:s[p])
    {
        sum+=(ch=='('?1:-1);
        ++cts[(ch=='(')][p];
        if(sum<0)return 0;
    }
    if(cts[0][p]>(k>>1)||cts[1][p]>(k>>1))return 0;
    // cout<<s[p]<<":\n";
    for(int i=(int)s[p].size()-1;i>=0;--i)
    {
        for(int c=0;c<=1;++c)
        {
            suf[c]=(suf[c]+1ull*num[c][s[p][i]-'(']*pw[c][(int)s[p].size()-i-1])%mod[c];
        }
        sum-=(s[p][i]=='('?1:-1);
        // printf("add(%d,%d,%d,%d)\n",s[p].size(),sum,suf[0],suf[1]);
        HT.add({(uint)s[p].size(),(uint)sum,suf[0],suf[1]},1);
    }
    return 1;
}
bool query(cint p)
{
    uint pre[2]={0,0};
    int sum=0;
    ctt[0][p]=ctt[1][p]=0;
    for(int i=t[p].size()-1;i>=0;--i)
    {
        sum+=(t[p][i]==')'?1:-1);
        ++ctt[(t[p][i]=='(')][p];
        if(sum<0)return 0;
    }
    if(ctt[0][p]>(k>>1)||ctt[1][p]>(k>>1))return 0;
    // cout<<t[p]<<":\n";
    for(int i=0;i<t[p].size();++i)
    {
        for(int c=0;c<=1;++c)
        {
            pre[c]=(num[c][t[p][i]-'(']+1ull*pre[c]*base[c])%mod[c];
        }
        // printf("ask(%d,%d,%d,%d)\n",k-(int)t[p].size()+i+1,sum,pre[0],pre[1]);
        (ans+=HT.ask({k-(uint)t[p].size()+i+1,(uint)sum,pre[0],pre[1]}))>=MOD?(ans-=MOD):0;
    }
    return 1;
}
inline int C(cint n,cint m)
{
    return ((n<m||m<0)?0:1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD);
}
inline int calc(cint x1,cint y1,cint x2,cint y2)
{
    return C(x2-x1+y2-y1,x2-x1);
}
int dp[B+1][B+1],dpk[B+1][B+1];
struct point{
    int x,y,v;
}ps[N+1],pt[N<<1|1];
vector<int>bs,bt;
int main()
{
    freopen("core.in","r",stdin);
    freopen("core.out","w",stdout);
    read();
    n=read();
    m=read();
    k=read();
    init();
    HT.init();
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        if(!insert(i))
        {
            --i;
            --n;
        }
    }
    for(int i=1;i<=m;++i)
    {
        cin>>t[i];
        if(!query(i))
        {
            --i;
            --m;
        }
    }
    for(int i=1;i<=n;++i)
    {
        ps[i]={cts[1][i]+1,cts[0][i],1};
    }
    for(int i=1;i<=m;++i)
    {
        cint x=(k>>1)-ctt[1][i],y=(k>>1)-ctt[0][i];
        pt[i]={x+1,y,1};
        pt[i+m]={y,x+1,MOD-1};
    }
    m<<=1;
    cint hk=(k>>1)+1;
    cint lim=min(B,k>>1);
    for(int i=1;i<=n;++i)
    {
        if(ps[i].x+ps[i].y<=lim)++dp[ps[i].x][ps[i].y];
    }
    for(int i=1;i<=m;++i)
    {
        if(pt[i].x+pt[i].y>=k+2-lim)
        {
            (dpk[hk-pt[i].x][hk-pt[i].y]+=pt[i].v)>=MOD?(dpk[hk-pt[i].x][hk-pt[i].y]-=MOD):0;
        }
    }
    for(int i=0;i<=lim;++i)
    {
        for(int j=0;j<=lim;++j)
        {
            if(i)
            {
                (dp[i][j]+=dp[i-1][j])>=MOD?(dp[i][j]-=MOD):0;
                (dpk[i][j]+=dpk[i-1][j])>=MOD?(dpk[i][j]-=MOD):0;
            }
            if(j)
            {
                (dp[i][j]+=dp[i][j-1])>=MOD?(dp[i][j]-=MOD):0;
                (dpk[i][j]+=dpk[i][j-1])>=MOD?(dpk[i][j]-=MOD):0;
            }
        }
    }
    for(int i=0;i<=lim;++i)
    {
        for(int j=0;j<=lim;++j)
        {
            ans=(ans+1ll*dp[i][lim-i]*dpk[j][lim-j]%MOD*calc(i,lim-i,hk-j,hk-lim+j))%MOD;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(ps[i].x+ps[i].y>lim)
        {
            bs.push_back(i);
            if(ps[i].x+ps[i].y>=k+2-lim)
            {
                (ans+=dpk[hk-ps[i].x][hk-ps[i].y])>=MOD?(ans-=MOD):0;
            }
            else
            {
                for(int j=0;j<=lim;++j)
                {
                    ans=(ans+1ll*dpk[j][lim-j]*calc(ps[i].x,ps[i].y,hk-j,hk-lim+j))%MOD;
                }
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        if(pt[i].x+pt[i].y<k+2-lim)
        {
            bt.push_back(i);
            if(pt[i].x+pt[i].y<=lim)
            {
                ans=(ans+1ll*dp[pt[i].x][pt[i].y]*pt[i].v)%MOD;
            }
            else
            {
                for(int j=0;j<=lim;++j)
                {
                    ans=(ans+1ll*dp[j][lim-j]*calc(j,lim-j,pt[i].x,pt[i].y)%MOD*pt[i].v)%MOD;
                }
            }
        }
    }
    for(int i:bs)
    {
        for(int j:bt)
        {
            ans=(ans+1ll*calc(ps[i].x,ps[i].y,pt[j].x,pt[j].y)*pt[j].v)%MOD;
        }
    }
    print(ans);
    return 0;
}