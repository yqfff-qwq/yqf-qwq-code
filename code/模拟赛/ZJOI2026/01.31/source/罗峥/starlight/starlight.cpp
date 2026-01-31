#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,n,a[N];
int main()
{
	freopen("starlight.in","r",stdin);
	freopen("starlight.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	while(t--)
	{
		srand(time(0));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<rand()%(n*(n+1)/2);
	}
	return 0;
}
