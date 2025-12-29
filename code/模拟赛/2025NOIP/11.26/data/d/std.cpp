#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int N=2e5+5;
int n,m,a[N],b[N],st1[N][20],st0[N][20],ans[N],v[N],M;
int get(int x,int y){
	return b[x]==b[y]?max(x,y):b[x]>b[y]?y:x;
}
struct fenwick{
	int t[N];
	void upd(int p,int v){
		for(;p<N;p+=p&-p)t[p]+=v;
	}
	int qry(int p){
		int s=0;
		for(;p;p-=p&-p)s+=t[p];
		return s;
	}
}K,B;
vector<array<int,3>>qy[N];
void upd(int i,int x,int y,int w){
	int L=lower_bound(v+1,v+M+1,x=a[x]-a[i])-v,
		R=lower_bound(v+1,v+M+1,y=a[y]-a[i])-v;
	K.upd(L,w);K.upd(R,-w);
	B.upd(L,-w*x);B.upd(R,w*y);
}
signed main(){
	n=rd();m=rd();
	for(int i=2;i<=n+1;i++)st1[i][0]=rd(),a[i]=st1[i][0]+a[i-1];
	for(int i=1;i<=n;i++)b[i]=rd(),st0[i][0]=i;
	st0[n+1][0]=n+1;
	for(int j=1;j<20;j++)
		for(int i=1;i+(1<<j)-1<=n+1;i++)
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<j-1)][j-1]),
			st0[i][j]=get(st0[i][j-1],st0[i+(1<<j-1)][j-1]);
	for(int i=1,l,r,u;i<=m;i++){
		l=rd();r=rd();v[i]=u=rd();
		auto getmx=[&](int l,int r){
			int t=__lg(r-l+1);
			return max(st1[l][t],st1[r-(1<<t)+1][t]);
		};
		if(getmx(l+1,r)>u){
			ans[i]=-1;
			continue;
		}
		qy[l].pb({u,1,i});
		int cur=r,ps=-1;
		for(int j=19;~j;j--)
			if(cur-(1<<j)+1>=l&&a[r]-a[cur-(1<<j)+1]<=u)cur-=1<<j;
		auto getmn=[&](int l,int r){
			int t=__lg(r-l+1);
			return get(st0[l][t],st0[r-(1<<t)+1][t]);
		};
		ps=getmn(cur+1,r);
		qy[ps].pb({u,-1,i});
		ans[i]=b[ps]*(a[r]-a[ps]);
	}
	sort(v+1,v+m+1);
	M=unique(v+1,v+m+1)-v-1;
	vi stk;
	for(int i=n+1;i;i--){
		while(!stk.empty()&&b[stk.back()]>b[i]){
			int x=stk.back();stk.pop_back();
			upd(i,x,stk.back(),-b[x]);
		}
		if(!stk.empty())upd(i,i,stk.back(),b[i]);
		stk.pb(i);
		for(auto [u,sig,id]:qy[i]){
			int p=lower_bound(v+1,v+M+1,u)-v;
			ans[id]+=sig*(K.qry(p)*u+B.qry(p));
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}
