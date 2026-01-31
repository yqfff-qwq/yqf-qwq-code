#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e6+10;
int a[N];
int n;
bool check(int i, int j)
{
	for(int cur=0;cur<=30;cur++)
	{
		int x=1<<cur;
		if(j<n&&(a[j+1]^x)>(a[i]^x)&&(a[j+1]^x)<(a[j]^x)) return false;
		if(i>1&&(a[i-1]^x)>(a[i]^x)&&(a[i-1]^x)<(a[j]^x)) return false;
	}
	return true;
}
signed main()
{
	freopen("starlight.in", "r", stdin);
	freopen("starlight.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1, a+1+n);
		int cnt=0;
		for(int i=1;i<n;i++)
			if(check(i, i+1)) cnt++;
		cout<<cnt<<'\n';
	}
	return 0;
}
