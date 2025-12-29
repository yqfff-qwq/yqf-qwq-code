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

#define int unsigned long long

struct SegTree{
	int ls,rs;
	int sum;
};

vector<SegTree> tr;

void pushup(SegTree &u,SegTree l,SegTree r){
	u.sum=l.sum+r.sum;
}
void pushup(int u){
	pushup(tr[u],tr[tr[u].ls],tr[tr[u].rs]);
}

void build(int u,int l,int r){
	tr[u].sum=0;
	if(l==r) return;
	int mid=l+r>>1;
	tr.push_back({});
	tr[u].ls=tr.size()-1;
	tr.push_back({});
	tr[u].rs=tr.size()-1;
	build(tr[u].ls,l,mid);
	build(tr[u].rs,mid+1,r);
	pushup(u);
}

void modify(int u,int x,int v,int la,int l,int r){
	if(l==r){
		tr[u].sum+=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid){
		tr[u].rs=tr[la].rs;
		tr.push_back(tr[tr[la].ls]);
		tr[u].ls=tr.size()-1;
		modify(tr[u].ls,x,v,tr[la].ls,l,mid);
	}else{
		tr[u].ls=tr[la].ls;
		tr.push_back(tr[tr[la].rs]);
		tr[u].rs=tr.size()-1;
		modify(tr[u].rs,x,v,tr[la].rs,mid+1,r);
	}
	pushup(u);
}

int query(int u,int ql,int qr,int l,int r){
//	cout<<l<<" "<<r<<endl;
	if(l>=ql&&r<=qr) return tr[u].sum;
	int mid=l+r>>1;
	int res=0;
	if(ql<=mid) res+=query(tr[u].ls,ql,qr,l,mid);
	if(qr>mid) res+=query(tr[u].rs,ql,qr,mid+1,r);
	return res;
}

const int N=2e5+10;

int edge[N<<1],ne[N<<1],head[N],tail[N],idx;
void con(int u,int v){
	idx++;
	edge[idx]=v;
	if(head[u]) ne[tail[u]]=idx;
	else head[u]=idx;
	tail[u]=idx;
}

int fa[N],id[N],pre_id[N],ver[N],sz[N],cnt;
void dfs(int u){
	cnt++;
	id[u]=cnt;
	pre_id[cnt]=u;
	sz[u]=1;
	for(int i=head[u];i;i=ne[i]){
		int v=edge[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		dfs(v);
		sz[u]+=sz[v];
	}
}

int n,q,rt;
int query(int u,int l,int r){
	return query(ver[id[u]+sz[u]-1],l,r,1,n)-query(ver[id[u]-1],l,r,1,n);
}

int juhuacnt;
namespace JUHUA{
	void Main(){
//		cout<<"juhua"<<endl;
		while(q--){
			int l,r,u;
			input(l);
			input(r);
			input(u);
			int t=r-l+1;
			if(u!=rt) print(0);
			else print(t*(t-1)/2);
			putchar('\n');
		}
		exit(0);
	}
}
signed main(){
	freopen("rplexq.in","r",stdin);
	freopen("rplexq.out","w",stdout);
	input(n);
	input(q);
	input(rt);
	for(int i=1;i<n;i++){
		int u,v;
		input(u);
		input(v);
		con(u,v);
		con(v,u);
		if(u==rt||v==rt) juhuacnt++;
	}
	if(juhuacnt==n-1) JUHUA::Main();
	dfs(rt);
	tr.push_back({});
	ver[0]=tr.size()-1;
	build(ver[0],1,n);
	for(int i=1;i<=n;i++){
		tr.push_back(tr[ver[i-1]]);
		ver[i]=tr.size()-1;
		modify(ver[i],pre_id[i],1,ver[i-1],1,n);
	}
	while(q--){
		int l,r,u;
		input(l);
		input(r);
		input(u);
		int t=query(u,l,r);
		int res=0;
//		cout<<t<<" ";
		for(int i=head[u];i;i=ne[i]){
			int v=edge[i];
			if(fa[u]==v) continue;
			int d=query(v,l,r);
			res+=d*(t-d);
//			cout<<res<<endl;
		}
		if(l<=u&&u<=r) res+=t-1;
		print(res/2);
		putchar('\n');
//		cout<<endl;
	}
}

