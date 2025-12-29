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
cint N=2e5+1,LGN=17,Q=2e5;
int n,q,a[N+1],b[N+1];
ll ql[Q+1],qr[Q+1],qv[Q+1];
ll s[N+1];
ll ans[Q+1];
namespace STEP0{
	struct Spare_Table{
		int st[LGN+1][N+1];
		void init()
		{
			for(int i=1;i<=n;++i)
			{
				st[0][i]=a[i];
			}
			for(int k=1;k<=__lg(n);++k)
			{
				for(int i=1;i<=n-(1<<k)+1;++i)
				{
					st[k][i]=max(st[k-1][i],st[k-1][i+(1<<k-1)]);
				}
			}
		}
		inline int ask(cint l,cint r)
		{
			cint p=__lg(r-l+1);
			return max(st[p][l],st[p][r-(1<<p)+1]);
		}
	}ST;
	void main()
	{
		ST.init();
		for(int i=1;i<=q;++i)
		{
			if(ST.ask(ql[i],qr[i]-1)>qv[i])ans[i]=-1;
		}
	}
}
namespace STEP1{
	struct Spare_Table{
		int st[LGN+1][N+1];
		void init()
		{
			for(int i=1;i<=n;++i)
			{
				st[0][i]=b[i];
			}
			for(int k=1;k<=__lg(n);++k)
			{
				for(int i=1;i<=n-(1<<k)+1;++i)
				{
					st[k][i]=min(st[k-1][i],st[k-1][i+(1<<k-1)]);
				}
			}
		}
		inline int ask(cint l,cint r)
		{
			cint p=__lg(r-l+1);
			return max(st[p][l],st[p][r-(1<<p)+1]);
		}
	}ST;
	struct matrix{
		ll a[4][4];
	}emp;
	struct vec{
		ll a[4];
	};
	vector<int>qry[N+1];
	vec operator*(vec x,matrix y)
	{
		vec res;
		res.a[0]=x.a[0]*y.a[0][0]+x.a[1]*y.a[1][0]+x.a[2]*y.a[2][0]+x.a[3]*y.a[3][0];
		res.a[1]=x.a[0]*y.a[0][1]+x.a[1]*y.a[1][1]+x.a[2]*y.a[2][1]+x.a[3]*y.a[3][1];
		res.a[2]=x.a[0]*y.a[0][2]+x.a[1]*y.a[1][2]+x.a[2]*y.a[2][2]+x.a[3]*y.a[3][2];
		res.a[3]=x.a[0]*y.a[0][3]+x.a[1]*y.a[1][3]+x.a[2]*y.a[2][3]+x.a[3]*y.a[3][3];
		return res;
	}
	matrix operator*(matrix x,matrix y)
	{
		matrix res;
		res.a[0][0]=x.a[0][0]*y.a[0][0]+x.a[0][1]*y.a[1][0]+x.a[0][2]*y.a[2][0]+x.a[0][3]*y.a[3][0];
		res.a[0][1]=x.a[0][0]*y.a[0][1]+x.a[0][1]*y.a[1][1]+x.a[0][2]*y.a[2][1]+x.a[0][3]*y.a[3][1];
		res.a[0][2]=x.a[0][0]*y.a[0][2]+x.a[0][1]*y.a[1][2]+x.a[0][2]*y.a[2][2]+x.a[0][3]*y.a[3][2];
		res.a[0][3]=x.a[0][0]*y.a[0][3]+x.a[0][1]*y.a[1][3]+x.a[0][2]*y.a[2][3]+x.a[0][3]*y.a[3][3];
		res.a[1][0]=x.a[1][0]*y.a[0][0]+x.a[1][1]*y.a[1][0]+x.a[1][2]*y.a[2][0]+x.a[1][3]*y.a[3][0];
		res.a[1][1]=x.a[1][0]*y.a[0][1]+x.a[1][1]*y.a[1][1]+x.a[1][2]*y.a[2][1]+x.a[1][3]*y.a[3][1];
		res.a[1][2]=x.a[1][0]*y.a[0][2]+x.a[1][1]*y.a[1][2]+x.a[1][2]*y.a[2][2]+x.a[1][3]*y.a[3][2];
		res.a[1][3]=x.a[1][0]*y.a[0][3]+x.a[1][1]*y.a[1][3]+x.a[1][2]*y.a[2][3]+x.a[1][3]*y.a[3][3];
		res.a[2][0]=x.a[2][0]*y.a[0][0]+x.a[2][1]*y.a[1][0]+x.a[2][2]*y.a[2][0]+x.a[2][3]*y.a[3][0];
		res.a[2][1]=x.a[2][0]*y.a[0][1]+x.a[2][1]*y.a[1][1]+x.a[2][2]*y.a[2][1]+x.a[2][3]*y.a[3][1];
		res.a[2][2]=x.a[2][0]*y.a[0][2]+x.a[2][1]*y.a[1][2]+x.a[2][2]*y.a[2][2]+x.a[2][3]*y.a[3][2];
		res.a[2][3]=x.a[2][0]*y.a[0][3]+x.a[2][1]*y.a[1][3]+x.a[2][2]*y.a[2][3]+x.a[2][3]*y.a[3][3];
		res.a[3][0]=x.a[3][0]*y.a[0][0]+x.a[3][1]*y.a[1][0]+x.a[3][2]*y.a[2][0]+x.a[3][3]*y.a[3][0];
		res.a[3][1]=x.a[3][0]*y.a[0][1]+x.a[3][1]*y.a[1][1]+x.a[3][2]*y.a[2][1]+x.a[3][3]*y.a[3][1];
		res.a[3][2]=x.a[3][0]*y.a[0][2]+x.a[3][1]*y.a[1][2]+x.a[3][2]*y.a[2][2]+x.a[3][3]*y.a[3][2];
		res.a[3][3]=x.a[3][0]*y.a[0][3]+x.a[3][1]*y.a[1][3]+x.a[3][2]*y.a[2][3]+x.a[3][3]*y.a[3][3];
		return res;
	}
	vec operator+(vec x,vec y)
	{
		vec res;
		res.a[0]=x.a[0]+y.a[0];
		res.a[1]=x.a[1]+y.a[1];
		res.a[2]=x.a[2]+y.a[2];
		res.a[3]=x.a[3]+y.a[3];
		return res;
	}
	struct Segment_Tree{
		struct node{
			int l,r;
			matrix tag;
			vec x;
		}t[N<<2|1];
		inline void push_up(cint p)
		{
			t[p].x=t[p<<1].x+t[p<<1|1].x;
		}
		inline void push_down(cint p)
		{
			t[p<<1].tag=t[p<<1].tag*t[p].tag;
			t[p<<1|1].tag=t[p<<1|1].tag*t[p].tag;
			t[p].tag=emp;
		}
		void Build(cint p,cint l,cint r)
		{
			t[p].l=l;
			t[p].r=r;
			t[p].tag=emp;
			if(l==r)
			{
				t[p].x={0,0,0,1};
				return;
			}
			cint mid=l+r>>1;
			Build(p<<1,l,mid);
			Build(p<<1|1,mid+1,r);
			push_up(p);
		}
		void build()
		{
			Build(1,1,n);
		}
		void Update(cint p,cint l,cint r,matrix x)
		{
			if(t[p].l>r||t[p].r<l)return;
			if(t[p].l>=l&&t[p].r<=r)
			{
				t[p].tag=t[p].tag*x;
				t[p].x=t[p].x*x;
				return;
			}
			push_down(p);
			Update(p<<1,l,r,x);
			Update(p<<1|1,l,r,x);
			push_up(p);
		}
		void update(cint l,cint r,matrix x)
		{
			Update(1,l,r,x);
		}
		vec Ask(cint p,cint l,cint r)
		{
			if(t[p].l>r||t[p].r<l)return vec{0,0,0,0};
			if(t[p].l>=l&&t[p].r<=r)return t[p].x;
			push_down(p);
			return Ask(p<<1,l,r)+Ask(p<<1|1,l,r);
		}
		vec ask(cint l,cint r)
		{
			return Ask(1,l,r);
		}
	}T;
	void init()
	{
		for(int i=0;i<4;++i)emp.a[i][i]=1;
		T.build();
		ST.init();
	}
	struct stck{
		int a[N+1],t;
		inline void clear(){t=0;}
		inline int top(){return a[t];}
		inline void push(cint x){a[++t]=x;}
		inline void pop(){--t;}
		inline bool empty(){return (t==0);}
	}st;
	void main()
	{
		init();
		for(int i=1;i<=q;++i)
		{
			if(ans[i]==-1)continue;
			cint p=lower_bound(s+1,s+n+1,s[ql[i]]+qv[i])-&s[0];
			qry[p].push_back(i);
		}
		st.clear();
		for(int i=1;i<=n;++i)
		{
			int lst=i;
			matrix tmp=emp;
			tmp.a[3][0]=b[i];
			T.update(i,i,tmp);
			while(!st.empty()&&b[st.top()]>b[i])
			{
				tmp.a[3][0]=b[i]-b[st.top()];
				T.update(st.top(),lst-1,tmp);
				lst=st.top();
				st.pop();
			}
			st.push(i);
			for(int p:qry[i])
			{
				ans[p]=T.ask(ql[p],ql[p]).a[2];
				ans[p]+=ST.ask(ql[p],i)*(s[ql[p]]+qv[p]-s[i]);
			}
		}
	}
}
struct point{
	ll x,y,val;
};
vector<point>pts;
namespace STEP2{
	struct stck{
		int a[N+1],t;
		inline void clear(){t=0;}
		inline int top(){return a[t];}
		inline void push(cint x){a[++t]=x;}
		inline void pop(){--t;}
		inline bool empty(){return (t==0);}
	}st;
	int tl[N+1],tr[N+1];
	void main()
	{
		for(int i=1;i<=n;++i)
		{
			while(!st.empty()&&b[st.top()]>b[i])st.pop();
			tl[i]=st.top();
		}
		st.clear();
		st.a[0]=n+1;
		for(int i=n;i>=1;--i)
		{
			while(!st.empty()&&b[st.top()]>=b[i])st.pop();
			tr[i]=st.top();
		}
		for(int i=1;i<=n;++i)
		{
			pts.push_back({0,s[i],b[i]});
			pts.push_back({s[i]-s[tl[i]],s[i],-b[i]});
			pts.push_back({s[tr[i]]-s[i],s[tr[i]],-b[i]});
			pts.push_back({s[tr[i]]-s[tl[i]],s[tr[i]],b[i]});
		}
		for(int i=1;i<=q;++i)
		{
			ql[i]=s[ql[i]]+qv[i];
			qr[i]=s[qr[i]];
		}
	}
}
namespace STEP3{
	struct Trie{
		
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n+1;++i)
	{
		s[i]=s[i-1]+a[i-1];
	}
	for(int i=1;i<=q;++i)
	{
		ql[i]=read();
		qr[i]=read();
		qv[i]=min(1ll*read(),s[qr[i]]-s[ql[i]]);
	}
	STEP0::main();
	STEP1::main();
	STEP2::main();
}