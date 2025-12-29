#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DEP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define pb push_back
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=1010;
int a[maxn];
ll q[maxn];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	Ios();
	int n;
	cin>>n;
	REP(i,1,n) cin>>a[i],q[i]=q[i-1]+a[i];
	set<ll> s1,s2;
	ll mn=1e18;
	REP(i,1,n-1)
	{
		REP(j,1,i) s1.insert(q[i]-q[j-1]),s2.insert(q[j-1]-q[i]);
		REP(j,i+1,n)
		{
			ll sum=q[j]-q[i];
			auto it1=s1.lower_bound(sum),it2=s2.lower_bound(-sum);
			if(it1!=s1.end())mn=min(mn,abs(sum-*it1));
			if(it2!=s2.end())mn=min(mn,abs(sum+*it2));
		}
	}
	cout<<mn;
}
//0+[0,100]+0+0
