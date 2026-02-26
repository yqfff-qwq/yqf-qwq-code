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
const int N=3e6+100;
int n,op[N],x[N],y[N],mx,f[N];
bool vis[N];
vector<int>arr;
int F(int x)
{
  return x==f[x]?x:f[x]=F(f[x]);
}
bool Merge(int x,int y)
{
  x=F(x);
  y=F(y);
  if(x==y)
  {
    return 0;
  }
  f[F(x)]=F(y);
  return 1;
}
bool Query(int x,int y)
{
  x=F(x);
  y=F(y);
  return x==y;
}
void build(int u,int l,int r)
{
  mx=max(mx,u);
  if(l==r)
  {
    return;
  }
  int mi=(l+r)>>1;
  build(u<<1,l,mi);
  build(u<<1|1,mi+1,r);
}
void update2(int u,int l,int r)
{
  if(vis[u]||l==r)
  {
    return;
  }
  vis[u]=1;
  int mi=(l+r)>>1;
  Merge(u,u<<1);
  Merge(u,u<<1|1);
  update2(u<<1,l,mi);
  update2(u<<1|1,mi+1,r);
}
void update(int u,int l,int r,int xx,int yy,int zz)
{
  if(xx<=l&&r<=yy)
  {
    Merge(zz,u);
    update2(u,l,r);
    return;
  }
  int mi=(l+r)>>1;
  if(xx<=mi)
  {
    update(u<<1,l,mi,xx,yy,zz);
  }
  if(yy>mi)
  {
    update(u<<1|1,mi+1,r,xx,yy,zz);
  }
}
int main()
{
  freopen("interval.in","r",stdin);
  freopen("interval.out","w",stdout);
  read(n);
  for(int i=1;i<=n;i++)
  {
    read(op[i]);
    read(x[i]);
    read(y[i]);
    if(op[i]==1)
    {
      x[i]*=2;
      y[i]*=2;
      y[i]--;
      arr.push_back(x[i]);
      arr.push_back(y[i]);
    }
  }
  sort(arr.begin(),arr.end());
  arr.erase(unique(arr.begin(),arr.end()),arr.end());
  int m=arr.size();
  for(int i=1;i<=n;i++)
  {
    if(op[i]==1)
    {
      x[i]=lower_bound(arr.begin(),arr.end(),x[i])-arr.begin()+1;
      y[i]=lower_bound(arr.begin(),arr.end(),y[i])-arr.begin()+1;
    }
  }
  build(1,1,m);
  for(int i=0;i<N;i++)
  {
    f[i]=i;
  }
  int ct=mx;
  for(int i=1;i<=n;i++)
  {
    if(op[i]==1)
    {
      ct++;
      update(1,1,m,x[i],y[i],ct);
    }
    else
    {
      int xx=x[i]+mx,yy=y[i]+mx;
      if(Query(xx,yy))
      {
        printf("YES\n");
      }
      else
      {
        printf("NO\n");
      }
    }
  }
  return 0;
}
