#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Mamba return
#define Out 0;
#define pb push_back
#define lowbit(x) x&-x
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline ll max(ll x,ll y){
	return x>y?x:y;
}
const int N=3e3+5,M=1e6+5,mod=998244353;
inline ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int T=1,n,m,k,head[N],s1,s2,in[N],num,cnt=1,a[N],r[N];
ll b[N][N],dp[N][N],d[N],p[N],res,inv[N],invf[N],dp_[N][N];
unordered_map<int,vector<int>>mp,mq;
bitset<N>vis,l,flag;
queue<int>q;
vector<int>w;
struct edge{
	int to,next;
}e[M<<1];
struct node{
	int opt,x,y;
}c[M+N];
inline void add(int u,int v){
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
inline ll add_(ll x,ll y){
	x+=y;
	if(x>=mod) x-=mod;
	return x;
}
inline ll C(ll x,ll y){
	return inv[x]*invf[x-y]%mod*invf[y]%mod;
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
//	T=read();
	while(T--){
		inv[0]=invf[0]=1;
		for(ll i=1;i<=3000;i++) inv[i]=inv[i-1]*i%mod;
		for(ll i=1;i<=3000;i++){
			invf[i]=qpow(inv[i],mod-2);
		}
		n=read();
		m=read();
		k=read();
		s1=read();
		s2=read();
		for(int i=1;i<=m;i++){
			int u=read(),v=read();
			add(u,v);
			add(v,u);
			in[u]++;
			in[v]++;
		}
		num=n;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(in[i]<=k){
				num--;
				q.push(i);
				vis[i]=true;
			}
		}
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int i=head[x];i;i=e[i].next){
				int z=e[i].to;
				if(!vis[z]){
					in[z]--;
					if(in[z]<=k){
						num--;
						q.push(z);
						vis[z]=true;
					}
				}
			}
		}
		if(num){
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					write(i);
					putchar(' ');
					num--;
					if(num<=0) break;
				}
			}
			Mamba Out
		}
//		for(int i=1;i<=n;i++){
//			for(int j=head[i];j;j=e[j].next){
//				b[e[j].to][a[i]]++;
//			}
//		}
		int t=s1+s2;
		for(int i=1;i<=t;i++){
			c[i].opt=read();
			c[i].x=read();
			c[i].y=read();
			if(c[i].opt==1) l[c[i].x]=true;
			else r[c[i].x]=max(r[c[i].x],c[i].y);
		}
		for(int i=1;i<=n;i++){
			if(r[i]){
//				write(i);
//				putchar('\n');
				for(int j=head[i];j;j=e[j].next){
					int z=e[j].to;
					if(!l[z]){
						if(!b[i][a[z]]){
							mp[i].pb(a[z]);
						}
						b[i][a[z]]++;
					}
				}
				mq[i].pb(0);
				dp[i][0]=1;
//				write(mp[i].size());
//				putchar('\n');
				for(auto j:mp[i]){
					res=0;
					for(auto k_:mq[i]){
						for(int l_=1;l_<=b[i][j];l_++){
							ll z=k_+l_*j;
							if(z>r[i]) break;
							if(!d[z]) p[++res]=z;
							d[z]=add_(d[z],dp[i][k_]*C(b[i][j],l_)%mod);
//							write(d[z]);
//							putchar(' ');
//							write(dp[i][k_]*C(b[i][j],l_)%mod);
//							putchar(' ');
//							write(dp[i][k_]);
//							putchar(' ');
//							write(C(b[i][j],l_));
//							putchar('\n');
						}
					}
//					write(j);
//					putchar(' ');
					for(int k_=1;k_<=res;k_++){
						if(!dp[i][p[k_]]){
							mq[i].pb(p[k_]);
						}
						dp[i][p[k_]]=add_(dp[i][p[k_]],d[p[k_]]);
//						write(p[k_]);
//						putchar('\n');
						d[p[k_]]=0;
					}
				}
//				putchar('\n');
			}
		}
		
//		for(int i=1;i<=n;i++){
//			if(r[i]){
//				write(i);
//				putchar(' ');
//				putchar(':');
//				putchar(' ');
//				for(int j=0;j<=r[i];j++){
//					write(dp[i][j]);
//					putchar(' ');
//				}
//				putchar('\n');
//			}
//		}
		
//		return 0;
		
		mp.clear();
		for(int i=1;i<=n;i++){
			if(r[i]){
				for(int j=head[i];j;j=e[j].next){
					int z=e[j].to;
					if(!l[z]){
						b[i][a[z]]=0;
					}
				}
				for(int j=head[i];j;j=e[j].next){
					int z=e[j].to;
					if(l[z]){
						if(!b[i][a[z]]){
							mp[i].pb(a[z]);
						}
						b[i][a[z]]++;
					}
				}
				for(auto j:mq[i]){
					dp_[i][j]=dp[i][j];
				}
			}
		}
		
//		for(int i=1;i<=n;i++){
//			if(r[i]){
//				write(i);
//				putchar(' ');
//				putchar(':');
//				putchar(' ');
//				for(int j=0;j<=r[i];j++){
//					write(dp_[i][j]);
//					putchar(' ');
//				}
//				putchar('\n');
//			}
//		}
		
//		return 0;
		for(int i=1;i<=n;i++){
			flag[i]=true;
		}
		for(int i=1;i<=t;i++){
			if(c[i].opt==1){
				if(a[c[i].x]==c[i].y) continue;
				for(int j=head[c[i].x];j;j=e[j].next){
					int z=e[j].to;
					if(r[z]){
						b[z][a[c[i].x]]--;
						b[z][c[i].y]++;
						flag[e[z].to]=true;
					}
				}
				a[c[i].x]=c[i].y;
			}else{
				if(!flag[c[i].x]){
					write(dp_[c[i].x][c[i].y]);
					putchar('\n');
					continue;
				}
				flag[c[i].x]=false;
				for(int j=0;j<=r[c[i].x];j++) dp_[c[i].x][j]=dp[c[i].x][j];
				for(auto j:mp[c[i].x]){
					if(b[c[i].x][j]<=0) continue;
					w=mq[c[i].x];
//					w.pb(0);
					res=0;
					for(auto k_:w){
						for(int l_=1;l_<=b[c[i].x][j];l_++){
							ll z=k_+l_*j;
							if(z>r[c[i].x]) break;
							if(!d[z]) p[++res]=z;
							d[z]=add_(d[z],dp_[c[i].x][k_]*C(b[c[i].x][j],l_)%mod);
						}
					}
					for(int k_=1;k_<=res;k_++){
						if(!dp_[c[i].x][p[k_]]){
							w.pb(p[k_]);
						}
						dp_[c[i].x][p[k_]]=add_(dp_[c[i].x][p[k_]],d[p[k_]]);
						d[p[k_]]=0;
					}
				}
				write(dp_[c[i].x][c[i].y]);
				putchar('\n');
			}
		}
//		while(t--){
//			ll op=read(),x=read(),y=read();
//			if(op==1){
//				for(int i=head[x];i;i=e[i].next){
//					b[e[i].to][a[x]]--;
//					b[e[i].to][y]++;
//				}
//				a[x]=y;
//			}else{
//				
//			}
//		}
	}
	Mamba Out
}
