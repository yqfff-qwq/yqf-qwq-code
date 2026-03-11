#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[505],ans;
bool cmp(int x,int y){return x>y;}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=3)
	{
		for(int i=1;i<=n;i++) ans|=a[i];
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					ans=max(ans,a[i]|a[j]|a[k]);
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
