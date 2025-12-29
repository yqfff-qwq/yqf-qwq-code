#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fir first
#define sec second
#define pii pair<int,int>
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
int ans[maxn];
signed main()
{
	freopen("modification.in","r",stdin);
	freopen("modification.out","w",stdout);
	Ios();
	int n;
	string s;
	cin>>n>>s;
	s=" "+s;
	int jz=n+1;
	REP(sta,0,(1<<(n-1)))
	{
		vector<string> g;
		int l=1;
		REP(w,0,n-2)
		if((sta>>w)&1)
		{
			int r=w+1;
			string u="";
			REP(i,l,r) u+=s[i];
			g.pb(u);
			l=r+1;
		}
		int r=n;
		string u="";
		REP(i,l,r) u+=s[i];
		g.pb(u);
		if(g.size()>=jz) continue;
	//	for(auto it:g) cerr<<it<<" ";cerr<<"\n";
		vector<int> d;
		int m=0;
		for(auto it:g)
		{
			int c0=0,c1=0;
			for(int j=0;it[j];j++) c0+=(it[j]=='0'),c1+=(it[j]=='1');
			d.pb(c1);
			m+=max(c0,c1);
		}
		int o=0;
		REP(i,0,g.size()-1)
		{
			int c0=0,c1=0;
			int mx=d[i];
			for(int j=0;g[i][j];j++)
			{
				c0+=(g[i][j]=='0'),c1+=(g[i][j]=='1');
				mx=max(mx,c0+d[i]-c1);
			}
			mx+=m;
			mx-=max(c0,c1);
			o=max(o,mx);
		}
		ans[g.size()]=max(ans[g.size()],o);
		if(o==n) jz=min(jz,(int)g.size());
	}
	REP(i,1,n) ans[i]=max(ans[i],ans[i-1]);
	REP(i,1,n) cout<<ans[i]<<" ";
	cout<<"\n";
}
//000000011111110000000
