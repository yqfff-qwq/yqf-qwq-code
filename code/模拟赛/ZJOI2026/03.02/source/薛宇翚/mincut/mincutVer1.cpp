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
int a[N],p[63];
signed main()
{
  freopen("mincut.in","r",stdin);
  freopen("mincut.out","w",stdout);
  int T;
  read(T);
  while(T--)
  {
    int n,m,s,t;
    read(n);
    read(m);
    read(s);
    read(t);
    for(int i=1;i<=n;i++)
    {
      a[i]=0;
    }
    while(m--)
    {
      int u,v,w;
      read(u);
      read(v);
      read(w);
      a[u]^=w;
      a[v]^=w;
      for(int i=0;i<63;i++)
      {
        p[i]=0;
      }
      for(int i=1;i<=n;i++)
      {
        if(i!=s&&i!=t)
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
      int x=a[s];
      for(int j=61;j>=0;j--)
      {
        if((x>>j)&1)
        {
          x^=p[j];
        }
      }
      printf("%lld\n",x);
    }
  }
  return 0;
}
