#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,mod;
int a[1000001];
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>mod;
		n*=2;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int be;
		for(int i=1;i<=n;i++){
			if(a[i]){
				be=i;
				break;
			}
		}
		int ans=mod+1;
		for(int i=be;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=min(ans,(a[i]+a[j])%mod);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
