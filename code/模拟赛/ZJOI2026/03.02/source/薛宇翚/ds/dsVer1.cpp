#include <bits/stdc++.h>
using namespace std;
const int N=(1<<18)+17,Q=5100,M=3e6+100;
int n,q,a[N];
long long s[Q][Q];
int f(int l,int r)
{
  int as=0;
  //for(int i=0;i<(1<<n);i++)
  for(int I=l;I<=r;I++)
  {
    int i=a[I];
    set<int>s;
    for(int j=l;j<=r;j++)
    {
      s.insert(a[j]^i);
    }
    int p=0;
    for(set<int>::iterator it=s.begin();;it++,p++)
    {
      if(it==s.end()||(*it)!=p)
      {
        as=max(as,p);
        break;
      }
    }
  }
  return as;
}
namespace yyyakioi
{
  int le[M],ri[M],qle[M],qri[M],ct,p[M],sz,bel[N],as[M],tr[M][2],d[M],trt,rt,app[M];
  bool cmp(int x,int y)
  {
    if(bel[le[x]]!=bel[le[y]])
    {
      return bel[le[x]]<bel[le[y]];
    }
    if(bel[le[x]]%2)
    {
      return ri[x]>ri[y];
    }
    return ri[x]<ri[y];
  }
  void update(int &u,int l,int r,int x,int y,int h)
  {
    if(!u)
    {
      trt++;
      u=trt;
    }
    if(l==r)
    {
      //d[u]=y;
      app[u]+=y;
      d[u]=(app[u]>0?1:0);
      return;
    }
    int mi=(l+r)>>1;
    if(x<=mi)
    {
      update(tr[u][0],l,mi,x,y,h-1);
    }
    else
    {
      update(tr[u][1],mi+1,r,x,y,h-1);
    }
    if(d[tr[u][0]]==(1<<(h-1))||d[tr[u][1]]==(1<<(h-1)))
    {
      d[u]=d[tr[u][0]]+d[tr[u][1]];
    }
    else
    {
      d[u]=max(d[tr[u][0]],d[tr[u][1]]);
    }
  }
  void main()
  {
    sz=sqrt(1<<n)+1;
    for(int i=1;i<=(1<<n);i++)
    {
      bel[i]=(i-1)/sz;
    }
    for(int i=1;i<=q;i++)
    {
      int lx,rx,ly,ry;
      scanf("%d%d%d%d",&lx,&rx,&ly,&ry);
      qle[i]=ct+1;
      for(int j=lx;j<=rx;j++)
      {
        for(int k=ly;k<=ry;k++)
        {
          if(j<=k)
          {
            ct++;
            le[ct]=j;
            ri[ct]=k;
          }
        }
      }
      qri[i]=ct;
    }
    for(int i=1;i<=ct;i++)
    {
      p[i]=i;
    }
    sort(p+1,p+ct+1,cmp);
    int l=1,r=0;
    for(int I=1;I<=ct;I++)
    {
      int i=p[I];
      while(l>le[i])
      {
        l--;
        update(rt,0,(1<<n)-1,a[l],1,n);
      }
      while(r<ri[i])
      {
        r++;
        update(rt,0,(1<<n)-1,a[r],1,n);
      }
      while(l<le[i])
      {
        update(rt,0,(1<<n)-1,a[l],-1,n);
        l++;
      }
      while(r>ri[i])
      {
        update(rt,0,(1<<n)-1,a[r],-1,n);
        r--;
      }
      as[i]=d[1];
    }
    for(int i=1;i<=q;i++)
    {
      long long asx=0;
      for(int j=qle[i];j<=qri[i];j++)
      {
        asx+=as[j];
      }
      printf("%lld\n",asx);
    }
  }
}
int main()
{
  freopen("ds.in","r",stdin);
  freopen("ds.out","w",stdout);
  scanf("%d%d",&n,&q);
  for(int i=1;i<=(1<<n);i++)
  {
    scanf("%d",&a[i]);
  }
  if(n<=6)
  {
    for(int i=1;i<=(1<<n);i++)
    {
      for(int j=1;j<=(1<<n);j++)
      {
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+f(i,j);
      }
    }
    while(q--)
    {
      int lx,rx,ly,ry;
      scanf("%d%d%d%d",&lx,&rx,&ly,&ry);
      long long as=0;
      /*
      for(int i=lx;i<=rx;i++)
      {
        for(int j=ly;j<=ry;j++)
        {
          as+=f(i,j);
        }
      }
      */
      as=s[rx][ry]-s[lx-1][ry]-s[rx][ly-1]+s[lx-1][ly-1];
      printf("%lld\n",as);
    }
    return 0;
  }
  yyyakioi::main();
  return 0;
}
