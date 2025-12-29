#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct Query{
	LL n,m;
};vector<Query>q;
namespace case1{
	void solve(){
		for(auto it:q){
			LL ans=0;
			for(LL i=0;i<=it.m;i++){
				LL tmp=(i^(it.n-1))%it.n;
				if(tmp==1)ans++;
			}
			cout<<ans<<'\n';
		}
		return;
	}
}
namespace case2{
	void solve(){
		for(auto it:q){
			LL ans=0;
			for(LL i=0;i<=2*it.m/it.n;i++){
				LL tmp=(1+i*it.n)^(it.n-1);
				if(tmp<=it.m)
					ans++;
			}
			cout<<ans<<'\n';
		}
		return;
	}
}
namespace space{
	void solve(){
		for(auto it:q){
			LL l=0,r=2*it.m/it.n;
			while(l<r){
				LL mid=l+r+1>>1;
				LL tmp=(1+mid*it.n)^(it.n-1);
				if(tmp<=it.m)l=mid;
				else r=mid-1;
			}
			cout<<l+1<<'\n';
		}
		return;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	int T; cin>>T;
	LL cnt1=0,cnt2=0;
	while(T--){
		LL n,m; cin>>n>>m;
		q.emplace_back(Query{n,m});
		cnt1+=m;
		cnt2+=m/n;
	}
	if(cnt1<=1e5)case1::solve();
	else if(cnt2<=1e5)case2::solve();
	else space::solve();
	return 0;
}
