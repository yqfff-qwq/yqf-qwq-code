#include<bits/stdc++.h>
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	string s; cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++)
		if(s[i]==s[0])ans++;
		else break;
	cout<<ans;
	return 0;
}

