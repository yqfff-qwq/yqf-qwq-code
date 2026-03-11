#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void solve();
signed main(){
	ios::sync_with_stdio(0);
	freopen("2w3123.out","w",stdout);

	int T=1;
	// cin>>T;
	for(int _=1;_<=T;_++){
		solve();
	}
	return 0;
}
inline void solve(){
	int n=2e9,ans=0;
	for(int i=1;;i++){
		ans=ans*10+9;
		if(ans>=n){
			break;
		}
		cout<<ans<<",";
	}
	return;
}

