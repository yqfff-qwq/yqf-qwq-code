#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using uint=unsigned int;
using ull=unsigned long long;
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define ne nth_element
#define mie min_element
#define mae max_element
#define eb emplace_back
#define ump unordered_map
#define pq priority_queue
#define clz __builtin_clz
#define ctz __builtin_ctz
#define sz(x) (int)x.size()
#define np next_permutation
#define clzl __builtin_clzll
#define ctzl __builtin_ctzll
#define ppc __builtin_popcount
#define all(x) x.begin(),x.end()
#define ppcl __builtin_popcountll
#define fpi(x) freopen(x,"r",stdin)
#define fpo(x) freopen(x,"w",stdout)
#define Time cerr<<"\nTime: "<<clock()
#define uid uniform_int_distribution
#define me(x,y) memset(x,y,sizeof(x))
#define seed chrono::system_clock::now().time_since_epoch().count()
#ifdef Nuj
template<class T> void _dbg(T h){
	string s=typeid(T).name();
	cerr<<" = ";
	bool f=s=="PKc"||s=="Pc"||s=="Ss";
	if(f) cerr<<'"';if(s=="c") cerr<<(char)39;
	cerr<<h;
	if(f) cerr<<'"';if(s=="c") cerr<<(char)39;
}
template<class T> void _dbg(int l,const char *c,T h){
	if(l) cerr<<fixed<<setprecision(10)<<"In Line "<<l<<' ';
	cerr<<c,_dbg(h),cerr<<endl;
}
template<class T,class...H> void _dbg(int l,const char *c,T h,H... a){
	if(l) cerr<<fixed<<setprecision(10)<<"In Line "<<l<<' ';
	int t=0;bool f=0,g=0;
	while(*c^44||f|g|t){
		if(*c==39) f=!f;if(*c==34) g=!g;
		if(!f&!g) t+=(*c==40)-(*c==41)+(*c==91)-(*c==93)+(*c=='{')-(*c=='}');
		cerr<<*c++;
	}
	_dbg(h),cerr<<", ",_dbg(0,++c,a...);
}
#define dbg(...) _dbg(__LINE__,#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...) 0
#define assert(...) 0
#endif
#define mod 998244353
#define inf 0x3f3f3f3f
vector<int> edge[500005];
ll t[500005],len[500005],w[500005],ans;
inline bool cmp(int x,int y){
	return t[x]*w[y]<t[y]*w[x];
}
void dfs(int u){
	for(int v:edge[u]) dfs(v),ans+=len[v]*w[v],w[u]+=w[v],t[u]+=t[v];
	sort(all(edge[u]),cmp);
	ll nowt=0;
	for(int v:edge[u]) ans+=nowt*w[v],nowt+=t[v];
}
int main(){
	fpi("walk.in");
	fpo("walk.out");
	#ifndef Nuj
	cin.tie(0)->sync_with_stdio(0);
	#endif
	int n;cin>>n;
	for(int i=2;i<=n;i++){
		int fa;cin>>fa>>len[i],t[i]=len[i];
		edge[fa].eb(i);
	}
	for(int i=1;i<=n;i++) cin>>w[i];
	dfs(1),cout<<ans;
	return 0;
}
