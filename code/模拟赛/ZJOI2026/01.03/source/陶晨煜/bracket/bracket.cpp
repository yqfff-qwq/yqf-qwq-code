#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define ll long long
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=105;
int p[maxn];
bool vis[maxn];
vector<int> h[maxn];
int c[maxn];
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	Ios();
	int n;
	cin>>n;
	REP(i,1,n) cin>>p[i];
	int tot=0;
	REP(i,1,n)
	if(vis[i]==0)
	{
		tot++;
		int u=i;
		while(!vis[u])
		{
			h[tot].pb(u);
			vis[u]=1;
			u=p[u];
		}
	}
	REP(sta,0,(1<<tot))
	{
		REP(i,1,n) c[i]=0;
		REP(w,1,tot)
		{
			int o=(sta>>(w-1))&1;
			for(auto it:h[w])
			c[it]=o,o^=1;
		}
		int l=0;
		bool fl=0;
		REP(i,1,n)
		if(c[i]) l++;
		else
		{
			l--;
			if(l<0) fl=1;
		}
		if(!fl&&!l)
		{
			REP(i,1,n) cout<<(c[i]?'(':')');
			return 0;
		}
	}
}
/*
node i is (
i -> pi
it cause pi must )
pi is ) ppi=i
*/
/*
checker bracket2.in bracket2.out bracket2.ans
checker bracket3.in bracket3.out bracket3.ans
checker bracket4.in bracket4.out bracket4.ans
checker bracket5.in bracket5.out bracket5.ans
*/
