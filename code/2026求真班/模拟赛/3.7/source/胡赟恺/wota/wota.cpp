#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans;
signed main(){
	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	cin>>n;
	if(n<=4){
		cout<<n*(n-1)/2;
		return 0;
	}
	int p=n+n-1;
	int rk=0;
	for(int i=1;i<=10;i++){
		rk=rk*10+9;
		if(rk>p){
			break;
		}
	}
	rk/=10;
	for(int i=1;i<=9;i++){
		int rr=rk*i+i-1;
		if(p>=rr){
			ans+=min(n-rr/2,rr/2);
		}
		else break;
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
