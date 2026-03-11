#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
signed main(){
	freopen("berry.in","r",stdin);
	freopen("berry.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int d=abs(x-y);
		if(d<=1)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
