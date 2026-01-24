#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar()
void read(int &x)
{
	x=0;
	bool f=0;
	char c=gc;
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=gc;
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=gc;
	}
	if(f)
	{
		x=-x;
	}
}
const int N=1e6+100,M=1e9+7;
int n,m,mi[N][5],mx[N][5];
int calc(int x,int y,int z,int zz)
{
	return (y<x)+(z<x)+(zz<x);
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	read(t);
	while(t--)
	{
		read(n);read(m);for(int i=0;i<=n+10;i++)mi[i][0]=mi[i][1]=mi[i][2]=mi[i][3]=0x3f3f3f3f,mx[i][0]=mx[i][1]=mx[i][2]=mx[i][3]=-0x3f3f3f3f;
		for(int i=1;i<=m;i++)
		{
			int l,r,x;
			read(l);read(r);read(x);
			mi[r][x]=min(mi[r][x],l);
			mx[r][x]=max(mx[r][x],l);
		}
		vector<vector<int> >dp(n+100,vector<int>(n+100,0));
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			vector<vector<int> >f(n+100,vector<int>(n+100,0));
			for(int j=0;j<i;j++)
			{
				for(int k=0;k<i;k++)
				{
					if(dp[j][k])
					{
						bool ff=1,gg=1,hh=1;
						for(int l=1;l<=3;l++)
						{
							if(mi[i][l]>mx[i][l])
							{
								continue;
							}
							if(calc(mi[i][l],i,j,k)!=l||calc(mx[i][l],i,j,k)!=l)
							{
								ff=0;
							}
							if(calc(mi[i][l],i,i-1,k)!=l||calc(mx[i][l],i,i-1,k)!=l)
							{
								gg=0;
							}
							if(calc(mi[i][l],i,j,i-1)!=l||calc(mx[i][l],i,j,i-1)!=l)
							{
								hh=0;
							}
						}
						if(ff)
						{
							f[j][k]=(f[j][k]+dp[j][k])%M;
						}
						if(gg)
						{
							f[i-1][k]=(f[i-1][k]+dp[j][k])%M;
						}
						if(hh)
						{
							f[i-1][j]=(f[i-1][j]+dp[j][k])%M;
						}
					}
				}
			}
			swap(dp,f);
		}
		int as=0;
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				as=(as+dp[j][k])%M;
			}
		}
		cout<<as<<"\n"; 
	}
	return 0;
}
