#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	string s;
	int ans=0;
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]==s[0])ans++;
		else break;
	}
	cout<<ans;
	return 0;
}
