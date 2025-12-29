#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DEP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define pb push_back
#define ll long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=3e5+10;
int a[maxn],b[maxn];
int ans[maxn];
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	Ios();
	int n;
	cin>>n;
	REP(i,1,n) cin>>a[i];
	REP(i,1,n) cin>>b[i];
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
	ll u=0;
	REP(i,1,n-1)
	{
		if(a[i]<a[i+1])
		u+=ans[i+1]-ans[i];
		else u+=ans[i]-ans[i+1]; 
	}
	cout<<u<<"\n";
	REP(i,1,n)
	if(ans[i]==0)
	{
		if(a[i-1]>a[i])
		{
			auto it=s2.lower_bound(-ans[i-1]);
			if(it==s2.end()) continue;
			ans[i]=-*it;
			s2.erase(it);
			s1.erase(s1.lower_bound(-*it));
		}
		else
		{
			auto it=s1.lower_bound(ans[i-1]);
			if(it==s1.end()) continue;
			ans[i]=*it;
			s1.erase(it);
			s2.erase(s2.lower_bound(-*it));
		}
	}
	//REP(i,1,n-1) if((a[i]<a[i+1]&&ans[i]>ans[i+1])||(a[i]>a[i+1]&&ans[i]<ans[i+1])) cerr<<"Wrong!\n";
	REP(i,1,n) cout<<ans[i]<<" ";
}
//<><<
//abcde
//b-a+b-c+e-c
/*
checker b1.in b1.out b1.ans
checker b2.in b2.out b2.ans
checker b3.in b3.out b3.ans
checker b4.in b4.out b4.ans
checker b5.in b5.out b5.ans
checker b6.in b6.out b6.ans
*/
