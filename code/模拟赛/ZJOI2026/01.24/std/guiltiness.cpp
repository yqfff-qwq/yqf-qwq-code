#include<bits/stdc++.h>
using namespace std;
int n,m,x[200003],y[200003];
long long ans;
int main(){
	freopen("guiltiness.in","r",stdin);
	freopen("guiltiness.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;i++)
		cin>>x[i];
	for(int i=1;i<m;i++)
		cin>>y[i];
	sort(x,x+n);reverse(x,x+n);n--;
	sort(y,y+m);reverse(y,y+m);m--;
	for(int i=0,j=0;i<n||j<m;)
		if(x[i]>y[j])
			ans+=(j+1ll)*x[i++];
		else
			ans+=(i+1ll)*y[j++];
	cout<<ans<<'\n';
}
