#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fir first
#define sec second
#define pii pair<int,int>
#define pb push_back
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DBG(x) cerr<<#x<<":"<<x<<"\n"
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5e5+10;
int nexO[maxn],preO[maxn];
int qzL[maxn],qzR[maxn];
int gxL[maxn],gxR[maxn];
signed main()
{
	freopen("train.in","r",stdin);
	freopen("train.out","w",stdout);
	Ios();
	int n;
	string s;
	cin>>n>>s;
	s=" "+s;
	REP(i,1,n)
	{
		if(s[i]=='O') preO[i]=i;
		else preO[i]=preO[i-1];
	}
	nexO[n+1]=n+1;
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='O') nexO[i]=i;
		else nexO[i]=nexO[i+1];
	}
	REP(i,1,n) qzL[i]=qzL[i-1]+(s[i]=='L'),qzR[i]=qzR[i-1]+(s[i]=='R');
	REP(i,1,n) gxL[i]=gxL[i-1]+(s[i]=='L'?i:0),gxR[i]=gxR[i-1]+(s[i]=='R'?i:0);
	REP(i,1,n)
	{
		if(s[i]=='O')
		{
			cout<<0<<" ";
			continue;
		}
		int u=preO[i],v=nexO[i];
		if(s[i]=='L')
		{
			int ct1=qzR[i]-qzR[u];
			int ct2=qzL[v]-qzL[i];
			if(ct1<=ct2)
			{
				int l=i,r=n;
				while(l<r)
				{
					int mid=(l+r)/2;
					if(qzL[mid]-qzL[i-1]<ct1+1) l=mid+1;
					else r=mid;
				}
				cout<<(2*(gxL[l]-gxL[i])+i)-((gxR[i]-gxR[u])*2+u)<<" ";
			}
			else
			{
				int l=1,r=i;
				while(l<r)
				{
					int mid=(l+r+1)/2;
					if(qzR[i]-qzR[mid-1]<ct2+1) r=mid-1;
					else l=mid;
				}
				cout<<(2*(gxL[v]-gxL[i])+i+v)-((gxR[i]-gxR[l-1])*2)<<" ";
			}
		}
		else
		{
			int ct1=qzR[i-1]-qzR[u];
			int ct2=qzL[v]-qzL[i];
			if(ct1<ct2)
			{
				int l=i,r=n;
				while(l<r)
				{
					int mid=(l+r)/2;
					if(qzL[mid]-qzL[i]<ct1+1) l=mid+1;
					else r=mid;
				}
				cout<<(2*(gxL[l]-gxL[i]))-(i+u+2*(gxR[i-1]-gxR[u]))<<" ";
			}
			else
			{
				int l=1,r=i;
				while(l<r)
				{
					int mid=(l+r+1)/2;
					if(qzR[i]-qzR[mid-1]<ct2+1) r=mid-1;
					else l=mid;
				}
				cout<<(2*(gxL[v]-gxL[i])+v)-((gxR[i-1]-gxR[l-1])*2+i)<<" ";
			}
		}
	}
}
/*
RRLLLLRRL
     x
RRRRRRRRL
 x
RLLLLLLLL
        x
RRRRRRRRR
x
    
L
-> preR
-> nexL
-> preR
-> nexL
*/
