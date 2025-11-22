#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int f(int l,int r,int x){
	if(l==r)return abs(a[l]-x);
	return abs(a[r]-f(l,r-1,x));
}
int main(){
	freopen("reflection.in","r",stdin);
	freopen("reflection.out","w",stdout);
	int n,q,c;
	cin>>n>>q>>c;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	int ans=0;
	while(q--){
		int l,r,x;
		cin>>l>>r>>x;
		l^=(c*ans),r^=(c*ans),x^=(c*ans);
		ans=f(l,r,x);
		cout<<ans<<"\n";
	}
} 
