#include <bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,m,p,q,le[N],ri[N],mny[N],d[N];
vector<pair<int,int> >g[N],h;
bool check(int x,int y)
{
  d[1]=1;
  for(int i=2;i<=n;i++)
  {
    d[i]=0;
    for(int j=0;j<g[i].size();j++)
    {
      int v=g[i][j].first,w=g[i][j].second;
      if(w<x||w>y)
      {
        continue;
      }
      d[i]|=d[v];
    }
    if(!d[i])
    {
      return 0;
    }
  }
  return 1;
}
namespace sub1
{
  void main()
  {
    for(int i=1;i<=q;i++)
    {
      if(check(le[i],ri[i]))
      {
        printf("Yes\n");
      }
      else
      {
        printf("No\n");
      }
    }
  }
}
namespace sub4
{
  int pre[N],as[N],tr[N];
  vector<pair<int,int> >qlis[N];
  void update(int x,int y)
  {
    x++;
    while(x<N)
    {
      tr[x]+=y;
      x+=(x&-x);
    }
  }
  int query(int x)
  {
    x++;
    int s=0;
    while(x)
    {
      s+=tr[x];
      x-=(x&-x);
    }
    return s;
  }
  void main()
  {
    map<int,int>las;
    for(int i=1;i<h.size();i++)
    {
      int v=h[i].second;
      pre[i]=las[v];
      las[v]=i;
    }
    for(int i=1;i<=q;i++)
    {
      int R=lower_bound(h.begin(),h.end(),make_pair(ri[i]+1,-0x3f3f3f3f))-h.begin()-1,L=lower_bound(h.begin(),h.end(),make_pair(le[i],-0x3f3f3f3f))-h.begin();
      qlis[R].push_back(make_pair(L,i));
    }
    for(int i=1;i<h.size();i++)
    {
      update(pre[i],1);
      for(int j=0;j<qlis[i].size();j++)
      {
        int L=qlis[i][j].first,ix=qlis[i][j].second;
        int diff=query(L-1)-(L-1);
        if(diff>=n-1)
        {
          as[ix]=1;
        }
      }
    }
    for(int i=1;i<=q;i++)
    {
      if(as[i])
      {
        printf("Yes\n");
      }
      else
      {
        printf("No\n");
      }
    }
  }
}
namespace sub2
{
  int rt[N],ct,tg[N];
  void main()
  {
    int j=0;
    for(int i=1;i<h.size();i++)
    {
      rt[i]=0x3f3f3f3f;
    }
    for(int i=1;i<h.size();i++)
    {
      if(j<i)
      {
        j=i;
      }
      while(j<h.size()&&ct<n-1)
      {
        tg[h[j].second]++;
        if(tg[h[j].second]==1)
        {
          ct++;
        }
        j++;
      }
      if(ct==n-1)
      {
        rt[i]=j-1;
      }
      else
      {
        break;
      }
      tg[h[i].second]--;
      if(!tg[h[i].second])
      {
        ct--;
      }
    }
    //cerr<<"A success\n";
    vector<int>usf;
    for(int i=1;i<h.size();i++)
    {
      if(rt[i]>=0x3f3f3f3f)
      {
        break;
      }
      if(h[i].first!=h[i-1].first)
      {
        usf.push_back(i);
      }
    }
    //cerr<<"Q "<<usf.size()<<"\n";
    //while(q--)
    for(int I=1;I<=q;I++)
    {
      int as=0x3f3f3f3f;
      for(int ppi=1;ppi<usf.size();ppi++)
      {
        int i=usf[ppi];
        int cs=(le[I]<=h[i].first?0:le[I]-h[i].first)+(h[rt[i]].first<=ri[I]?0:h[rt[i]].first-ri[I]);
        as=min(as,cs);
      }
      if(as>mny[I])
      {
        printf("No\n");
      }
      else
      {
        printf("Yes\n");
      }
    }
  }
}
int main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  scanf("%d%d%d",&n,&m,&p);
  bool suba=(n<=50&&m<=50);
  h.push_back(make_pair(-0x3f3f3f3f,-0x3f3f3f3f));
  for(int i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    g[v].push_back(make_pair(u,w));
    h.push_back(make_pair(w,v));
  }
  sort(h.begin(),h.end());
  scanf("%d",&q);
  suba&=(q<=50);
  for(int i=1;i<=q;i++)
  {
    scanf("%d%d%d",&le[i],&ri[i],&mny[i]);
    suba&=(mny[i]==0);
  }
  if(suba)
  {
    sub1::main();
    return 0;
  }
  bool subb=1;
  for(int i=1;i<=q;i++)
  {
    subb&=(mny[i]==0);
  }
  if(subb)
  {
    sub4::main();
    return 0;
  }
  sub2::main();
  return 0;
}
