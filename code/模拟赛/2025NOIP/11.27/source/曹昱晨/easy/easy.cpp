#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[200005];
signed main() {
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	long long t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		for(long long i=1;i<=n;i++)cin>>a[i];
		cout<<(k/__gcd(k,__gcd(a[1],a[2]))+1)%mod<<'\n';
	}
	return 0;
}
