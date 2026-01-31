#include<iostream>
using namespace std;
int T;
int n,m;
int a[510];
int b[510];
int ans=1e9;
void dfs(int i,int mx) {
	if(i>n*2) {
		ans=min(mx,ans);
		return;
	}
	if(mx>ans)
		return;
	int t;
	for(int j=1; j<=n*2; j++) {
		if(a[j]!=-1) {
			b[i]=a[j];
			a[j]=-1;
			if(i>n)
				t=max((b[i]+b[i-n])%m,mx);
			else
				t=0;
			dfs(i+1,t);
			a[j]=b[i];
		}
	}
	return;
}
int main() {
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1; i<=n*2; i++)
			cin>>a[i];
		ans=1e9;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
