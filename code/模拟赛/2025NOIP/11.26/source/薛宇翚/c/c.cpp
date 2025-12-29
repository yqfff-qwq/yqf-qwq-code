#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=355;
int n,k,h[N],c[N],as;
vector<int>g[N],re;
bool cmp(int x,int y)
{
	return c[x]<c[y];
}
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i]>>c[i];
		g[h[i]].push_back(i);
	}
	int mi=0;
	for(int i=0;i<N;i++)
	{
		if(g[i].size())
		{
			mi=i;
			break;
		}
	}
	sort(g[mi].begin(),g[mi].end(),cmp);
	while(g[mi].size()>1)
	{
		as+=k;
		g[mi+1].push_back(g[mi].back());
		g[mi].pop_back();
	}
	int xmi=c[g[mi][0]];
	re.push_back(g[mi][0]);
	for(int i=mi+1;i<N;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			if(!re.empty())
			{
				re.pop_back();
			}
			else
			{
				as+=xmi;
			}
		}
		for(int j=0;j<g[i].size();j++)
		{
			re.push_back(g[i][j]);
			xmi=min(xmi,c[g[i][j]]);
		}
	}
	cout<<as<<"\n";
	return 0;
}
