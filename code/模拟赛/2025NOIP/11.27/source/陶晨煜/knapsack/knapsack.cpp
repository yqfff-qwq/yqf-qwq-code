#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define umap unordered_map
#define pqueue priority_queue
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=5e5+10;
int v[maxn],m[maxn];
map<int,int> mp;
umap<int,int> dy;
int fdy[maxn];
vector<int> g[maxn];
int dp[maxn*2];
struct st
{
	int v,m,id;
	double b;
}a[maxn];
bool cmp(st a,st b)
{
	return a.b>b.b;
}
signed main()
{
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	Ios();
	int n,M;
	cin>>n>>M;
	REP(i,1,n) cin>>v[i]>>m[i],mp[m[i]]=1;
	int tot=0;
	for(auto it:mp) dy[it.fir]=++tot,fdy[tot]=it.fir;
	//tot<=log2(1e12)
	REP(i,1,n) g[dy[m[i]]].pb(v[i]);
	REP(i,1,tot) sort(all(g[i])),reverse(all(g[i]));
	if(tot==1)
	{
		int cs=M/m[1],ans=0;
		for(int i=0;i<cs&&i<g[1].size();i++) ans+=g[1][i];
		cout<<ans<<"\n";
		return 0;
	}
	if(tot==2)
	{
		vector<int> tmp;
		for(auto it:mp) tmp.pb(it.fir);
		int a=tmp[0],b=tmp[1],ida=dy[a],idb=dy[b];
		int cs1=M/a;
		vector<int> q(n+10,0);
		for(int i=0;i<g[idb].size();i++)
		q[i+1]=q[i]+g[idb][i];
		int tot=0,mx=q[min(M/b,(int)g[idb].size()-1)];
		for(int i=0;i<cs1&&i<g[ida].size();i++)
		{
			tot+=g[ida][i];
			int rest=M-(i+1)*a;
			int cs2=min(rest/b,(int)g[idb].size()-1);
			int ans=q[cs2]+tot;
			mx=max(mx,ans);
		}
		cout<<mx<<"\n";
		return 0;
	}
	if(n*M>1e8)
	{
		REP(i,1,n) a[i]={v[i],m[i],i,v[i]*1.0/m[i]*1.0};
		//REP(i,1,n) cerr<<a[i].b<<"\n";
		sort(a+1,a+1+n,cmp);
		int ans=0;
		vector<bool> tag(n+10);
		int nn=n;
		REP(i,1,n)
		{
			if(M>=a[i].m) M-=a[i].m,ans+=a[i].v,tag[a[i].id]=1,nn--;
			if(M<=1e6&&nn*M<=1e8) break;
		}
		vector<pii> vv;
		REP(i,1,n) if(!tag[i]) vv.pb({v[i],m[i]});
		for(auto it:vv)
		for(int j=M;j>=it.sec;j--)
		dp[j]=max(dp[j],dp[j-it.sec]+it.fir);
		cout<<ans+dp[M]<<"\n";
		return 0;
	}
	REP(i,1,tot)
	for(auto it:g[i])
	for(int j=M;j>=fdy[i];j--)
	dp[j]=max(dp[j],dp[j-fdy[i]]+it);
	cout<<dp[M];
}
//merge->diff number < log2(1e12)=39
//xymsb xymsb xymsb xymsb xymsb xymsb
//1e12 /2 /2
//log dp or tanxin
