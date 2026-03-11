#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[505];
bool b[505][65];
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				ans=max(ans,a[i]|a[j]|a[k]);
			}
		}
	}
	cout<<ans;
	return 0;
}