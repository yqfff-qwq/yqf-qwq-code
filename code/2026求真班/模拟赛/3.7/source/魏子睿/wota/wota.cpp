#include <bits/stdc++.h>
#define int long long
using namespace std;
int calc(int x)
{
	string s=to_string(x);
	int cnt=0;
	while(s.size()&&s.back()=='9') cnt++, s.pop_back();
	return cnt;
}
int solve(int n)
{
	int maxn=0, ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int res=calc(i+j);
			if(res>maxn) maxn=res, ans=0;
			if(res==maxn) ans++;
		}
	}
	return ans;
}
signed main()
{
	freopen("wota.in", "r", stdin);
	freopen("wota.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	if(n<=49)
	{
		cout<<solve(n);
		return 0;
	}
	int now=500;
	while(n>=now) now*=10;
	now/=10;
	int id=now-1, k=1, last=0;
	while(id+now*2<=n) last=last+now*2*k-1, id+=now*2, k++;
	int ans=last+(n-id)*k;
	if(n-id>=now) ans--;
	cout<<ans;
	return 0;
}
