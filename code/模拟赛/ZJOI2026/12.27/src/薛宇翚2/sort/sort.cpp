#include <bits/stdc++.h>
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
const int N=1e6+100;
int n,q,a[N],as[N],tr[N],rv[N],ne[N];
struct oper
{
	int t,d,x;
}b[N];
vector<oper>g[N];
void update(int x,int y)
{
	while(x<N)
	{
		tr[x]+=y;
		x+=(x&-x);
	}
}
int query(int x)
{
	int s=0;
	while(x)
	{
		s+=tr[x];
		x-=(x&-x);
	}
	return s;
}
pair<int,int>find(int x)
{
	int s=0,p=0;
	for(int i=17;i>=0;i--)
	{
		if((p|(1<<i))<=n&&s+tr[p|(1<<i)]<x)
		{
			p|=(1<<i);
			s+=tr[p];
		}
	}
	return make_pair(p+1,x-s);
}
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	read(n);
	read(q);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		rv[a[i]]=i;
	}
	stack<int>st;
	for(int i=n;i;i--)
	{
		while(!st.empty()&&a[st.top()]<a[i])
		{
			st.pop();
		}
		//cout<<i<<" "<<ne[i]<<"\n";
		if(st.empty())
		{
			ne[i]=n+1;
		}
		else
		{
			ne[i]=st.top();
		}
		st.push(i);
	}
	for(int i=1;i<=n;i=ne[i])
	{
		update(a[i],ne[i]-i);
	}
	for(int i=1;i<=q;i++)
	{
		read(b[i].t);
		read(b[i].d);
		b[i].x=i;
		if(b[i].t>n)
		{
			b[i].t=n;
		}
		g[b[i].t].push_back(b[i]);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			pair<int,int>pos=find(g[i][j].d);
			as[g[i][j].x]=a[rv[pos.first]+pos.second-1];
		}
		int mi=(n>>1)+1;
		pair<int,int>pos=find(mi);
		//cout<<pos.first<<" "<<pos.second<<"\n";
		if(pos.second==1)
		{
			continue;
		}
		int crbloc=query(pos.first)-query(pos.first-1);
		update(pos.first,-crbloc+pos.second-1);
		for(int j=rv[pos.first]+pos.second-1;j<rv[pos.first]+crbloc;j=ne[j])
		{
			update(a[j],min(ne[j],rv[pos.first]+crbloc)-j);
		}
	}
	for(int i=1;i<=q;i++)
	{
		printf("%d\n",as[i]);
	}
	return 0;
}
