#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n,a[1005],f[1005],s[1005],X;
vector<int> ans[1005];
int find(int u){if(f[u]==u)return u;return f[u]=find(f[u]);}
signed main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];f[i]=i;}
	for(int i=1;i<=n;i++){f[find(i)]=find(a[i]);}
	for(int i=1;i<=n;i++)s[find(i)]++;
	for(int i=1;i<=n;i++)if(s[i]>1)
	{
		int U=i,u=a[i];ans[++X].push_back(i);
		while(u!=U){ans[X].push_back(u);u=a[u];}
	}
	cout<<X<<"\n";
	for(int i=1;i<=X;i++)
	{
		int x=ans[i].size();cout<<x<<" ";
		for(int j=0;j<x;j++)cout<<ans[i][j]<<" ";cout<<"\n";
	}
	return 0;
}
