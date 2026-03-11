#include<bits/stdc++.h>
using namespace std;
long long ans,a[200005];
signed main(){
 	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long r=1;
	for(long long l=1;l<=n;l++){
		while(r+1<=n&&a[r+1]-a[l]<=5)r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
6
1 10 17 12 15 2
*/
