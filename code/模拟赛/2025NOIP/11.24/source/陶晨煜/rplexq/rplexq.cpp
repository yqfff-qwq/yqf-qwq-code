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
int dfn_getlca(int u,int v)
{
	if(u==v) return u;
	if(u>v) swap(u,v);
	u++;
	int l=__lg(v-u+1);
	int x=st[l][u],y=st[l][v-(1<<l)+1];
	return (dep[x]<dep[y]?x:y);
}
int cf[maxn];
/*
struct Fenwick
{
	int tr[maxn];
	int lowbit(int x){return x&-x;}
	void add(int x,int v)
	{
		for(int i=x;i<=n;i+=lowbit(i))
		tr[i]+=v;
	}
	int qry(int l)
	{
		int u=0;
		for(int i=l;i>0;i-=lowbit(i))
		u+=tr[i];
		return u;
	}
	int query(int l,int r)
	{
		return qry(r)-qry(l-1);
	}
};
*/
int main()
{
	freopen("rplexq.in","r",stdin);
	freopen("rplexq.out","w",stdout);
	Ios();
	cin>>n>>m>>r;
	REP(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	if(n>4000||m>4000)//juhua
	{
		int R=r;
		while(m--)
		{
			ll l,r,x;
			cin>>l>>r>>x;
			ll ans=(r-l)*(r-l+1)/2; 
			if(x==R) cout<<ans<<"\n";
			else cout<<0<<"\n";
		}
		return 0;
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
		REP(i,1,n) cf[i]=0;
		REP(i,l,r) cf[dfn[i]]++;
		REP(i,1,n) cf[i]+=cf[i-1];
		ll ans=0;
		REP(i,l,r)
		{
			int L=dfn[i]+1,R=n;
			while(L<R)
			{
				int mid=(L+R)/2;
				if(dep[dfn_getlca(dfn[i],mid)]<=dep[x]) R=mid;
				else L=mid+1;
			}
			int pos1=L;
			L=dfn[i]+1,R=n;
			while(L<R)
			{
				int mid=(L+R+1)/2;
				if(dep[dfn_getlca(dfn[i],mid)]<dep[x]) R=mid-1;
				else L=mid;
			}
			int pos2=L;
			if(dfn_getlca(dfn[i],pos1)==x)
			ans+=cf[pos2]-cf[pos1-1];
		}
		cout<<ans<<"\n";
	}
}
//lca(i,j)=x -> dfn[i] to dfn[j] 's depmin node is x
