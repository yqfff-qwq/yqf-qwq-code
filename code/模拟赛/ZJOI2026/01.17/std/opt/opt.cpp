#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,fa[N];
vector<int>g[N];
#define pb push_back
char c1[N],c2[N];
const int mod=1e9+7;
int qpow(int a,int b){
    int c=1;
    for(;b;b>>=1){
        if(b&1)c=1ll*a*c%mod;
        a=1ll*a*a%mod;
    }
    return c;
}
int s[N][2][3],jc[N],ij[N],sz[N],son[N];
int C(int a,int b){if(a<0||b<0||a<b)return 0;return 1ll*jc[a]*ij[b]%mod*ij[a-b]%mod;}
void doi(){jc[0]=ij[0]=1;for(int i=1;i<=1000000;i++)jc[i]=1ll*i*jc[i-1]%mod,ij[i]=qpow(jc[i],mod-2);}
void dfs(int x,int d){
    sz[x]=1;int mm=-1;
    for(int v:g[x])if(v!=fa[x]){
        fa[v]=x,dfs(v,d^1),sz[x]+=sz[v];
        if(mm<sz[v])mm=sz[v],son[x]=v;
        for(int i=0;i<2;i++)for(int j=0;j<3;j++)s[x][i][j]+=s[v][i][j];
    }
    if(c1[x]!='?')s[x][0][(c1[x]-'0')^d]++;
    else s[x][0][2]++;
    if(c2[x]!='?')s[x][1][(c2[x]-'0')^d]++;
    else s[x][1][2]++;
}
int a_[N],b_[N],be[N],S;
void dfs2(int x){
    be[++S]=x;
    if(!son[x])return;dfs2(son[x]);
    for(int v:g[x])if(v!=fa[x]&&v!=son[x])dfs2(v);
}
struct qb{
    int f,X,Y;
    inline int bl(int a,int b){
        int s=0;
        for(int i=0;i<=a;i++)(s+=1ll*C(b,i)*C(Y-b,X-i)%mod)%=mod;
        return s;
    }
    int a,b;
    inline void ks(int x_,int y_){X=x_,Y=y_;a=b=0,f=C(Y,X);}
    inline int t1(){
        return 1ll*C(b,a+1)*C(Y-b,X-(a+1))%mod;
    }
    inline int t2(){
        if(a<0||Y<0||X<0||b>Y||b<-1||Y<X)return 0;
        if(b==-1)return C(Y,X);
        if(b==Y)return (X>a)?0:(mod-C(Y,X));
        return mod-1ll*C(b,a)*C(Y-1-b,X-1-a)%mod;
    }
    inline void doi(int a_,int b_){
        while(a<a_)(f+=t1())%=mod,a++;
        while(a>a_)a--,(f-=t1())%=mod;
        while(b<b_)(f+=t2())%=mod,b++;
        while(b>b_)b--,(f-=t2())%=mod;
    }
}q1,q2;
void sol(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        g[i].clear(),fa[i]=0,son[i]=0;
        for(int j=0;j<2;j++)for(int k=0;k<3;k++)s[i][j][k]=0;
    }
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),g[u].pb(v),g[v].pb(u);
    scanf("%s%s",c1+1,c2+1);dfs(1,0),S=0,dfs2(1);
    int ans=0,X=-(s[1][0][1]-s[1][1][2]-s[1][1][1]),Y=s[1][0][2]+s[1][1][2];
    if(X<0){puts("0");return;}
    for(int i=2;i<=n;i++)a_[i]=-(s[i][0][1]-s[i][1][2]-s[i][1][1]),b_[i]=s[i][0][2]+s[i][1][2];
    q1.ks(X,Y),q2.ks(X-1,Y-1);
    for(int i=2;i<=n;i++){
        int u=be[i],a=a_[u],b=b_[u];
        q1.doi(a,b),q2.doi(a-1,b-1);
        (ans-=1ll*q2.f*b%mod)%=mod;
        (ans+=1ll*q1.f*a%mod)%=mod;
    }
    ans=1ll*ans*2%mod;
    for(int i=2;i<=n;i++){
        (ans-=1ll*a_[i]*C(Y,X)%mod)%=mod;
        (ans+=1ll*b_[i]*C(Y-1,X-1)%mod)%=mod;
    }
    printf("%d\n",(ans+mod)%mod);
}
int main(){
    freopen("opt.in","r",stdin);
    freopen("opt.out","w",stdout);
    doi(),sol();
    return 0;
}