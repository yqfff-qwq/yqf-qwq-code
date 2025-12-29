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
const int maxn=1e4+10;
struct st
{
	int l,r,id;
}a[maxn];
int n,t;
bool cmp(st a,st b)
{
	return a.r<b.r;
}
bool used[maxn];
int ans[maxn];
void work()
{
	REP(i,1,n) used[i]=0,ans[i]=0;
	int End=0;
	REP(i,1,n)
	{
		int mn=1e9,pos=-1,beg=-1;
		REP(j,1,n)
		if(!used[j])
		{
			int Beg=max(a[j].l,End);
			int ed=Beg+t;
			if(ed>a[j].r) continue;
			int u=rand()%10;
			if((ed<mn&&u<=8)||mn==1e9||u>8)
			{
				mn=ed;
				pos=j;
				beg=Beg;
			}
		}
		if(mn==1e9) {return;}
		used[pos]=1;
		End=mn;
		ans[a[pos].id]=beg;
	}
	cout<<"yes\n";
	REP(i,1,n) cout<<ans[i]<<" ";
	exit(0);
}
signed main()
{
	srand(time(0));
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	Ios();
	cin>>n>>t;
	REP(i,1,n) cin>>a[i].l>>a[i].r,a[i].id=i;
	int tot=1e8/(n*n);
	while(tot--) work();
	cout<<"no";
}
//ALl in T4!
