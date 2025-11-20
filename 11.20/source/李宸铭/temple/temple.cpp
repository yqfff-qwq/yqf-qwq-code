#include<bits/stdc++.h>
using namespace std;
int n,base,mod,q;
int a[100025],in[100025];
int u[100025],v[100025]; 
int ne[200025],e[200025],h[200025],idx;
void add(int x,int y)
{
	ne[++idx]=h[x];
	e[idx]=y;
	h[x]=idx;
}
int flag;
unordered_map<int,int> mp; 
int dfs(int x,int f,int z)
{
	if(x==z)
	{
		mp[a[x]]++;
		return 1;
	}
	
	for(int i=h[x];i;i=ne[i])
	{
		if(f==e[i]) continue;
		if(dfs(e[i],x,z)==1)
		{
			mp[a[x]]++;
			if(mp[a[x]]==2) flag=1;
			return 1; 
		}
	}
	return 0;
}
signed main()
{
	freopen("temple.in","r",stdin);
	freopen("temple.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>base>>mod; 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
		in[x]++;
		in[y]++;
	}
	cin>>q; 
//	if(n<=5000&&q<=5000)
	{
		for(int i=1;i<=q;i++)
		{
			cin>>u[i]>>v[i];
			flag=0;
			mp.clear();
			dfs(u[i],-1,v[i]);
			if(flag==1) cout<<"Yes"<<'\n';
			else cout<<"No"<<'\n';
		}
	}
	
	return 0;
}
