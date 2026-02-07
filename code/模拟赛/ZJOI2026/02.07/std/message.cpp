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
#define mod 1000000007
#define inf 0x3f3f3f3f
int f[205][205][205],sum[205][205][205],a[205],inv[205];
inline int rmod(int x){
	return x-mod+(x-mod>>31&mod);
}
inline int lmod(int x){
	return x+(x>>31&mod);
}
int main(){
	fpi("message.in");
	fpo("message.out");
	#ifndef Nuj
	cin.tie(0)->sync_with_stdio(0);
	#endif
	int n,m;cin>>n>>m;
	inv[1]=1;for(int i=2;i<=m+1;i++) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m+1;i++){
		sum[i][i-1][0]=f[i][i-1][0]=1;
		for(int j=1;j<=m+1;j++) sum[i][i-1][j]=rmod(sum[i][i-1][j-1]+f[i][i-1][j]);
	}
	for(int len=1;len<=m;len++) for(int l=1;l<=m-len+1;l++){
		int r=l+len-1;
		for(int i=l;i<=r;i++) if(a[i]^a[r+1]){
			for(int j=1;j<=m+1;j++) f[l][r][j]=(f[l][r][j]+(ll)sum[l][i-1][j-1]*sum[i+1][r][j])%mod;
		}
		sum[l][r][0]=f[l][r][0];
		for(int i=1;i<=m+1;i++) sum[l][r][i]=rmod(sum[l][r][i-1]+f[l][r][i]);
	}
	if(n<=m+1) cout<<sum[1][m][n];
	else{
		int ans=0;
		for(int i=1;i<=m+1;i++){
			int mul=1;
			for(int j=0;j<=m+1;j++){
				if(i<j) mul=lmod((ll)mul*(j-n)%mod*inv[j-i]%mod);
				if(i>j) mul=(ll)mul*(n-j)%mod*inv[i-j]%mod;
			}
			ans=(ans+(ll)sum[1][m][i]*mul)%mod;
		}
		cout<<ans;
	}
	return 0;
}
