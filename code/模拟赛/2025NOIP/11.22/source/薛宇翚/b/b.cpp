#include <bits/stdc++.h>
using namespace std;
#define int long long
void read(int &x)
{
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	if(f)
	{
		x=-x;
	}
}
const int N=3e3+100,M=2e6+100,Mo=998244353;
int n,m,k,sx,sy,ind[N],nid[N],ex[M],ey[M],f[N][N],a[N];
vector<int>g[N],arr,upd[N];
bool vis[N];
int findmin()
{
	int x=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&ind[i]<ind[x])
		{
			x=i;
		}
	}
	return x;
}
void update(int x,int y)
{
	for(int i=N-1;i>=y;i--)
	{
		f[x][i]=(f[x][i]+f[x][i-y])%Mo;
	}
}
void recover(int x,int y)
{
	for(int i=y;i<N;i++)
	{
		f[x][i]=((f[x][i]-f[x][i-y])%Mo+Mo)%Mo;
	}
}
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n);
	read(m);
	read(k);
	read(sx);
	read(sy);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		read(u);
		read(v);
		g[u].push_back(v);
		g[v].push_back(u);
		ex[i]=u;
		ey[i]=v;
	}
	for(int i=1;i<=n;i++)
	{
		ind[i]=g[i].size();
		vis[i]=0;
	}
	ind[0]=n+100;
	int alv=n;
	while(alv)
	{
		int p=findmin();
		if(!p||ind[p]>k)
		{
			break;
		}
		arr.push_back(p);
		nid[p]=arr.size();
		alv--;
		vis[p]=1;
		for(int i=0;i<g[p].size();i++)
		{
			int v=g[p][i];
			if(!vis[v])
			{
				ind[v]--;
			}
		}
	}
	if(alv)
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				printf("%lld ",i);
			}
		}
		printf("\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int u=ex[i],v=ey[i];
		if(nid[u]<nid[v])
		{
			upd[u].push_back(v);
		}
		else
		{
			upd[v].push_back(u);
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0]=1;
		read(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<upd[i].size();j++)
		{
			update(upd[i][j],a[i]);
		}
	}
	int mp=sx+sy;
	while(mp--)
	{
		int op,x,y;
		read(op);
		read(x);
		read(y);
		if(op==1)
		{
			for(int j=0;j<upd[x].size();j++)
			{
				recover(upd[x][j],a[x]);
			}
			a[x]=y;
			for(int j=0;j<upd[x].size();j++)
			{
				update(upd[x][j],a[x]);
			}
		}
		else
		{
			int nq=upd[x].size(),as=0;
			//cerr<<nq<<"\n";
			for(int j=0;j<(1<<nq);j++)
			{
				int las=y;
				for(int jj=0;jj<nq;jj++)
				{
					if((j>>jj)&1)
					{
						las-=a[upd[x][jj]];
					}
				}
				if(las>=0)
				{
					as=(as+f[x][las])%Mo;
				}
			}
			as=(as%Mo+Mo)%Mo;
			printf("%lld\n",as);
		}
	}
	return 0;
}
//为什么 我菜到 连模数都能写错
//为什么 看到题 却不知应该怎做
//直把求和看成异或
//直把深搜当成广搜
//谁说犯的低级错误 还不算多
//为什么 我菜到 连板子都不会默
//为什么 看到trick 却怎么也想不通
//直把贪心结论弄错
//直把计数忘记取模
//谁说犯的低级错误 还不算多
//为什么 为什么 为什么
//事情总不能一遍过
//为什么 为什么 为什么
//在错误上浪费太多
//为什么 为什么 为什么
//直面那菜到透的我
//谁说等不到 那天空海阔
//为什么 我菜到 连模数都能写错
//为什么 看到题 却不知应该怎做
//直把求和看成异或
//直把深搜当成广搜
//谁说犯的低级错误 还不算多
//为什么 我菜到 连板子都不会默
//为什么 看到trick 却怎么也想不通
//直把贪心结论弄错
//直把计数忘记取模
//谁说犯的低级错误 还不算多
//为什么 为什么 为什么
//事情总不能一遍过
//为什么 为什么 为什么
//在错误上浪费太多
//为什么 为什么 为什么
//谁说错误一定受挫
//谁说终不能 点燃希望之火
//为什么 为什么 为什么
//谁说天命终不能破
//为什么 为什么 为什么
//谁说人生注定落寞
//为什么 为什么 为什么
//必将品尝成功之果
//终将战胜 阻碍前行之我
//终将把那 一切困难冲破