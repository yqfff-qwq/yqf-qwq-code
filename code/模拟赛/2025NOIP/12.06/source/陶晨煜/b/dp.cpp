#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DEP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define pb push_back
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=3e5+10;
int a[maxn],b[maxn],n;
int ans[maxn];
void main1()
{
	REP(i,1,n) ans[i]=0;
	vector<int> pos;
	pos.pb(1);
	REP(i,1,n-1)
	{
		if(a[i]<a[i+1])
		{
			while(a[i+1]<a[i+2]&&i+2<=n) i++;
			pos.pb(i+1);
		}
		else
		{
			while(a[i+1]>a[i+2]&&i+2<=n) i++;
			pos.pb(i+1);
		}
	}
	int beg=0;
	//0< 1>
	if(a[1]>a[2]) beg=1;
	multiset<int> s1,s2;
	REP(i,1,n) s1.insert(b[i]),s2.insert(-b[i]);
	REP(i,1,(int)pos.size()-2)
	{
		if(beg)
		{
			int num=*s1.begin();
			ans[pos[i]]=num;
			s1.erase(*s1.begin());
			s2.erase(s2.lower_bound(-num));
		}
		else
		{
			int num=-*s2.begin();
			ans[pos[i]]=num;
			s1.erase(s1.lower_bound(num));
			s2.erase(*s2.begin());
		}
		beg^=1;
	}
	if(a[1]<a[2])
	{
		int num=*s1.begin();
		ans[1]=num;
		s1.erase(*s1.begin());
		s2.erase(s2.lower_bound(-num));
	}
	else
	{
		int num=-*s2.begin();
		ans[1]=num;
		s1.erase(s1.lower_bound(num));
		s2.erase(*s2.begin());
	}
	if(a[n-1]<a[n])
	{
		int num=-*s2.begin();
		ans[n]=num;
		s1.erase(s1.lower_bound(num));
		s2.erase(*s2.begin());
	}
	else
	{
		int num=*s1.begin();
		ans[n]=num;
		s1.erase(*s1.begin());
		s2.erase(s2.lower_bound(-num));
	}
	REP(i,1,n)
	if(ans[i]==0)
	{
		if(a[i-1]>a[i])
		{
			auto it=s2.lower_bound(-ans[i-1]);
			if(it==s2.end())
			{cerr<<"Oh no\n";
			cout<<"Wrong!\n";
	REP(i,1,n) cout<<a[i]<<" ";cout<<"\n";
	REP(i,1,n) cout<<b[i]<<" ";cout<<"\n";
	exit(0);
			}
			ans[i]=-*it;
			s2.erase(it);
			s1.erase(s1.lower_bound(-*it));
		}
		else
		{
			auto it=s1.lower_bound(ans[i-1]);
			if(it==s1.end())
			{
			cerr<<"Oh no\n";
			cout<<"Wrong!\n";
	REP(i,1,n) cout<<a[i]<<" ";cout<<"\n";
	REP(i,1,n) cout<<b[i]<<" ";cout<<"\n";
	exit(0);
			}
			ans[i]=*it;
			s1.erase(it);
			s2.erase(s2.lower_bound(-*it));
		}
	}
	ll u=0;
	REP(i,1,n-1) u+=abs(ans[i+1]-ans[i]);
	REP(i,1,n-1) if((a[i]<a[i+1]&&ans[i]>ans[i+1])||(a[i]>a[i+1]&&ans[i]<ans[i+1]))
	{
	cout<<"Wrong!\n";
	REP(i,1,n) cout<<a[i]<<" ";cout<<"\n";
	REP(i,1,n) cout<<b[i]<<" ";cout<<"\n";
	exit(0);
	}
}
ll RAND()
{
	return rand()*1ll*RAND_MAX*1ll+rand();
}
int main()
{
	n=3e5;
	int u=0;
	while(1)
	{
		u++;
		unordered_map<int,int> mp;
		REP(i,1,n)
		{
			a[i]=RAND()%(int)(1e9)+1;
			if(mp[a[i]]) a[i]=RAND()%(int)(1e9)+1;
			mp[a[i]]=1;
		}
		mp.clear();
		REP(i,1,n)
		{b[i]=RAND()%(int)(1e9)+1;
		if(mp[b[i]]) b[i]=RAND()%(int)(1e9)+1;
			mp[b[i]]=1;
		}
		main1();
		if(u%1==0)
		cout<<"Accpted! # "<<u<<"!\n";
	}
}
