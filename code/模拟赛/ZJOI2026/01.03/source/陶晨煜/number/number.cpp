#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define ll long long
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e6+10000;
int prim[maxn],tot;
bool vis[maxn];
void init(int N)
{
	REP(i,2,N)
	{
		if(!vis[i])
		{
			prim[++tot]=i;
			for(int j=i;j<=N;j+=i) vis[j]=1;
		}
	}
}
int B;
void solve(int a)
{
	int y=1,cs=0;
	while(prim[y]*prim[y]<=a&&y<=tot)
	{
		int u=prim[y];
		int cnt=0;
		while(a%u==0) a/=u,cnt++;
		if(cnt==1)
		{
			cout<<"no\n";
			return;
		}
		y++;
	}
	int u=sqrt(a);
	if(u*u==a||(u-1)*(u-1)==a||(u+1)*(u+1)==a) cout<<"yes\n";
	else cout<<"no\n";
}
//3-ys 1e6
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Ios();
	int t;
	cin>>t;
	vector<int> q;
	int mx=0;
	while(t--)
	{
		int x;
		cin>>x;
		q.pb(x);
		mx=max(mx,x);
	}
	B=pow(mx,0.33333333333333333)+100;
	init(B);
	for(auto it:q) solve(it);
}
