#include <bits/stdc++.h>
using namespace std;
#define int long long
void read(int &x)
{
  x=0;
  bool f=0;
  char c=getchar();
  while(c<'0'||c>'9')
  {
    if(c=='-')
    {
      f^=1;
    }
    c=getchar();
  }
  while(c>='0'&&c<='9')
  {
    x=(x<<3)+(x<<1)+(c^'0');
    c=getchar();
  }
  if(f)
  {
    x=-x;
  }
}
const int N=1e6+100;
int a[N],p[63],n,m,s,t,gu[N],gv[N],gw[N];//fin[N];
bool vis[N];
void solve()
{
  read(n);
  read(m);
  read(s);
  read(t);
  for(int i=1;i<=n;i++)
  {
    a[i]=0;
  }
  int b=sqrt(n)+1;
  int nu=m/b+bool(m%b);
  for(int bl=0;bl<nu;bl++)
  {
    int le=bl*b+1,ri=min(m,(bl+1)*b);
    for(int i=1;i<=n;i++)
    {
      vis[i]=0;
    }
    //cerr<<bl<<" "<<le<<" "<<ri<<"\n";
    for(int i=le;i<=ri;i++)
    {
      read(gu[i]);
      read(gv[i]);
      read(gw[i]);
      //cerr<<i<<" "<<gu[i]<<" "<<gv[i]<<" "<<gw[i]<<"\n";
      vis[gu[i]]=vis[gv[i]]=1;
      //fin[gu[i]]^=gw[i];
      //fin[gv[i]]^=gw[i];
    }
    for(int i=0;i<63;i++)
    {
      p[i]=0;
    }
    vector<int>yqfakioi;
    for(int i=1;i<=n;i++)
    {
      if(i==s||i==t)
      {
        continue;
      }
      if(vis[i])
      {
        yqfakioi.push_back(i);
        //cerr<<"YQF AK IOI "<<(1988+i)<<"\n";
      }
      else
      {
        int x=a[i];
        for(int j=61;j>=0;j--)
        {
          if((x>>j)&1)
          {
            if(!p[j])
            {
              p[j]=x;
              break;
            }
            x^=p[j];
          }
        }
      }
    }
    for(int i=le;i<=ri;i++)
    {
      int u=gu[i],v=gv[i],w=gw[i];
      a[u]^=w;
      a[v]^=w;
      vector<int>tcyakioi;
      for(int j=0;j<yqfakioi.size();j++)
      {
        int x=a[yqfakioi[j]];
        for(int k=61;k>=0;k--)
        {
          if((x>>k)&1)
          {
            if(!p[k])
            {
              tcyakioi.push_back(k);
              p[k]=x;
              break;
            }
            x^=p[k];
          }
        }
      }
      int x=a[s];
      for(int j=61;j>=0;j--)
      {
        if((x>>j)&1)
        {
          x^=p[j];
        }
      }
      printf("%lld\n",x);
      for(int j=0;j<tcyakioi.size();j++)
      {
        p[tcyakioi[j]]=0;
      }
    }
  }
}
signed main()
{
  freopen("mincut.in","r",stdin);
  freopen("mincut.out","w",stdout);
  int T;
  read(T);
  while(T--)
  {
    solve();
  }
  return 0;
}
