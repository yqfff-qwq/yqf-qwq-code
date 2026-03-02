#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+100;
int n,m,a[N],b[N],c[N],as,d[N];
vector<pair<int,int> >g;
void dfs(int x)
{
  if(x==g.size())
  {
    int mx=0;
    for(int i=1;i<=n;i++)
    {
      mx=max(mx,d[i]);
    }
    as=min(as,mx);
    return;
  }
  for(int i=g[x].first;i<g[x].second;i++)
  {
    d[i]++;
  }
  dfs(x+1);
  for(int i=g[x].first;i<g[x].second;i++)
  {
    d[i]--;
  }
  for(int i=1;i<g[x].first;i++)
  {
    d[i]++;
  }
  for(int i=g[x].second;i<=n;i++)
  {
    d[i]++;
  }
  dfs(x+1);
  for(int i=1;i<g[x].first;i++)
  {
    d[i]--;
  }
  for(int i=g[x].second;i<=n;i++)
  {
    d[i]--;
  }
}
signed main()
{
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  scanf("%lld%lld",&n,&m);
  as=0x3f3f3f3f3f3f3f3fll;
  for(int i=1;i<=m;i++)
  {
    scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    while(c[i]--)
    {
      g.push_back(make_pair(min(a[i],b[i]),max(a[i],b[i])));
    }
  }
  dfs(0);
  printf("%lld\n",as);
  return 0;
}
