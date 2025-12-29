//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int X[55],Y[55],ans;
inline void solve(){
	int n,w,h;cin>>n>>w>>h;
	rep(i,0,n-1) cin>>X[i]>>Y[i];
	rep(S,0,(1<<n)-1){
		vector<int>A,B;
		A.push_back(0),A.push_back(w);
		B.push_back(0),B.push_back(h);
		rep(i,0,n-1) if (S>>i&1) A.push_back(X[i]);else B.push_back(Y[i]);
		sort(A.begin(),A.end()),sort(B.begin(),B.end());
		int sz1=A.size(),sz2=B.size(),mx1=0,mx2=0;
		rep(i,1,sz1-1) mx1=max(mx1,A[i]-A[i-1]);
		rep(i,1,sz2-1) mx2=max(mx2,B[i]-B[i-1]);
		// if ((mx1+mx2)*2==96){
		// 	cout<<S<<" :\n";
		// 	rep(i,0,n-1) cout<<(S>>i&1);
		// 	cout<<'\n';
		// 	for (auto i:A) cout<<i<<' ';
		// 	cout<<'\n';
		// 	for (auto i:B) cout<<i<<' ';
		// 	cout<<'\n';
		// }
		ans=max(ans,(mx1+mx2)*2);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("perimeter.in","r",stdin);
	freopen("perimeter_.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}