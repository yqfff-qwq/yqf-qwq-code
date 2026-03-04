#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=350;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,q,sz[N],fa[N];
vector<int>g[N],h[N],au[N],ag[N];
ll dp[N][N],s[N],tp[N];
void calc(int x)
{
  sz[x]=0;
  dp[x][0]=0;
  for(int i=1;i<N;i++)
  {
    dp[x][i]=-inf;
  }
  for(int i=0;i<g[x].size();i++)
  {
    int v=g[x][i];
    if(v!=fa[x])
    {
      memcpy(tp,dp[x],sizeof(tp));
      memset(dp[x],-0x3f,sizeof(dp[x]));
      for(int j=0;j<=sz[x];j++)
      {
        for(int k=0;k<=sz[v]&&j+k<N;k++)
        {
          dp[x][j+k]=max(dp[x][j+k],tp[j]+dp[v][k]);
        }
      }
      sz[x]+=sz[v];
    }
  }
  for(int i=0;i<au[x].size();i++)
  {
    for(int j=N-1;j;j--)
    {
      dp[x][j]=max(dp[x][j],dp[x][j-1]+au[x][i]);
    }
  }
  sz[x]+=au[x].size();
  for(int i=0;i<ag[x].size();i++)
  {
    for(int j=0;j+1<N;j++)
    {
      dp[x][j]=max(dp[x][j],dp[x][j+1]+ag[x][i]);
    }
  }
}
void dfs(int x,int y)
{
  fa[x]=y;
  for(int i=1;i<N;i++)
  {
    dp[x][i]=-inf;
  }
  for(int i=0;i<g[x].size();i++)
  {
    int v=g[x][i],w=h[x][i];
    if(v!=y)
    {
      s[v]=s[x]+w;
      dfs(v,x);
    }
  }
}
int main()
{
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  scanf("%d%d",&n,&q);
  for(int i=1;i<n;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    g[u].push_back(v);
    h[u].push_back(w);
    g[v].push_back(u);
    h[v].push_back(w);
  }
  dfs(1,0);
  while(q--)
  {
    int op,u,v;
    scanf("%d%d%d",&op,&u,&v);
    if(op==1)
    {
      ag[u].push_back(v-s[u]);
    }
    else
    {
      au[u].push_back(v+s[u]);
    }
    while(u)
    {
      //cerr<<"calc "<<u<<"\n";
      calc(u);
      u=fa[u];
    }
    printf("%lld\n",dp[1][0]);
  }
  return 0;
}
