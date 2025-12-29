#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long
#define pii pair<long long,long long>
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e5+10;
vector<pii> g[maxn];
int dis[maxn];
int dis2[maxn];
map<pii,bool> tag;
void djk(int s)
{
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > pr;
	pr.push({0,s});
	while(!pr.empty())
	{
		int u=pr.top().sec,s=pr.top().fir;
		pr.pop();
		for(auto it:g[u])
		{
			int sp=s+it.sec,To=it.fir;
			if(tag.count({u,To})) sp=s;
			if(sp<dis[To])
			{
				dis[To]=sp;
				pr.push({sp,To});
			}
		}
	}
}
bitset<maxn> vis;
void get1(int t)
{
	tag.clear(),vis.reset();
	queue<int> q;
	q.push(t);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(auto it:g[t])
		{
			if(dis[it.fir]+it.sec==dis[t])
			{
				tag[{it.fir,t}]=1;
				if(!vis[it.fir])
				q.push(it.fir),vis[it.fir]=1;
			}
		}
	}
}
void get2(int t)
{
	tag.clear(),vis.reset();
	queue<int> q;
	q.push(t);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(auto it:g[t])
		{
			if(dis[it.fir]+it.sec==dis[t])
			{
				tag[{t,it.fir}]=1;
				if(!vis[it.fir])
				q.push(it.fir),vis[it.fir]=1;
			}
		}
	}
}
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	Ios();
	int n,m,s,t,u,v;
	cin>>n>>m>>s>>t>>u>>v;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].pb({b,c});
		g[b].pb({a,c});
	}
	djk(s);
	REP(i,1,n) dis2[i]=dis[i];
	get1(t);djk(u);
	int ans1=dis[v];
	REP(i,1,n) dis[i]=dis2[i];
	get2(t);djk(u);
	int ans2=dis[v];
	cout<<min(ans1,ans2)<<"\n";
}
//可以建出一个图使得这个图上s->t的所有的不重边路径都是最短路？定义这个东西为“最优子图” 
//直接从u走到v就行了。 
//证明：u->v 只会通过最优子图的一条边。
//become DAG ac! 
//maybe i can win!
