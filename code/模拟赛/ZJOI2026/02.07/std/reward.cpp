#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
#define pc putchar
#define sp pc(' ')
#define en pc('\n')
#define gc getchar()
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
#define fs fflush(stdout)
#define ump unordered_map
#define pq priority_queue
#define clz __builtin_clz
#define ctz __builtin_ctz
#define sz(x) (int)x.size()
#define np next_permutation
#define clzl __builtin_clzll
#define par __builtin_parity
#define ctzl __builtin_ctzll
#define ppc __builtin_popcount
#define parl __builtin_parityll
#define all(x) x.begin(),x.end()
#define ppcl __builtin_popcountll
#define fpi(x) freopen(x,"r",stdin)
#define fpo(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define dbg(x) cerr<<#x<<"= "<<(x)<<'\n'
template<class T> inline T &rd(T &x){
	x=0;int f=1;char ch=gc;
	while(ch<48||ch>57){if(ch==45) f=-f;ch=gc;}
	while(ch>47&&ch<58) x=(x<<1)+(x<<3)+(ch^48),ch=gc;
	return x*=f;
}
template<class T> inline void pr(T x){
	static char buf[40];static int cnt=0;
	if(x<0) pc(45),x=-x;
	do buf[++cnt]=x%10^48;while(x/=10);
	do pc(buf[cnt--]);while(cnt);
}
#define mod 998244353
#define inf 0x3f3f3f3f
vector<int> edge[500005],vec[500005];
int len[2000005],n,ls[2000005],rs[2000005],sum[2000005],ans[500005],tot,tim,dfn[500005],siz[500005];
void build(int x,int l,int r){
	x=++tot;if(l==r) return ;
	int mid=l+r>>1;build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}
void change(int x,int l,int r,int l1,int r1,int v){
	if(l<=l1&&r1<=r){if(len[x]+=v) sum[x]=r1-l1+1;else sum[x]=sum[x<<1]+sum[x<<1|1];return ;}
	int mid=l1+r1>>1;
	if(l<=mid) change(x<<1,l,r,l1,mid,v);if(mid<r) change(x<<1|1,l,r,mid+1,r1,v);
	if(!len[x]) sum[x]=sum[x<<1]+sum[x<<1|1];
}
void dfs1(int u){
	dfn[u]=++tim,siz[u]=1;
	for(int v:edge[u]) dfs1(v),siz[u]+=siz[v];
}
void dfs2(int u){
	for(int to:vec[u]) change(1,dfn[u],dfn[u]+siz[u]-1,1,n,1),change(1,dfn[to],dfn[to]+siz[to]-1,1,n,1);
	ans[u]=sum[1];for(int v:edge[u]) dfs2(v);
	for(int to:vec[u]) change(1,dfn[u],dfn[u]+siz[u]-1,1,n,-1),change(1,dfn[to],dfn[to]+siz[to]-1,1,n,-1);
}
int main(){
	fpi("reward.in");
	fpo("reward.out");
	cin.tie(0)->sync_with_stdio(0);
	int i,m;cin>>n>>m;
	for(i=1;i<n;i++){int fa;cin>>fa,edge[fa].eb(i+1);}
	while(m--){int u,v;cin>>u>>v;vec[u].eb(v),vec[v].eb(u);}
	dfs1(1),build(1,1,n),dfs2(1);for(i=1;i<=n;i++) cout<<max(0,ans[i]-1)<<' ';
	return 0;
}
