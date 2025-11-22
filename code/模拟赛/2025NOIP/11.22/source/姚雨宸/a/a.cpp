#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int T,n,P[25],l,a[10]={0,2,3,6,7,8,9};
void solve()
{
	cin>>n;l=0;int s=0;n--;
	while(n){P[++l]=n%7;n/=7;}
	while(l)s=(s*10+a[P[l--]])%p;
	cout<<s<<"\n";
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;while(T--)solve();
	return 0;
}
