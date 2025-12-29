#include <bits/stdc++.h>
#define int long long
using namespace std;
const int B=(1<<10),N=1e5;
void read(int &x)
{
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	if(f)
	{
		x=-x;
	}
}
int r()
{
	return (rand()%B)*B*B+(rand()%B)*B+rand()%B;
}
signed main()
{
	system("g++ root.cpp -o root");
	int st=time(0),ct=0;
	srand(time(0));
	while(time(0)-st<=4200)
	{
		ct++;
		cout<<ct<<" "<<time(0)-st<<"\n";
		FILE *inf=fopen("root.in","w");
		int t=r()%3000+1;
		vector<int>as;
		fprintf(inf,"%lld\n",t);
		int tt=t;
		while(t--)
		{
			int n=r()%N+2,m=r()%N;
			fprintf(inf,"%lld %lld\n",n,m);
			int ct=0;
			for(int i=0;i<=m;i++)
			{
				ct+=((i^(n-1))%n==1);
			}
			as.push_back(ct);
		}
		fclose(inf);
		system("root");
		FILE *ouf=fopen("root.out","r");
		for(int i=0;i<tt;i++)
		{
			int x;
			fscanf(ouf,"%lld",&x);
			if(x!=as[i])
			{
				cout<<"WA "<<i<<"\n";
				return 0;
			 } 
		}
		cout<<"AC\n";
		fclose(ouf);
		system("del root.out");
		system("del root.in");
	}
	cout<<"%%%\n";
	return 0;
}
