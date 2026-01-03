#include <bits/stdc++.h>
using namespace std;
const int N=5100,M=998244353;
int n,b[N],s,a[N],ct;
vector<int>g,h;
void dfs()
{
	bool fl=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			fl=0;
			break;
		}
	}
	if(fl)
	{
		ct++;
		ct%=M;
		return;
	}
	for(int i=0;i<g.size();i++)
	{
		int x=g[i],y=h[i];
		if(a[x]+1>b[x]||a[y]+1>b[y])
		{
			continue;
		}
		a[x]++;
		a[y]++;
		dfs();
		a[x]--;
		a[y]--;
	}
}
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		s+=b[i];
	}
	if(s&1)
	{
		printf("0\n");
		return 0;
	}
	if(n==1)
	{
		if(b[1]==0)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
		return 0;
	}
	if(n==2)
	{
		if(b[1]==b[2])
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			g.push_back(i);
			h.push_back(j);
		}
	}
	dfs();
	cout<<ct<<"\n";
	return 0;
}
