#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
vector<int>g[N];
int n,ct,xx[N],yy[N];
bool vis[N];
bool check(int a,int b)
{
  return (xx[b]<xx[a]&&xx[a]<yy[b])||(xx[b]<yy[a]&&yy[a]<yy[b]);
}
int main()
{
  freopen("interval.in","r",stdin);
  freopen("interval.out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    int op,x,y;
    scanf("%d%d%d",&op,&x,&y);
    if(op==1)
    {
      ct++;
      xx[ct]=x;
      yy[ct]=y;
      for(int i=1;i<ct;i++)
      {
        if(check(ct,i))
        {
          g[ct].push_back(i);
        }
        if(check(i,ct))
        {
          g[i].push_back(ct);
        }
      }
    }
    else
    {
      queue<int>q;
      q.push(x);
      vis[x]=1;
      bool f=1;
      vector<int>Q;
      Q.push_back(x);
      while(!q.empty())
      {
        int u=q.front();
        q.pop();
        if(u==y)
        {
          printf("YES\n");
          f=0;
          break;
        }
        for(int j=0;j<g[u].size();j++)
        {
          int v=g[u][j];
          if(vis[v])
          {
            continue;
          }
          vis[v]=1;
          Q.push_back(v);
          q.push(v);
        }
      }
      if(f)
      {
        printf("NO\n");
      }
      for(int i=0;i<Q.size();i++)
      {
        vis[Q[i]]=0;
      }
    }
  }
  return 0;
}
