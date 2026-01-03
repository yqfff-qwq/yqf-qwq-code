#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define ll long long
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
int Rand()
{
	return rand()*32765ll+rand(); 
}
signed main()
{
	srand(time(0));
	freopen("struct.in","w",stdout);
	int n=500,m=1e6;
	cout<<n<<" "<<m<<"\n";
	REP(i,1,n) cout<<Rand()%n+1<<" ";
	cout<<"\n";
	while(m--)
	{
		int l=Rand()%n+1,r=Rand()%n+1;
		if(l>r) swap(l,r);
		cout<<l<<" "<<r<<"\n";
	}
}
