#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200001];
signed main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,ans=0;
	for(int i=1;i<=n;i++){
		while(a[i]-a[l]>5)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
