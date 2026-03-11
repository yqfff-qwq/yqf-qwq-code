#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,x,y;
signed main(){
	freopen("berry.in","r",stdin);
	freopen("berry.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(abs(x-y)<=1) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
