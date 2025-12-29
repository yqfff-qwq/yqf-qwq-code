#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=' ';
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(f) x=-x;
	}

	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;

const int N=4e3+10;
char p[N][N];

int f[N][N];
int n,m,q;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[N][N];
int a,b,c,d;
void bfs(int sx,int sy){
	queue<pair<int,int> > q;
	vis[sx][sy]=1;
	f[sx][sy]=1;
	q.push({sx,sy});
	while(q.size()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int fx=x+dx[i];
			int fy=y+dy[i];
			if(fx>=a&&fy>=b&&fx<=c&&fy<=d&&!vis[fx][fy]&&p[sx][sy]==p[fx][fy]){
				vis[fx][fy]=1;
				f[fx][fy]=0;
				q.push({fx,fy});
			}
		}
	}
}

signed main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	input(n);
	input(m);
	input(q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>p[i][j];
	while(q--){
		input(a);
		input(b);
		input(c);
		input(d);
		for(int i=a;i<=c;i++)
			for(int j=b;j<=d;j++)
				vis[i][j]=0;
		int ans=0;
		for(int i=a;i<=c;i++)
			for(int j=b;j<=d;j++)
				if(!vis[i][j]) bfs(i,j),ans++;
		print(ans);
		putchar('\n');
	}
}

