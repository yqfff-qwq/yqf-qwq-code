#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int T;
int l,n;
int a[N],x[N];
signed main(){
	freopen("synapse.in","r",stdin);
	freopen("synapse.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>l>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		x[0]=0,x[n]=l;
		for(int i=1;i<n;i++){
			x[i]=a[i];
		}
		for(int i=0;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
