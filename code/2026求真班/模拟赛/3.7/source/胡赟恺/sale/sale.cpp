#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a[505];
int k[66];
int p[66];
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>n;
	p[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				ans=max(ans,a[i]|a[j]|a[k]);
			}
		}
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
