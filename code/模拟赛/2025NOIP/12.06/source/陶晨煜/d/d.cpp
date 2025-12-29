#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DEP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define pb push_back
#define ll long long
#define ull unsiged long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=2e5+10;
const int maxk=51;
const int B=450;
bitset<maxk> bit[B];
bitset<maxk> ok;
int cnt[B][maxk];
int a[maxn];
int tot,L[maxn],R[maxn],bel[maxn];
int n;
void build()
{
	tot=n/B;
	if(n%B) tot++;
	REP(i,1,tot)
	{
		L[i]=(i-1)*B+1;
		R[i]=i*B;
	}
	R[tot]=min(R[tot],n);
	REP(i,1,tot)
	{
		REP(j,L[i],R[i])
		bit[i][a[j]]=1,cnt[i][a[j]]++,bel[j]=i;
	}
}
bitset<maxk> emp;
struct SegTree
{
	bitset<maxk> tr[B*4+10];
	#define lson x<<1,l,mid
	#define rson x<<1|1,mid+1,r
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			tr[x]=bit[l];
			return;
		}
		int mid=(l+r)/2;
		build(lson);build(rson);
		tr[x]=tr[x<<1|1]|tr[x<<1];
	}
	void clear(int n)
	{
		REP(i,0,n*4) tr[i]=emp;
	}
	void update(int x,int l,int r,int p,int v,bool fl)
	{
		if(p<l||p>r) return;
		if(l==r)
		{
			tr[x][v]=fl;
			return;
		}
		int mid=(l+r)/2;
		update(lson,p,v,fl);
		update(rson,p,v,fl);
		tr[x]=tr[x<<1|1]|tr[x<<1];
	}
	bitset<maxk> query(int x,int l,int r,int ql,int qr)
	{
	//	cerr<<x<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<"\n";
		if(ql>qr) return emp;
		if(ql<=l&&r<=qr) return tr[x];
		int mid=(l+r)/2;
		if(qr<=mid) return query(lson,ql,qr);
		if(ql>mid) return query(rson,ql,qr);
		return query(lson,ql,qr)|query(rson,ql,qr);
	}
}t,tt;
void upd(int x,int v)
{
	cnt[bel[x]][a[x]]--;
	if(cnt[bel[x]][a[x]]==0)
	{
		bit[bel[x]][a[x]]=0;
		t.update(1,1,tot,bel[x],a[x],0);
	}
	cnt[bel[x]][v]++;
	if(cnt[bel[x]][v]==1)
	{
		bit[bel[x]][v]=1;
		t.update(1,1,tot,bel[x],v,1);
	}
	a[x]=v;
}
int queryl(int x,bitset<maxk> q)
{
	REP(i,L[x],R[x])
	{
		q[a[i]]=1;
		if(q==ok) return i-L[x]+1;
	}
	return -1;
}
int k;
int queryr(int x)
{
	tt.clear(R[x]-L[x]+1);
	REP(i,L[x],R[x]) tt.update(1,1,R[x]-L[x]+1,i-L[x]+1,a[i],1);
	int mx=1e9;
	REP(i,L[x],R[x])
	{
		int l=i-L[x]+1,r=R[x]-L[x]+1,beg=i-L[x]+1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(tt.query(1,1,R[x]-L[x]+1,beg,mid)==ok) r=mid;
			else l=mid+1;
		}
		if(tt.query(1,1,R[x]-L[x]+1,beg,l)!=ok) continue;
		mx=min(mx,l-beg+1);
	}
	return mx;
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	Ios();
	int m;
	cin>>n>>k>>m;
	REP(i,1,n) cin>>a[i];
	REP(i,1,k) ok[i]=1;
	build();
	t.build(1,1,tot);
	while(m--)
	{
		int opt;
		cin>>opt;
		if(opt==1)
		{
			int p,v;
			cin>>p>>v;
			upd(p,v);
		}
		else
		{
			int ans=1e9;
			REP(i,1,tot)
			{
				int l=i,r=n;
				while(l<r)
				{
					int mid=(l+r)/2;
					if(t.query(1,1,tot,i,mid)==ok) r=mid;
					else l=mid+1;
				}
				if(t.query(1,1,tot,i,l)!=ok) continue;
				int cnt=R[l]-L[i]+1;
				cnt-=(R[l]-L[l]+1);
				if(l!=i)
				cnt+=queryl(l,t.query(1,1,tot,i,l-1));
				else cnt+=queryr(l);
				ans=min(ans,cnt);
			}
			cout<<(ans==1e9?-1:ans)<<"\n";
		}
	}
}
