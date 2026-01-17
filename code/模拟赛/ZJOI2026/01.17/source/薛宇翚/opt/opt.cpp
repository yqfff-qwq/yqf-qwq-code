#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7,N=5e5+1000;
int n,a[N],b[N],as;
string s,t;
vector<string>alis;
void dfs1(int x)
{
	if(x==t.size())
	{
		//cout<<"pb "<<t<<"\n";
		alis.push_back(t);
		return;
	}
	if(t[x]!='?')
	{
		dfs1(x+1);
	}
	else
	{
		t[x]='0';
		dfs1(x+1);
		t[x]='1';
		dfs1(x+1);
		t[x]='?';
	}
}
void dfs(int x)
{
	if(x==s.size())
	{
		//cout<<"s="<<s<<"\n";
		map<string,int>mp;
		mp[s]=1;
		queue<string>q;
		q.push(s);
		while(!q.empty())
		{
			string x=q.front();
			int d=mp[x];
			//cout<<x<<" "<<d<<"\n";
			q.pop();
			for(int i=1;i<n;i++)
			{
				if(x[a[i]]==x[b[i]])
				{
					string y=x;
					y[a[i]]='0'+'1'-y[a[i]];
					y[b[i]]='0'+'1'-y[b[i]];
					if(!mp[y])
					{
						mp[y]=d+1;
						q.push(y);
					}
				}
			}
		}
		for(int i=0;i<alis.size();i++)
		{
			if(mp.find(alis[i])!=mp.end())
			{
				as+=mp[alis[i]]-1;
				as%=M;
			}
		}
		return;
	}
	if(s[x]!='?')
	{
		dfs(x+1);
	}
	else
	{
		s[x]='0';
		dfs(x+1);
		s[x]='1';
		dfs(x+1);
		s[x]='?';
	}
}
int main()
{
	freopen("opt.in","r",stdin);
	freopen("opt.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
	}
	cin>>s>>t;
	dfs1(0);
	dfs(0);
	cout<<as<<"\n";
	return 0;
}
/*
世上最可敬的
便是那
即使胜利无望
也一定要把热血
洒到最后一刻
也一定要奋战
直至最后一息
也一定要在纸上
写下壮烈的最后一笔
正如一句话所说
有存在，便有希望
有希望，便是光明
虽死
亦有荣焉 
*/
