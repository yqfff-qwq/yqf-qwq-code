#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int ans=0;
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	a[n+1]=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		int l=1,r=n+1,mid;
		while(l<r)
		{
			mid=l+r>>1;
			if(a[mid]<=a[i]+5) l=mid+1;
			else r=mid;
		
		}
		ans=max(ans,l-i);
	
	}
	cout<<ans;

/*	
	
	
	for(int i=1;i<=n-1;i++)
	{
		res[i]=a[i+1]-a[i];
	}
	int k=0,s=0;
	for (int i=1;i<=n-1;i++)
	{	
		k+=res[i];
		s++;			
		if(k>5)
		{
			s=0;
			k=0;
		}
		ans=max(ans,s+1);
	}		
	cout<<ans;
	return 0;
*/	
}


//1 2 10 12 15 17
//1 8 2  3  2


