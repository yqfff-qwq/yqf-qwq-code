#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,root;
int ne[400025],e[40025],h[200025],idx;
int ans[200025],sx[200025];
queue<int> q[200025];
struct ilj{
	int l,r;
}a[200025];
int C(int x)
{
	return x*(x-1)/2;
}
void add(int x,int y)
{
	ne[++idx]=h[x];
	h[x]=idx;
	e[idx]=y;
}
int find(int x,int f,int l,int r)
{
	int sum=0;
	if(l<=x&&x<=r) sum++;
	for(int i=h[x];i;i=ne[i])
	{
		if(e[i]==f) continue;
		sum+=find(e[i],x,l,r);
	}
	return sum;
}
int cale(int x,int f,int zz)
{
	int ans=0,r=1,z=0;
	for(int i=h[x];i;i=ne[i]) r++;
	int s[r];
	for(int i=h[x];i;i=ne[i])
	{
		if(e[i]==f) continue;
		s[++z]=find(e[i],x,a[zz].l,a[zz].r);
//		cout<<s[z]<<" ";
//		cout<<'\n';
		if(a[zz].l<=x&&x<=a[zz].r) ans+=s[z];
	}
	
	for(int i=1;i<z;i++) for(int j=i+1;j<=z;j++) ans+=s[i]*s[j];
	
	return ans;
}
void dfs(int x,int f)
{
	for(int i=h[x];i;i=ne[i])
	{
		if(e[i]==f) continue;
		while(!q[x].empty())
		{
			ans[q[x].front()]=cale(x,f,q[x].front());
			q[x].pop();
		}
		dfs(e[i],x);
	}
}
int b[200025],c[200025];
void dfs2(int x,int f)
{
	c[x]=1;
	for(int i=h[x];i;i=ne[i])
	{
		if(e[i]==f) continue;
		while(!q[x].empty())
		{
			int sum=a[q[x].front()].r-a[q[x].front()].l+1;
			for(int j=a[q[x].front()].l;j<=a[q[x].front()].r;j++) sum-=c[j];
			ans[q[x].front()]=sum;
			q[x].pop();
		}
		dfs2(e[i],x);
	}
}
signed main()
{
	freopen("rplexq.in","r",stdin);
	freopen("rplexq.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>root;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
		b[x]++;
		b[y]++;
	}
	
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1) flag++;
		else if(b[i]!=2) flag=3;
		if(flag>=3) break;
	}
	
	if(n<=1e5&&m<=1e5)
	{
		for(int i=1;i<=m;i++)
		{
			int l,r,x;
			cin>>l>>r>>x;
			q[x].push(i);
			a[i]={l,r};
		}
		
		dfs(root,-1);
		
		for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
	}
	else if(flag==2)
	{
		for(int i=1;i<=m;i++)
		{
			int l,r,x;
			cin>>l>>r>>x;
			if(l<=x&&x<=r)
			{
				q[x].push(i);
				a[i]={l,r};
			}
			else ans[i]=0;
		}
		
		dfs2(root,-1);
		
		for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			int l,r,x;
			cin>>l>>r>>x;
			int sum=0;
			if(x==root)
			{
				if(root>=l&&root<=r)
				{
					sum+=r-l+1;
					sum+=C(r-l);
				}
				else sum+=C(r-l+1);
			}
			cout<<sum<<'\n';
		}
	}
	
	return 0;
}
