#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5010;
char c[maxn][maxn];
int a1,b1,a2,b2;
bool vis[maxn][maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int newx=x+dx[i],newy=y+dy[i];
		if(newx<a1||newx>a2||newy<b1||newy>b2) continue;
		if(vis[newx][newy]) continue;
		if(c[newx][newy]!=c[x][y]) continue;
		vis[newx][newy]=1;
		dfs(newx,newy);
	}
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	Ios();
	int n,m,q;
	cin>>n>>m>>q;
	REP(i,1,n) REP(j,1,m) cin>>c[i][j];
	while(q--)
	{
		cin>>a1>>b1>>a2>>b2;
		REP(i,a1,a2)
		REP(j,b1,b2)
		vis[i][j]=0;
		int cnt=0;
		REP(i,a1,a2)
		REP(j,b1,b2)
		if(!vis[i][j]) cnt++,vis[i][j]=1,dfs(i,j);
		cout<<cnt<<"\n";
	}
}
/*
4 8 9
ABBAAAAA
ABAAAABA
CAADABBA
AAAAAAAA
1 1 4 8
3 5 3 8
1 3 2 4
1 4 2 5
1 1 3 3
4 4 4 4
2 6 4 8
3 5 4 6
1 6 3 8
*/
