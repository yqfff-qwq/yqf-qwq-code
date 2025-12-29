#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
struct st
{
	int a,b,id;
}a[maxn];
bool cmp(st a,st b)
{
	return a.b<b.b;
}
int q[maxn];
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	Ios();
	int n,m;
	cin>>n>>m;
	REP(i,1,n) cin>>a[i].a,q[i]=q[i-1]+a[i].a;
	q[n+1]=q[n];
	REP(i,1,n) cin>>a[i].b;
	REP(i,1,n) a[i].id=i;
	while(m--)
	{
		int s,t,u;
		cin>>s>>t>>u;
		vector<st> v;
		int tot=0;
		REP(i,s,t) v.pb(a[i]);
		sort(v.begin(),v.end(),cmp);
		int pos=t;
		for(auto it:v)
		{
			if(pos<it.id) continue;
			int need=min(q[pos]-q[it.id],u);
			tot+=need*it.b;
			pos=it.id;
		}
		cout<<tot<<"\n";
	}
}
/*
5 4
3 4 1 1 4
2 5 1 2 1
1 6 3
1 6 4
3 5 1
2 5 9
*/
