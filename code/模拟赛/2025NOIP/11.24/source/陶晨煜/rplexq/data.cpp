#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
int fa[maxn];
int main()
{
	srand(time(0));
	freopen("rplexq.in","w",stdout);
	int n=2e5,m=2e5,r=rand()%n+1;
	cout<<n<<" "<<m<<" "<<r<<"\n";
	REP(i,2,n) fa[i]=rand()%(i-1)+1;
	REP(i,1,n)
	if(i!=r)
	{
		fa[i]=r;
		cout<<i<<" "<<fa[i]<<"\n";
	}
	int rt=r;
	REP(i,1,m)
	{
		int l=rand()%n+1,r=rand()%n+1,x=rand()%n+1;
		if(l>r) swap(l,r);
		x=rt;
		if(rand()%5==0) x=rand()%n+1;
		cout<<l<<" "<<r<<" "<<x<<"\n";
	}
}
