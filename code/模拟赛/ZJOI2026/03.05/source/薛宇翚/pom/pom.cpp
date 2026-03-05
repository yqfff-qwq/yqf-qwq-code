#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;
const ll inf=0x3f3f3f3f3f3f3fll;
int n;
char a[N],b[N];
ll c[N],as,suf[N];
void func(int l,int r)
{
	//cerr<<"func "<<l<<" "<<r<<"\n";
	int laso=r+1;
	ll miv=inf;
	for(int i=r;i>=l;i--)
	{
		if(a[i]=='1')
		{
			//cerr<<"seg "<<i<<" "<<laso<<"\n";
			ll cmiv=miv,cas=inf,csu=0;
			for(int j=laso-1;j>i;j--)
			{
				cas=min(cas,csu+c[j]);
				cmiv=min(cmiv,c[j]);
				csu+=cmiv;
			}
			cas=min(cas,csu);
			miv=min(cmiv,c[i]);
			as+=cas;
			laso=i;
			//cerr<<"add cas "<<cas<<"\n";
		}
	}
	suf[laso]=0;
	for(int j=laso-1;j>=l;j--)
	{
		miv=min(miv,c[j]);
		suf[j]=suf[j+1]+miv;
	}
	ll cas=suf[l],smiv=inf;
	for(int j=laso-1;j>=l;j--)
	{
		cas=min(cas,smiv+c[j]-suf[j]+suf[l]);
		smiv=min(smiv,suf[j+1]+c[j]);
	}
	as+=cas;
}
void solve()
{
	//cerr<<"new case\n";
	scanf("%d%s%s",&n,a+1,b+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='1'&&b[i]=='0')
		{
			printf("-1\n");
			return;
		}
	}
	b[n+1]='0';
	vector<pair<int,int> >d;
	int las=0;
	for(int i=1;i<=n+1;i++)
	{
		if(b[i]=='0')
		{
			d.push_back(make_pair(las+1,i-1));
			las=i;
		}
	}
	as=0;
	for(int i=0;i<d.size();i++)
	{
		if(d[i].first<=d[i].second)
		{
			func(d[i].first,d[i].second);
		}
	}
	printf("%lld\n",as);
}
int main()
{
	freopen("pom.in","r",stdin);
	freopen("pom.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
