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
cint N=4e5,M=1.1e6;
cll inf=1e18;
int n,m,ks,kt,ku,kv;
struct info{
	int u;
	ll dis;
};
bool operator<(info p,info q)
{
	return (p.dis==q.dis?(p.u<q.u):(p.dis>q.dis));
}
bool operator==(info p,info q)
{
	return (p.u==q.u&&p.dis==q.dis);
}
struct Graph{
	//string name;
	int n;
	struct edge{
		int to,val;
	};
	vector<edge>E[N+1];
	inline void add_edge(cint u,cint v,cint w)
	{
		//cout<<name<<':'<<u<<' '<<v<<' '<<w<<endl;
		E[u].push_back({v,w});
	}
	ll dis[N+1];
	struct Deletable_Heap{
		priority_queue<info>p,q;
		void insert(info x)
		{
			q.push(x);
		}
		void erase(info x)
		{
			p.push(x);
		}
		void D()
		{
			while(!p.empty()&&p.top()==q.top())
			{
				p.pop();
				q.pop();
			}
		}
		bool empty()
		{
			D();
			return q.empty();
		}
		info top()
		{
			D();
			return q.top();
		}
	}q;
	void dijkstra(cint s)
	{
		for(int i=1;i<=n;++i)
		{
			dis[i]=inf;
		}
		dis[s]=0;
		for(int i=1;i<=n;++i)
		{
			q.insert({i,dis[i]});
		}
		while(!q.empty())
		{
			info top=q.top();
			cint x=top.u;
			q.erase(top);
			for(edge e:E[x])
			{
				if(dis[e.to]>dis[x]+e.val)
				{
					q.erase({e.to,dis[e.to]});
					dis[e.to]=dis[x]+e.val;
					q.insert({e.to,dis[e.to]});
				}
			}
		}
	}
}G,NG;
ll diss[N+1],dist[N+1];
int eu[M+1],ev[M+1],ew[M+1];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	//G.name="G";
	//NG.name="NG";
	n=read();
	m=read();
	ks=read();
	kt=read();
	ku=read();
	kv=read();
	for(int i=1;i<=m;++i)
	{
		eu[i]=read();
		ev[i]=read();
		ew[i]=read();
		G.add_edge(eu[i],ev[i],ew[i]);
		G.add_edge(ev[i],eu[i],ew[i]);
	}
	G.n=n;
	G.dijkstra(ks);
	for(int i=1;i<=n;++i)
	{
		diss[i]=G.dis[i];
		//printf("diss[%d]=%lld\n",i,diss[i]);
	}
	G.dijkstra(kt);
	for(int i=1;i<=n;++i)
	{
		dist[i]=G.dis[i];
		//printf("dist[%d]=%lld\n",i,dist[i]);
	}
	for(int i=1;i<=m;++i)
	{
		NG.add_edge(eu[i],ev[i],ew[i]);
		NG.add_edge(ev[i],eu[i],ew[i]);
		NG.add_edge(eu[i]+n*3,ev[i]+n*3,ew[i]);
		NG.add_edge(ev[i]+n*3,eu[i]+n*3,ew[i]);
		if(diss[ev[i]]<diss[eu[i]])swap(eu[i],ev[i]);
		if(diss[eu[i]]+dist[ev[i]]+ew[i]==diss[kt])
		{
			NG.add_edge(eu[i]+n,ev[i]+n,0);
			NG.add_edge(ev[i]+n*2,eu[i]+n*2,0);
		}
	}
	for(int i=1;i<=n;++i)
	{
		NG.add_edge(i,i+n,0);
		NG.add_edge(i,i+n*2,0);
		NG.add_edge(i,i+n*3,0);
		NG.add_edge(i+n,i+n*3,0);
		NG.add_edge(i+n*2,i+n*3,0);
	}
	NG.n=n*4;
	NG.dijkstra(ku);
	print(NG.dis[kv+n*3]);
	return 0;
}