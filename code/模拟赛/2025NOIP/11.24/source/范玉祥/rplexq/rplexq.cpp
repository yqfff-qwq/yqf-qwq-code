#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int B=450,N=2e5+5;
int n,m,rt,dfn[N],cnt,x[N],y[N],z[N],ans[N];
vi son[N],e[N];
void dfs(int u,int fa){
	dfn[u]=++cnt;
	for(auto v:e[u])if(v^fa){
		son[u].pb(v),dfs(v,u);
	}
}
namespace fenkuai1{
	int bl[N],L[N],R[N];

}
namespace solsmall{
	vector<array<int,4>>qy[N];
	void sol(){
		for(int i=1;i<=m;i++){
			if(son[z[i]].size()<=B){
				for(auto to:son[z[i]]){
					qy[to].pb({x[i],y[i],i,-1});
				}
				qy[z[i]].pb({x[i],y[i],i,1});
			}
		}
		
	}
}
signed main(){
	n=rd();m=rd();rt=rd();
	for(int i=1,u,v;i<n;i++)
		u=rd(),v=rd(),e[u].pb(v),e[v].pb(u);
	dfs(rt,0);
	for(int i=1;i<=m;i++)x[i]=rd(),y[i]=rd(),z[i]=rd();
	
	return 0;
}