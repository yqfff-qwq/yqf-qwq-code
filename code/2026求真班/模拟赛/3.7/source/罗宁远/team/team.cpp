#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
int a[N],ans,n;
signed main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int lef=1,rig=1;
	while(lef<=rig&&rig<=n){
		ans=max(ans,rig-lef+1),rig++;
		while(a[rig]-a[lef]>5&&lef<rig)lef++;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
6
1 10 17 12 15 2

10
1337 1337 1337 1337 1337 1337 1337 1337 1337 1337

6
1 1000 10000 10 100 1000000000
*/ 
