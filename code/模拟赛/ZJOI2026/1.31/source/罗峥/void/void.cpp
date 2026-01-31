#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[2005][2005];
int main()
{
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			a[u][v]=a[v][u]=1;
		}
		for(int i=1;i<=n;i++)
		{
			int flag=0;
			for(int j=i+1;j<=n;j++)
			{
				int cnt=0;
				for(int k=1;k<=n;k++)
				{
					if(a[i][k]==1&&a[j][k]==1) cnt++;
				}
				if(cnt%2==0)
				{
					cout<<i<<' '<<j<<'\n';
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
	}
	return 0;
}
