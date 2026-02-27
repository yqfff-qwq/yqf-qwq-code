#include <bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int sz[N],n,ct,a[N][29],m,d[N];
char s[N];
long long as;
void dfs(int x)
{
  as+=1ll*d[x]*(sz[x]-d[x])+1ll*d[x]*(d[x]-1)/2;
  for(int i=0;i<29;i++)
  {
    if(a[x][i])
    {
      dfs(a[x][i]);
    }
  }
}
int main()
{
  freopen("dfa.in","r",stdin);
  freopen("dfa.out","w",stdout);
  ct=1;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%s",s+1);
    int le=strlen(s+1),u=1;
    sz[u]++;
    for(int j=1;j<=le;j++)
    {
      int &S=a[u][s[j]-'a'];
      if(!S)
      {
        ct++;
        S=ct;
      }
      u=S;
      sz[u]++;
    }
    d[u]++;
  }
  dfs(1);
  printf("%lld\n",as);
  return 0;
}
