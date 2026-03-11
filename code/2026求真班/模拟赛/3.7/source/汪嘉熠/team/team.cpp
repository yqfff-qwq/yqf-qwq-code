#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int n,w[N];
int find(int x){ // the first one which bigger than x
	int l=1,r=n+1;
	while(l<r){
		int mid=l+r>>1;
		if(w[mid]<=x)l=mid+1;
		else r=mid;
	}
	return l;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	sort(w+1,w+n+1);
	w[n+1]=INT_MAX;
	int what_the_dog_doing=0;
	for(int i=1;i<=n;i++){
		int id=find(w[i]+5);
		what_the_dog_doing=max(what_the_dog_doing,id-i);
	}
	cout<<what_the_dog_doing;
	return 0;
}
