#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pii pair<int,int>
#define pb push_back
#define int long long
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
int x[maxn],y[maxn];
int mn=1e18;
int n,m;
vector<int> pp;
void dfs(int a,int b,int c)
{
	if(c>=mn) return;
	if(a==n&&b==m)
	{
		mn=c;
		return;
	}
	if(a<n) pp.pb(1),dfs(a+1,b,c+x[a]*b),pp.pop_back();
	if(b<m) pp.pb(2),dfs(a,b+1,c+y[b]*a),pp.pop_back();
}
int baoli()
{
	mn=1e18;
	dfs(1,1,0);
	return mn;
}
int qx[maxn],qy[maxn];
int solve()
{
	REP(i,1,n-1) qx[i]=qx[i-1]+x[i];
	REP(i,1,m-1) qy[i]=qy[i-1]+y[i];
	int pos1=1,pos2=1;
	int ans=0;
	REP(i,1,n+m-2)
	{
		if(pos1>=n) ans+=y[pos2]*pos1,pos2++;
		else if(pos2>=m) ans+=x[pos1]*pos2,pos1++;
		else
		{
			if(x[pos1]<=y[pos2]) ans+=y[pos2]*pos1,pos2++;
			else ans+=x[pos1]*pos2,pos1++;
		}
	}
	return ans;
}
signed main()
{
	int cs=0;
	while(++cs)
	{
		n=rand()%15+1,m=rand()%15+1;
		REP(i,1,n-1) x[i]=rand()%1000+1;
		REP(j,1,m-1) y[j]=rand()%1000+1;
		sort(x+1,x+n);reverse(x+1,x+n);
		sort(y+1,y+m);reverse(y+1,y+m);
		int u=baoli(),v=solve();
		if(u!=v)
		{
			cout<<"Wrong answer on test #"<<cs<<"\n";
			cout<<n<<" "<<m<<"\n";
			REP(i,1,n-1) cout<<x[i]<<" ";cout<<"\n";
			REP(j,1,m-1) cout<<y[j]<<" ";cout<<"\n";
			cout<<u<<" "<<v<<"\n";
			exit(0);
		}
		if(cs%1000==0) cout<<"Accpted #"<<cs<<"!\n";
	}
}
