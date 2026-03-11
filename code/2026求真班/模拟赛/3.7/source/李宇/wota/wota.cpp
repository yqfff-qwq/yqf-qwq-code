#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool pd9(int x){
	while(x){
		if(x%10!=9) return 0;
		x/=10;
	}
	return 1;
}
bool pd(int x){
	while(x){
		if(x<10&&x!=1) return 0;
		if(x>=10&&x%10!=0) return 0;
		x/=10;
	}
	return 1;
}
signed main() {
	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	cin>>n;
	if(n<=5) {
		for(int nn=1;nn<=500;nn++) {
			int mx=0,ans=0;
			for(int i=1;i<=nn;i++){
				for(int j=i+1;j<=nn;j++){
					if(i==j) continue;
					int xx=i+j,tt=0;
					while(xx){
						if(xx%10==9) tt++,xx/=10;
						else break;
					}
					mx=max(mx,tt);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j) continue;
					int xx=i+j,tt=0;
					while(xx){
						if(xx%10==9) tt++,xx/=10;
						else break;
					}
					if(tt==mx) ans++;
				}
			}
			if(nn==n){
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	if(pd9(n)) n--;
	int ans=0,n5=0;
	for(int i=5;;i*=10){
		if(n>=i&&n<(i*10)){
			n5=i;
			break;
		}
	}
	int sc=n-n5+1;
	int kk=sc/(n5/5*10);
	for(int i=1;i<=kk;i++) ans+=i*(n5/5*10);
	sc=sc%(n5/5*10);
	ans+=sc*(kk+1);
	if(pd(n)) ans--;
	cout<<ans;
	return 0;
}
