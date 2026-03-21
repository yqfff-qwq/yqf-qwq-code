#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0));
	system("g++ glob.cpp -o glob.exe");
	system("g++ yyyakioi.cpp -o yyyakioi.exe");
	string S="UDLRC";
	while(1)
	{
		cout<<"New Testcase\n";
		int n=rand()%20+1,m=rand()%20+1,p=rand()+2;
		int x=rand()%(p-1)+1,t=rand()%20000+1;
		FILE *inf=fopen("glob.in","w");
		fprintf(inf,"%d %d %d %d %d\n",n,m,x,p,t);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int l=rand()%3;
				if(l==0)
				{
					l=3;
				}
				else if(l==1)
				{
					l=7;
				}
				else
				{
					l=9;
				}
				fprintf(inf,"%d ",l);
				for(int k=0;k<l;k++)
				{
					char c=S[rand()%5];
					fprintf(inf,"%c",c);
				}
				fprintf(inf," ");
			}
			fprintf(inf,"\n");
		}
		fclose(inf);
		cout<<"Data Finished\n";
		system("yyyakioi.exe");
		cout<<"Std Finished\n";
		system("glob.exe");
		cout<<"User Finished\n";
		if(system("fc glob.out glob.ans"))
		{
			cout<<"Wrong Answer\n";
			return 0;
		}
		system("del glob.in");
		system("del glob.out");
		system("del glob.ans");
		cout<<"Accepted\n";
	}
	return 0;
}