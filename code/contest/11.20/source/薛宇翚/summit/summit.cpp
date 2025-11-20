#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("summit.in","r",stdin);
	freopen("summit.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,l,r,x;
		cin>>n>>l>>r;
		vector<int>a(n+1),b(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		vector<vector<vector<int> > >f(n+1,vector<vector<int> >(n+1,vector<int>(n+1,0x3f3f3f3f3f3f3f3fll)));
		f[0][0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=j;k<=n;k++)
				{
					for(int jj=j+1;jj<=n;jj++)
					{
						for(int kk=max(k+1,jj);kk<=n;kk++)
						{
							f[i][jj][kk]=min(f[i][jj][kk],f[i-1][j][k]+a[jj]+b[kk]);
						}
					}
				}
			}
		}
		for(int i=l;i<=r;i++)
		{
			int as=0x3f3f3f3f3f3f3f3fll;
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					as=min(as,f[i][j][k]);
				}
			}
			cout<<as<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
