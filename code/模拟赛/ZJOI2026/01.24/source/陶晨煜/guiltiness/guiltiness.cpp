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
signed main()
{
	freopen("guiltiness.in","r",stdin);
	freopen("guiltiness.out","w",stdout);
	Ios();
	int n,m;
	cin>>n>>m;
	REP(i,1,n-1) cin>>x[i];
	REP(i,1,m-1) cin>>y[i];
	sort(x+1,x+n);reverse(x+1,x+n);
	sort(y+1,y+m);reverse(y+1,y+m);
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
	cout<<ans;
}
