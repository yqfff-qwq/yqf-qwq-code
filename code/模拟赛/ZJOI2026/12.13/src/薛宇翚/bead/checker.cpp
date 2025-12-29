#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100,B=32768,M=998244353;
int n,a[N],as,m;
int r()
{
	return rand()%B*B+rand()%B;
}
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
void dfs(int x,int g)
{
	if(x==n+1)
	{
		as=(as+g)%M;
		return;
	}
	dfs(x+1,g);
	dfs(x+1,gcd(g,a[x]));
}
int main()
{
	system("g++ bead.cpp -o bead.exe");
	srand(time(0));
	int st=time(0),ct=0,y;
	while((y=time(0)-st)<=60*60*2+60*40)
	{
		ct++;
		cout<<"Run "<<ct<<" on time "<<y<<"\n";
		FILE *gen=fopen("bead.in","w");
		n=rand()%25+1;
		m=r()%100000+1;
		fprintf(gen,"%d %d\n",n,m);
		for(int i=1;i<=n;i++)
		{
			a[i]=r()%m+1;
			fprintf(gen,"%d ",a[i]);
		}
		fprintf(gen,"\n");
		fclose(gen);
		as=0;
		dfs(1,0);
		system("bead.exe");
		FILE *ouf=fopen("bead.out","r");
		int pans;
		fscanf(ouf,"%d",&pans);
		fclose(ouf);
		if(as!=pans)
		{
			cout<<"Wa, read "<<pans<<" expected "<<as<<"\n";
			return 0;
		}
		cout<<"Ac.\n";
		system("del bead.in");
		system("del bead.out");
	}
	cout<<"%%%\n";
	return 0;
}
