#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template <typename T>
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

	template <typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;

#define int long long
const int N=1e5+10;
const int M=2e5+10;
const int INF=1e15;

int n,m,S,T,U,V;

mt19937 rnd(time(0));

namespace N300{
	const int maxN=3e2+10;
	int dis[maxN][maxN];
	void floyd(){
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	void Main(){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)	
				dis[i][j]=INF;
		for(int i=1;i<=n;i++)
			dis[i][i]=0;
		for(int i=1;i<=m;i++){
			int a,b,c;
			input(a);
			input(b);
			input(c);
			dis[a][b]=dis[b][a]=min(dis[a][b],c);
		}
		floyd();
		int d=dis[S][T];
		int ans=dis[U][V];
//		for(int i=1;i<=n;i++,putchar('\n'))
//			for(int j=1;j<=n;j++,putchar(' '))
//				print(dis[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[S][i]+dis[i][j]+dis[j][T]==d||dis[S][j]+dis[j][i]+dis[i][T]==d)
					ans=min(ans,dis[U][i]+dis[j][V]);
		print(ans);
		exit(0);
	}
}

namespace ONLY{
	int l[M<<1],ne[M<<1],head[N],tail[N],idx,e[M<<1];
	void con(int u,int v,int val){
		idx++;
		l[idx]=v;
		e[idx]=val;
		if(head[u]) ne[tail[u]]=idx;
		else head[u]=idx;
		tail[u]=idx;	
	}
	
	struct Node{
		int v,dis;
	};
	bool operator<(Node A,Node B){
		return A.dis>B.dis;
	}
	priority_queue<Node> q;
	
	int dis[N];
	void dijikstra(int s){
		for(int i=1;i<=n;i++) dis[i]=INF;	
		dis[s]=0;
		q.push({s,0});
		while(q.size()){
			int u=q.top().v;
			q.pop();
			for(int i=head[u];i;i=ne[i]){
				int v=l[i];
				if(dis[u]+e[i]<dis[v]){
					dis[v]=dis[u]+e[i];
					q.push({v,dis[v]});
				}
			}
		}
	}
	
	int f[2][N];
	int g[2][N];
	
	struct Road{
		int u,v;
		int dis;
	};
	vector<Road> road;
	
	void Main(){
		for(int i=1;i<=m;i++){
			int u,v,val;
			input(u);
			input(v);
			input(val);
			con(u,v,val);
			con(v,u,val);
			road.push_back({u,v,val});
		}
		dijikstra(S);
		for(int i=1;i<=n;i++) g[0][i]=dis[i];
		dijikstra(T);
		for(int i=1;i<=n;i++) g[1][i]=dis[i];
		dijikstra(U);
		for(int i=1;i<=n;i++) f[0][i]=dis[i];
		dijikstra(V);
		for(int i=1;i<=n;i++) f[1][i]=dis[i];
		int minU=INF,minV=INF;
		int d=g[0][T];
		for(auto x:road)
			if(g[0][x.v]+x.dis+g[1][x.u]==d||g[0][x.u]+x.dis+g[1][x.v]==d)
				minU=min({minU,f[0][x.u],f[0][x.v]}),minV=min({minV,f[1][x.u],f[1][x.v]});
		print(minU+minV);
	}
}

namespace SU{
	int l[M<<1],ne[M<<1],head[N],tail[N],idx,e[M<<1];
	void con(int u,int v,int val){
		idx++;
		l[idx]=v;
		e[idx]=val;
		if(head[u]) ne[tail[u]]=idx;
		else head[u]=idx;
		tail[u]=idx;	
	}
	
	struct Node{
		int v,dis;
	};
	bool operator<(Node A,Node B){
		return A.dis>B.dis;
	}
	priority_queue<Node> q;
	
	int dis[N];
	void dijikstra(int s){
		for(int i=1;i<=n;i++) dis[i]=INF;	
		dis[s]=0;
		q.push({s,0});
		while(q.size()){
			int u=q.top().v;
			q.pop();
			for(int i=head[u];i;i=ne[i]){
				int v=l[i];
				if(dis[u]+e[i]<dis[v]){
					dis[v]=dis[u]+e[i];
					q.push({v,dis[v]});
				}
			}
		}
	}
	
	int f[2][N];
	int g[2][N];
	
	void Main(){
		for(int i=1;i<=m;i++){
			int u,v,val;
			input(u);
			input(v);
			input(val);
			con(u,v,val);
			con(v,u,val);
		}
		dijikstra(S);
		for(int i=1;i<=n;i++) g[0][i]=dis[i];
		dijikstra(T);
		for(int i=1;i<=n;i++) g[1][i]=dis[i];
		dijikstra(U);
		for(int i=1;i<=n;i++) f[0][i]=dis[i];
		dijikstra(V);
		for(int i=1;i<=n;i++) f[1][i]=dis[i];
		int ans=f[0][V];
		int d=g[0][T];
		for(int k=1;k<=n;k++)
			if(g[0][k]+g[1][k]==d)
				ans=min(ans,f[1][k]);
		print(ans);
	}
}

signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	input(n);
	input(m);
	input(S);
	input(T);
	input(U);
	input(V);
	if(n<=300) N300::Main();//24 Pts
	else if(S==U) SU::Main();//16 Pts
	else ONLY::Main();//15 Pts
}

