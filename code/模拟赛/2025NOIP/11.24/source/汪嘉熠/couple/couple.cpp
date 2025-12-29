#include<bits/stdc++.h>
using namespace std;
int const N=505;
int r[N];
void solve(){
	memset(r,0,sizeof r);
	int n,R=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int ri,ci;
		cin>>ci>>ri;
		r[ci]=max(r[ci],ri);
		R=max(R,ci);
	}
	int total=0;
	for(int i=0;i<=500;i++)
		total+=r[i];
	bitset<N*N>dp;
	dp[0]=1;
	int ans=0x3f3f3f3f;
	for(int i=0;i<R;i++)
		for(int j=total;j>=r[i];j--)
			if(dp[j-r[i]]){
				dp[j]=1;
				int tmp=max(j*2-r[i]+i,(total-j)*2-r[R]+R);
				ans=min(ans,tmp);
			}
	cout<<ans<<'\n';
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	int T; cin>>T;
	while(T--)solve();
	return 0;
}