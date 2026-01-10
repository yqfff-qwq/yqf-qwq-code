#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pii pair<int,int>
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pb push_back
#define int long long
#define tdsb 0
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5e5+10;
int a[maxn];
vector<int> g[maxn];
void add(int x,int dep,int c)
{
	a[x]+=c;
	if(dep==0) return;
	for(auto it:g[x]) add(it,dep-1,c);
}
int sum(int x,int dep)
{
	int s=a[x];
	if(dep==0) return s;
	for(auto it:g[x]) s+=sum(it,dep-1);
	return s;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	Ios();
	int n,q;
	cin>>n>>q;
	REP(i,1,n) cin>>a[i];
	REP(i,2,n)
	{
		int x;
		cin>>x;
		g[x].pb(i);
	}
	int tot=n;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int a,b,c;
			cin>>a>>b>>c;
			add(a,b,c);
		}
		else if(op==2)
		{
			int a,b;
			cin>>a>>b;
			cout<<sum(a,b)<<"\n";
		}
		else
		{
			int f,c;
			cin>>f>>c;
			tot++;
			g[f].pb(tot);
			a[tot]=c;
		}
	}
}
