#include <bits/stdc++.h>
using namespace std;
const int N=3e6+300;
int n,m,a[N],as[N],tr[N];
bool vis[N];
vector<int>g[N];
struct square
{
	int lmi,lmx,rmi,rmx;
	square(int x=0,int y=0,int z=0,int u=0):lmi(x),lmx(y),rmi(z),rmx(u){}
};
vector<square>h;
struct line
{
	int t,l,p;
	line(int x=0,int y=0,int u=0):t(x),l(y),p(u){}
};
vector<line>H;
bool cmp(line x,line y)
{
	return x.t<y.t;
}
struct qry
{
	int l,r,ix;
	qry(int le=0,int ri=0,int iz=0):l(le),r(ri),ix(iz){}
}b[N];
bool cmpb(qry x,qry y)
{
	return x.r<y.r;
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<N;i++)
	{
		g[i].push_back(0);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		g[a[i]].push_back(i);
		vis[a[i]]=1;
	}
	for(int i=0;i<N;i++)
	{
		g[i].push_back(n+1);
	}
	for(int i=1;i<=n+1;i++)
	{
		if(vis[i])
		{
			int miv=g[i][1],mxv=g[i][g[i].size()-2];
			int lasles=lower_bound(g[i-1].begin(),g[i-1].end(),miv)-g[i-1].begin()-1,firnex=upper_bound(g[i-1].begin(),g[i-1].end(),mxv)-g[i-1].begin();
			if(lasles+1==firnex)
			{
				h.push_back(square(g[i-1][lasles]+1,miv+1,mxv,g[i-1][firnex]));
			}
		}
		else
		{
			for(int j=1;j<g[i-1].size();j++)
			{
				int mi=g[i-1][j-1],mx=g[i-1][j];
				h.push_back(square(mi+1,mx,mi+1,mx));
			}
		}
	}
	for(int i=0;i<h.size();i++)
	{
		H.push_back(line(h[i].rmi,h[i].lmi,1));
		H.push_back(line(h[i].rmi,h[i].lmx,-1));
		H.push_back(line(h[i].rmx,h[i].lmi,-1));
		H.push_back(line(h[i].rmx,h[i].lmx,1));
	}
	sort(H.begin(),H.end(),cmp);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].l,&b[i].r);
		b[i].ix=i;
	}
	sort(b+1,b+m+1,cmpb);
	int jx=0;
	for(int i=1;i<=m;i++)
	{
		while(H[jx].t<=b[i].r)
		{
			int px=H[jx].l;
			while(px<N)
			{
				tr[px]+=H[jx].p;
				px+=(px&-px);
			}
			jx++;
		}
		int &s=as[b[i].ix];
		int px=b[i].l;
		while(px)
		{
			s+=tr[px];
			px-=(px&-px);
		}
	}
	for(int i=1;i<=m;i++)
	{
		as[i]=n+1-as[i];
		printf("%d\n",as[i]);
	}
	return 0;
}