#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353,N=510;
int n,f[N],g[N];
string s;
map<string,int>mp;
int ksm(int x,int y=M-2)
{
	int as=1;
	while(y)
	{
		if(y&1)
		{
			as=as*x%M;
		}
		x=x*x%M;
		y>>=1;
	}
	return as;
}
int C(int x,int y)
{
	return (x>=0&&y>=0&&x>=y?1ll*f[x]*g[y]%M*g[x-y]%M:0ll);
}
int func(string s)
{
	if(mp.find(s)!=mp.end())
	{
		return mp[s];
	}
	if(s=="")
	{
		return mp[s]=1;
	}
	int as=0;
	string pre="",bac=s.substr(1);
	for(int i=0;i<s.size();i++)
	{
		if(i==0||s[i]!=s[i-1])
		{
			as+=func(pre+bac);
		}
		pre+=s[i];
		if(bac!="")
		{
			bac=bac.substr(1);
		}
	}
	return mp[s]=as;
}
signed main()
{
	freopen("sub.in","r",stdin);
	freopen("sub.out","w",stdout);
	f[0]=1;
	for(int i=1;i<N;i++)
	{
		f[i]=f[i-1]*i%M;
	}
	g[N-1]=ksm(f[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		g[i]=g[i+1]*(i+1)%M;
	}
	cin>>n>>s;
	bool isz=0,iso=0;
	for(int i=0;i<s.size();i++)
	{
		isz|=(s[i]=='0');
		iso|=(s[i]=='1');
	}
	if(!isz||!iso)
	{
		printf("1\n");
		return 0;
	}
	int ct=0;
	vector<int>h;
	for(int i=0;i<=s.size();i++)
	{
		if(i==s.size()||(i!=0&&s[i]!=s[i-1]))
		{
			h.push_back(ct);
			ct=0;
		}
		ct++;
	}
	if(h.size()==2)
	{
		printf("%lld\n",C(n,h[0])%M);
		return 0;
	}
	printf("%lld\n",func(s)%M);
	return 0;
}
