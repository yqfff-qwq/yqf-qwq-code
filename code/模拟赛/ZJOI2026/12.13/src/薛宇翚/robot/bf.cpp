#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<ll>a,b;
		int n,m;
		cin>>n;
		a.push_back(0);
		b.push_back(0);
		map<ll,ll>mp;
		for(int i=1;i<=n;i++)
		{
			ll x,y;
			cin>>x>>y;
			ll z=a.back();
			for(int j=1;j<=y;j++)
			{
				z+=x;
				a.push_back(z);
			}
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			ll x,y;
			cin>>x>>y;
			ll z=b.back();
			for(int j=1;j<=y;j++)
			{
				z+=x;
				b.push_back(z);
			}
		}
		for(int i=0;i<a.size();i++)
		{
			mp[b[i]-a[i]]++;
		}
		ll as=0;
		for(map<ll,ll>::iterator i=mp.begin();i!=mp.end();i++)
		{
			as=max(as,i->second);
		}
		printf("%lld\n",as);
	}
	return 0;
}
