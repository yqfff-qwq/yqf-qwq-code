#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("summit.in","r",stdin);
	freopen("summit.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,l,r;
		cin>>n>>l>>r;
		vector<int>a(n+1),b(n+1);
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		cin>>b[i];
		for(int k=l;k<=r;k++){
			int ans=INT_MAX;
			vector<int>p(k),q(k);
			if(k==1){
				for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
				ans=min(ans,a[i]+b[j]);
			}
			else if(k==2){
				for(int i1=1;i1<=n;i1++)
				for(int i2=i1+1;i2<=n;i2++)
				for(int j1=i1;j1<=n;j1++)
				for(int j2=j1+1;j2<=n;j2++)
				if(i2<j2)
				ans=min(ans,a[i1]+a[i2]+b[j1]+b[j2]);
			}
			else ans=0;
			cout<<ans<<(k==r?"\n":" ");
		}
	}
} 
