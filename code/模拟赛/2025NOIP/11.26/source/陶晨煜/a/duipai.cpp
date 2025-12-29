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
int main1(string s)
{
	int n=s.size();
	s=" "+s;
	int pos=n;
	REP(i,1,n) if(s[i]!=s[1])
	{
		pos=i-1;
		break;
	}
	return pos;
}
int ans=0;
void dfs(string s)
{
	bool p=0;
	REP(i,1,s.size()-1-1)
	if(s[i]=='0'&&s[i+1]=='1')
	{p=1;
		string t=" ";
		REP(j,1,i-1) t+=s[j];
		t+='0';
		REP(j,i+2,s.size()-1) t+=s[j];
		dfs(t);
	}
	else if(s[i]=='1'&&s[i+1]=='0')
	{p=1;
		string t=" ";
		REP(j,1,i-1) t+=s[j];
		t+='1';
		REP(j,i+2,s.size()-1) t+=s[j];
		dfs(t);
	}
	if(!p)
	{
		ans=min(ans,(int)s.size()-1);
		return;
	}
}
int main2(string s)
{
	s=" "+s;
	ans=1e9;
	dfs(s);
	return ans;
}
int main()
{
	int cs=0;
	while(++cs)
	{
		if(cs%1000==0) cout<<"Accpted #"<<cs<<"\n";
		string g="";
		REP(i,0,10) g+=(rand()%2+'0');
		int u=main1(g),v=main2(g);
		if(u!=v)
		{
			cout<<g<<" "<<u<<" "<<v<<"\n";
			return 0;
		}
	}
}
