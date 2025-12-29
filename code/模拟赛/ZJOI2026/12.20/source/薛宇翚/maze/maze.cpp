#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2100;
ll a[N][N][9];
bool vis[N][N][9];
char c[N][N];
int n,m,k,t,dx[4]={1,-1},dy[4]={0,0,1,-1};
struct nd
{
	int x,y,r;
	ll d;
	nd(int X=0,int Y=0,int R=0,ll D=0):x(X),y(Y),r(R),d(D){}
	bool friend operator >(const nd &x,const nd &y)
	{
		return x.d>y.d;
	}
};
priority_queue<nd,vector<nd>,greater<nd> >q;
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&t);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]=='S')
			{
				a[i][j][0]=0;
				q.push(nd(i,j,0,0));
			}
		}
	}
	while(!q.empty())
	{
		nd u=q.top();
		q.pop();
		if(vis[u.x][u.y][u.r])
		{
			continue;
		}
		vis[u.x][u.y][u.r]=1;
		if(!u.r)
		{
			if(c[u.x][u.y]=='T')
			{
				printf("%lld\n",a[u.x][u.y][0]);
				return 0;
			}
			if(c[u.x][u.y]=='#')
			{
				continue;
			}
			for(int i=0;i<4;i++)
			{
				nd v=nd(u.x+dx[i],u.y+dy[i],0,a[u.x][u.y][0]+1);
				if(v.x>=1&&v.x<=n&&v.y>=1&&v.y<=m&&c[v.x][v.y]!='#'&&!vis[v.x][v.y][0]&&a[v.x][v.y][0]>v.d)
				{
					a[v.x][v.y][0]=v.d;
					q.push(v);
				}
			}
			if(!vis[u.x][u.y][k]&&a[u.x][u.y][k]>a[u.x][u.y][0]+t)
			{
				a[u.x][u.y][k]=a[u.x][u.y][0]+t;
				q.push(nd(u.x,u.y,k,a[u.x][u.y][k]));
			}
		}
		else
		{
			if(c[u.x][u.y]!='#'&&!vis[u.x][u.y][0]&&a[u.x][u.y][0]>a[u.x][u.y][u.r])
			{
				a[u.x][u.y][0]=a[u.x][u.y][u.r];
				q.push(nd(u.x,u.y,0,a[u.x][u.y][0]));
			}
			for(int i=0;i<4;i++)
			{
				nd v=nd(u.x+dx[i],u.y+dy[i],u.r-1,a[u.x][u.y][u.r]);
				if(v.x>=1&&v.x<=n&&v.y>=1&&v.y<=m&&(c[v.x][v.y]!='#'||v.r)&&!vis[v.x][v.y][v.r]&&a[v.x][v.y][v.r]>v.d)
				{
					a[v.x][v.y][v.r]=v.d;
					q.push(v);
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}
