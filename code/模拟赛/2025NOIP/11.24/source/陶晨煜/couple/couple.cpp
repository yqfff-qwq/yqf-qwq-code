#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
const int maxm=500+10; 
int r[maxn],c[maxn];
int dp[2][maxm*maxm];
int mx[maxn];
int q[maxn];
void solve()
{
	int n;
	cin>>n;
	REP(i,1,n) cin>>r[i]>>c[i];
	REP(i,1,500) mx[i]=0;
	REP(i,1,n) mx[r[i]]=max(mx[r[i]],c[i]);
	REP(i,1,500) q[i]=q[i-1]+mx[i];
	int mxr=0;
	REP(i,1,n) mxr=max(mxr,r[i]);
//	if(n<=10)
//	{
//		int ans=1e9;
//		REP(sta,0,(1<<mxr))
//		{
//			int a1=0,b1=0,a2=0,b2=0;
//			REP(w,0,mxr-1)
//			if((sta>>w)&1) a1=max(a1,w+1),a2+=mx[w+1]*2;
//			else b1=max(b1,w+1),b2+=mx[w+1]*2;
//			a2-=mx[a1],b2-=mx[a2];
//			ans=min(ans,max(a1+a2,b1+b2));
//		}
//		cout<<ans<<"\n";
//		return;
//	}
	memset(dp,0x3f,sizeof dp);
	int ans=0x3f3f3f3f;
	dp[0][0]=0;
	int o=1;
	REP(i,1,mxr)
	{
		REP(j,0,q[mxr])
		{
			if(j>=mx[i]) dp[o][j]=min(dp[o^1][j]+mx[i],dp[o^1][j-mx[i]]);
			else dp[o][j]=dp[o^1][j]+mx[i];
			dp[o][j]=min(dp[o][j],0x3f3f3f3f);
			int v=q[mxr]-q[i];
			if(j>=mx[i])
			{
				int u=max((j+v)*2-mx[mxr]+mxr,(dp[o^1][j]+mx[i])*2-mx[i]+i);
				ans=min(ans,u);
			}
			else
			{
				int u=max((j+v)*2-mx[mxr]+mxr,dp[o][j]*2-mx[i]+i);
				ans=min(ans,u);
			}
		}
		o^=1;
		REP(j,0,q[mxr]) dp[o][j]=0x3f3f3f3f;
	}
	cout<<ans<<"\n";
}
//j1 dp2
int main()
{
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	Ios();
	int t;
	cin>>t;
	while(t--) solve();
}
/*
形式化题意：你一开始在一个直角坐标系的(0,0)上 
当y=0的时候，你可以向左或右或上移动1，即y=0时不能向下走
否则你只可以上下走。 
*/ 
