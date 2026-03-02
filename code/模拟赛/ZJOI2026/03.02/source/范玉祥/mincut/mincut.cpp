#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned int
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=1e6+5;
int n,m,s,t,d[N],a[61],id[61],b[61],u[N],v[N],w[N],p[N],q[N],cur[N];
void ins(int x,int y,int z){
	for(int i=59;~i;i--){
		if(x>>i&1){
			if(!a[i]||b[i]<z){
				swap(id[i],y),swap(b[i],z);swap(x,a[i]);
				if(!x)break;
				x^=a[i];
				continue;
			}
			x^=a[i];
		}
	}
}
int qry(int x){
	for(int i=59;~i;i--)if(x>>i&1)x^=a[i];
	return x;
}
void sol(){
	n=rd();m=rd(),s=rd(),t=rd();
	for(int i=1;i<=n;i++)d[i]=0,cur[i]=m+1;
	fill(a,a+60,0);
	fill(b,b+60,0);
	fill(id,id+60,0);
	for(int i=1;i<=m;i++)u[i]=rd(),v[i]=rd(),w[i]=rd();
	for(int i=m;i;i--){
		p[i]=cur[u[i]];
		cur[u[i]]=i;
		q[i]=cur[v[i]];
		cur[v[i]]=i;
	}
	for(int i=1;i<=m;i++){
		auto clear=[&](int u){
			for(int i=0;i<60;i++)if(id[i]==u)id[i]=0,a[i]=0,b[i]=0;
		};
		clear(u[i]);clear(v[i]);
		if(u[i]^s&&u[i]^t)ins(d[u[i]]^=w[i],u[i],p[i]);
		if(v[i]^s&&v[i]^t)ins(d[v[i]]^=w[i],v[i],q[i]);
		if(u[i]==s||v[i]==s)d[s]^=w[i];
		cout<<qry(d[s])<<'\n';
	}
}
signed main(){
	freopen("mincut.in","r",stdin);
	freopen("mincut.out","w",stdout);
	for(int t=rd();t--;)sol();
	return 0;
}