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
namespace BAOLI
{
ll solve(ll n,ll m)
{
	ll ans=0,u;
	for(u=1;u-(n-1)<=m;u+=n)
	if((u^(n-1))<=m) ans++;
	return ans;
}
}
namespace SDT
{
	bool check(ll x,ll n,ll m)
{
	ll u=x*n+1;
	return (u^(n-1))<=m;
}
ll solve(ll n,ll m)
{
	ll R=(m+n-2)/n+3;//[0,R]
	ll ck=min(R,10ll);
	ll ans=R-ck;
	for(ll i=R-ck;i<=R;i++)
	if(check(i,n,m)) ans++;
	return ans;
}
}
ll RAND()
{
	return rand()*1ll*RAND_MAX*1ll*RAND_MAX+rand()*1ll*RAND_MAX+rand()*1ll;
}
int main()
{
	ll cs=0;
	while(++cs)
	{
		if(cs%10000000==0) cout<<"Accpted #"<<cs<<"!\n";
		ll n=RAND()%(ll)1e15+2;
		ll m=n*(rand()%100)*1ll;
		ll u=BAOLI::solve(n,m);
		ll v=SDT::solve(n,m);
		if(u!=v)
		{
			cout<<"Wrong answer on test "<<cs<<"!\n";
			cout<<u<<" "<<v<<"\n";
			cout<<n<<" "<<m<<"\n";
		}
	}
}
