#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define int long long
#define pii pair<int,int>
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5e5+10;
const int mod=1e9+7;
vector<int> g[maxn];
string a,b;
int ca[maxn],cb[maxn];
int ans=0;
int dfs(int x,int fa)
{
	int c=ca[x];
	for(auto it:g[x])
	if(it!=fa)c^=dfs(it,x);
	
}
signed main()
{
	freopen("opt.in","r",stdin);
	freopen("opt.out","w",stdout);
	Ios();
	int n;
	cin>>n;
	REP(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	cin>>a>>b;
	a=" "+a,b=" "+b;
	int cnt1=0,cnt2=0;
	REP(i,1,n) cnt1+=(a[i]=='?'),cnt2+=(b[i]=='?');
	REP(sta1,0,(1<<cnt1)-1)
	REP(sta2,0,(1<<cnt2)-1)
	{
		int x=0;
		REP(i,1,n)
		if(a[i]=='?') ca[i]=(sta1>>x)&1,x++;
		else ca[i]=a[i]-'0';
		x=0;
		REP(i,1,n)
		if(b[i]=='?') cb[i]=(sta2>>x)&1,x++;
		else cb[i]=b[i]-'0';
		int diff=0;
		REP(i,1,n)
		diff+=(ca[i]!=cb[i]);
		if(diff%2) continue;
		
	}
}
//0 pts
