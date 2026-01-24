#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pii pair<int,int>
#define pb push_back
#define int long long
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
bool dp[110][110][110][2];
bool vis[110][110][110][2];
int ct=0;
int lim=1e9;
bool dfs(int a,int b,int c,int x)
{
	if(a>b) swap(a,b);if(b>c) swap(b,c);if(a>b) swap(a,b);
	b-=a,c-=a;a=0;
	if(b!=c&&b!=0&&x==1) return 1;
	ct++;
	if(a<=100&&b<=100&&c<=100)
	if(vis[a][b][c][x])
	return dp[a][b][c][x];
	if(x)
	{
		bool p=0;
		int g=1;
		while(a+g<=b-g)
		{
			if(p||g>lim) break;
			p|=dfs(a+g,b-g,c,x^1),g++;
		}
		g=1;
		while(b+g<=c-g)
		{
			if(p||g>lim) break;
			p|=dfs(a,b+g,c-g,x^1),g++;
		}
		g=1;
		while(a+g<=c-g)
		{
			if(p||g>lim) break;
			p|=dfs(a+g,b,c-g,x^1),g++;
		}
		if(a<=100&&b<=100&&c<=100)
		vis[a][b][c][x]=1,dp[a][b][c][x]=p;
		return p;
	}
	else
	{
		bool p=1;
		int g=1;
		while(a+g<=b-g)
		{
			if(!p||g>lim) break;
			p&=dfs(a+g,b-g,c,x^1),g++;
		}
		g=1;
		while(b+g<=c-g)
		{
			if(!p||g>lim) break;
			p&=dfs(a,b+g,c-g,x^1),g++;
		}
		g=1;
		while(a+g<=c-g)
		{
			if(!p||g>lim) break;
			p&=dfs(a+g,b,c-g,x^1),g++;
		}
		if(a<=100&&b<=100&&c<=100)
		vis[a][b][c][x]=1,dp[a][b][c][x]=p;
		return p;
	}
}
const int maxn=3e5+10;
int a[maxn];
bool canmove(int a,int b,int c)
{
	if(a>b) swap(a,b);
	return a+c<=b-c;
}
bool check(int x,int y,int z)
{
	y-=x,z-=x;x=0;
	if(y!=z&&y!=0) return 1;
//	if(y==z) swap(x,z); 
//	if((y+z)%2==0) return 0
	return dfs(0,y,z,1);
}
void solve()
{
	int n;
	cin>>n;
	map<int,int> mp;
	REP(i,1,n) cin>>a[i],mp[a[i]]++;
	if(mp.size()==n)
	{
		cout<<n*(n-1)*(n-2)/6<<"\n";
		return;
	}
	if(n>10) lim=2;
	else lim=1e9;
	int cnt=0;
	REP(i,1,n)
	REP(j,i+1,n)
	REP(k,j+1,n)
	{
		int x=a[i],y=a[j],z=a[k];
		if(x>y) swap(x,y);
		if(y>z) swap(y,z);
		if(x>y) swap(x,y);
		if(check(x,y,z))cnt++;
	}
	cout<<cnt<<"\n";
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	Ios();
	int t;
	cin>>t; 
	bool tmp;
	REP(j,0,100)
	tmp=dfs(0,j,j,1);
	REP(j,0,100)
	tmp=dfs(0,0,j,1);
	while(t--) solve();
//	cerr<<ct<<"\n";
}
