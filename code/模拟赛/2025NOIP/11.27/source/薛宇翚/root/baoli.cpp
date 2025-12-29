#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,p;
	while(cin>>n>>m)
	{
		p=0;
		for(int i=0;i<m;i++)
		{
			int x=(i*n+1)^(n-1);
			int y=x-p;
			cout<<i<<" "<<x<<" "<<y<<"\n";
			p=x;
		}
		//cout<<"\n";
	}
	return 0;
}

