#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,res=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[mid]<=a[i]+5)
			{
				l=mid+1;
				res=mid;
			}
			else r=mid-1;
		}
		ans=max(ans,res-i+1);
	}
	cout<<ans;
	return 0;
}
