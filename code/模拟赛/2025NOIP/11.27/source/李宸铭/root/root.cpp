#include<bits/stdc++.h>
using namespace std;
int T,n,m;
void solve()
{
	cin>>n>>m;
	
	if(m<=100000)
	{
		int sum=0;
		for(int i=0;i<=m;i++) if((i^(n-1))%n==1) sum++; 
		cout<<sum<<'\n';
	}
	else cout<<m/n+1<<'\n';
}
signed main()
{
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--) solve();
	
	return 0;
}
