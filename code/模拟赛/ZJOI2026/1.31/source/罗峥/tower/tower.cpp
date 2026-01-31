#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int t,n,m,a[N],vis[N],ans;
bool check(int x)
{
	for(int i=1;i<=n*2;i++) vis[i]=0;
	for(int i=1;i<=n*2;i++)
	{
		if(vis[i]) continue;
		int tmp=i;
		for(int j=i+1;j<=n*2;j++)
		{
			if((a[i]+a[j])%m<=x&&vis[j]==0) tmp=j;
			if((a[i]+a[j])%m==x&&vis[j]==0) break;
		}
		if(tmp==i) return 0;
		vis[i]=vis[tmp]=1;
	}
	return 1;
}
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n*2;i++) cin>>a[i];
		sort(a+1,a+n*2+1);
		int l=0,r=m-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
			{
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	return 0;
}
