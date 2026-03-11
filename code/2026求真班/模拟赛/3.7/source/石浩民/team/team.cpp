#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
signed main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int miku=0;
	for(int i=1;i<=n;i++){
		int k=lower_bound(a+1,a+1+n,a[i]-5)-a;
		miku=max(miku,i-k+1);
	}
	cout<<miku;
	return 0;
}
/*
I can't wait
no mistake
I'm in love
like a drug
pick me up
these feelings will never leave my heart
love me
love me
ah aH Ah AH
*/
