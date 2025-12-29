#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	Ios();
	string s;
	cin>>s;
	int n=s.size();
	s=" "+s;
	int pos=n;
	REP(i,1,n) if(s[i]!=s[1])
	{
		pos=i-1;
		break;
	}
	cout<<pos;
}
