#include<bits/stdc++.h>
using namespace std;
signed main(){
 	freopen("berry.in","r",stdin);
	freopen("berry.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long t;
	cin>>t;
	while(t--){
		long long x,y;
		cin>>x>>y;
		if(abs(x-y)>=2)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
