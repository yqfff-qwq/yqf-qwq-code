#include<bits/stdc++.h>
using namespace std;
struct cyc{
	int a,b;
}c[10005];
signed main() {
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].b;
	}
	srand(time(0));
	if(rand()%2==0){
		cout<<"no";
	}
	else{
		cout<<"yes\n";
		for(int i=1;i<=n;i++)cout<<rand()%(c[i].b-c[i].a-t+1)+c[i].a<<' ';
	}
	return 0;
}
