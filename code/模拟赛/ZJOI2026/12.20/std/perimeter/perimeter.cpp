//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=3e5+10;
int n,w,h,ans,ha[N],hb[N],a[N],b[N];
namespace Sub2{
	int prea[N],preb[N];
	struct node{int mx,L,R,pos;};
	inline node merge(node A,node B){
		node C;C.mx=max(A.mx,B.mx);
		if (A.mx==C.mx) C=A;else C=B;
		return C;
	}
	struct Segment_Tree{
		#define ls (x<<1)
		#define rs (x<<1|1)
		#define mid ((l+r)>>1)
		node c[N<<2];
		int lazy[N<<2],tg1[N<<2],tg2[N<<2];
		inline void push(int x,int y){
			c[x].mx+=y,lazy[x]+=y;
		}
		inline void pusH(int x,int y){
			c[x].L=tg1[x]=y;
		}
		inline void puSH(int x,int y){
			c[x].R=tg2[x]=y;
		}
		inline void pushdown(int x){
			if (lazy[x]) push(ls,lazy[x]),push(rs,lazy[x]),lazy[x]=0;
			if (tg1[x]) pusH(ls,tg1[x]),pusH(rs,tg1[x]),tg1[x]=0;
			if (tg2[x]) puSH(ls,tg2[x]),puSH(rs,tg2[x]),tg2[x]=0;
		}
		inline void build(int x,int l,int r){
			lazy[x]=tg1[x]=tg2[x]=0;
			if (l==r)
				return c[x].mx=-preb[l-1]+prea[n],
				c[x].pos=l,c[x].L=1,c[x].R=n,void();
			build(ls,l,mid),build(rs,mid+1,r);
			c[x]=merge(c[ls],c[rs]);
		}
		inline void update(int x,int l,int r,int ll,int rr,int v1,int v2){
			if (ll<=l && r<=rr){
				if (v1) push(x,prea[c[x].L-1]-prea[v1-1]),pusH(x,v1);
				if (v2) push(x,prea[min(n,v2+1)]-prea[min(n,c[x].R+1)]),puSH(x,v2);
				return;
			}
			pushdown(x);
			if (ll<=mid) update(ls,l,mid,ll,rr,v1,v2);
			if (mid<rr) update(rs,mid+1,r,ll,rr,v1,v2);
			c[x]=merge(c[ls],c[rs]);
		}
		inline node query(int x,int l,int r,int ll,int rr){
			if (ll<=l && r<=rr) return c[x];
			pushdown(x);
			if (ll<=mid && mid<rr) return merge(query(ls,l,mid,ll,rr),query(rs,mid+1,r,ll,rr));
			else if (ll<=mid) return query(ls,l,mid,ll,rr);
			else return query(rs,mid+1,r,ll,rr);
		}
	}T;
	int mxl[N],mir[N],stk1[N],stk2[N],top1,top2;
	inline void work(int op){
		rep(i,1,n) prea[i]=prea[i-1]+ha[i];
		rep(i,1,n) preb[i]=preb[i-1]+hb[i];
		int p=0;
		rep(i,1,n) if (prea[i]>prea[n]/2){p=i;break;}
		rep(i,1,n+n) mxl[i]=1,mir[i]=n;
		rep(i,1,p) mxl[a[i]]=i+1;
		per(i,n,p) mir[a[i]]=i-1;
		T.build(1,1,n),top1=top2=0;
		if (prea[n]>=ans) ans=prea[n];
		rep(i,1,n){
			while (top1 && mxl[b[stk1[top1]]]<mxl[b[i]]){
				T.update(1,1,n,stk1[top1-1]+1,stk1[top1],mxl[b[i]],0);
				--top1;
			}
			while (top2 && mir[b[stk2[top2]]]>mir[b[i]]){
				T.update(1,1,n,stk2[top2-1]+1,stk2[top2],0,mir[b[i]]);
				--top2;
			}
			T.update(1,1,n,i,i,mxl[b[i]],mir[b[i]]);
			node res=T.query(1,1,n,1,i);
			if (res.mx+preb[min(n,i+1)]>ans) ans=res.mx+preb[min(n,i+1)];
			stk1[++top1]=i,stk2[++top2]=i;
		}
	}
}
inline void solve(){
	cin>>n>>w>>h;
	int m=0;
	rep(i,1,n){
		int x,y;cin>>x>>y;
		if (x!=w && y!=h && x && y) ++m,ha[m]=x,hb[m]=y,a[m]=m,b[m]=m;
	}
	n=m;
	++n,a[n]=b[n]=n,ha[n]=w,hb[n]=h;
	++n,a[n]=b[n]=n,ha[n]=w,hb[n]=h;
	++n,a[n]=b[n]=n;
	++n,a[n]=b[n]=n;
	sort(a+1,a+n+1,[](int A,int B){return (ha[A]^ha[B])?(ha[A]<ha[B]):(A<B);});
	sort(b+1,b+n+1,[](int A,int B){return (hb[A]^hb[B])?(hb[A]<hb[B]):(A>B);});
	sort(ha+1,ha+n+1),sort(hb+1,hb+n+1);
	per(i,n,1) ha[i]-=ha[i-1],hb[i]-=hb[i-1];
	rep(i,1,n) ans=max(ans,ha[i]+h),ans=max(ans,hb[i]+w);
	int las=ans;
	Sub2::work(1),swap(a,b),swap(ha,hb),Sub2::work(2);
	cout<<ans*2<<'\n';
}
signed main(){
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}