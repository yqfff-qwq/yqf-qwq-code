#include <bits/stdc++.h>
using namespace std;
const int N=150;
int a[N],n,ct;
vector<int>g[N];
bool vis[N];
char s[N];
void dfs(int x)
{
	if(x==ct+1)
	{
		int su=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='(')
			{
				su++;
			}
			else if(!su)
			{
				return;
			}
			else
			{
				su--;
			}
		}
		if(su)
		{
			return;
		}
		for(int i=1;i<=n;i++)
		{
			printf("%c",s[i]);
		}
		printf("\n");
		exit(0);
		return;
	}
	for(int i=0;i<g[x].size();i++)
	{
		s[g[x][i]]=(i%2?'(':')');
	}
	dfs(x+1);
	for(int i=0;i<g[x].size();i++)
	{
		s[g[x][i]]=(i%2?')':'(');
	}
	dfs(x+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ct++;
			vis[i]=1;
			g[ct].push_back(i);
			int j=a[i];
			while(j!=i)
			{
				vis[j]=1;
				g[ct].push_back(j);
				j=a[j];
			}
		}
	}
	dfs(1);
	return 0;
}
//Where should I stop?
//I ask myself.
