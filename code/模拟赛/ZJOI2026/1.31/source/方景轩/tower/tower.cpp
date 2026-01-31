#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10;
int T;
int a[N],ans[N];
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		sort(a+1,a+2*n+1);
		for(int i=1;i<=n;i++){
			int minn=0x3f3f3f3f;
			int x;
			if(a[i]==-1) continue;
			for(int j=1;j<=2*n;j++){
				if(i==j) continue;
				if(a[j]==-1) continue;
				int s=(a[i]+a[j])%m;
				if(s<minn){
					minn=a[j];
					x=j;
				}
			}
			ans[i]=a[i];
			ans[i+n]=a[x];
			a[i]=a[x]=-1;
		}
		int maxx=-1e9;
		for(int i=1;i<=n;i++){
			int sum=(ans[i]+ans[i+n])%m;
			maxx=max(maxx,sum);
		}
		cout<<maxx<<endl;
	}
	return 0;
}
