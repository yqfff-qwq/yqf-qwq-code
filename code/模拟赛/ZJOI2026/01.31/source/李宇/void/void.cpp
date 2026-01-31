#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
struct nnd{
	int to,vl;
};
int T;
int n,m;
int cf[2010][2010];
vector<int>g[N];
bool vs[N];
signed main(){
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		bool fg=0;
		memset(vs,0,sizeof vs);
		scanf("%lld %lld",&n,&m);
		// if(n<=500){
			for(int i=1;i<=m;i++){
				int x,y;
				scanf("%lld %lld",&x,&y);
				g[x].push_back(y);
				g[y].push_back(x);
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<g[i].size();j++) vs[g[i][j]]=1;
				int ff=0;
				for(int j=i+1;j<=n;j++){
					for(int k=0;k<g[j].size();k++)
						if(vs[g[j][k]]) ff++;
					if((g[i].size()+g[j].size()-ff)%2==0) {
						fg=1;
						printf("%lld %lld\n",i,j);
						break;
					}
				}
				if(fg) break;
				for(int j=0;j<g[i].size();j++) vs[g[i][j]]=0;
			}
			if(fg) continue;
		// }
	}
	return 0;
}