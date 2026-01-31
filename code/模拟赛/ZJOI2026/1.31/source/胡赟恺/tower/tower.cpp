#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define getchar _getchar_nolock
#else
#define getchar getchar_unlocked
#endif
inline int read(){
	int ret=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ret=(ret<<3)+(ret<<1)+c-'0';
		c=getchar();
	}
	return ret*w;
}
int n,m,n2,T;
int a[100005];
map<int,int>p;
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	cin>>T;
	while(T--){
		p.clear();
		cin>>n>>m;
		n2=n,n*=2;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			p[a[i]]++;
		}
		srand(time(0));
		cout<<rand()%m<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
