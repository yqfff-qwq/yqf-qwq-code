#include <bits/stdc++.h>
using namespace std;
const int N=3e6+300;
int n,m,a[N],b[N],su,as[N],bsz,fdb[N];
struct qry
{
	int x,y,ix;
	qry(int X=0,int Y=0,int Ix=0):x(X),y(Y),ix(Ix){}
}q[N];
bool cmp(qry x,qry y)
{
	if(fdb[x.x]!=fdb[y.x])
	{
		return fdb[x.x]<fdb[y.x];
	}
	return x.y<y.y;
}
namespace SPEA
{
	bool qmp(qry x,qry y)
	{
		return x.y<y.y;
	}
	int tr[N],pr[N],las[N];
	void update(int x,int y)
	{
		x++;
		while(x<N)
		{
			tr[x]+=y;
			x+=(x&-x);
		}
	}
	int query(int x)
	{
		int s=0;
		x++;
		while(x)
		{
			s+=tr[x];
			x-=(x&-x);
		}
		return s;
	}
	void solve()
	{
		//cerr<<"call\n";
		for(int i=n+1;i<=n+n;i++)
		{
			a[i]=a[i-n];
		}
		for(int i=1;i<=n+n;i++)
		{
			pr[i]=las[a[i]];
			las[a[i]]=i;
		}
		int qnt=0;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			qnt++;
			q[qnt]=qry(x,y,i);
			qnt++;
			q[qnt]=qry(y+1,x+n-1,i);
		}
		sort(q+1,q+qnt+1,qmp);
		int re=0;
		for(int i=1;i<=qnt;i++)
		{
			while(re<q[i].y)
			{
				re++;
				update(pr[re],1);
			}
			as[q[i].ix]+=query(q[i].x-1)-(q[i].x-1);
		}
		for(int i=1;i<=m;i++)
		{
			printf("%d\n",as[i]);
		}
	}
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	bool spahlz=1;
	scanf("%d%d",&n,&m);
	bsz=sqrt(n)+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		fdb[i]=(i/bsz)+bool(i%bsz);
		if(!b[a[i]])
		{
			su++;
		}
		b[a[i]]++;
		if(a[i]%2==0)
		{
			spahlz=0;
		}
	}
	if(spahlz)
	{
		SPEA::solve();
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].x,&q[i].y);
		q[i].ix=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].y)
		{
			r++;
			b[a[r]]--;
			if(!b[a[r]])
			{
				su--;
			}
			if(!b[a[r]+1])
			{
				su++;
			}
			b[a[r]+1]++;
		}
		while(l>q[i].x)
		{
			l--;
			b[a[l]]--;
			if(!b[a[l]])
			{
				su--;
			}
			if(!b[a[l]+1])
			{
				su++;
			}
			b[a[l]+1]++;
		}
		while(r>q[i].y)
		{
			b[a[r]+1]--;
			if(!b[a[r]+1])
			{
				su--;
			}
			if(!b[a[r]])
			{
				su++;
			}
			b[a[r]]++;
			r--;
		}
		while(l<q[i].x)
		{
			b[a[l]+1]--;
			if(!b[a[l]+1])
			{
				su--;
			}
			if(!b[a[l]])
			{
				su++;
			}
			b[a[l]]++;
			l++;
		}
		as[q[i].ix]=su;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d\n",as[i]);
	}
	return 0;
}
