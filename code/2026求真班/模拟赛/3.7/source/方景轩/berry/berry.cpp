#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 y_1
int x,y;
signed main(){
	freopen("berry.in","r",stdin);
	freopen("berry.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(abs(x-y)<=1) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
