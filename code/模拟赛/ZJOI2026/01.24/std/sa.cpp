#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<random>
#include<map>
#include<math.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) ((x)&-(x))
#define popcount(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define umap unordered_map
#define all(x) x.begin(),x.end()
#define mk make_pair
#define pb push_back
#define ckmax(x,y) x=max(x,y)
#define ckmin(x,y) x=min(x,y)
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define N 100005
using namespace std;
inline int read(){
	int x=0,f=0; char ch=getchar();
	while(!isdigit(ch)) f|=(ch==45),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int mo=998244353;
inline void red(int &x){x>=mo?x-=mo:0;}
inline int qpow(int x,int b){
	int res=1;
	for(;b;x=1LL*x*x%mo,b>>=1) if(b&1) res=1LL*res*x%mo;
	return res;
}
struct FHQ{
	int ls,rs,sze,cnt,sum,lazy;
	pii v;
}T[N*2];
int rt,pool;
mt19937 rnd(114514);
inline int newNode(int l,int r){
	T[++pool].sze=1,T[pool].cnt=T[pool].sum=max(r-l+1,l-r+1),T[pool].v={l,r};
	return pool;
}
inline void pushup(int k){
	T[k].sze=T[T[k].ls].sze+T[T[k].rs].sze+1;
	T[k].sum=T[T[k].ls].sum+T[T[k].rs].sum+T[k].cnt;
}
inline void pushdown(int k){
	if(!T[k].lazy) return;
	T[k].lazy=0;
	swap(T[T[k].ls].v.fi,T[T[k].ls].v.se);
	swap(T[T[k].rs].v.fi,T[T[k].rs].v.se);
	swap(T[T[k].ls].ls,T[T[k].ls].rs);
	swap(T[T[k].rs].ls,T[T[k].rs].rs);
	T[T[k].ls].lazy^=1;
	T[T[k].rs].lazy^=1;
}
int U;
void split(int k,int &x,int &y,int s){
	if(!k) return (void)(x=y=0);
	pushdown(k);
	if(T[T[k].ls].sum+T[k].cnt<=s){
		x=k;
		split(T[k].rs,T[k].rs,y,s-T[T[k].ls].sum-T[k].cnt);
		U+=T[T[k].ls].sum+T[k].cnt;
	}
	else{
		y=k;
		split(T[k].ls,x,T[k].ls,s);
	}
	pushup(k);
}
int merge(int x,int y){
	if(!x || !y) return x+y;
	pushdown(x),pushdown(y);
	if(rnd()%(T[x].sze+T[y].sze)<T[x].sze){
		T[x].rs=merge(T[x].rs,y);
		pushup(x);return x;
	}
	else{
		T[y].ls=merge(x,T[y].ls);
		pushup(y);return y;
	}
}
int n,m;
pii b[2*N];
void get(int k){
	pushdown(k);
	if(T[k].ls) get(T[k].ls);
	b[++m]=T[k].v;
	if(T[k].rs) get(T[k].rs);
}
map<int,int> rk;
signed main(){
	freopen("sa.in","r",stdin);
	freopen("sa.out","w",stdout);
	n=read(),m=read();
	rt=newNode(1,n);
	for(int i=1;i<=m;++i){
		int op=read(),l=read(),r=read();
		int x,y,z;
		U=0;
		split(rt,x,y,l-1);
		U=l-1-U;
		if(U){
			int now=y;
			while(T[now].ls){
				pushdown(now);
				T[now].sum-=U;
				now=T[now].ls;
			}
			T[now].sum-=U,T[now].cnt-=U;
			if(T[now].v.fi<=T[now].v.se){
				int mid=T[now].v.fi+U-1;
				x=merge(x,newNode(T[now].v.fi,mid));
				T[now].v.fi=mid+1;
			}
			else{
				int mid=T[now].v.fi-U+1;
				x=merge(x,newNode(T[now].v.fi,mid));
				T[now].v.fi=mid-1;
			}
		}
		U=0;
		split(y,y,z,r-l+1);
		U=(r-l+1)-U;
		if(U){
			int now=z;
			while(T[now].ls){
				pushdown(now);
				T[now].sum-=U;
				now=T[now].ls;
			}
			T[now].sum-=U,T[now].cnt-=U;
			if(T[now].v.fi<=T[now].v.se){
				int mid=T[now].v.fi+U-1;
				y=merge(y,newNode(T[now].v.fi,mid));
				T[now].v.fi=mid+1;
			}
			else{
				int mid=T[now].v.fi-U+1;
				y=merge(y,newNode(T[now].v.fi,mid));
				T[now].v.fi=mid-1;
			}
		}
		if(op==0){
			rt=merge(y,merge(x,z));	
		}
		else{
			swap(T[y].v.fi,T[y].v.se);
			swap(T[y].ls,T[y].rs);
			T[y].lazy^=1;
			rt=merge(x,merge(y,z));
		}
	}
	m=0;
	get(rt);
	// for(int i=1;i<=m;++i) fprintf(stderr,"%d %d\n",b[i].fi,b[i].se);
	int pre=0;
	for(int i=1;i<=m;++i){
		rk[b[i].fi]=pre+1;
		pre+=abs(b[i].fi-b[i].se)+1;
		rk[b[i].se]=pre;
	}
	int ans=-1,lst=-1;
	pre=0;
	for(int i=1;i<=m;++i){
		if(b[i].fi<=b[i].se){
			if(b[i].fi!=b[i].se){
				if(pre+2>lst) ans++;
			}
			else if(rk[b[i].fi+1]>lst) ans++;
			pre+=b[i].se-b[i].fi+1;
			if(b[i].fi!=b[i].se){
				if(rk[b[i].se+1]>pre) ans++;
			}
			lst=rk[b[i].se+1];
		}
		else{
			if(rk[b[i].fi+1]>lst) ans++;
			if(pre+1>rk[b[i].fi+1]) ans++;
			pre+=b[i].fi-b[i].se+1;
			lst=pre-1;
		}
		ans+=max(0,abs(b[i].fi-b[i].se)-1);
	}
	cout<<qpow(2,ans);
	return 0;
}
