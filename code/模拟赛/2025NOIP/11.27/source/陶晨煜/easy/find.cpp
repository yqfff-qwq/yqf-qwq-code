#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define umap unordered_map
#define pqueue priority_queue
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=2e5+10;
const int mod=998244353;
int a[maxn];
int solve(int a,int b,int k)
{
	map<int,int> mp;
	REP(x,0,k-1) REP(y,0,k-1) mp[(a*x+b*y)%k]=1;
	return mp.size();
}
signed main()
{
	REP(k,2,100)
	REP(a,0,k-1)
	REP(b,0,k-1)
	{
		int u=solve(a,b,k),d=k/__gcd(a,__gcd(b,k));
		if(u!=d)
		cout<<a<<" "<<b<<' '<<k<<" "<<u<<" "<<d<<"\n";
	}
}
