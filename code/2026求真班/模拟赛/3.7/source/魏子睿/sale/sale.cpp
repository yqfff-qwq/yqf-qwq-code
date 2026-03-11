#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[505], cnt[70];
signed main()
{
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	if(n<=3)
		for(int i=1;i<=n;i++) ans|=a[i];
	else
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					ans=max(ans, a[i]|a[j]|a[k]);
	cout<<ans;
	return 0;
}
/*
3 
2 1 3

3
3 1 4

1
1

4
7 7 1 1
*/
