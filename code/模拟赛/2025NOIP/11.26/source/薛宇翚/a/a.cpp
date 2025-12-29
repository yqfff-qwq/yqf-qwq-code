#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	string s;
	cin>>s;
	s+="#";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[0])
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
