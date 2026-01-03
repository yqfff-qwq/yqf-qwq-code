#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define ll long long
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
//#define int long long
#define pii pair<int,int>
#define umap unordered_map
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e6+10;
int B,n,m;
int a[maxn];
int res[maxn];
int ans;
struct Q
{
	int id,l,r;
};
vector<Q> q;
bool cmp(Q a,Q b)
{
	if(a.l/B==b.l/B) return ((a.l/B&1)?a.r<b.r:a.r>b.r);
	return a.l<b.l;
}
int vis[maxn];
void add(int x)
{
	vis[a[x]]--;
	if(vis[a[x]]==0) ans--;
	a[x]++;
	vis[a[x]]++;
	if(vis[a[x]]==1) ans++;
}
void del(int x)
{
	vis[a[x]]--;
	if(vis[a[x]]==0) ans--;
	a[x]--;
	vis[a[x]]++;
	if(vis[a[x]]==1) ans++;
}
/*bool chkA()
{
	REP(i,1,n) if(a[i]%2==0) return 0;
	return 1;
}*/
/*
namespace SubA
{
	struct st
	{
		int id,l,r;
	};
	bool cmpp(st a,st b)
	{
		if(a.l==b.l) return a.r<b.r;
		return a.l<b.l;
	}
	struct Fenwick
	{
		int tr[maxn*4];int n;
		int lowbit(int x){return x&-x;}
		void add(int x,int v)
		{
			for(int i=x;i<=n;i+=lowbit(i))
			tr[i]+=v;
		}	
		int qry(int x)
		{
			int u=0;
			for(int i=x;i>0;i-=lowbit(i)) u+=tr[i];
			return u;
		}
		int query(int l,int r)
		{
			return qry(r)-qry(l-1);
		}
	}t;
	int l[maxn],r[maxn];
	int res[maxn];
	bool vs[maxn];
	vector<int> g;
	void main()
	{
		REP(i,1,n) vs[a[i]]=1;
		int ans=0;
		REP(i,1,n) if(vs[i]) ans++;
		REP(i,1,n+1) l[i]=0,r[i]=0;
		REP(i,1,n)
		{
			if(l[a[i]]==0) l[a[i]]=r[a[i]]=i;
			else l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
		}
		vector<st> q;
		vector<pii> lr;
		REP(i,1,m)
		{
			int x,y;
			cin>>x>>y;
			q.pb({i,x,-y});
		}
		REP(i,1,n) if(l[i]!=0) lr.pb({l[i],-r[i]});
		sort(lr.begin(),lr.end());reverse(lr.begin(),lr.end());
		for(auto it:lr) g.pb(it.fir),g.pb(it.sec);
		for(auto it:q) g.pb(it.l),g.pb(it.r);
		sort(g.begin(),g.end());
		umap<int,int> mp;
		int tot=0;
		for(int i=0;i<g.size();i++)
		{
			if(i==0) mp[g[i]]=++tot;
			else if(g[i]!=g[i-1]) mp[g[i]]=++tot;
		}
		sort(q.begin(),q.end(),cmpp);reverse(q.begin(),q.end());
		t.n=tot;
		int pos=0;
		for(auto it:q)
		{
			while(pos<lr.size())
			{
				//cerr<<lr[pos].fir<<" "<<-lr[pos].sec<<"\n";
				if(lr[pos].fir>=it.l)
				t.add(mp[lr[pos].sec],1),cerr<<"add "<<lr[pos].fir<<" "<<-lr[pos].sec<<"\n",pos++;
				else break;
			}
			int delta=t.query(mp[it.r],tot);
			cerr<<delta<<"\n";
			delta=lr.size()-delta;
			res[it.id]=ans+delta;
		}
		REP(i,1,m) cout<<res[i]<<"\n";
		cout<<"\n";
	}
}
*/ 
signed main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	Ios();
	cin>>n>>m;
	REP(i,1,n) cin>>a[i],vis[a[i]]++;
	/*if(chkA())
	{
		SubA::main();
		return 0;
	}*/
	REP(i,1,n) if(vis[i]) ans++; 
	B=sqrt(n)+1;
	REP(i,1,m)
	{
		int l,r;
		cin>>l>>r;
		q.pb({i,l,r});
	}
	sort(q.begin(),q.end(),cmp);
	int l=1,r=1;add(1);
	for(auto it:q)
	{
		while(l>it.l) l--,add(l);
		while(r>it.r) del(r),r--;
		while(r<it.r) r++,add(r);
		while(l<it.l) del(l),l++;
		res[it.id]=ans;
	}
	REP(i,1,m) cout<<res[i]<<"\n";
	//l-r-r+l+
}
//tot:all color
//颜色num增加需要满足：num没有被全部修改,未修改的地方没有num+1。
//颜色num减少需要满足:num被全部修改，未修改的地方有num+1
//其余不变。
//delta=n
//li>=ql&&-ri>=-qr delta--
//x in [l,r]
