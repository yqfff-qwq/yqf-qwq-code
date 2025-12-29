#include <bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int x[N],y[N],n,w,h;
long long as;
bool cmp(int al,int bl)
{
	return x[al]>x[bl];
}
int main()
{
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	as=0;
	for(int i=1;i<=n;i++)
	{
		multiset<int>s;
		vector<int>g;
		int maxd=0;
		s.insert(0);
		s.insert(h);
		for(int j=1;j<=n;j++)
		{
			if(x[j]<=x[i])
			{
				continue;
			}
			g.push_back(j);
			s.insert(y[j]);
		}
		for(multiset<int>::iterator j=s.begin();j!=s.end();j++)
		{
			multiset<int>::iterator k=j;
			k++;
			if(k==s.end())
			{
				continue;
			}
			int d=(*k)-(*j);
			maxd=max(maxd,d);
			as=max(as,2ll*d+2ll*(w-x[i]));
		}
		sort(g.begin(),g.end(),cmp);
		for(int j=0;j<g.size();j++)
		{
			int v=g[j];
			multiset<int>::iterator it=s.lower_bound(y[v]);
			multiset<int>::iterator jt,kt;
			if(it!=s.end())
			{
				kt=it;
				kt++;
				if(kt!=s.end()&&it!=s.begin())
				{
					jt=it;
					jt--;
					maxd=max(maxd,(*kt)-(*jt));
				}
				s.erase(it);
			}
			as=max(as,2ll*maxd+2ll*(x[v]-x[i]));
		}
	}
	printf("%lld\n",as);
	return 0;
}
