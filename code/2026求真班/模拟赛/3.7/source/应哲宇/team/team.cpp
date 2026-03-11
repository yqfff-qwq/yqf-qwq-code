#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],ans;
int erfen(int x){
	int l=0,r=n,ans=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<x){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
signed main()
{
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans=max(ans,i-erfen(max(1LL,a[i]-5)));
	}
	cout<<ans<<endl;
	return 0;
}
