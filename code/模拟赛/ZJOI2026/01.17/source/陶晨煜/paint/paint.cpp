#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define int long long
#define pii pair<int,int>
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e5+10;
//int a[maxn],x[maxn],b[maxn],y[maxn];
vector<pii> g[maxn];
int n,m;
int cant[maxn][3];
int ans=0;
int id(int x,int y)
{
	return x*4+y;
}
void dfs(int u)
{
	if(u>n)
	{
		ans++;
		return;
	}
	REP(i,0,2)
	if(!cant[u][i])
	{
		for(auto it:g[id(u,i)])
		cant[it.fir][it.sec]++;
		dfs(u+1);
		for(auto it:g[id(u,i)])
		cant[it.fir][it.sec]--;
	}
}
void dfs2(int u)
{
	if(u>n)
	{
		ans++;
		return;
	}
	if(!cant[u][0])
	{
		for(auto it:g[id(u,0)])
		cant[it.fir][it.sec]++;
		dfs2(u+1);
		for(auto it:g[id(u,0)])
		cant[it.fir][it.sec]--;
	}
	int ans1=ans;
	dfs2(u+1);
	int ans2=ans;
	ans+=ans2-ans1;
}
const int mod=1e16+61;
unordered_map<int,int> mem;
int hs(int x)
{
	int u=x;
	REP(i,1,n) REP(j,0,2) u*=131,u+=(bool)(cant[i][j]),u%=mod;
	return u;
}
void dfs3(int u)
{
	if(u>n)
	{
		ans++;
		return;
	}
	int p=hs(u);
	if(mem.count(p))
	{
		ans+=mem[p];
		return;
	}
	int ans1=ans;
	REP(i,0,2)
	if(!cant[u][i])
	{
		for(auto it:g[id(u,i)])
		cant[it.fir][it.sec]++;
		dfs3(u+1);
		for(auto it:g[id(u,i)])
		cant[it.fir][it.sec]--;
	}
	int ans2=ans;
	mem[p]=ans2-ans1;
}
signed main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	Ios();
	cin>>n>>m;
	bool fl=1;
	REP(i,1,m)
	{
		int a,x,b,y;
		cin>>a>>x>>b>>y;
		if(x!=0||y!=0) fl=0;
		g[id(a,x)].pb({b,y});
		g[id(b,y)].pb({a,x});
	}
	if(fl)
	{
		dfs2(1);
		cout<<ans;
		return 0;
	}
	if(n>13)
	{
		//cerr<<"dududu!\n";
		mem.reserve(1e4);
		dfs3(1);
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
}
