#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,a[1000001];
int a1[1000001];
signed main(){
	freopen("starlight.in","r",stdin);
	freopen("starlight.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a1[i]=a[i];
			maxn=max(maxn,a[i]);
		}
		sort(a1+1,a1+n+1);
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int f=1;
				for(int k=1;k<=n;k++){
					for(int q=1;q<=n;q++){
						int x=a[i]^a1[q];
						int y=a[j]^a1[q];
						int z=a[k]^a1[q];
						if(!(z<=x||z>=y)){
							f=0;
							break;
						}
					}
					if(!f){
						break;
					}
				}
				if(f){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
