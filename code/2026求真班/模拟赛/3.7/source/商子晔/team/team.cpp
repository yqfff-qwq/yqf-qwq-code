#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int q[200010];
int ans;
int main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	q[r]=a[1];
	for(int i=2;i<=n;i++){
		q[++r]=a[i];
		while(q[r]-q[l]>5) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
