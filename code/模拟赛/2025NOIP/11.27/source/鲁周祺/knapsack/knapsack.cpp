#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
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
inline ll min(ll x,ll y){
	return x<y?x:y;
}
const int N=5e5+5,M=1e4+5,K=1e3+5;
ll T=1,n,m,fa[N],head[K],po=1,dp[M],mx;
bitset<K>vis;
struct edge{
	ll to,next;
}e[N];
inline void add(ll u,ll v){
	e[po].to=v;
	e[po].next=head[u];
	head[u]=po++;
}
struct node{
	ll v,w;
	bool operator< (const node& g){
		return w==g.w?v>g.v:w<g.w;
	}
}a[N];
inline ll finds(ll x){
	return fa[x]==x?x:fa[x]=finds(fa[x]);
}
inline void merge(ll x,ll y){
	ll fax=finds(x),fay=finds(y);
	if(fax!=fay){
		add(x,y);
		fa[fax]=fay;
	}
}
inline void dfs(ll x){
	mx=max(mx,dp[m]);
//	write(x);
//	putchar('\n');
	int z;
	vector<ll>v;
	for(int i=head[x];i;i=e[i].next){
		z=e[i].to;
		for(int j=m;j>=a[z].w;j--){
			v.pb(dp[j]);
			dp[j]=max(dp[j],dp[j-a[z].w]+a[z].v);
		}
		dfs(z);
		for(int j=a[z].w;j<=m;j++){
			dp[j]=v[m-j];
			v.pop_back();
		}
	}
}
signed main(){
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++){
			a[i].v=read();
			a[i].w=read();
			fa[i]=i;
		}
		sort(a+1,a+1+n);
		if(a[1].w==a[n].w){
			ll ans=0,mun=0;
			for(int i=1;i<=n;i++){
				if(mun+a[i].w>m) break;
				ans+=a[i].v;
				mun+=a[i].w;
			}
			write(ans);
			putchar('\n');
			return 0;
		}
		ll l=0;
		for(int i=2;i<=n;i++){
			if(a[i].w!=a[i-1].w){
				if(a[i].w==a[n].w) l=i-1;
				break;
			}
		}
		if(l){
			if(a[n].w%a[1].w!=0){
				ll ans=0,mun=0,res=0;
				for(int i=1;i<=l;i++){
					if(mun+a[i].w>m) break;
					ans+=a[i].v;
					mun+=a[i].w;
				}
				mun=0;
				for(int i=l+1;i<=n;i++){
					if(mun+a[i].w>m) break;
					res+=a[i].v;
					mun+=a[i].w;
				}
				write(max(res,ans));
				putchar('\n');
				return 0;
			}else{
				ll ans=0,x=m%a[n].w,y=x/a[1].w,q=0;
				for(int i=1;i<=y;i++){
					ans+=a[i].v;
				}
				x=m/a[n].w;
				for(int i=l+1;i<=l+x;i++){
					ans+=a[i].v;
				}
				ll r=a[n].w/a[1].w,cnt=-1;
				vector<ll>v;
				for(int i=y+1;i<=l;i+=r){
					v.pb(0);
					cnt++;
					for(int j=i;j<=min(i+r-1,l);j++){
						v[cnt]+=a[j].v;
					}
				}
				for(int i=l+x;i>l;i--){
					if(q>cnt) break;
					if(v[q]>a[i].v){
						ans=ans-a[i].v+v[q];
						q++;
					}else break;
				}
				write(ans);
				putchar('\n');
				return 0;
			}
		}
//		cerr<<"NO\n";
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				if(a[j].w%a[i].w==0){
					merge(i,j);
				}
			}
		}
//		puts("YES");
		for(int i=1;i<=n;i++){
			ll x=finds(i);
			if(!vis[x]){
				vis[x]=true;
				if(a[i].w>m) break;
				for(int j=m;j>=a[i].w;j--) dp[j]=a[i].v;
				dfs(i);
				for(int j=m;j>=a[i].w;j--) dp[j]=0;
			}
		}
		write(mx);
		putchar('\n');
	}
	return 0;
}