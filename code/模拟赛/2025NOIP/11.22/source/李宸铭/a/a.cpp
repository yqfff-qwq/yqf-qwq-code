#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int t,n;
int a[25],b[25]; 
void init()
{
	b[0]=1;
	a[1]=3;
	b[1]=10-a[1];
	int s=10; 
	for(int i=2;i<=15;i++)
	{
		a[i]=3*s+7*a[i-1];
		b[i]=s*10-a[i];
		s*=10;
	}
//	for(int i=1;i<=15;i++) cout<<a[i]<<" ";
}
int Pow(int x)
{
	int sum=1;
	for(int i=1;i<=x;i++) sum=(sum*10)%mod;
	return sum;
}
void solve()
{
	int n,sum=0;
	
	cin>>n;
	
	n--;
	for(int i=15;i>=1;i--)
	{
		if(n==0) break;
		int s=n/b[i];
		n-=s*b[i];
		if(s==0) continue;
		
		int add=Pow(i),z=0;
		while(s)
		{
			z++;
			if(z==1||z==4||z==5) continue;
			s--;
		}
//		cout<<i<<" "<<z<<'\n';
		sum=(sum+z*add)%mod;
		if(n==0) break;
	}
	int z=0;
	while(n)
	{
		z++;
		if(z==1||z==4||z==5) continue;
		n--;
	}
	sum+=z;
	
	cout<<sum%mod<<'\n';
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	init();
	cin>>t;
	while(t--) solve();
	
	return 0;
}
//OuO?
//1 4 5 10 11 12 13 14 15 16 17 18 19 21 24 25 31 34 35 40 41 42 43 44 45 46  47 48 49 50 51 52 53 54 55   :35
