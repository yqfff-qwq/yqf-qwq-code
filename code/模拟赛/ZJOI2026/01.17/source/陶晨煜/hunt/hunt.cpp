#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define int long long
#define pii pair<int,int>
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5e5+10;
struct st
{
	int x,y,z;
}a[maxn];
struct cmp(st a,st b)
{
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y<b.y;
	return a.z<b.z;
}
bool check(int k)
{
	
}
signed main()
{
	freopen("hunt.in","r",stdin);
	freopen("hunt.out","w",stdout);
	Ios();
	int n;
	cin>>n;
	REP(i,1,n) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+1+n,cmp);
	int l=1,r=2e9;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
}
