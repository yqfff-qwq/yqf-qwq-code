#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,M,sum,flag,fir,sec;
struct ilj{
	int v,m;
}a[500025];
int f[100000025];
priority_queue<int> q,qq;
bool cmp1(ilj s,ilj q)
{
	return s.v<q.v;
}
void solve1()
{
	sort(a+1,a+1+n,cmp1);
	
	for(int i=n;i>=1;i--)
	{
		M-=a[i].m;
		sum+=a[i].v;
	}
	
	cout<<sum<<'\n';
	
	exit(0);
}
bool cmp(ilj s,ilj q)
{
	if(s.m!=q.m) return s.m<q.m;
	else return s.v>q.v; 
}
void solve2()
{
	sort(a+1,a+1+n,cmp);
	
	int lim=1;
	while(a[lim].m==a[lim+1].m) lim++;
	
	int i,j;
	for(i=1,j=lim+1;i<=lim,j<=n;j++)
	{
		if(M<a[j].m) break;
		int res=a[j].m,ans=0;
		while(res>=a[i].m)
		{
			ans+=a[i].v;
			res-=a[i].m; 
			i++;
		}
		if(ans<a[j].v) sum+=a[j].v;
		else sum+=ans;
		M-=a[j].m; 
	}
	while(M>=a[i].m)
	{
		sum+=a[i].v;
		M-=a[i].m;
		i++;
	}
	
	cout<<sum<<'\n';
	
	exit(0);
}
signed main()
{
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>M;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v>>a[i].m;
		if(flag==1) continue;
		if(a[i].m!=fir&&a[i].m!=sec)
		{
			if(fir==0) fir=a[i].m;
			else if(sec==0) sec=a[i].m;
			else flag=1;
		}
	}
	
	if(sec==0) solve1();
	else if(flag==0) solve2();
	
	q.push(0);
	for(int i=1;i<=n;i++)
	{
		qq=q;
		while(!q.empty())
		{
			int t=q.top();
			q.pop();
			if(a[i].m+t<=M)
			{
				if(f[a[i].m+t]==0) qq.push(a[i].m+t); 
				f[a[i].m+t]=max(f[a[i].m+t],f[t]+a[i].v);
				sum=max(sum,f[a[i].m+t]);
			}
		}
		q=qq;
	}
	
	cout<<sum<<'\n';
	
	return 0;
}
