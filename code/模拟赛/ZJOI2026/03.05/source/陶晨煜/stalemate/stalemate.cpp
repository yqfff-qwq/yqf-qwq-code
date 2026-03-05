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
const int mod=998244353;
const int maxn=101;
int h[maxn];
int x[maxn],y[maxn];
int deg[maxn];
int f[maxn];
int cnt[maxn];
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
signed main()
{
	freopen("stalemate.in","r",stdin);
	freopen("stalemate.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	REP(i,1,m) cin>>x[i]>>y[i];
	REP(sta,0,(1<<m)-1)
	{
		REP(i,1,n) deg[i]=0,f[i]=i;
		int cnt1=0; 
		REP(w,0,m-1)
		if((sta>>w)&1)
		{
			int u=x[w+1],v=y[w+1];
			f[find(u)]=find(v);
			deg[u]++,deg[v]++;
			cnt1++;
		}
		vector<int> v;
		REP(i,1,n) if(deg[i]) v.pb(i);
		if(cnt1!=v.size()) continue;
		bool fl=0;
		for(auto it1:v)
		for(auto it2:v)
		if(find(it1)!=find(it2))
		{
			fl=1;
			break;
		}
		if(fl) continue;
		int k=0;
		for(auto it:v) if(deg[it]>=2) k++;
		cnt[k]++;
	}
	while(q--)
	{
		REP(i,1,n) cin>>h[i];
		int ans=0;
		REP(i,1,n) ans+=h[i]*cnt[i],ans%=mod;
		cout<<ans<<"\n"; 
	}
}
