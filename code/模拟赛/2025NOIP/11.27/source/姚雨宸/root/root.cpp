#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,ans;
int ask(int l,int r){return (r+n-1)/n-(l+n-2)/n;}
void solve()
{
	cin>>n>>m;ans=0;
	for(int i=62,r=0;i>=0;i--)
	{
		if((n-1>>i)&1)r+=(1ll<<i);
		if(m+1>=(1ll<<i))
		{
			ans+=ask(r,r+(1ll<<i)-1);
			m-=1ll<<i;r^=1ll<<i;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;while(T--)solve();
	return 0;
}
