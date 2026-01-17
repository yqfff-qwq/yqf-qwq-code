#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define int long long
#define pii pair<int,int>
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=3e5+10;
int a[maxn],mp[21][maxn];
int n,m,ans;
void dfs(int a,int b,int c,int d,int lim)
{
	if(a>b||b>c||c>d) return;
	if(!mp[lim][a]||!mp[lim][b]||!mp[lim][c]||!mp[lim][d]) return;
	if(lim==0)
	{
		if(a!=b&&b!=c&&c!=d)ans++;
		if(ans>=m)
		{
			cout<<m;
			exit(0);
		}
		return;
	}
	REP(i,0,1)
	REP(xa,0,1)
	REP(xc,0,1)
	{
		int xb=i^xa,xd=i^xc;
		dfs(a*2+xa,b*2+xb,c*2+xc,d*2+xd,lim-1);
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	Ios();
	cin>>n>>m;
	REP(i,1,n) cin>>a[i];
	REP(w,0,19)
	REP(j,1,n)
	mp[w][a[j]>>w]++;
	dfs(0,0,0,0,19);
	cout<<ans;
}
