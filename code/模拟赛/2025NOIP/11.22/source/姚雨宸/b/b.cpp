#include <bits/stdc++.h>
//#define int long long
const int p=998244353;
using namespace std;
//struct xxx{int op,x,y;}Q[2000005];
int n,m,k,S1,S2,u,v,d[3005],a[3005],op,x,y,f[3005][100005];bool F[3005];
vector<int> ve[3005];
queue<int> q;
signed main()
{
	freopen("b3.in","r",stdin);
	freopen("b3.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>k>>S1>>S2;
	for(int i=1;i<=m;i++){cin>>u>>v;ve[u].push_back(v);ve[v].push_back(u);}
	for(int i=1;i<=n;i++){d[i]=ve[i].size();if(d[i]<=k){q.push(i);F[i]=true;}}
	while(!q.empty())
	{
		u=q.front();q.pop();
		for(auto i:ve[u])if(!F[i]&&(--d[i])<=k){q.push(i);F[i]=true;}
	}
	bool flag=false;
	for(int i=1;i<=n;i++)if(!F[i]){cout<<i<<" ";flag=true;}
	if(flag)return 0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f[i][0]=1;
		for(auto j:ve[i])
		{
			for(int k=1e5;k>=a[j];k--)f[i][k]=(f[i][k]+f[i][k-a[j]])%p;
		}
	}
	for(int i=1;i<=S1+S2;i++)
	{
		cin>>op>>x>>y;
		if(op==1)
		{
			for(auto j:ve[x])
			{
				for(int k=1e5;k>=a[x];k--)f[j][k]=(f[j][k]-f[j][k-a[x]])%p;
//				for(int k=a[x];k<=1e6;k++)f[j][k]=(f[j][k]-f[j][k-a[x]])%p;
				a[x]=y;
				for(int k=1e5;k>=a[x];k--)f[j][k]=(f[j][k]+f[j][k-a[x]])%p;
			}
		}
		else cout<<(f[x][y]+p)%p<<"\n";
	}
	return 0;
}
//WA
