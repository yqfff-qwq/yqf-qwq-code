#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull n[100005],m[100005];
signed main(){
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	ull t,ans,sum=0;
	cin>>t;
	for(ull i=1;i<=t;i++){
		cin>>n[i]>>m[i];
		sum+=m[i];
	}
	if(sum<=100000){
		for(ull j=1;j<=t;j++){
			ans=0;
			for(ull i=0;i<=m[j];i++){
				if((i^(n[j]-1))%n[j]==1)ans++;
			}
			cout<<ans<<'\n';
		}
	}
	else{
		for(ull j=1;j<=t;j++){
			ans=0;
			for(ull x=0;;x++){
				ull i=(1+x*n[j])^(n[j]-1);
				if(i<=m[j])ans++;
				else if(i>m[j]*2)break;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
