#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
typedef long long ll;
int calc(int x)
{
	if(x==0)
	{
		return 0;
	}
	if(x<=2)
	{
		return x+1;
	}
	return x+3;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		vector<int>arr;
		n--;
		while(n)
		{
			arr.push_back(calc(n%7));
			n/=7;
		}
		ll as=0;
		for(int i=arr.size()-1;i>=0;i--)
		{
			as=(10ll*as+arr[i])%M;
		}
		printf("%lld\n",as);
	}
	return 0;
}
//逸一时，误一世。