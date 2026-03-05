#include <bits/stdc++.h>
using namespace std;
const int N=(1<<23)+100;
typedef long long ll;
ll n,dp[N],A,B,a[N],b[N],pw[N],c[N];
int main()
{
	pw[0]=1;
	for(int i=1;i<25;i++)
	{
		pw[i]=pw[i-1]*2;
	}
	system("g++ pom.cpp -o pom");
	int st=time(0),ct=0;
	srand(time(0));
	while(time(0)-st<=3600)
	{
		ct++;
		cout<<"Test "<<ct<<" at time "<<(time(0)-st)<<"\n";
		FILE *inf=fopen("pom.in","w");
		int t=rand()%100+1;
		fprintf(inf,"%d\n",t);
		vector<ll>as;
		while(t--)
		{
			n=rand()%19+1;
			fprintf(inf,"%lld\n",n);
			for(int i=n-1;i>=0;i--)
			{
				int x=rand()%100;
				if(x<50)
				{
					a[i]=0;
					b[i]=1;
				}
				else if(x<75)
				{
					a[i]=b[i]=1;
				}
				else if(x<98)
				{
					a[i]=b[i]=0;
				}
				else
				{
					a[i]=1;
					b[i]=0;
				}
				fprintf(inf,"%lld",a[i]);
			}
			fprintf(inf,"\n");
			A=B=0;
			for(int i=n-1;i>=0;i--)
			{
				if(a[i])
				{
					A+=pw[i];
				}
				if(b[i])
				{
					B+=pw[i];
				}
				fprintf(inf,"%lld",b[i]);
			}
			fprintf(inf,"\n");
			memset(dp,0x3f,sizeof(dp));
			dp[A]=0;
			for(int i=n-1;i>=0;i--)
			{
				c[i]=rand();
				fprintf(inf,"%lld ",c[i]);
			}
			fprintf(inf,"\n");
			for(int i=0;i<=(1<<n)-1;i++)
			{
				for(int j=0;j<n;j++)
				{
					int d=pw[j];
					if(i+d<(1<<n))
					{
						dp[i|(i+d)]=min(dp[i|(i+d)],dp[i]+c[j]);
					}
					if(i-d>=0)
					{
						dp[i|(i-d)]=min(dp[i|(i-d)],dp[i]+c[j]);
					}
				}
			}
			if(dp[B]>=0x3f3f3f3f3f3f3fll)
			{
				as.push_back(-1);
			}
			else
			{
				as.push_back(dp[B]);
			}
		}
		fclose(inf);
		system("./pom");
		FILE *ouf=fopen("pom.out","r");
		for(int i=0;i<as.size();i++)
		{
			ll x;
			fscanf(ouf,"%lld",&x);
			if(x!=as[i])
			{
				cout<<"L "<<(i+1)<<" R "<<x<<" E "<<as[i]<<"\n";
				fclose(ouf);
				return 1;
			}
		}
		fclose(ouf);
		cout<<"AC\n";
		//return 0;
		system("rm pom.in");
		system("rm pom.out");
	}
	return 0;
}
