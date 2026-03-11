#include<bits/stdc++.h>
#define LL long long
using namespace std;
void solve(){
	LL x,y; cin>>x>>y;
	cout<<(abs(x-y)<=1?"No":"Yes")<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("berry.in","r",stdin);
	freopen("berry.out","w",stdout);
	int T; cin>>T;
	srand(0);
	while(T--)solve();
	return 0;
}
