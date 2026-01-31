#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int ma=0;
	while(!('0'<=c&&c<='9'))c=getchar();
	while(('0'<=c&&c<='9'))ma=ma*10+c-'0',c=getchar();
	return ma;
}
const int N=2e6+20;
int n,m,ans=2e9+20;
int a[N];
int c[N];
int vis[N];
int kcm(){
	int ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,(c[i]+c[n+i])%m);
	return ma;
}
void dfs(int x){
	if(x>2*n){
		ans=min(kcm(),ans);
		return ;
	}
	for(int i=1;i<=2*n;i++)
		if(vis[i]==0){
			c[x]=a[i];
			vis[i]++;
			dfs(x+1);
			vis[i]--;
		}
}
void sol(){
	n=read(),m=read();
	for(int i=1;i<=n*2;i++){
		a[i]=read();
		a[i]%=m;
	}
	dfs(1);
	cout<<ans<<"\n";
}
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	int t=read();
	while(t--)sol();
	return 0;
}
