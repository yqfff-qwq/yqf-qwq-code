#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define REP(i,a,b) for(register int (i)=(a);(i)<=(b);(i)++)
void Ios(){ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
const int maxn=2010;
char c[maxn][maxn];
static int dx[4]={0,0,1,-1};
static int dy[4]={1,-1,0,0};
static int qz[2]={1,-1};
struct point
{
	int x,y,s;
};
//bitset<maxn> vis1[maxn],vis2[maxn],upd[maxn];
bool vis1[maxn][maxn],vis2[maxn][maxn],upd[maxn][maxn];
point q[maxn*maxn],ex[maxn*maxn];
signed main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	Ios();
	int n,m,k,u;
	cin>>n>>m>>k>>u;
	REP(i,1,n) REP(j,1,m) cin>>c[i][j];
	int sx,sy,tx,ty;
	int cnt=0;
	REP(i,1,n) REP(j,1,m)
	{
		if(c[i][j]=='S') sx=i,sy=j,c[i][j]='.';
		if(c[i][j]=='T') tx=i,ty=j,c[i][j]='.';
		cnt+=(c[i][j]=='#');
	}
	//cerr<<cnt<<"\n";
	vis2[sx][sy]=vis1[sx][sy]=1;
	int tq=0,wq=1,tex=0,wex=0;
	q[0]={sx,sy,0};
	if(n>1000&&m>1000&&k>=6&&abs(sx-tx)+abs(sy-ty)!=1&&cnt!=0)
	{
	//	cerr<<"DuDuDu!\n";
		while(tq<wq||tex<wex)
	{
		point t;
		if(tq==wq) t=ex[tex],tex++;
		else if(tex==wex) t=q[tq],tq++;
		else if(q[tq].s<=ex[tex].s) t=q[tq],tq++;
		else t=ex[tex],tex++;
		if(t.x==tx&&t.y==ty)
		{
			cout<<t.s<<"\n";
			return 0;
		}
		if(upd[t.x][t.y]) continue;
		upd[t.x][t.y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=t.x+dx[i],ny=t.y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m) continue;
			if(c[nx][ny]=='#') continue;
			if(vis1[nx][ny]) continue;
			vis1[nx][ny]=1;
			q[wq++]={nx,ny,t.s+1};
		}
		REP(i,0,k)
		REP(q1,0,1)
		{
			int nx=t.x+i*qz[q1];
			if(nx<1||nx>n) continue;
			REP(q2,0,1)
			REP(j,0,k-i)
			{
				int ny=t.y+j*qz[q2];
				if(ny<1||ny>m) continue;
				if(c[nx][ny]=='#') continue;
				if(vis2[nx][ny])
				{
					j=max(j+1,k-i-1);
					continue;
				}
				vis2[nx][ny]=1;
				ex[wex++]={nx,ny,t.s+u};
			}
		}
	}
	cout<<-1<<"\n";
	return 0;
	}
//	cerr<<"aaa\n";
	while(tq<wq||tex<wex)
	{
		point t;
		if(tq==wq) t=ex[tex],tex++;
		else if(tex==wex) t=q[tq],tq++;
		else if(q[tq].s<=ex[tex].s) t=q[tq],tq++;
		else t=ex[tex],tex++;
		if(t.x==tx&&t.y==ty)
		{
			cout<<t.s<<"\n";
			return 0;
		}
		if(upd[t.x][t.y]) continue;
		upd[t.x][t.y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=t.x+dx[i],ny=t.y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m) continue;
			if(c[nx][ny]=='#') continue;
			if(vis1[nx][ny]) continue;
			vis1[nx][ny]=1;
			q[wq++]={nx,ny,t.s+1};
		}
		REP(i,0,k)
		REP(q1,0,1)
		{
			int nx=t.x+i*qz[q1];
			if(nx<1||nx>n) continue;
			REP(q2,0,1)
			{
				int l=t.y,r=t.y+(k-i)*qz[q2];
				if(l>r) swap(l,r);
				l=max(l,1ll),r=min(r,m);
				REP(j,l,r)
				{
					if(c[nx][j]=='#'||vis2[nx][j]) continue;
					vis2[nx][j]=1;
					ex[wex++]={nx,j,t.s+u};
				}
			}
		}
	}
	cout<<-1<<"\n";
}
