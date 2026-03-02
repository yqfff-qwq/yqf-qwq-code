#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned int
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=2e5+5;
int n,m,f[N],a[N],b[N],c[N],p[N],z[N];
vi vec[N];
signed main(){
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=m;i++){
		a[i]=rd(),b[i]=rd(),c[i]=rd();
		if(a[i]>b[i])swap(a[i],b[i]);
		p[a[i]]+=c[i];
		p[b[i]]-=c[i];
		vec[a[i]].pb(i);
	}
	for(int i=2;i<=n;i++)p[i]+=p[i-1];
	int X=max_element(p+1,p+n+1)-p;
	auto chk=[&](int x,int y){
		z[X]=p[X]-x+y;
		for(int i=1;i<X;i++)z[i]=max(0ll,(p[i]+z[X]-x+1)/2);
		for(int i=1;i<=n;i++)f[i]=0;
		priority_queue<array<int,3>>h;
		int cur=0;
		for(int i=1;i<=X;i++){
			for(auto j:vec[i])
				if(b[j]>X)h.push({b[j],i,c[j]});
			while(!h.empty()&&cur<z[i]){
				auto t=h.top();h.pop();
				int x=t[0],y=t[1],z=t[2];
				int w=min(z,::z[i]-cur);
				f[1]+=w;
				f[y]-=w*2;
				f[x]+=w*2;
				cur+=w;
				if(w<z)h.push({x,y,z-w});
			}
			if(cur<z[i])return 0;
		}
		for(int i=1;i<=n;i++){
			f[i]+=f[i-1];
			if(f[i]+p[i]>x)return 0;
		}
		return 1;
	};
	int l=1,r=2e14;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid,0)||chk(mid,1))r=mid-1;
		else l=mid+1;
	}
	cout<<r+1<<'\n';
	return 0;
}