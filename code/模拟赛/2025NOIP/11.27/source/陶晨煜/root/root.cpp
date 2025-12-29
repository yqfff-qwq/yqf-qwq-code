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
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
ll n,m;
bool check(ll x)
{
	ll u=x*n+1;
	return (u^(n-1))<=m;
}
void solve()
{
	cin>>n>>m;
	ll R=(m+n-2)/n+3;//[0,R]
	ll ck=min(R,1000ll);
	ll ans=R-ck;
	for(ll i=R-ck;i<=R;i++)
	if(check(i)) ans++;
	cout<<ans<<"\n";
}
int main()
{
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	Ios();
	int t;
	cin>>t;
	while(t--) solve();
}
//i<=m+n-1 llmax=9e18
