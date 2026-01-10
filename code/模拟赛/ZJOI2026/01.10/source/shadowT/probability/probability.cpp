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
int dp[1010][61][55];
signed main()
{
	freopen("probability.in","r",stdin);
	freopen("probability.out","w",stdout);
	int n,p,m;
	cin>>n>>p>>m;
	dp[0][0][0]=1;
	REP(i,1,n)
	REP(j,0,m)
	REP(k,0,p-1)
	REP(u,0,9)
	if(j+u<=m)
	dp[i][j+u][(k*10+u)%p]+=dp[i-1][j][k],
	dp[i][j+u][(k*10+u)%p]%=mod;
	int sum=0;
	REP(i,0,m)
	{
		sum+=dp[n][i][0];sum%=mod;
		cout<<sum<<" ";
	}
}
