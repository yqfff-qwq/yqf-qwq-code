#include<bits/stdc++.h>
using namespace std;
int n,m,q,x1,x2,y1,y2;
char a[4025][4025];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int f[1000025];
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void solve()
{
	cin>>x1>>y1>>x2>>y2;
	int sum=(y2-y1+1)*(x2-x1+1);
	for(int i=x1;i<=x2;i++) for(int j=y1;j<=y2;j++) f[(i-1)*m+j]=(i-1)*m+j;
	
	for(int i=x1;i<=x2;i++)
	{
		for(int j=y1;j<=y2;j++)
		{
			for(int k=0;k<4;k++)
			{
				int xx=i+dx[k],yy=j+dy[k];
				if(xx>=x1&&xx<=x2&&y1<=yy&&yy<=y2&&a[xx][yy]==a[i][j])
				{
					int x=find(f[(i-1)*m+j]),y=find(f[(xx-1)*m+yy]);
					if(x!=y)
					{
						f[x]=y;
						sum--;
					}
				}
			}
		}
	}
	
	cout<<sum<<'\n';
}
signed main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	while(q--) solve();
	
	return 0;
}
