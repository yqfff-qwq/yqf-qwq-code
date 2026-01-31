#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=1e6+1;
int T,n;
int a[N];
signed main(){
	freopen("starlight.in","r",stdin);
	freopen("starlight.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		int sum=0;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int f=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=1;x<=9;x++){
					for(int k=1;k<=n;k++){
						if(a[k]^x<=a[i]^x||a[k]^x>=a[j]^x){
							f=1;
						}
						else{
							f=0;
							break;
						}
					}
					if(!f) break;
				}
				if(f) sum++;
				f=1;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
