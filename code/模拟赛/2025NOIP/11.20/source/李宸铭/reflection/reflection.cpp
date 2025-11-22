#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,c; 
int a[200025],cc[200025];
int f(int l,int r,int x)
{
	if(l==r) return abs(a[l]-x);
	else if(l<r) return abs(a[r]-f(l,r-1,x));
}
signed main()
{
	freopen("reflection.in","r",stdin);
	freopen("reflection.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>q>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
//	if(n<=10000)
	{
		while(q--)
		{
			int l,r,x;
			cin>>l>>r>>x;
			cout<<f(l,r,x)<<'\n';
		}
	}
//	else
//	{
//		cc[1]=a[1];
//		for(int i=2;i<=n;i++) cc[i]=abs(a[i]-cc[i-1]);
//		while(q--)
//		{
//			int l,r,x;
//			cin>>l>>r>>x;
//			if(l==1)
//			{
//				int y=abs(a[l]-x);
//				if(r%2==0) cout<<abs(cc[r]-y)<<'\n';
//				else cout<<cc[r]+x<<'\n';
//			}
//			else
//			{
//				
//			}
//		}
//	}
	
	return 0;
}
