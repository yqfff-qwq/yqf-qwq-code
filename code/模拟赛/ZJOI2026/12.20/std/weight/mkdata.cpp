//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
mt19937 rnd(time(0));
inline void solve(){
	int n=3e5;
	cout<<n<<'\n';
	rep(i,2,n) cout<<i/2<<' '<<i<<'\n';
	rep(i,1,n) cout<<rnd()<<' ';
	cout<<'\n'<<rnd()<<'\n';
}
signed main(){
	freopen("weight.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}