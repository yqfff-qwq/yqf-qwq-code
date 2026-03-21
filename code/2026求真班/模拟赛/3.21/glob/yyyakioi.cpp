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
	freopen("glob.ans","w",stdout);
	cin>>n>>m>>x>>p>>t;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j]>>s[i][j];
		}
	}
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