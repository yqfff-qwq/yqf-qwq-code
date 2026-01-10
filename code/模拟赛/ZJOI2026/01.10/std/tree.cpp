#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double 
#define ull unsigned ll
#define LL __int128
#define siz(A) ((int)A.size())
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int xx=5e5+5;
const int B=4000;
// 每 .. 次重构。 
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int fa[xx],f[xx],dfx[xx],siz[xx],dep[xx],cst;
ll a[xx];
void dfs(int x,int y)
{
	dep[x]=dep[y]+1,siz[x]=1,dfx[x]=++cst;
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dfs(e[i].to,x),siz[x]+=siz[e[i].to];
}
struct inf
{
	ll sm;
	int siz,adt,l,r;
	int nd,md,mn,mx;
}t[xx];
void ad(int k,ll z)
{
	if(k)
	{
		t[k].sm+=t[k].siz*z;
		t[k].adt+=z,a[k]+=z;
	}
}
void pd(int k)
{
	if(t[k].adt)
	{
		ad(t[k].l,t[k].adt);
		ad(t[k].r,t[k].adt);
		t[k].adt=0;
	}
}
int id[xx];
int Ct=0;
int build(int l,int r,int d)
{
	if(l>r)return 0;
	int mid=l+r>>1;
	if(d&1)nth_element(id+l,id+mid,id+r+1,[&](int A,int B){return dep[A]<dep[B];});
	else nth_element(id+l,id+mid,id+r+1,[&](int A,int B){return dfx[A]<dfx[B];});
	int k=id[mid];
	t[k].l=build(l,mid-1,d^1);
	t[k].r=build(mid+1,r,d^1);
	t[k].adt=0,t[k].sm=a[k]+t[t[k].l].sm+t[t[k].r].sm,t[k].siz=1+t[t[k].l].siz+t[t[k].r].siz;
	t[k].md=max({dep[k],t[t[k].l].md,t[t[k].r].md});
	t[k].nd=min({dep[k],t[t[k].l].nd,t[t[k].r].nd});
	t[k].mx=max({dfx[k],t[t[k].l].mx,t[t[k].r].mx});
	t[k].mn=min({dfx[k],t[t[k].l].mn,t[t[k].r].mn});
	return k;
}
void cg(int k,int x,int y,int z,int v)
{
	if(!k)return;
	if(t[k].mx<x||t[k].mn>y||t[k].nd>z)return;
	if(x<=t[k].mn&&t[k].mx<=y&&t[k].md<=z)return ad(k,v);
	if(x<=dfx[k]&&dfx[k]<=y&&dep[k]<=z)a[k]+=v;
	pd(k);
	cg(t[k].l,x,y,z,v);
	cg(t[k].r,x,y,z,v);
	t[k].sm=a[k]+t[t[k].l].sm+t[t[k].r].sm;
}
ll ask(int k,int x,int y,int z)
{
	if(!k)return 0;
	++Ct;
	if(t[k].mx<x||t[k].mn>y||t[k].nd>z)return 0;
	if(x<=t[k].mn&&t[k].mx<=y&&t[k].md<=z)return t[k].sm;
	ll ans=0;
	if(x<=dfx[k]&&dfx[k]<=y&&dep[k]<=z)ans+=a[k];
	pd(k);
	ans+=ask(t[k].l,x,y,z);
	ans+=ask(t[k].r,x,y,z);
	return ans;
}
void down(int k)
{
	if(!k)return;
	pd(k),down(t[k].l),down(t[k].r);
}
int rt,n,q,lst;
void build()
{
	cst=0,dfs(1,0);
	down(rt),t[0].mx=-1e9,t[0].mn=1e9,t[0].md=-1e9,t[0].nd=1e9;
	for(int i=1;i<=n;i++)id[i]=i;
	rt=build(1,n,0),lst=n;
	for(int i=1;i<=n;i++)fa[i]=i;
}
void Ad(int x,int lim,int v)
{
	a[x]+=v;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x])continue;
		if(dep[e[i].to]<=lim)Ad(e[i].to,lim,v);
	}
}
ll res;
void Gt(int x,int lim)
{
	res+=a[x];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x])continue;
		Gt(e[i].to,lim);
	}
}
char ED;
int main(){
	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)f[i]=read();
	for(int i=1;i<=n;i++)if(f[i])add(i,f[i]),add(f[i],i);
	build();
	while(q--)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),d=read(),v=read();
			int lim=dep[x]+d;
			if(x>lst)
			{
				Ad(x,lim,v);
				continue;
			}
			for(int i=lst+1;i<=n;i++)
			{
				int to=fa[i];
				if(dfx[x]<=dfx[to]&&dfx[to]<dfx[x]+siz[x]&&dep[i]<=lim)
					a[i]+=v;
			}
			cg(rt,dfx[x],dfx[x]+siz[x]-1,lim,v);
		}
		if(op==2)
		{
			int x=read(),d=read();
			int lim=dep[x]+d;
			if(x>lst)
			{
				res=0;
				Gt(x,lim);
				cout<<res<<"\n";
				continue;
			}
			ll ans=0;
			for(int i=lst+1;i<=n;i++)
			{
				int to=fa[i];
				if(dfx[x]<=dfx[to]&&dfx[to]<dfx[x]+siz[x]&&dep[i]<=lim)
					ans+=a[i];
			}
			ans+=ask(rt,dfx[x],dfx[x]+siz[x]-1,lim);
			cout<<ans<<"\n";
		}
		if(op==3)
		{
			++n,f[n]=read(),a[n]=read();
			add(n,f[n]),add(f[n],n);
			fa[n]=fa[f[n]],dep[n]=dep[f[n]]+1;
		}
		if(n-lst>B)build();
	}
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}
