#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define ll long long
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5010;
const int mod=998244353;
int a[maxn],n;
map<vector<int>,int> mp;
int miss=0;
int dfs(vector<int> g,int cs)
{
	//sort(g.begin(),g.end());
	if(cs==0) return 1;
	if(mp.count(g))
	{
		return mp[g];
	}
	int tot=0;
	REP(i,0,n-1)
	if(g[i]!=0)
	REP(j,i+1,n-1)
	if(g[j]!=0)
	{
		g[i]--,g[j]--;
		tot+=dfs(g,cs-2);
		tot%=mod;
		g[i]++,g[j]++;
	}
	tot%=mod;
	return mp[g]=tot;
}
signed main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	Ios();
	cin>>n;
	int cnt=0;
	REP(i,1,n) cin>>a[i],cnt+=a[i];
	if(cnt&1)
	{
		cout<<0;
		return 0;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n<=5&&cnt<=8)
	{
		vector<int> g;
		REP(i,1,n)g.pb(a[i]);
		cout<<dfs(g,cnt);
		return 0;
	}
	if(n==2)
	{
		if(a[1]==a[2]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(cnt==n)
	{
		int ans=1;
		while(n)
		{
			int mul=n*(n-1)/2%mod;
			ans*=mul;ans%=mod;
			n-=2;
		}
		cout<<ans<<"\n";
		return 0;
	}
	vector<int> g;
	REP(i,1,n)g.pb(a[i]);
	cout<<dfs(g,cnt);
}
