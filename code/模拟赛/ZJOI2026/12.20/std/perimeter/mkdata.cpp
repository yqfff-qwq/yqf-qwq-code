//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
mt19937_64 rnd(time(0));
inline void solve(){
	int n=20,w=40,h=40;
	cout<<n<<' '<<w<<' '<<h<<'\n';
	rep(i,1,n) cout<<rnd()%(w+1)<<' '<<rnd()%(h+1)<<'\n';
}
signed main(){
	freopen("perimeter.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}