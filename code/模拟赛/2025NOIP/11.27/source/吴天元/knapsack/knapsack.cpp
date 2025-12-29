#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pb emplace_back
#define SZ(a) ((int)(a).size())
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define gc getchar
#define cint const int

cint mod = 998244353;

cint INF = 1e18;

inline void cmx(int &a,int b){
	a=max(a,b);
}

inline void cmn(int &a,int b){
	a=min(a,b);
}

inline void add(int &a,int b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
	if(a<mod){
		a+=mod;
	}
}

inline int rd(){
	int x=0,y=1;
	char c=gc();
	for(;!isdigit(c);c=gc()){
		if(c=='-'){
			y=-1;
		}
	}
	for(;isdigit(c);c=gc()){
		x=(x<<3)+(x<<1)+(c^48);
	}
	return x*y;
}

namespace Day_Tao{
	cint N = 5e5 + 5;
	int n,M,t;
	struct node{
		int v,m;
		friend bool operator<(const node &a,const node &b){
			return a.m<b.m;
		}
	}a[N];
	int b[N],cnt[N];
	priority_queue<int,vector<int>,less<int>>q[41];
	void SOLVE(){
		n=rd(),M=rd();
		F(i,1,n){
			int v=rd(),m=rd();
			a[i]=(node){v,m};
			b[i]=m;
		}
		sort(b+1,b+n+1);
		t=unique(b+1,b+n+1)-b-1;
		sort(a+1,a+n+1);
		F(i,1,n){
			int p=lower_bound(b+1,b+t+1,a[i].m)-b;
			q[p].push(a[i].v);
		}
		F_(i,t,1){
			cnt[i]=M/b[i];
			M%=b[i];
		}
		int ans=0;
		F(i,1,t){
			while(!q[i].empty()&&cnt[i]){
				int v=q[i].top();
				q[i].pop();
				ans+=v;
				cnt[i]--;
			}
			int ct=0,sm=0;
			while(!q[i].empty()){
				++ct;
				sm+=q[i].top();
				q[i].pop();
				if(ct==b[i+1]/b[i]){
					q[i+1].push(sm);
					sm=0,ct=0;
				}
			}
			if(sm){
				q[i+1].push(sm);
			}
		}
		printf("%lld\n",ans);
		return ;
	}
}

signed main(){
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	int T=1;
	// T=rd();
	while(T--){
		Day_Tao::SOLVE();
	}
	return 0;
}