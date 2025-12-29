#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
vector<int> g[maxn];
int dep[maxn],dfn[maxn],tot;
int st[21][maxn];
int n,m,r;
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	dfn[x]=++tot;
	st[0][tot]=fa;
	for(auto it:g[x])
	{
		if(it==fa) continue;
		dfs(it,x);
	}
}
int getlca(int u,int v)
{
	if(u==v) return u;
	u=dfn[u],v=dfn[v];
	if(u>v) swap(u,v);
	u++;
	int l=__lg(v-u+1);
	int x=st[l][u],y=st[l][v-(1<<l)+1];
	return (dep[x]<dep[y]?x:y);
}
int main()
{
	freopen("rplexq.in","r",stdin);
	freopen("rplexq.ans","w",stdout);
	Ios();
	cin>>n>>m>>r;
	REP(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(r,0);
	REP(i,1,20)
	for(int j=1;j+(1<<i)-1<=n;j++)
	{
		int u=st[i-1][j],v=st[i-1][j+(1<<(i-1))];
		st[i][j]=(dep[u]<dep[v]?u:v);
	}
	while(m--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		int ans=0;
		REP(i,l,r)
		REP(j,i+1,r)
		if(getlca(i,j)==x) ans++;
		cout<<ans<<"\n";
	}
}
//lca(i,j)=x -> dfn[i] to dfn[j] 's depmin node is x
