#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
inline void solve();
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);

	int T=1;
	// cin>>T; do
	for(int _=1;_<=T;_++){
		solve();
	}
#if __LINE__ != 17
	cout<<"I AK IOI";
#endif
	return 0;
}
inline void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	queue<int> q;
	for(int i=1;i<=n;i++){
		for(;!q.empty()&&q.front()+5<a[i];){
			q.pop();
		}
		q.push(a[i]);
		int sz=q.size();
		ans=max(sz,ans);
	}
	cout<<ans;
	return;
}

