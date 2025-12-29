#include<bits/stdc++.h>
using namespace std;
int n;
int a[1025],id[1025],f[1025],s[1025];
int ne[1025];
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=i;
		s[i]=1;
		id[a[i]]=i;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			int xx=find(i),yy=find(id[i]);
//			cout<<xx<<" "<<yy<<'\n';
			if(xx!=yy)
			{
				f[xx]=yy;
				s[yy]+=s[xx];
				ne[id[i]]=i;
			}
		}
	}
	
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i)
		{
			if(s[i]==1) continue;
			sum++;
		}
	}
	cout<<sum<<'\n';
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i)
		{
			if(s[i]==1) continue;
			cout<<s[i]<<" ";
			for(int j=i;j;j=ne[j]) cout<<j<<" ";
			cout<<'\n';
		}
	}
	
	return 0;
}
