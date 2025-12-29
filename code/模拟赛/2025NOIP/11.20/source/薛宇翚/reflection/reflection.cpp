#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("reflection.in","r",stdin);
	freopen("reflection.out","w",stdout);
	int n,q,c;
	cin>>n>>q>>c;
	vector<int>a(n+15,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<vector<int> >b(111,vector<int>(n+15,0));
	for(int i=1;i<=100;i++)
	{
		int x=i;
		for(int j=1;j<=n;j++)
		{
			x=abs(x-a[j]);
			b[i][j]=x;
		}
	}
	int lasas=0;
	while(q--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		if(l==1&&x>=1&&x<=100)
		{
			cout<<b[x][r]<<"\n";
		}
		else
		{
			for(int j=l;j<=r;j++)
			{
				x=abs(x-a[j]);
			}
			cout<<x<<"\n";
		}
	}
	return 0;
}
