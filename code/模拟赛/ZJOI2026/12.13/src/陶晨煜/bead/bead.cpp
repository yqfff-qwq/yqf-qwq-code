#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define ll long long
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1e5+10;
const int mod=998244353;
int a[maxn];
int dp[maxn];
int f[maxn];
int tag[maxn];
inline void MOD(int &x)
{
	x=(x>=mod?x-mod:x);
}
int g[maxn];
signed main()
{
	freopen("bead.in","r",stdin);
	freopen("bead.out","w",stdout);
	Ios();
	int n,m;
	cin>>n>>m;
	REP(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	REP(j,0,m) f[j]=dp[j];
	int key=0;
	int add=2,sum=1;
	REP(i,1,n)
	{
		key++;
		int pos=0;
		for(int j=1;j*j<=a[i];j++)
		if(a[i]%j==0)
		{
			g[++pos]=j;
			if(j*j!=a[i]) g[++pos]=a[i]/j;
		}
		sort(g+1,g+1+pos);reverse(g+1,g+1+pos);
		vector<pii> opt;
		REP(k,1,pos)
		{
			int it=g[k];
			if(it==1) break;
			//gcd(x,ai)=it
			int upd=0;
			for(int p=0;p<=a[i];p+=it)
			{
				if(tag[p]!=key)
				upd+=f[p],tag[p]=key,MOD(upd);
			}
			dp[it]+=upd;MOD(dp[it]);
			sum+=upd;MOD(sum);
			opt.pb({it,upd});
		}
		f[1]=dp[1]=(add-sum+mod)%mod;
		for(auto it:opt) f[it.fir]+=it.sec,MOD(f[it.fir]);
		add*=2,MOD(add);
	}
	int ans=0;
	REP(i,1,m) ans+=dp[i]*1ll*i%mod,ans%=mod;
	cout<<ans;
}
/*
5 7
2 4 6 7 7
*/
//nothing to 
