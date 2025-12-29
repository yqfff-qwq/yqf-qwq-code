#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n,q,c,a[200005],l,r,x;
signed main()
{
	freopen("reflection.in","r",stdin);
	freopen("reflection.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(q--)
    {
    	cin>>l>>r>>x;
    	for(int i=l;i<=r;i++)x=abs(a[i]-x);
    	cout<<x<<"\n";
	}
    return 0;
}
//0 pts