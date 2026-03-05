#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fir first
#define sec second
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>
#define all(x) x.begin(),x.end();
#define int long long
#define gunmu 0
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e5+1000;
int c[maxn];
int pre[maxn];
int dp[maxn];
struct segtree
{
	#define lson p<<1,l,mid
	#define rson p<<1|1,mid+1,r
	int mn[maxn<<2];
	void clear(int n)
	{
		REP(i,1,n*4) mn[i]=1e18;
	}
	void upd(int p,int l,int r,int x,int v)
	{
		if(l==r)
		{
			mn[p]=min(v,mn[p]);
			return;
		}
		int mid=(l+r)/2;
		if(x<=mid) upd(lson,x,v);
		else upd(rson,x,v);
		mn[p]=min(mn[p<<1],mn[p<<1|1]);
	}
	int query(int p,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr) return mn[p];
		int mid=(l+r)/2,ans=1e18;
		if(ql<=mid) ans=min(ans,query(lson,ql,qr));
		if(qr>mid) ans=min(ans,query(rson,ql,qr));
		mn[p]=min(mn[p<<1],mn[p<<1|1]);
		return ans;
	}
}sgt;
void solve()
{
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	a=" "+a,b=" "+b;
	REP(i,1,n) cin>>c[i];
	REP(i,1,n)
	if(a[i]=='1'&&b[i]=='0')
	{
		cout<<-1<<"\n";
		return; 
	}
	pre[n+1]=n+1;
	for(int i=n;i>=1;i--)
	if(a[i]=='1') pre[i]=i;
	else pre[i]=pre[i+1];
	vector<pii> p;
	bool fl=0;
	int l;
	REP(i,1,n)
	{
		if(b[i]=='1'&&!fl)fl=1,l=i;
		if(b[i]=='0'&&fl)
		{
			fl=0;
			p.pb({l,i-1});
		}
	}
	if(fl) p.pb({l,n});
	int ans=0;
	for(auto it:p)
	{
		int l=it.fir,r=it.sec,len=r-l+10;
		REP(j,l,r) dp[j]=1e18;
		dp[r+1]=0;
		sgt.clear(len);
		int mn=1e18;
		for(int j=r;j>=l;j--)
		{
			mn=min(mn,c[j]);
			if(a[j]=='1')
			{
				dp[j]=dp[j+1];
			}
			if(a[j]=='0')
			{
				dp[j]=min(dp[j],dp[j+1]+mn);
				int cj=c[j];
				if(a[j-1]=='1') cj=0;
				int R=min(r,pre[j]-1);
				dp[j]=min(dp[j],sgt.query(1,1,len,j+1-l+1,R-l+1)+cj);
			}
			sgt.upd(1,1,len,j-l+1,dp[j+1]+c[j]);
		}
		ans+=dp[l];
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("pom.in","r",stdin);
	freopen("pom.out","w",stdout);
	Ios();
	int t;
	cin>>t;
	while(t--) solve();
}
/*
1. 在一个点0减一下，然后当前这个位置到前面的第一个ai=1，全部变成1
2. 在一个点1加一下，然后前面的第一个ai=0变成1(末尾段)
3. 在一个点0加一下，然后这一位变ai=1
4. 在一个点1减一下，滚木。(x)
对一个0的连续段的操作不会影响其他连续段.
*/ 
