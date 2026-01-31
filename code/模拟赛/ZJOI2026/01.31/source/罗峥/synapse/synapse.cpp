#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int t,n,l,a[N],ans[N];
int main()
{
//	freopen("synapse.in","r",stdin);
//	freopen("synapse.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>l>>n;
		double tmp=l/n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ans[i]=tmp*i;
		}
		ans[n]=l;
		for(int i=1;i<n;i++)
		{
			if(ans[i]<a[i]) ans[i]=a[i];
			if(ans[i]>a[i+1]) ans[i]=a[i+1];
		}
		for(int i=0;i<=n;i++) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
