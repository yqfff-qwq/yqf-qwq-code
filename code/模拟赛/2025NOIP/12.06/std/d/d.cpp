//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=2e5+10;
int n,k,m,R,hz[N],a[N*2],b[N],lf[N*2],mp[N];
set<int>s[N];multiset<int>gg,hg;
struct Segment_Tree{
	#define ls (x<<1)
	#define rs (x<<1|1)
	#define mid ((l+r)>>1)
	int c[N<<2],mi[N<<2],g[N<<2];
	inline int qry(int x,int l,int r,int p){
		if (p<=mi[x]) return l-p+1;
		if (l==r) return l-mi[x]+1;
		if (mi[rs]<=p) return min(g[x],qry(rs,mid+1,r,p));
		else return min(qry(ls,l,mid,min({mi[rs],lf[mid+1],p})),mid+1-p+1);
	}
	inline void pushup(int x,int l,int r){
		g[x]=qry(ls,l,mid,min(mi[rs],lf[mid+1]));
		c[x]=min(c[rs],g[x]);
		mi[x]=min({mi[ls],mi[rs],lf[mid+1]});
	}
	inline void build(int x,int l,int r){
		if (l==r) return c[x]=mi[x]=2e9,void();
		build(ls,l,mid),build(rs,mid+1,r),pushup(x,l,r);
	}
	inline void update(int x,int l,int r,int p){
		if (l==r) return;
		if (p<=mid) update(ls,l,mid,p);
		else update(rs,mid+1,r,p);
		pushup(x,l,r);
	}
	inline int query(int x,int l,int r,int p,int &v){
		if (p>n) return 1e9;
		if (l>=p){
			int res=qry(x,l,r,v);
			v=min({v,mi[x],lf[l]});
			return res;
		}
		int ans=query(rs,mid+1,r,p,v);
		if (p<=mid) ans=min(ans,query(ls,l,mid,p,v));
		return ans;
	}
}T;
inline void upd(int id){
	T.update(1,1,n,id);
}
inline void solve(){
	cin>>n>>k>>m;
	rep(i,1,k) mp[i]=-2*n;
	rep(i,1,n) cin>>a[i];
	rep(i,n+1,n+k) a[i]=i-n;
	rep(i,1,n+k) lf[i]=mp[a[i]],mp[a[i]]=i,s[a[i]].insert(i);
	rep(i,1,k) gg.insert(*s[i].begin()),hg.insert(lf[*(--s[i].end())]);
	T.build(1,1,n);while (m--){
		int op;cin>>op;
		switch (op){
			case 1:{
				int p,v;cin>>p>>v;
				gg.erase(gg.find(*s[a[p]].begin()));
				hg.erase(hg.find(lf[*(--s[a[p]].end())]));
				auto it=s[a[p]].find(p);
				++it;
				int g=*it;
				--it;
				if (it==s[a[p]].begin()) lf[g]=-2*n,upd(g);
				else --it,lf[g]=*it,upd(g);
				s[a[p]].erase(p);
				gg.insert(*s[a[p]].begin());
				hg.insert(lf[*(--s[a[p]].end())]);
				a[p]=v;
				gg.erase(gg.find(*s[a[p]].begin()));
				hg.erase(hg.find(lf[*(--s[a[p]].end())]));
				it=s[a[p]].upper_bound(p);
				if (it!=s[a[p]].end()) lf[*it]=p,upd(*it);
				if (it!=s[a[p]].begin()) --it,lf[p]=*it;
				else lf[p]=-2*n;
				upd(p);
				s[a[p]].insert(p);
				gg.insert(*s[a[p]].begin());
				hg.insert(lf[*(--s[a[p]].end())]);
				break;
			}
			case 2:{
				R=*(--gg.end());
				int v=*hg.begin(),an=T.query(1,1,n,R,v);
				if (an>n) cout<<"-1\n";else cout<<an<<'\n';
				break;
			}
		}
	}
}
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}
