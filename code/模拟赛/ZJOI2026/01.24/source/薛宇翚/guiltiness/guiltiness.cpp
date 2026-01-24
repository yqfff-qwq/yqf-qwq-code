#include <bits/stdc++.h>
using namespace std;
#define gc getchar()
void read(int &x)
{
	x=0;
	bool f=0;
	char c=gc;
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=gc;
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=gc;
	}
	if(f)
	{
		x=-x;
	}
}
int n,m;
vector<pair<int,int> >a;
int main()
{
	freopen("guiltiness.in","r",stdin);
	freopen("guiltiness.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<n;i++)
	{
		int x;
		read(x);
		a.push_back(make_pair(x,0));
	}
	for(int i=1;i<m;i++)
	{
		int x;
		read(x);
		a.push_back(make_pair(x,1));
	}
	sort(a.begin(),a.end());
	int nct=n,mct=m;
	long long as=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i].second)
		{
			as+=1ll*a[i].first*nct;
			mct--;
		}
		else
		{
			as+=1ll*a[i].first*mct;
			nct--;
		}
	}
	printf("%lld\n",as);
	return 0;
}
