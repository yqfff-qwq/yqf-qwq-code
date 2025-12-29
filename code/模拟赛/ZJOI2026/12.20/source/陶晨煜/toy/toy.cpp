#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=3e6+10;
int nex[maxn];
int main()
{
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	Ios();
	int b,a,n;
	cin>>b>>a>>n;
	string s;
	cin>>s;
	s=" "+s;
	int cnt=0;
	REP(i,1,n) cnt+=(s[i]=='1');
//	if(cnt==s.size()-1)
//	{
//		ll ans=0;
//		int pos1=a,pos2=b;
//		while(pos1<n||pos2<n)
//		{
//			//b->a
//			ans+=b;
//			pos2=pos1;
//			int w=pos2+a-b;
//			w=min(w,n);
//			ans+=w-pos1;
//			pos1=w;
//			//cerr<<pos1<<" "<<pos2<<" "<<ans<<"\n";
//		}
//		cout<<ans;
//		return 0;
//	}
	nex[n+1]=n+1;
	for(int i=n;i>=1;i--)
	if(s[i]=='0') nex[i]=nex[i+1];
	else nex[i]=i;
	int l=1,r=a,tail=b;
	ll ans=0;
	vector<int> g;
	REP(i,1,b) g.pb(i);
	int gb=g.back(),yr=r;
	while(r<n||g.back()<n)
	{
		int L=l;
		int w=g[g.size()-b]-l;
	//	cerr<<w<<" "<<g[g.size()-b]<<"\n";
	//	cerr<<ans<<"\n";
		l=g[g.size()-b];r=l+a-1;
		if(r>n)
		{
			int u=r-n;
			r-=u,l-=u;
		}
		ans+=l-L;
		REP(i,gb+1,r) if(s[i]=='1') g.pb(i);
	//	cerr<<l<<' '<<r<<"\n";
	//	for(auto it:g) cerr<<it<<" ";
	//	cerr<<"\n";
		if(g.back()!=gb) ans+=b;
//		cerr<<ans<<"\n";
		if(g.back()==gb&&yr==r)
		{
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
		gb=g.back(),yr=r;
	}
	cout<<ans;
	return 0;
	cout<<"IMPOSSIBLE\n";
}
