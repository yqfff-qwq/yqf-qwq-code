#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DBG(x) cerr<<#x<<":"<<x<<"\n"
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
vector<int> a[maxn];
int n;
void change(vector<int> a,vector<int> &newa)
{
	newa.resize(n+3);
	int cnt=0;
	int j=n/2+1;
	REP(i,1,n/2)
	{
		while(j<=n&&a[j]<a[i])
		{
			newa[++cnt]=a[j];
			j++;
		}
		newa[++cnt]=a[i]; 
	}
	while(j<=n) newa[++cnt]=a[j],j++;
}
signed main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	Ios();
	int Q;
	cin>>n>>Q;
	a[0].resize(n+3); 
	REP(i,1,n) cin>>a[0][i];
	int u=2e7/n;
	REP(t,1,u) change(a[t-1],a[t]);
	while(Q--)
	{
		int t,i;
		cin>>t>>i;
		cout<<a[min(t,u)][i]<<"\n";
	}
}
