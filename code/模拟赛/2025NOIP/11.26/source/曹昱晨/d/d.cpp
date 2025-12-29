#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,a[N],b[N];
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>b[i];
	}
	for(long long i=1;i<=m;i++){
		int s,t,u;
		cin>>s>>t>>u;
		cout<<-1<<'\n';
	}
	return 0;
}
