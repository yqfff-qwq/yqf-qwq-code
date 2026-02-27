#include <bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int n,q,k,tr[N];
vector<long long>pw;
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
long long lowbit(long long x)
{
  for(int i=0;i<pw.size();i++)
  {
    int s=(x/pw[i])%k;
    if(s)
    {
      return 1ll*s*pw[i];
    }
  }
  return 1;
}
void add(int x,int v)
{
  while(x<=n)
  {
    tr[x]^=v;
    x+=lowbit(x);
  }
}
int query(int x)
{
  int as=0;
  while(x>0)
  {
    as^=tr[x];
    x-=lowbit(x);
  }
  return as;
}
int main()
{
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  read(n);
  read(q);
  read(k);
  pw.push_back(1);
  while(pw.back()<=n)
  {
    long long x=pw.back();
    pw.push_back(1ll*x*k);
  }
  while(q--)
  {
    int op;
    read(op);
    if(op==1)
    {
      int x,v;
      read(x);
      read(v);
      add(x,v);
    }
    else
    {
      int x;
      read(x);
      printf("%d\n",query(x));
    }
  }
  return 0;
}
