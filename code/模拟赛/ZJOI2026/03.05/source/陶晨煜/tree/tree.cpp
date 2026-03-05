#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fir first
#define sec second
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>
#define all(x) x.begin(),x.end();
#define int long long
#define gunmu 0
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e4+10;
int c[maxn],v[maxn];
int fa[maxn];
vector<int> g;
vector<int> G[maxn];
int n,k,t;
int C[maxn];
vector<int> dp[maxn];
void dfs(int x)
{
	REP(i,1,min(k,c[x])) dp[x][i]=i*v[x];
	for(auto it:G[x])
	{
		dfs(it);
		vector<int> f;
		f.resize(k+10);
		REP(j,1,k)
		REP(l,1,k-j)
		f[j+l]=max(f[j+l],dp[x][j]+dp[it][l]);
		dp[x]=f;
	}
}
int work()
{
	REP(i,1,n) C[i]=c[i],dp[i].clear(),dp[i].resize(k+10);
	int ans=0;
	for(auto it:g)
	{
		int u=it;
		while(u!=0)
		{
			c[u]--;
			ans+=v[u];
			u=fa[u];
		}
	}
	dfs(1);
	int mx=0;
	REP(i,1,k) mx=max(mx,dp[1][i]);
	REP(i,1,n) c[i]=C[i];
	return mx+ans;
}
int ans;
void dfss(int u)
{
	if(g.size()==t)
	{
		ans=max(ans,work());
		return;
	}
	REP(i,u,n)
	{
		g.pb(i);
		dfss(i+1);
		g.pop_back();
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>k>>t;
	REP(i,1,n) cin>>c[i]>>v[i];
	REP(i,2,n) cin>>fa[i],G[fa[i]].pb(i);
	dfss(1);
	cout<<ans;
}
