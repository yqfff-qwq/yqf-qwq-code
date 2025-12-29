#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL const mod=998244353;
int const N=2e5+5;
LL A[N];
namespace case1{
	void solve(LL k){
		LL x,y; cin>>x>>y;
		LL d=__gcd(x,y);
		LL d0=__gcd(d,k);
		LL ans=k/d0+1;
		ans%=mod;
		cout<<ans<<'\n';
	}
}
namespace case2{
	void solve(int n,LL k){
		LL ans=0;
		
		return ans;
	}
}
void solve(){
	int n; LL k;
	cin>>n>>k;
	if(n==2){
		case1::solve(k);
		return;
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		if(i!=1&&__gcd(A[i],A[i-1])!=1)
			flag=false;
	}
	if(flag){
		case2::solve(n,k);
		return;
	}
	
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int T; cin>>T;
	while(T--)solve();
	return 0;
}
