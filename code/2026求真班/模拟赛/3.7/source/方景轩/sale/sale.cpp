#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 y_1
const int N=1e4+1;
int n,ans;
int a[N];
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=3){
		for(int i=1;i<=n;i++) ans|=a[i];
	}
	else{
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
