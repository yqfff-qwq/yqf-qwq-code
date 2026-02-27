#include <bits/stdc++.h>
using namespace std;
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
int n,m,q;
namespace sub2
{
  const int N=3e6+100;
  int f[N];
  int F(int x)
  {
    return x==f[x]?x:f[x]=F(f[x]);
  }
  void addeg(int u,int v)
  {
    f[F(u)]=F(v);
  }
  void main()
  {
    for(int i=0;i<N;i++)
    {
      f[i]=i;
    }
    while(q--)
    {
      int op,u,v;
      read(op);
      read(u);
      read(v);
      if(op==1)
      {
        int w;
        read(w);
        w%=m;
        if(w)
        {
          addeg(u,v+n);
          addeg(u+n,v);
        }
        else
        {
          addeg(u,v);
          addeg(u+n,v+n);
        }
      }
      else
      {
        int x,b,c,as=0;
        read(x);
        read(b);
        read(c);
        x%=m;
        for(int i=0;i<c;i++)
        {
          if(F(u)==F(v+x*n))
          {
            as++;
          }
          x+=b;
          x%=m;
        }
        printf("%d\n",as);
      }
    }
  }
}
bool isprime(int x)
{
  if(x<2)
  {
    return 0;
  }
  for(int i=2;i<=x/i;i++)
  {
    if(x%i==0)
    {
      return 0;
    }
  }
  return 1;
}
namespace sub3
{
  const int N=1e6+100;
  int f[N],g[N];
  bool iseg[N];
  int F(int x)
  {
    return x==f[x]?x:f[x]=F(f[x]);
  }
  int G(int x)
  {
    return x==g[x]?x:g[x]=G(g[x]);
  }
  void main()
  {
    for(int i=0;i<N;i++)
    {
      f[i]=g[i]=i;
    }
    while(q--)
    {
      int op,u,v;
      read(op);
      read(u);
      read(v);
      if(op==1)
      {
        int w;
        read(w);
        w%=m;
        g[G(u)]=G(v);
        if(w)
        {
          iseg[F(u)]=iseg[F(v)]=1;
        }
        else
        {
          iseg[F(v)]|=iseg[F(u)];
          f[F(u)]=F(v);
        }
      }
      else
      {
        int x,b,c,as=0;
        read(x);
        read(b);
        read(c);
        if(G(u)!=G(v))
        {
          printf("0\n");
          continue;
        }
        x%=m;
        for(int i=0;i<c;i++)
        {
          if(F(u)!=F(v)||iseg[F(u)]||x%m==0)
          {
            as++;
          }
          x+=b;
          x%=m;
        }
        printf("%d\n",as);
      }
    }
  }
}
namespace sub1
{
  const int N=3e6+100;
  int f[N];
  int F(int x)
  {
    return x==f[x]?x:f[x]=F(f[x]);
  }
  void addeg(int u,int v)
  {
    f[F(u)]=F(v);
  }
  int findq(int x,int y)
  {
    return x*m+y%m;
  }
  void main()
  {
    for(int i=0;i<N;i++)
    {
      f[i]=i;
    }
    while(q--)
    {
      int op,u,v;
      read(op);
      read(u);
      read(v);
      if(op==1)
      {
        int w;
        read(w);
        w%=m;
        for(int i=0;i<m;i++)
        {
          addeg(findq(u,i),findq(v,(i+w)%m));
          addeg(findq(u,(i+w)%m),findq(v,i));
        }
      }
      else
      {
        int x,b,c,as=0;
        read(x);
        read(b);
        read(c);
        x%=m;
        for(int i=0;i<c;i++)
        {
          if(F(findq(u,0))==F(findq(v,x%m)))
          {
            as++;
          }
          x+=b;
          x%=m;
        }
        printf("%d\n",as);
      }
    }
  }
}
int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  read(n);
  read(m);
  read(q);
  if(m==2)
  {
    sub2::main();
    return 0;
  }
  if(isprime(m))
  {
    sub3::main();
    return 0;
  }
  sub1::main();
  return 0;
}
