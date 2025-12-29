//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=1e3+10;
int n,a[N],sm[N],ans=1e18;set<int>s;
inline void solve(){
	cin>>n;
	rep(i,1,n) cin>>a[i],sm[i]=sm[i-1]+a[i];
	per(j,n,1){
		per(i,j,1){
			int k=sm[j]-sm[i-1];
			auto it=s.lower_bound(k);
			if (it!=s.end()) ans=min(ans,*it-k);
			if (it!=s.begin()) --it,ans=min(ans,k-*it);
		}
		rep(i,j,n) s.insert(sm[i]-sm[j-1]);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}
