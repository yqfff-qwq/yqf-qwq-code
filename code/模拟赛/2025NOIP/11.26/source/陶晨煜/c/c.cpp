#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
int h[305],c[305];
struct st
{
	int u,v,w;
};
vector<st> v;
bool cmp(st a,st b)
{
	return a.w<b.w;
}
int f[305];
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int tmp[305];
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	Ios();
	int n,k;
	cin>>n>>k;
	int mxh=0,mxc=0;
	REP(i,1,n) cin>>h[i]>>c[i],mxh=max(mxh,h[i]),mxc=max(mxc,c[i]);
	if(k>=1e5&&mxh<=300&&mxc<=100)
	{
		int mn=1e18;
		REP(i,1,n)
		{
			int cost=0;
			REP(j,1,n) tmp[j]=h[j];
			REP(j,1,n)
			if(i!=j)
			{
				if(tmp[j]<h[i]+1)
				{
					int c=h[i]+1-tmp[j];
					cost+=c*k;
					tmp[j]=h[i]+1;
				}
			}
			//cerr<<cost<<"\n";
			if(cost>=mn) continue;
			v.clear();
			REP(j,1,n) 
			REP(k,1,n)
			if(tmp[j]>tmp[k])
			v.pb({j,k,c[k]});
			//cerr<<v.size()<<"\n";
			REP(j,1,n) f[j]=j;
			sort(v.begin(),v.end(),cmp);
			int l=0;
			map<int,bool> mp;
			for(auto it:v)
			{
				if(find(it.u)==find(it.v)) continue;
				if(!mp[it.v])
				f[find(it.u)]=find(it.v),mp[it.v]=1,l++;
			}
			for(auto it:v)
			{
				if(find(it.u)==find(it.v)) continue;
				cost+=it.w;l++;
				f[find(it.u)]=find(it.v);
			}
			//cerr<<l<<"\n";
			if(l==n-1)
			mn=min(mn,cost);
		} 
		cout<<mn;
		return 0;
	}
}
