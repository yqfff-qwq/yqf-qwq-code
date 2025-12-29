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
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
ll RAND()
{
	return rand()*1ll*RAND_MAX*1ll*RAND_MAX+rand()*1ll*RAND_MAX+rand()*1ll;
}
int main()
{
	srand(time(0));
	freopen("root6.in","w",stdout);
	int t=1e5;
	cout<<t<<"\n";
	while(t--)
	{
		ll n=RAND()%(ll)1e3+2;
		ll m=RAND()*(rand()*1ll)%(ll)1e18;
		cout<<n<<" "<<m<<"\n";
	}
}
