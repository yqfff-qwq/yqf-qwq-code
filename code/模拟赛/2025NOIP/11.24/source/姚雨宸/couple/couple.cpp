#include <bits/stdc++.h>
//#define int long long
using namespace std;
int T,n,r,c,S,s,p,ans,mx[505],f[2][250005];
void solve()
{
	cin>>n;for(int i=1;i<=500;i++)mx[i]=0;S=0;s=0;p=0;
	memset(f[0],0,sizeof(f));f[0][0]=true;
	for(int i=1;i<=n;i++){cin>>r>>c;mx[r]=max(mx[r],c);}
	for(int i=1;i<=n;i++)if(mx[i]){S+=mx[i];p=i;}
	S=S*2+p-mx[p];ans=S;
//	cout<<ans<<"\n";
	for(int i=1,I=1;i<n;i++,I^=1)
	{
		s+=mx[i];
		for(int j=s;j>=0;j--)
		{
			f[I][j]|=f[I^1][j];
			if(j>=mx[i]&&f[I^1][j-mx[i]])
			{
				f[I][j]|=f[I^1][j-mx[i]];
				ans=min(ans,max(j*2-mx[i]+i,S-j*2));
//				cout<<i<<" "<<j<<" "<<j*2-mx[i]+i<<" "<<S-j*2<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
//	freopen("couple.txt","r",stdin);
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;while(T--)solve();
	return 0;
}
//我倒是知道我为啥错了，你看我有时间改吗/ll 
