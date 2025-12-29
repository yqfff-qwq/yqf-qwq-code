//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=3e5+10;
int n,a[N],b[N],c[N];
inline void solve(){
	cin>>n;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) cin>>b[i];
	sort(b+1,b+n+1);
	vector<int>Max,Min;
	if (a[1]<a[2]) Min.push_back(1);
	else Max.push_back(1);
	if (a[n]>a[n-1]) Max.push_back(n);
	else Min.push_back(n);
	rep(i,2,n-1)
		if (a[i]>a[i-1] && a[i]>a[i+1]) Max.push_back(i);
		else if (a[i]<a[i-1] && a[i]<a[i+1]) Min.push_back(i);
	int ans=0,sz1=Min.size(),sz2=Max.size();
	rep(i,1,sz1) ans-=2*b[i];
	rep(i,n-sz2+1,n) ans+=2*b[i];
	if (a[1]<a[2]) ans+=b[sz1--];
	else ans-=b[n-sz2+1],--sz2;
	if (a[n]<a[n-1]) ans+=b[sz1--];
	else ans-=b[n-sz2+1],--sz2;
	int ct1=0,ct2=n+1;
	for (auto i:Max){
		if (i==1 || i==n) continue;
		c[i]=b[--ct2];
	}
	for (auto i:Max)
		if (i==1 || i==n) c[i]=b[--ct2];
	for (auto i:Min){
		if (i==1 || i==n) continue;
		c[i]=b[++ct1];
	}
	for (auto i:Min)
		if (i==1 || i==n) c[i]=b[++ct1];
	rep(i,2,n-1)
		if (a[i]>a[i-1] && a[i]>a[i+1]);
		else if (a[i]<a[i-1] && a[i]<a[i+1]);
		else{
			if (a[i-1]>a[i]) c[i]=b[--ct2];
			else c[i]=b[++ct1];
		}
	cout<<ans<<'\n';
	rep(i,1,n) cout<<c[i]<<' ';
	cout<<'\n';
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}
