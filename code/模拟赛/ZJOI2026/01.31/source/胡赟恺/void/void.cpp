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
int n,m,T;
int cnt,ga;
int fa[2000005];
int h[2000005],e[5000005],ne[5000005];
set<int> va[2000005];
void add(int u,int v){
	ne[++cnt]=h[u];
	h[u]=cnt;
	e[cnt]=v;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			fa[i]=i;
			h[i]=0;
			va[i].clear();
		}
		ga=n;
		for(int i=1;i<=m;i++){
			int u=read(),v=read();
			add(u,v),add(v,u);
			if(find(u)!=find(v)){
				fa[find(v)]=find(u);
				ga--;
			}
			va[u].insert(v);
			va[v].insert(u);
		}
		if(m==n*(n-1)/2){
			cout<<1<<' '<<2<<'\n';
			continue;
		}
		if(ga>1){
			int da=0;
			for(int i=1;i<=n;i++){
				if(fa[i]==i){
					if(!da)da=i;
					else{
						cout<<i<<' '<<da<<'\n';
						break;
					}
				}
			}
			continue;
		}
		for(int i=1,ffa=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int c=0;
				for(auto v:va[i]){
					auto it=va[j].find(v);
					if(it!=va[j].end())c++;
				}
				if(c%2==0){
					cout<<i<<' '<<j<<'\n';
					ffa=0;
					break;
				}
			}
			if(ffa==0)break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
