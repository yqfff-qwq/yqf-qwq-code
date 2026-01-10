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
const int mod=998244353;
const int md=1e16+61;
int n;
unordered_map<int,int> mp;
int hs(vector<int> g)
{
	int u=0;
	for(auto it:g) u*=131,u+=it,u%=md;
	return u;
}
int dfs(vector<int> l,int c)
{
	if(c==1) return 1;
	int H=hs(l);
	if(mp.count(H)) return mp[H];
	int u=0;
	for(int i=0;i<l.size();i++)
	{
		l[i]--;
		vector<int> p;
		for(int j=0;j<l.size();j++)
		if(l[j]) p.pb(l[j]);
		else
		{
			if(j+1<l.size()&&j-1>=0) p[j-1]+=l[j+1],j++;
		}
		u+=dfs(p,c-1);
		u%=mod;
		l[i]++;
	}
	return mp[H]=u;
}
bool chk9(string s)
{
	for(int i=0;i<n;i++)
	if(s[i]=='1') return 0;
	return 1;
}
int c[555][555];
signed main()
{
	freopen("sub.in","r",stdin);
	freopen("sub.out","w",stdout);
	c[0][0]=1;
	for(int i=1;i<=500;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=500;j++) c[i][j]=c[i-1][j]+c[i][j-1],c[i][j]%=mod;
	}
	Ios();
	string s;
	cin>>n>>s;
	if(chk9(s))
	{
		cout<<1<<"\n";
		return 0;
	}
	if(n>30)
	{
		cout<<c[(n+1)/2+1][n/2]<<"\n";
		return 0;
	}
	vector<int> g;
	int l=1;
	for(int i=1;s[i];i++)
	if(s[i]!=s[i-1]) g.pb(l),l=1;
	else l++;
	g.pb(l);
	cout<<dfs(g,n);
}
//10000111
//0011
//i j k
