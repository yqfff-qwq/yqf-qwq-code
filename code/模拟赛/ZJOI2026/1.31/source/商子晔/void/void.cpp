#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,m;
int x,y;
int du[10000010];
signed main(){
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(du,0,sizeof(du));
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			du[x]^=1;
			du[y]^=1;
		}
		int f=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(du[i]==du[j]){
					cout<<i<<" "<<j<<"\n";
					f=1;
					break;
				}
			}
			if(f) break;
		}
	}
	
	return 0;
}
