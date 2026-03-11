#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int x,y;
signed main(){
	freopen("berry.in","r",stdin);
	freopen("berry.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>x>>y;
		if(abs(x-y)<=1){
			cout<<"No\n";
			continue;
		}
		else{
			cout<<"Yes\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
