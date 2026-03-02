#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned int
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=4e5+5;
int n,m,p,v[N],cnt,q,r[N],f[N][20],mn[N<<2];
vi e[N],ad[N];
void upd(int p,int v,int l,int r,int rt){
	if(l==r){
		mn[rt]=v;
		return ;
	}
	int mid=l+r>>1;
	if(p<=mid)upd(p,v,l,mid,rt<<1);
	else upd(p,v,mid+1,r,rt<<1|1);
	mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
int calc(int l,int r){
	int L=lower_bound(v,v+cnt,l)-v+1,R=lower_bound(v,v+cnt,r)-v+1;
	if(L==R)return r-::r[R-1];
	int t=__lg(R-L);
	return max({f[L][t],f[R-(1<<t)][t],r-::r[R-1]});
}
signed main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
	n=rd(),m=rd(),p=rd();
	for(int u,v,w;m--;){
		u=rd(),v=rd(),w=rd();
		e[v].pb(w);
		::v[cnt++]=w;
	}
	sort(v,v+cnt);
	cnt=unique(v,v+cnt)-v;
	for(int i=1;i<=n;i++)
		for(auto w:e[i])ad[lower_bound(v,v+cnt,w)-v].pb(i);
	memset(r,inf,sizeof r);
	memset(mn,255,sizeof mn);
	int l=0,p=cnt;
	upd(1,inf,1,n,1);
	for(int r=0;r<p;r++){
		for(auto x:ad[r])upd(x,r,1,n,1);
		while(l<=mn[1])::r[l++]=v[r];
	}
	v[p]=inf;
	for(int i=0;i<p;i++)f[i+1][0]=v[i]-r[i];
	for(int j=1;j<20;j++)
		for(int i=1;i+(1<<j)-1<=p;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
	q=rd();
	for(int l,r,x;q--;){
		l=rd(),r=rd(),x=rd();
		cout<<(r-l+x+calc(l-x,l)>=0?"Yes\n":"No\n");
	}
	return 0;
}