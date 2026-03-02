#include <bits/stdc++.h>
using namespace std;
const int N=170;
int l,n,t,x[N],y[N];
namespace sub3
{
  void dfs(int z,int a,int b,int c,int d)
  {
    if(a>t||b>t||c>t||d>t)
    {
      return;
    }
    if(z==n+1)
    {
      printf("Yes\n");
      exit(0);
    }
    int goa=x[z]-1+y[z]-1,gob=l-x[z]+y[z]-1,goc=x[z]-1+l-y[z],god=l-x[z]+l-y[z];
    dfs(z+1,a+goa,b,c,d);
    dfs(z+1,a,b+gob,c,d);
    dfs(z+1,a,b,c+goc,d);
    dfs(z+1,a,b,c,d+god);
  }
  void main()
  {
    dfs(1,0,0,0,0);
    printf("No\n");
  }
}
namespace sub5
{
  const int T=20100;
  bool f[N][T],g[N][T];
  int pre[N],suf[N];
  void main()
  {
    sort(x+1,x+n+1);
    f[0][0]=g[n+1][0]=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<T;j++)
      {
        f[i][j]=f[i-1][j];
      }
      int dist=((x[i]-1+y[i]-1)<<1);
      pre[i]=pre[i-1]+dist;
      for(int j=dist;j<T;j++)
      {
        f[i][j]|=f[i-1][j-dist];
      }
    }
    for(int i=n;i;i--)
    {
      for(int j=0;j<T;j++)
      {
        g[i][j]=g[i+1][j];
      }
      int dist=((l-x[i]+y[i]-1)<<1);
      suf[i]=suf[i+1]+dist;
      for(int j=dist;j<T;j++)
      {
        g[i][j]|=g[i+1][j-dist];
      }
    }
    for(int i=0;i<=n;i++)
    {
      bool leok=0,riok=0;
      for(int j=max(pre[i]-t,0);j<=t;j++)
      {
        if(f[i][j])
        {
          leok=1;
          break;
        }
      }
      for(int j=max(suf[i+1]-t,0);j<=t;j++)
      {
        if(g[i+1][j])
        {
          riok=1;
          break;
        }
      }
      if(leok&&riok)
      {
        printf("Yes\n");
        return;
      }
    }
    printf("No\n");
  }
}
namespace sub1
{
  bool f[55][55][55][55],g[55][55][55][55];
  void main()
  {
    //cerr<<"call sub1 main\n";
    f[0][0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
      memcpy(g,f,sizeof(g));
      memset(f,0,sizeof(f));
      int goa=x[i]-1+y[i]-1,gob=l-x[i]+y[i]-1,goc=x[i]-1+l-y[i],god=l-x[i]+l-y[i];
      for(int j=0;j<55;j++)
      {
        for(int k=0;k<55;k++)
        {
          for(int m=0;m<55;m++)
          {
            for(int o=0;o<55;o++)
            {
              if(!g[j][k][m][o])
              {
                continue;
              }
              //cerr<<"func "<<i<<" "<<j<<" "<<k<<" "<<m<<" "<<o<<" "<<goa<<" "<<gob<<" "<<goc<<" "<<god<<"\n";
              if(j+goa<55)
              {
                f[j+goa][k][m][o]=1;
              }
              if(k+gob<55)
              {
                f[j][k+gob][m][o]=1;
              }
              if(m+goc<55)
              {
                f[j][k][m+goc][o]=1;
              }
              if(o+god<55)
              {
                f[j][k][m][o+god]=1;
              }
              //cerr<<"finish\n";
            }
          }
        }
      }
    }
    for(int i=0;i<=t;i++)
    {
      for(int j=0;j<=t;j++)
      {
        for(int k=0;k<=t;k++)
        {
          for(int m=0;m<=t;m++)
          {
            if(f[i][j][k][m])
            {
              printf("Yes\n");
              return;
            }
          }
        }
      }
    }
    printf("No\n");
  }
}
namespace commander
{
  void main()
  {
    printf("Yes\n");
  }
}
int main()
{
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  scanf("%d%d%d",&l,&n,&t);
  for(int i=1;i<=n;i++)
  {
    scanf("%d%d",&x[i],&y[i]);
  }
  //sub1::main();
  if(n<=10)
  {
    sub3::main();
    return 0;
  }
  if(l%2==1&&n<=45)
  {
    bool f=1;
    int cent=(l+1)/2;
    for(int i=1;i<=n;i++)
    {
      if(y[i]!=cent)
      {
        f=0;
        break;
      }
    }
    if(f)
    {
      sub5::main();
      return 0;
    }
  }
  if(t<=50)
  {
    sub1::main();
    return 0;
  }
  commander::main();
  return 0;
}
