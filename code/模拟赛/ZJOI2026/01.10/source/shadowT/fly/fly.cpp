#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pii pair<int,int>
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pb push_back
#define int long long
#define tdsb 0
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=3e5+10;
vector<pii> g[maxn];
int n,m;
int f1[502][502];
void floyd1()
{
	REP(i,1,n) REP(j,1,n)
	if(i!=j) f1[i][j]=1e18;
	REP(i,1,n)
	for(auto it:g[i])
	f1[i][it.fir]=1;
	REP(k,1,n) REP(i,1,n) REP(j,1,n) f1[i][j]=min(f1[i][j],f1[i][k]+f1[k][j]);
}
int f2[502][502];
struct edge
{
	int u,v,w;
};
vector<edge> f;
void floyd2()
{
	REP(i,1,n) REP(j,1,n)
	if(i!=j) f2[i][j]=1e18;
	REP(i,1,n)
	for(auto it:g[i])
	{
		f2[i][it.fir]=min(f2[i][it.fir],it.sec);
		REP(j,1,n) f2[i][j]=min(f2[i][j],it.sec+it.sec*f1[it.fir][j]);
	}
	REP(k,1,n) REP(i,1,n) REP(j,1,n) f2[i][j]=min(f2[i][j],f2[i][k]+f2[k][j]);
	/*
	for(auto it:f)
	REP(i,1,n) REP(j,1,n)
	f2[i][j]=min(f2[i][it.u]+it.w+it.w*f1[it.v][n],f2[i][j]);*/
}
signed main()
{
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
	Ios();
	cin>>n>>m;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
		f.pb({u,v,w});
		f.pb({v,u,w});
	}
	floyd1();
	floyd2();
	cout<<f2[1][n];
	return tdsb;
}
