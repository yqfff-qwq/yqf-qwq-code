#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+100;
int n,p[N],w[N],d[N];
vector<int>g[N];
void dfs(int x)
{
  d[x]=w[x];
  for(int i=0;i<g[x].size();i++)
  {
    int v=g[x][i];
    dfs(v);
    d[x]+=d[v];
  }
}
namespace BaoLi
{
  void solve()
  {
    for(int i=1;i<=n;i++)
    {
      int as=d[i],ps=p[i],las=i;
      while(ps>=0)
      {
        int xx=as;
        for(int j=0;j<g[ps].size();j++)
        {
          int v=g[ps][j];
          if(v==las)
          {
            continue;
          }
          as+=min(xx,d[v]);
        }
        las=ps;
        ps=p[ps];
      }
      printf("%lld\n",as);
    }
  }
}
namespace Lian
{
  void solve()
  {
    for(int i=1;i<=n;i++)
    {
      printf("%lld\n",d[i]);
    }
  }
}
namespace JuHua
{
  int pos[N],as[N],pre[N];
  bool cmp(int x,int y)
  {
    return w[x]<w[y];
  }
  void solve()
  {
    for(int i=1;i<=n;i++)
    {
      pos[i]=i;
    }
    sort(pos+1,pos+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
      pre[i]=pre[i-1]+w[pos[i]];
      as[pos[i]]=pre[i]+1ll*(n-i)*w[pos[i]];
    }
    for(int i=1;i<=n;i++)
    {
      printf("%lld\n",as[i]);
    }
  }
}
signed main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  scanf("%lld",&n);
  for(int i=1;i<=n;i++)
  {
    scanf("%lld%lld",&p[i],&w[i]);
    g[p[i]].push_back(i);
  }
  p[0]=-1;
  dfs(0);
  if(n<=5000)
  {
    BaoLi::solve();
    return 0;
  }
  bool isl=1;
  for(int i=1;i<=n;i++)
  {
    if(p[i]!=i-1)
    {
      isl=0;
      break;
    }
  }
  if(isl)
  {
    Lian::solve();
    return 0;
  }
  bool isj=1;
  for(int i=1;i<=n;i++)
  {
    if(p[i])
    {
      isj=0;
      break;
    }
  }
  if(isj)
  {
    JuHua::solve();
    return 0;
  }
  BaoLi::solve();
  return 0;
}
