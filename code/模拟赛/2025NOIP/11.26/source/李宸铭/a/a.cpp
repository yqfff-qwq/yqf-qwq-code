#include<bits/stdc++.h>
using namespace std;
int ans=0x3f3f3f3f;
string s;
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>s;
	
//	bool flag=1;
//	for(int i=1;i<s.size();i++)
//	{
//		if(s[i]!=s[i-1])
//		{
//			flag=0;
//			break;
//		}
//	}
//	if(flag==1)
//	{
//		cout<<s.size()<<'\n';
//		return 0;
//	}
	
	int st=1;
	while(s[st]==s[st-1]) st++;
	cout<<st<<'\n';
//	int la=s[st],sum=1;
//	for(int i=st+1;i<s.size();i++)
//	{
//		if(s[i]==la) sum++;
//		else
//		{
//			ans=min(ans,sum);
//			la=s[i];
//			sum=1;
//		}
//	}
//	if(sum!=0) ans=min(ans,sum);
//	
//	cout<<max(ans,st)<<'\n'; 
	
	return 0;
}
//000010011001001000111
