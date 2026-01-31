#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int l,n,a[N];
void sol(){
	cin >>l>>n;
	for(int i=1;i<=n;i++)cin >>a[i];
	for(int i=0;i<=n;i++)cout<<i*2<<" ";cout<<"\n";
}
signed main(){
	freopen("synapse.in","r",stdin);
	freopen("synapse.out","w",stdout);	
	int t;
	cin >>t;
	while(t--)sol();
	return 0;
}
