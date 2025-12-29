//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define all(x) (x).begin(),(x).end()
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
mt19937_64 rnd(time(0));
inline void solve(){
	int b=1145,a=5514,n=3e6;
	cout<<b<<' '<<a<<' '<<n<<'\n';
	rep(i,1,b) cout<<"1";
	rep(i,1,n-2*b) cout<<rnd()%2;
	rep(i,1,b) cout<<"1";
	cout<<'\n';
}
signed main(){
	freopen("toy.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}