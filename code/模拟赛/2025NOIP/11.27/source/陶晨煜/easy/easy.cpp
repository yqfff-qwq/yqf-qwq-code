#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define umap unordered_map
#define pqueue priority_queue
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=2e5+10;
const int mod=998244353;
int a[maxn];
void solve()
{
	int n,k;
	cin>>n>>k;
	REP(i,1,n) cin>>a[i];
	cout<<(k/__gcd(a[1],__gcd(a[2],k))+1)%mod<<"\n";
}
signed main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	Ios();
	int t;
	cin>>t;
	while(t--) solve();
}
