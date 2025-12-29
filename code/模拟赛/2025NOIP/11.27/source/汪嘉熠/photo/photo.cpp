#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int const N=1e4+5;
int n,t;
struct Node{
	int st,ed,id;
}t[N];
struct segmenttree{
	struct Node{
		int l,r,w,d,id;
	}tr[N<<3];
	#define lc (p<<1)
	#define rc (p<<1|1)
	void pushup(int p){
		if(tr[lc].w>tr[rc].w){
			tr[p].w=tr[lc].w;
			tr[p].id=tr[lc].id;
		}
		else{
			tr[p].w=tr[rc].w;
			tr[p].id=tr[rc].id;
		}
	}
	void pushdown(int p){
		if(tr[p].d){
			tr[lc].w+=tr[p].d;
			tr[rc].w+=tr[p].d;
			tr[lc].d+=tr[p].d;
			tr[rc].d+=tr[p].d;
			tr[p].d=0;
		}
	}
	void build(int p,int l,int r){
		tr[p]={l,r,0,0};
		if(l==r){
			tr[p].id=l;
			return;
		}
		int mid=l+r>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void qmodfiy(int p,int x,int y){
		if(x<=tr[p].l&&tr[p].r<=y){
			tr[p].w++;
			tr[p].d++;
			return;
		}
		pushdown(p);
		int mid=tr[p].l+tr[p].r>>1;
		if(x<=mid)qmodfiy(lc,x,y);
		if(y>mid)qmodfiy(rc,x,y);
		pushup(p);
	}
	pair<int,int>query(int p,int x,int y){
		if(x<=tr[p].l&&tr[p].r<=y)
			return tr[p].w;
		pushdown(p);
		int mid=tr[p].l+tr[p].r>>1;
		pair<int,int>res={0x3f3f3f3f,0};
		if(x<=mid){
			auto it=query(lc,x,y);
			if(it.w<res.w)res=it;
		}
		if(y>mid){
			auto it=query(rc,x,y);
			if(it.w<res.w)res=it;
		}
		return res;
	}
}segtr;
namespace case1{
	int way[N];
	void solve(){
		segtr.build(1,1,n*2);
		sort(t+1,t+n+1,[](const Node&x,const Node&y){
			int l1=x.ed-x.st,l2=y.ed-y.st;
			if(l1!=l2)return l1<l2;
			return x.st<y.st;
		});
		vector<int>h;
		for(int i=1;i<=n;i++){
			h.emplace_back(t[i].st);
			h.emplace_back(t[i].ed);
		}
		sort(h.begin(),h.end());
		h.erase(unique(h.begin(),h.end()),h.end());
		for(int i=1;i<=n;i++){
			int st=lower_bound(h.begin(),h.end(),t[i].st)-h.begin()+1;
			int ed=lower_bound(h.begin(),h.end(),t[i].ed)-h.begin()+1;
			auto it=segtr.query(1,st,ed);
			if(it.first!=0){
				cout<<"no";
				return;
			}
			way[t[i].id]=it.second;
		}
		cout<<"yes\n";
		for(int i=1;i<=n;i++)
			cout<<way[i]<<' ';
		return;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>t[i].st>>t[i].ed;
		t[i].id=i;
	}
	if(t==1)case1::solve();
	return 0;
}
