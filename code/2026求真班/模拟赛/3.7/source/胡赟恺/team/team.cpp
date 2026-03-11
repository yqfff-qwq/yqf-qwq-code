#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a[200668];
map<int,int>m;
inline int read(){
	int ret=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w*=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ret=(ret<<3)+(ret<<1)+c-'0';
		c=getchar();
	}
	return ret*w;
}
signed main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=read();
		m[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=0;j<=5;j++){
			cnt+=m[a[i]+j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
