#include<bits/stdc++.h>
using namespace std;
struct cyc{
	int r,c;
};
int r[505];
bool dp[500005];
vector<cyc> v;
signed main(){
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(r,0,sizeof r);
		memset(dp,0,sizeof dp);
		dp[0]=1;
		int ans=INT_MAX;
		int n,R=0,sumr=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int rr,c;
			cin>>rr>>c;
			c*=2;
			r[rr]=max(r[rr],c);
			R=max(R,rr);
		}
		for(int i=0;i<=500;i++)sumr+=r[i];
		for(int i=1;i<=R;i++){
			for(int j=sumr;j>=r[i];j--){
				if(dp[j-r[i]]){
					dp[j]=1;
					ans=min(ans,max(j+i-r[i]/2,sumr-j+R-r[R]/2));
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
