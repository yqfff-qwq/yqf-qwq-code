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
	int n=2e3-2,m=2e3,k=8,t=1e9;
	cout<<n<<' '<<m<<' '<<k<<' '<<t<<'\n';
	rep(i,1,n){
		rep(j,1,m)
			if (i==1 && j==1) cout<<'S';
			else if (i==n && j==m) cout<<'T';
			else if (rnd()%5==0) cout<<'.';
			else cout<<'#';
		cout<<'\n';
	}
}
signed main(){
	freopen("maze.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}