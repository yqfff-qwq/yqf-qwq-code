#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,x,p,t,a[N][N],tox[N][N],toy[N][N],adx[N][N],as[N][N],oas[N][N],otox[N][N],otoy[N][N],oadx[N][N];
string s[N][N];
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	freopen("glob.in","r",stdin);
	freopen("glob.out","w",stdout);
	cin>>n>>m>>x>>p>>t;
	int l=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j]>>s[i][j];
			l=l/gcd(l,a[i][j])*a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int px=i,py=j;
			for(int k=0;k<l;k++)
			{
				char c=s[px][py][k%a[px][py]];
				if(c=='L')
				{
					py--;
				}
				else if(c=='R')
				{
					py++;
				}
				else if(c=='U')
				{
					px--;
				}
				else if(c=='D')
				{
					px++;
				}
				if(px<1||px>n||py<1||py>m)
				{
					break;
				}
			}
			if(px>=1&&px<=n&&py>=1&&py<=m)
			{
				tox[i][j]=px;
				toy[i][j]=py;
			}
			for(int K=0;K<l;K++)
			{
				if(s[i][j][K%a[i][j]]=='C')
				{
					int px=i,py=j;
					for(int k=K+1;k<l;k++)
					{
						char c=s[px][py][k%a[px][py]];
						if(c=='L')
						{
							py--;
						}
						else if(c=='R')
						{
							py++;
						}
						else if(c=='U')
						{
							px--;
						}
						else if(c=='D')
						{
							px++;
						}
						if(px<1||px>n||py<1||py>m)
						{
							break;
						}
					}
					if(px>=1&&px<=n&&py>=1&&py<=m)
					{
						adx[px][py]=(adx[px][py]+x)%p;
					}
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<i<<" "<<j<<" "<<tox[i][j]<<" "<<toy[i][j]<<" "<<adx[i][j]<<"\n";
		}
	}
	*/
	int tt=t/l;
	while(tt)
	{
		if(tt&1)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					oas[i][j]=as[i][j];
					as[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(tox[i][j]&&toy[i][j])
					{
						as[tox[i][j]][toy[i][j]]=(as[tox[i][j]][toy[i][j]]+oas[i][j])%p;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					as[i][j]=(as[i][j]+adx[i][j])%p;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				otox[i][j]=tox[i][j];
				otoy[i][j]=toy[i][j];
				oadx[i][j]=adx[i][j];
				tox[i][j]=toy[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int px=otox[otox[i][j]][otoy[i][j]],py=otoy[otox[i][j]][otoy[i][j]];
				if(px&&py)
				{
					tox[i][j]=px;
					toy[i][j]=py;
				}
				if(otox[i][j]&&otoy[i][j])
				{
					adx[otox[i][j]][otoy[i][j]]=(adx[otox[i][j]][otoy[i][j]]+oadx[i][j])%p;
				}
			}
		}
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<i<<" "<<j<<" "<<tox[i][j]<<" "<<toy[i][j]<<" "<<adx[i][j]<<"\n";
			}
		}
		*/
		tt>>=1;
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<as[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	t%=l;
	for(int k=0;k<t;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				oas[i][j]=as[i][j];
				as[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c=s[i][j][k%a[i][j]];
				if(c=='C')
				{
					as[i][j]=(as[i][j]+(oas[i][j]+x)%p)%p;
				}
				else if(c=='L')
				{
					as[i][j-1]=(as[i][j-1]+oas[i][j])%p;
				}
				else if(c=='R')
				{
					as[i][j+1]=(as[i][j+1]+oas[i][j])%p;
				}
				else if(c=='U')
				{
					as[i-1][j]=(as[i-1][j]+oas[i][j])%p;
				}
				else if(c=='D')
				{
					as[i+1][j]=(as[i+1][j]+oas[i][j])%p;
				}
			}
		}
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<as[i][j]<<" ";
			}
			cout<<"\n";
		}
		*/
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			as[i][j]=(as[i][j]%p+p)%p;
		}
		int las=as[i][1],ct=1;
		for(int j=2;j<=m;j++)
		{
			if(as[i][j]!=las)
			{
				cout<<ct<<" "<<las<<" ";
				las=as[i][j];
				ct=1;
			}
			else
			{
				ct++;
			}
		}
		cout<<ct<<" "<<las<<"\n";
	}
	return 0;
}