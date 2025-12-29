#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=' ';
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(f) x=-x;
	}
	
	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;

const int N=1010;

int n,a[N];

int fa[N],sz[N];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);	
}

void merge(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v) return;
	if(u<v) swap(u,v);
	fa[u]=v;
	sz[v]+=sz[u];
}

int ans;
vector<int> v[N];

bool vis[N];
void dfs(int u,int T){
//	if(vis[u]) return;
//	vis[u]=1;
//	v[T].push_back(u);
//	dfs(a[u],T);
	for(u;!vis[u];vis[u]=1,u=a[u]) v[T].push_back(u);
}

signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	input(n);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) sz[i]=1;
	for(int i=1;i<=n;i++) input(a[i]);
	for(int i=1;i<=n;i++) merge(i,a[i]);
	for(int i=1;i<=n;i++){
		if(find(i)!=i) continue;
		if(sz[i]==1) continue;
		ans++;
		dfs(i,ans);
	}
	print(ans);
	putchar('\n');
	for(int i=1;i<=ans;i++,putchar('\n')){
		print(v[i].size());
		putchar(' ');
		for(auto x:v[i]) print(x),putchar(' ');
	}
}
