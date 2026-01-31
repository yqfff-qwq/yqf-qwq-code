#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,a[1000];
signed main(){
	freopen("starlight.in","r",stdin);
	freopen("starlight.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				for(int x=0;x<=1000;x++){
					bool f=0;
					for(int k=1;k<=n;k++){
//						cout<<(a[k]^x)<<' '<<(a[i]^x)<<' '<<(a[k]^x)<<' '<<(a[j]^x)<<endl;
						if(((a[k]^x)<=(a[i]^x))&&((a[k]^x)<(a[j]^x))) continue;
						if(((a[k]^x)>(a[i]^x))&&((a[k]^x)>=(a[j]^x))) continue;
						f=1;break;
					}
					if(f==0) {
//						cout<<i<<' '<<j<<' '<<x<<endl;
						ans++;
						break;
					}
				}
			}
		cout<<ans<<endl;
	}

} 
