#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 y_1
const int N=2e5+10;
int n;
int a[N],b[N];
signed main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	b[1]=a[1];
	int ans=0;
	for(int i=2;i<=n;i++){
		b[++r]=a[i];
		while(b[r]-b[l]>5) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*

8
1 2 5 8 8 8 8 8
cout:6

*/ 
