#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull unsigned long long
#define cull const unsigned long long
using namespace std;
inline int read()
{
	int x=0,zf=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')zf=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*zf;
}
void print(cll x)
{
	if(x<0)
	{
		putchar('-');
		print(-x);
		return;
	}
	if(x<10)
	{
		putchar(x+'0');
		return;
	}
	print(x/10);
	putchar(x%10+'0');
}
void princh(cll x,const char ch)
{
	print(x);
	putchar(ch);
}
cint N=300,LGN=8;
cll INF=1e18;
int n,m,c;
set<int>HS;
int h[N+1],cnt[N+1];
ll mn[N+1];
int ah[N+1],ac[N+1];
ll f[N+1][N+1],g[N+1][N+1];
ll ans;
struct Spare_Table{
	ll a[N+1];
	ll st[LGN+1][N+1];
	void init()
	{
		for(int i=0;i<=n;++i)
		{
			st[0][i]=a[i];
		}
		for(int k=1;k<=__lg(n+1);++k)
		{
			for(int i=0;i<=n-(1<<k)+1;++i)
			{
				st[k][i]=min(st[k-1][i],st[k-1][i+(1<<k-1)]);
			}
		}
	}
	inline ll ask(int l,int r)
	{
		l=max(l,0);
		r=min(r,n);
		if(l>r)return INF;
		cint p=__lg(r-l+1);
		return min(st[p][l],st[p][r-(1<<p)+1]);
	}
}ST;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();
	c=read();
	for(int i=1;i<=n;++i)
	{
		ah[i]=read();
		HS.insert(ah[i]);
		ac[i]=read();
	}
	for(int x:HS)
	{
		h[++m]=x;
	}
	for(int i=1;i<=n;++i)
	{
		cint p=lower_bound(h+1,h+m+1,ah[i])-&h[0];
		++cnt[p];
	}
	int lst=-1;
	for(int i=1;i<=m;++i)
	{
		lst=max(lst,h[i]-1);
		for(int c=1;c<=cnt[i];++c)HS.insert(++lst);
	}
	m=0;
	for(int x:HS)
	{
		h[++m]=x;
		cnt[m]=0;
		mn[m]=INF;
	}
	for(int i=1;i<=n;++i)
	{
		cint p=lower_bound(h+1,h+m+1,ah[i])-&h[0];
		++cnt[p];
		mn[p]=min(mn[p],1ll*ac[i]);
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
		{
			f[i][j]=INF;
		}
	}
	f[0][1]=0;
	for(int i=1;i<=n;++i)
	{
		//printf("cnt[%d]=%d\n",h[i],cnt[i]);
		for(int j=0;j<=n;++j)
		{
			for(int k=0;k<=n;++k)
			{
				g[j][k]=f[j][k];
				f[j][k]=INF;
			}
		}
		for(int k=0;k<=n;++k)
		{
			for(int j=0;j<=n;++j)
			{
				ST.a[j]=g[j][k]+1ll*c*j;
			}
			ST.init();
			for(int j=0;j<=n;++j)
			{
				f[j][k]=min(f[j][k],ST.ask(j-cnt[i],j+k-cnt[i]));
			}
		}
		for(int j=0;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				f[j][k]=min(f[j][k],f[j][k-1]+mn[i]);
				//printf("f[%d][%d][%d]=%lld\n",h[i],j,k,f[j][k]);
			}
		}
	}
	ans=INF;
	for(int i=n;i>=0;--i)
	{
		ans=min(ans,f[0][i]);
	}
	print(ans);
	return 0;
}