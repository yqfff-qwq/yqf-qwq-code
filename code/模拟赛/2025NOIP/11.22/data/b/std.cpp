#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pr;
inline LL rd(){
	LL x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const LL p=998244353,N=3005;
LL qp(LL x,LL y){LL z=1;for(;y;y>>=1,x=x*x%p)if(y&1)z=z*x%p;return z;}
LL n,m,k,s1,s2,a[N],g[N][N],de[N],vs[N];vector<LL>to[N],vc,ve[N];queue<LL>q;
inline void ad(LL &x,LL y){x+=y;if(x>=p)x-=p;}
inline void add(LL x,LL y){for(LL i=3000;i>=y;--i)ad(g[x][i],g[x][i-y]);}
inline void del(LL x,LL y){for(LL i=y;i<=3000;++i)ad(g[x][i],p-g[x][i-y]);}
int main(){
//	freopen("b9.in","r",stdin);
//	freopen("b9.ans","w",stdout);
 	freopen("b20.in","r",stdin);
 	freopen("b20.ans","w",stdout);
	n=rd();m=rd();k=rd();s1=rd();s2=rd();
	for(LL x,y;m--;)x=rd(),y=rd(),ve[x].push_back(y),ve[y].push_back(x),++de[x],++de[y];
	for(LL i=1;i<=n;++i)if(de[i]<=k)q.push(i);
	while(!q.empty()){
		LL x=q.front();q.pop();vs[x]=1;
		for(auto y:ve[x])if(!vs[y])to[x].push_back(y);
		for(auto y:ve[x])if((--de[y])==k)q.push(y);
	}
	for(LL i=1;i<=n;++i)if(!vs[i])vc.push_back(i);
	if(vc.size()){
		sort(vc.begin(),vc.end());
		for(auto i:vc)printf("%lld ",i);return 0;
	}
	for(LL i=1;i<=n;++i)a[i]=rd(),g[i][0]=1;
	for(LL i=1;i<=n;++i)for(auto j:to[i])add(j,a[i]);s1+=s2;
	for(LL op,x,y;s1--;){
		op=rd();x=rd();y=rd();
		if(op==1){
			for(auto j:to[x])del(j,a[x]),add(j,y);
			a[x]=y;
		}else{
			LL o=to[x].size(),an=0;
			for(LL i=0;i<(1<<o);++i){
				LL sm=y;
				for(LL j=0;j<o;++j)if(i>>j&1)sm-=a[to[x][j]];
				if(sm>=0)ad(an,g[x][sm]);
			}
			printf("%lld\n",an);
		}
	}
	return 0;
}
