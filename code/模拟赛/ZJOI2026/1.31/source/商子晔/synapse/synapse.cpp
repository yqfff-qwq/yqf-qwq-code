#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int l,n;
int a[2000001];
int x[2000010];
signed main(){
	freopen("synapse.in","r",stdin);
	freopen("synapse.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>l>>n;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(x,0,sizeof(x));
		x[0]=0;
		x[1]=(a[1]+a[2])/2;
		x[n]=l;
		int minx=1000000;
		for(int i=1;i<n;i++){
			if(n>=3&&i==n-1){
				x[i]=(a[i]+l)/2;
				continue;
			}
			if(a[i]+minx>=a[i+1]){
				x[i]=(a[i]+a[i+1])/2;
			}else if((a[i]+a[i+1])/2>a[i]+minx){
				x[i]=(a[i]+a[i+1])/2;
			}else{
				x[i]=a[i]+minx-1;
			}
			minx=min(x[i]-x[i-1],minx);
		}
		for(int i=0;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
