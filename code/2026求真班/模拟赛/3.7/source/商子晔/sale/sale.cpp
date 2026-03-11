#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10005],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		for(int i=1;i<=n;i++) ans|=a[i];
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]|a[j]|a[k]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
