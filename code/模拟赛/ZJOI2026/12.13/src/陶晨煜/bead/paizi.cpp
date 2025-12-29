#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define int long long
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e5+10;
const int mod=998244353;
int a[maxn];
int dp[maxn];
int f[maxn];
int id[maxn],idx[maxn];
int vis[maxn];
signed main1(int n,int m)
{
	REP(i,0,100) vis[i]=dp[i]=f[i]=id[i]=idx[i]=0;
	set<int> d;
	REP(i,1,n)
	{
		for(int j=1;j*j<=a[i];j++)
		if(a[i]%j==0) d.insert(j),d.insert(a[i]/j);
	}
	d.insert(0);
	int tot=0;
	for(auto it:d) id[it]=++tot,idx[tot]=it;
	dp[1]=1;
	int add=1;
	sort(a+1,a+1+n);
	int key=0;
	int ggg=0;
	REP(i,1,n)
	{
		key++;
		vector<int> g;
		int u=a[i],y=2;
		while(y*y<=u)
		{
			bool fl=0;
			while(u%y==0) fl=1,u/=y;
			if(fl)
			{
				int sum=y;
				while(sum<=a[i])
				{
					if(vis[sum]!=key&&id[sum])
					g.pb(sum),vis[sum]=key;
					sum+=y;
				}
			}
			y++;
		}
		if(u>1)
		{
			int sum=u;
			while(sum<=a[i])
			{
				if(vis[sum]!=key&&id[sum])
				g.pb(sum),vis[sum]=key;
				sum+=u;
			}
		}
		g.pb(0);
		ggg+=g.size();
		for(auto it:g) f[id[it]]=dp[id[it]];
		int sum=0;
		for(auto it:g)
		{
			int j=id[it];
			int pos=id[__gcd(idx[j],a[i])];
			dp[pos]+=f[j];dp[pos]%=mod;
			sum+=f[j];sum%=mod;
		}
		dp[id[1]]+=(add-sum+mod)%mod,dp[id[1]]%=mod;
		//REP(j,1,tot) cerr<<idx[j]<<"->"<<dp[j]<<',';cerr<<"\n";
		add*=2,add%=mod;
	}
	int ans=0;
	REP(i,1,tot) ans+=dp[i]*idx[i],ans%=mod;
	return ans;
}
signed main2(int n,int m)
{
	int ans=0;
	REP(sta,0,(1<<n))
	{
		int g=0;
		REP(w,0,n-1)
		if((sta>>w)&1) g=__gcd(g,a[w+1]);
		ans+=g;
	}
	return ans;
}
signed main()
{
	int cs=0;
	while(++cs)
	{
		if(cs%1==0) cout<<"Accpted #"<<cs<<"!\n";
		int n=20,m=70;
		REP(i,1,n) a[i]=rand()%m+1;
		int v=main2(n,m),u=main1(n,m);
		if(u!=v)
		{
			cout<<"Wrong answer on test #"<<cs<<"\n";
			cout<<u<<' '<<v<<"\n";
			cout<<n<<' '<<m<<"\n";
			REP(i,1,n) cout<<a[i]<<" ";
			return 0;
		}
	}
}
