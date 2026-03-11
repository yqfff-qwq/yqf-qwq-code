#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a,b;
signed main(){
	freopen("berry.in","r",stdin);
	freopen("berry.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a<b)swap(a,b);
		if(a>=b+2)cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';
	}
	return 0;
}
