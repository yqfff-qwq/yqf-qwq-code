#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,m,p[N],a[N][29],ct,fl[N];
string s[N];
bool vis[N],vit[N];
vector<int>g[N];
bool cmp(int x,int y)
{
  return s[x].size()<s[y].size();
}
void clean(int x)
{
  fl[x]=0;
  for(int i=0;i<29;i++)
  {
    a[x][i]=0;
  }
}
void dfs(int x)
{
  vit[x]=1;
  for(int i=0;i<g[x].size();i++)
  {
    dfs(g[x][i]);
  }
}
int main()
{
  freopen("dfa.in","r",stdin);
  freopen("dfa.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    p[i]=i;
    cin>>s[i];
  }
  sort(p+1,p+n+1,cmp);
  long long as=0;
  for(int I=1;I<=n;I++)
  {
    int i=p[I];
    for(int J=1;J<I;J++)
    {
      int j=p[J];
      //cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<"\n";
      ct=1;
      clean(1);
      int xa,xb;
      for(int k=0;k<s[i].size();k++)
      {
        a[ct][s[i][k]-'a']=ct+1;
        ct++;
        clean(ct);
      }
      xa=ct;
      int u=1;
      bool f=1;
      for(int k=0;k<s[j].size();k++)
      {
        if(!a[u][s[j][k]-'a'])
        {
          f=0;
          ct++;
          clean(ct);
          a[u][s[j][k]-'a']=ct;
        }
        u=a[u][s[j][k]-'a'];
      }
      xb=u;
      if(f)
      {
        //cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<" p\n";
        as++;
        continue;
      }
      queue<int>q;
      fl[1]=1;
      for(int k=0;k<m;k++)
      {
        if(a[1][k])
        {
          fl[a[1][k]]=1;
          q.push(a[1][k]);
        }
        else
        {
          a[1][k]=1;
        }
      }
      while(!q.empty())
      {
        int u=q.front();
        q.pop();
        for(int k=0;k<m;k++)
        {
          if(a[u][k])
          {
            fl[a[u][k]]=a[fl[u]][k];
            q.push(a[u][k]);
          }
          else
          {
            a[u][k]=a[fl[u]][k];
          }
        }
      }
      for(int k=1;k<=ct;k++)
      {
        g[k].clear();
      }
      for(int k=1;k<=ct;k++)
      {
        //cout<<k<<" fl"<<fl[k]<<" E: ";
        if(fl[k]!=k)
        {
          g[fl[k]].push_back(k);
        }
        /*
        for(int l=0;l<m;l++)
        {
          cout<<a[k][l]<<" ";
        }
        cout<<"\n";
        */
      }
      for(int k=1;k<=ct;k++)
      {
        vis[k]=0;
        vit[k]=0;
      }
      dfs(xb);
      f=0;
      for(int k=0;k<m;k++)
      {
        if(a[xa][k]&&!vis[a[xa][k]]&&!vit[a[xa][k]])
        {
          vis[a[xa][k]]=1;
          q.push(a[xa][k]);
        }
      }
      while(!q.empty())
      {
        int u=q.front();
        q.pop();
        if(u==xa)
        {
          f=1;
          break;
        }
        for(int k=0;k<m;k++)
        {
          if(a[u][k]&&!vit[a[u][k]]/*!=xb*/&&!vis[a[u][k]])
          {
            vis[a[u][k]]=1;
            q.push(a[u][k]);
          }
        }
      }
      if(!f)
      {
        //cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<" q\n";
        as++;
        continue;
      }
      for(int k=1;k<=ct;k++)
      {
        vis[k]=0;
        vit[k]=0;
      }
      dfs(xa);
      f=0;
      for(int k=0;k<m;k++)
      {
        if(a[xb][k]&&!vis[a[xb][k]]&&!vit[a[xb][k]])
        {
          vis[a[xb][k]]=1;
          q.push(a[xb][k]);
        }
      }
      while(!q.empty())
      {
        int u=q.front();
        q.pop();
        if(u==xb)
        {
          f=1;
          break;
        }
        for(int k=0;k<m;k++)
        {
          if(a[u][k]&&!vit[a[u][k]]/*!=xa*/&&!vis[a[u][k]])
          {
            vis[a[u][k]]=1;
            q.push(a[u][k]);
          }
        }
      }
      if(!f)
      {
        //cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<" r\n";
        as++;
      }
    }
  }
  cout<<as<<"\n";
  return 0;
}
