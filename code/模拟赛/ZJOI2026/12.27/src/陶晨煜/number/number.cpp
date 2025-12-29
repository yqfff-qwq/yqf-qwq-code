#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fir first
#define sec second
#define pii pair<int,int>
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
bool ban[12];
int num[21];
int dp[21];
int dfs(bool lim,bool zer,int pos)
{
	if(dp[pos]!=-1&&!lim&&!zer) return dp[pos];
	if(pos==0) return 1;
	int tot=0;
	for(int i=zer;i<=(lim?num[pos]:9);i++)
	if(!ban[i]) tot+=dfs(lim&&(i==num[pos]),0,pos-1);
	if(!lim&&!zer) dp[pos]=tot;
	return tot;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	REP(i,0,9) ban[i]=0;
	REP(i,0,20) dp[i]=-1;
	while(m--)
	{
		int x;
		cin>>x;
		ban[x]=1;
	}
	int tot=0;
	do num[++tot]=n%10,n/=10;
	while(n>0);
	int ans=dfs(1,1,tot);
	REP(i,1,tot-1) ans+=dfs(0,1,i);
	if(!ban[0]) ans++;
	cout<<ans<<"\n";
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Ios();
	int t;
	cin>>t;
	while(t--) solve();
}
