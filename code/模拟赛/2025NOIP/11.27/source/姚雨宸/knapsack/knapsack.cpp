#include <bits/stdc++.h>
#define int long long
using namespace std;
struct xxx{int v,m;}a[500005];
int n,M,X,m[45],t[45],ans;set<int> S[45];
bool cmp(xxx x,xxx y){return x.m<y.m;}
signed main()
{
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>M;
	for(int i=1;i<=n;i++)cin>>a[i].v>>a[i].m;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].m!=a[i-1].m)m[++X]=a[i].m;
		S[X].insert(a[i].v);
	}
	for(int i=X;i>=1;i--){t[i]=min((int)S[i].size(),M/m[i]);M-=m[i]*t[i];}
//	for(int i=1;i<=X;i++)cout<<m[i]<<" "<<t[i]<<"\n";
//	for(auto i:S[7])cout<<i<<" ";cout<<"\n";
	for(int i=1;i<X;i++)
	{
		auto it=prev(S[i].end());int T=t[i];
		while(t[i]--){ans+=*it;it--;}
		int I=m[i+1]/m[i],x=S[i].size()-T;x/=I;
//		cout<<i<<" "<<m[i]<<": "<<I<<" "<<S[i].size()<<" "<<T<<" "<<x<<"\n";
		for(int j=1;j<=x;j++)
		{
			int s=0;
			for(int k=1;k<=I;k++){s+=*it;it--;}
//			cout<<s<<" ";
			S[i+1].insert(s);
		}
//		cout<<"\n";
//		cout<<ans<<"\n";
	}
//	cout<<m[7]<<"\n";
//	for(auto i:S[7])cout<<i<<" ";cout<<"\n";
	auto it=prev(S[X].end());
	while(t[X]--){ans+=*it;it--;}
	cout<<ans;
	return 0;
}
