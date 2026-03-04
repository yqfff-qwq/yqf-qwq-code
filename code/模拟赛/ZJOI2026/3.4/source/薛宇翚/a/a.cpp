#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=7e5+100;
int n,m,q;
struct eg
{
  int v;
  ll w;
  eg(int vv=0,ll ww=0):v(vv),w(ww){}
};
vector<eg>g[N];
namespace Sub1Solve
{
  ll a[N];
  void main()
  {
    for(int i=1;i<=m;i++)
    {
      a[i]+=a[i-1];
    }
    while(q--)
    {
      int l,r;
      scanf("%d%d",&l,&r);
      ll as=a[l]+(a[m]-a[r]);
      printf("%lld\n",as);
    }
  }
}
namespace Sub4Solve
{
  int au[N],ag[N],f[N],bel[N],le[N],ri[N],p[N],cu[N],ct,as[N];
  int F(int x)
  {
    return x==f[x]?x:f[x]=F(f[x]);
  }
  bool cmp(int x,int y)
  {
    if(bel[le[x]]!=bel[le[y]])
    {
      return bel[le[x]]<bel[le[y]];
    }
    return ri[x]<ri[y];
  }
  void main()
  {
    for(int i=0;i<n;i++)
    {
      f[i]=i;
    }
    int toteg=n-1;
    for(int i=1;i<=m;i++)
    {
      if(Sub1Solve::a[i]==1)
      {
        if(F(au[i])==F(ag[i]))
        {
          continue;
        }
        f[F(au[i])]=F(ag[i]);
        toteg--;
      }
    }
    for(int i=0;i<n;i++)
    {
      f[i]=F(i);
    }
    int bsz=sqrt(n)+1;
    for(int i=0;i<n;i++)
    {
      bel[i]=i/bsz;
    }
    for(int i=1;i<=q;i++)
    {
      scanf("%d%d",&le[i],&ri[i]);
      p[i]=i;
    }
    sort(p+1,p+q+1,cmp);
    int l=0,r=-1;
    for(int I=1;I<=q;I++)
    {
      int i=p[I];
      while(l>le[i])
      {
        l--;
        cu[f[l]]++;
        if(cu[f[l]]==1)
        {
          ct++;
        }
      }
      while(r<ri[i])
      {
        r++;
        cu[f[r]]++;
        if(cu[f[r]]==1)
        {
          ct++;
        }
      }
      while(l<le[i])
      {
        cu[f[l]]--;
        if(!cu[f[l]])
        {
          ct--;
        }
        l++;
      }
      while(r>ri[i])
      {
        cu[f[r]]--;
        if(!cu[f[r]])
        {
          ct--;
        }
        r--;
      }
      as[i]=ct;
    }
    for(int i=1;i<=q;i++)
    {
      ll mreg=as[i]-1;
      ll toweg=toteg-mreg;
      ll oneg=(n-1)-(ri[i]-le[i]);
      ll tras=oneg+toweg;
      printf("%lld\n",tras);
    }
  }
}
namespace Sub3Solve
{
  struct fulleg
  {
    int u,v;
    ll w;
    fulleg(int uu=0,int vv=0,ll ww=0):u(uu),v(vv),w(ww){}
  }b[N];
  bool cmp(fulleg x,fulleg y)
  {
    return x.w<y.w;
  }
  vector<eg>h[N];
  const int B=25;
  int fa[N][B],dep[N];
  ll mxw[N][B];
  void dfs(int x,int y)
  {
    for(int i=0;i<h[x].size();i++)
    {
      int v=h[x][i].v;
      ll w=h[x][i].w;
      if(v!=y)
      {
        fa[v][0]=x;
        mxw[v][0]=w;
        dep[v]=dep[x]+1;
        dfs(v,x);
      }
    }
  }
  pair<int,ll>lca(int x,int y)
  {
    if(dep[x]>dep[y])
    {
      swap(x,y);
    }
    ll as=0;
    for(int i=B-1;i>=0;i--)
    {
      if(dep[fa[y][i]]>=dep[x])
      {
        as=max(as,mxw[y][i]);
        y=fa[y][i];
      }
    }
    if(x==y)
    {
      return make_pair(x,as);
    }
    for(int i=B-1;i>=0;i--)
    {
      if(fa[x][i]!=fa[y][i])
      {
        as=max(as,max(mxw[x][i],mxw[y][i]));
        x=fa[x][i];
        y=fa[y][i];
      }
    }
    return make_pair(fa[x][0],max(as,max(mxw[x][0],mxw[y][0])));
  }
  void main()
  {
    for(int i=0;i<n;i++)
    {
      Sub4Solve::f[i]=i;
    }
    sort(b+1,b+m+1,cmp);
    int ct=0;
    ll as=0;
    for(int i=1;i<=m;i++)
    {
      int uu=Sub4Solve::F(b[i].u),vv=Sub4Solve::F(b[i].v);
      if(uu==vv)
      {
        continue;
      }
      Sub4Solve::f[Sub4Solve::F(uu)]=Sub4Solve::F(vv);
      as+=b[i].w;
      h[b[i].u].push_back(eg(b[i].v,b[i].w));
      h[b[i].v].push_back(eg(b[i].u,b[i].w));
      ct++;
      if(ct==n-1)
      {
        break;
      }
    }
    for(int j=0;j<B;j++)
    {
      fa[n+1][j]=n+1;
    }
    fa[0][0]=n+1;
    dep[0]=1;
    dfs(0,n+1);
    for(int j=1;j<B;j++)
    {
      for(int i=0;i<n;i++)
      {
        fa[i][j]=fa[fa[i][j-1]][j-1];
        mxw[i][j]=max(mxw[i][j-1],mxw[fa[i][j-1]][j-1]);
      }
    }
    for(int i=1;i<=q;i++)
    {
      ll tras=as-max(lca(Sub4Solve::le[i],Sub4Solve::ri[i]).second,0ll);
      printf("%lld\n",tras);
    }
  }
}
int main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  scanf("%d%d%d",&n,&m,&q);
  bool issuba=(m==n-1),issubd=1;
  for(int i=1;i<=m;i++)
  {
    int u,v;
    ll w;
    scanf("%d%d%lld",&u,&v,&w);
    g[u].push_back(eg(v,w));
    g[v].push_back(eg(u,w));
    issuba&=(u==i-1&&v==i);
    Sub1Solve::a[i]=w;
    issubd&=(w>=1&&w<=2);
    Sub4Solve::au[i]=u;
    Sub4Solve::ag[i]=v;
    Sub3Solve::b[i]=Sub3Solve::fulleg(u,v,w);
  }
  if(issuba)
  {
    Sub1Solve::main();
    return 0;
  }
  if(issubd)
  {
    Sub4Solve::main();
    return 0;
  }
  bool issubc=1;
  for(int i=1;i<=q;i++)
  {
    scanf("%d%d",&Sub4Solve::le[i],&Sub4Solve::ri[i]);
    issubc&=(Sub4Solve::ri[i]==Sub4Solve::le[i]+1);
  }
  if(issubc)
  {
    Sub3Solve::main();
    return 0;
  }
  for(int i=1;i<=q;i++)
  {
    //cerr<<"Ans "<<i<<" "<<Sub4Solve::le[i]<<" "<<Sub4Solve::ri[i]<<"\n";
    int mct=m;
    for(int j=1;j<=m;j++)
    {
      Sub3Solve::b[j]=Sub3Solve::fulleg(Sub4Solve::au[j],Sub4Solve::ag[j],Sub1Solve::a[j]);
    }
    for(int j=Sub4Solve::le[i];j<=Sub4Solve::ri[i];j++)
    {
      mct++;
      Sub3Solve::b[mct]=Sub3Solve::fulleg(j,n,0);
    }
    for(int j=0;j<=n;j++)
    {
      Sub4Solve::f[j]=j;
    }
    for(int j=1;j<=mct;j++)
    {
      //cerr<<"OldEg "<<j<<" "<<Sub3Solve::b[j].u<<" "<<Sub3Solve::b[j].v<<" "<<Sub3Solve::b[j].w<<"\n";
    }
    sort(Sub3Solve::b+1,Sub3Solve::b+mct+1,Sub3Solve::cmp);
    int ct=0;
    ll as=0;
    for(int i=1;i<=mct;i++)
    {
      int uu=Sub4Solve::F(Sub3Solve::b[i].u),vv=Sub4Solve::F(Sub3Solve::b[i].v);
      if(uu==vv)
      {
        continue;
      }
      Sub4Solve::f[Sub4Solve::F(uu)]=Sub4Solve::F(vv);
      as+=Sub3Solve::b[i].w;
      ct++;
      if(ct==n)
      {
        break;
      }
    }
    printf("%lld\n",as);
  }
  return 0;
}
