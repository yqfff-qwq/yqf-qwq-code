#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n,m,minn;
int a[10000010];
int b[10000010];
bool vs[100010];
void dfs(int s,int mx){
	if(s>2*n){
		// cout<<mx<<endl;
		minn=min(minn,mx);
		return ;
	}
	for(int i=1;i<=n*2;i++){
		if(!vs[i]){
			b[s]=a[i];
			vs[i]=1;
			if(s>n) mx=max(mx,(b[s]+b[s-n])%m);
			dfs(s+1,mx);
			vs[i]=0;
		}
	}
}
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		minn=1e9+10;
		memset(vs,0,sizeof vs);
		scanf("%lld %lld",&n,&m);
		for(int i=1;i<=n*2;i++) scanf("%lld",&a[i]);
		dfs(1,0);
		printf("%lld\n",minn);
	}
	return 0;
}