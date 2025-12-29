#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int cnt=0;
		for(int i=0;i<=m;i++)
		if(((i^(n-1))%n)==1)
		cnt+=1;
		cout<<cnt<<"\n";
	}
} 
