#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100,B=262144,M=1e5+100,bb=32768;;
int n,a[N],as,m;
bool vis[N];
int r()
{
	return rand()%bb*bb+rand()%bb;
}
void update(int x,int y)
{
	while(x<N)
	{
		a[x]+=y;
		x+=(x&-x);
	}
}
int smallrand()
{
	int y;
	do
	{
		y=rand()%4-1;
	}
	while(y==2);
	return y;
}
int main()
{
	system("g++ bf.cpp -o bf.exe");
	system("g++ robot.cpp -o robot.exe");
	srand(time(0));
	int st=time(0),ct=0,y;
	while((y=time(0)-st)<=60*60+60*30)
	{
		ct++;
		cout<<"Run "<<ct<<" on time "<<y<<"\n";
		FILE *gen=fopen("robot.in","w");
		int T=rand()%5+1,tt;
		fprintf(gen,"%d\n",T);
		tt=T;
		while(T--)
		{
			memset(a,0,sizeof(a));
			int L=r()%M+1;
			int n=r()%L,m=r()%L;
			//cerr<<L<<" "<<n<<" "<<m<<"\n";
			memset(vis,0,sizeof(vis));
			for(int i=1;i<L;i++)
			{
				update(i,1);
			}
			vis[L]=1;
			for(int i=1;i<=n;i++)
			{
				int tot=L-i,cur=(B<<1);
				for(int j=B;j;j>>=1)
				{
					int le=a[cur-j];
					if(r()%tot<le)
					{
						tot=a[cur-j];
						cur-=j;
					}
					else
					{
						tot-=a[cur-j];
					}
				}
				vis[cur]=1;
				update(cur,-1);
			}
			int las=0;
			fprintf(gen,"%d\n",n+1);
			for(int i=1;i<=L;i++)
			{
				if(vis[i])
				{
					fprintf(gen,"%d %d\n",smallrand(),i-las);
					las=i;
				}
			}
			memset(a,0,sizeof(a));
			memset(vis,0,sizeof(vis));
			for(int i=1;i<L;i++)
			{
				update(i,1);
			}
			vis[L]=1;
			for(int i=1;i<=m;i++)
			{
				int tot=L-i,cur=(B<<1);
				for(int j=B;j;j>>=1)
				{
					int le=a[cur-j];
					if(r()%tot<le)
					{
						tot=a[cur-j];
						cur-=j;
					}
					else
					{
						tot-=a[cur-j];
					}
				}
				vis[cur]=1;
				update(cur,-1);
			}
			las=0;
			fprintf(gen,"%d\n",m+1);
			for(int i=1;i<=L;i++)
			{
				if(vis[i])
				{
					fprintf(gen,"%d %d\n",smallrand(),i-las);
					las=i;
				}
			}
		}
		fclose(gen);
		system("bf.exe < robot.in > robot.ans");
		system("robot.exe");
		FILE *ouf=fopen("robot.out","r"),*ans=fopen("robot.ans","r");
		for(int i=1;i<=tt;i++)
		{
			cout<<"checking line "<<i<<"\n";
			int pans,jans;
			fscanf(ouf,"%d",&pans);
			fscanf(ans,"%d",&jans);
			if(jans!=pans)
			{
				cout<<"Wa, read "<<pans<<" expected "<<jans<<"\n";
				return 0;
			}
			cout<<"Ok.\n";
		}
		cout<<"Ac.\n";
		fclose(ouf);
		fclose(ans);
		system("del robot.in");
		system("del robot.out");
		system("del robot.ans");
	}
	cout<<"%%%\n";
	return 0;
}
