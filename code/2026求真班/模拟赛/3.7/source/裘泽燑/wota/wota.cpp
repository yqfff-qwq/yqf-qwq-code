#include<bits/stdc++.h>
#define int long long
using namespace std;
int f(int n){
	int m=1;
	while(1){
		int nm=m*10;
		int fn=nm-1;
		if(fn>2*n)break;
		m=nm;
	}
	return m;
}
int c(int n,int S){
	if(S<3)return 0;
	int l=max(1LL,S-n);
	int r=min((S-1)/2,n-1LL);
	return l>r?0:r-l+1;
}
int t(int n,int m){
	int F=m-1;
	int sum=0,cnt=0;
	while(1){
		int S=F+cnt*m;
		if(S>2*n-1)break;
		sum+=c(n,S);
		cnt++;
	}
	return sum;
}
int n;
signed main(){
	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	cin>>n;
	if(n<2){
		cout<<0;
		return 0;
	}
	int m=f(n);
	int ans=t(n,m);
	cout<<ans;
	return 0;
}
