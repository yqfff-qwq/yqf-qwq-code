#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[505],ans,n;
bool b[501][61];
inline void qsort(int l,int r){
	int i=l,j=r,t=a[(l+r)/2];
	while(i<=j){
		while(a[i]<t)i++;
		while(a[j]>t)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				ans=max(ans,a[i]|a[j]|a[k]);
	cout<<ans;
	return 0;
}
