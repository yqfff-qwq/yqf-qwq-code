#include <bits/stdc++.h>
using namespace std;
const int N=1e5,M=1e9;
int main()
{
	freopen("b.in","w",stdout);
	int m=N-1;
	cout<<N<<" "<<m<<"\n1 2\n2 "<<N<<"\n";
	for(int i=1;i<=m;i++)
	{
		int j=i+1;
		cout<<i<<" "<<j<<" "<<M<<"\n";
	}
	return 0;
}
