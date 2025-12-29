#include <bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x)
{
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	if(f)
	{
		x=-x;
	}
}
const int N=1e6+100,LI=1e4;
int n,m;
struct thing
{
	int v,w,ix;
	bool vis;
	bool friend operator <(const thing &x,const thing &y)
	{
		if(x.v==y.v)
		{
			return x.ix>y.ix;
		}
		return x.v<y.v;
	}
}a[N];
int ct,d[LI+10];
vector<int>arr,co,rw,emp;
vector<vector<int> >lid;
vector<thing>b[N];
priority_queue<thing>lis[N];
void solve()
{
	for(int i=1;i<=n;i++)
	{
		int v,w;
		cin>>v>>w;
		for(int j=m;j>=w;j--)
		{
			d[j]=max(d[j],d[j-w]+v);
		}
	}
	cout<<d[m]<<"\n";
}
signed main()
{
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	read(n);
	read(m);
	if(m<=LI)
	{
		solve();
		return 0;
	}
	co.push_back(0);
	rw.push_back(0);
	lid.push_back(emp);
	for(int i=1;i<=n;i++)
	{
		read(a[i].v);
		read(a[i].w);
		arr.push_back(a[i].w);
		a[i].vis=0;
		a[i].ix=i;
		co.push_back(0);
		rw.push_back(0);
		lid.push_back(emp);
	}
	//cerr<<"!!!\n";
	ct=n;
	sort(arr.begin(),arr.end());
	int q=unique(arr.begin(),arr.end())-arr.begin();
	for(int i=1;i<=n;i++)
	{
		a[i].w=lower_bound(arr.begin(),arr.begin()+q,a[i].w)-arr.begin()+1;
		//cerr<<i<<" "<<a[i].w<<"\n";
		lis[a[i].w].push(a[i]);
	}
	for(int i=1;i<=q;i++)
	{
		//cerr<<": "<<i<<"\n";
		while(!lis[i].empty())
		{
			b[i].push_back(lis[i].top());
			co[lis[i].top().ix]=i;
			rw[lis[i].top().ix]=b[i].size()-1;
			//cerr<<lis[i].top().ix<<"\n";
			lis[i].pop();
		}
		if(i==q)
		{
			continue;
		}
		int ne=arr[i]/arr[i-1];
		for(int j=0;j+ne<=b[i].size();j+=ne)
		{
			thing u;
			ct++;
			u.vis=0;
			u.ix=ct;
			u.w=i+1;
			u.v=0;
			co.push_back(0);
			rw.push_back(0);
			lid.push_back(emp);
			for(int k=j;k<j+ne;k++)
			{
				u.v+=b[i][k].v;
				lid[ct].push_back(b[i][k].ix);
			}
			//cerr<<"new "<<ct<<" "<<u.v<<"\n";
			lis[i+1].push(u);
		}
	}
	/*
	for(int i=1;i<=ct;i++)
	{
		cerr<<i<<" "<<co[i]<<" "<<rw[i]<<":";
		for(int j=0;j<lid[i].size();j++)
		{
			cerr<<" "<<lid[i][j];
		}
		cerr<<"\n";
	}
	*/
	int as=0;
	for(int i=q;i;i--)
	{
		//cerr<<"loop "<<i<<"\n";
		for(int j=0;j<b[i].size();j++)
		{
			//cerr<<m<<" "<<arr[i-1]<<"\n";
			if(b[i][j].vis)
			{
				//cerr<<b[i][j].ix<<" visited\n";
				int x=b[i][j].ix;
				for(int k=0;k<lid[x].size();k++)
				{
					int y=lid[x][k];
					b[co[y]][rw[y]].vis=1;
				}
			}
			else if(m<arr[i-1])
			{
				//cerr<<"no more\n";
				break;
			}
			else
			{
				//cerr<<i<<" "<<j<<" "<<b[i][j].ix<<" "<<b[i][j].v<<"\n";
				m-=arr[i-1];
				as+=b[i][j].v;
				b[i][j].vis=1;
				int x=b[i][j].ix;
				for(int k=0;k<lid[x].size();k++)
				{
					int y=lid[x][k];
					b[co[y]][rw[y]].vis=1;
					//cerr<<"rem "<<y<<" "<<co[y]<<" "<<rw[y]<<"\n";
				}
			}
		}
	}
	printf("%lld\n",as);
	return 0;
}
