#include<bits/stdc++.h>
// #define hwq T Jan_31th_mock_race
#define ll long long
using namespace std;
inline void read(int &x){
	char c; while((c=getchar())<'0'||c>'9');
	for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c^48);
}
inline void write(const int &x){
	if(x>9) write(x/10);
	putchar(x%10+48);
}
const int N=5000005;
int n,n2,m,a[N<<1],b[N<<1],tot;
bool vis[N<<1];
inline int tf(int x,int l){
	int r=n2,mid,ans=n2;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>=x){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
inline bool pd(int x){
	for(int i=1;i<=n2;++i) vis[i]=false;
	for(int i=1,y,k;i<=n2;++i){
		if(vis[i]) continue;
		y=m; k=n2+1;
		if(x-a[i]>=a[i]){
			k=tf(x-a[i],i+1);
			if(!vis[k]) y=(a[i]+a[k])%m;
		}
		int z=tf(x+m-a[i],i+1);
		if(!vis[z]){
			if(y>x) y=(a[i]+a[z])%m,k=z;
			else if(((a[i]+a[z])%m<=x)&&((a[i]+a[z])%m>y))
				y=(a[i]+a[z])%m,k=z;
		}
		if(y>x) return false;
		vis[k]=vis[i]=true;
	}
	return true;
}
inline void baoli(int s){
	if(s>n2){
		int mx=0;
		for(int i=1;i<=n;++i)
			mx=max(mx,(b[i]+b[i+n])%m);
		tot=min(tot,mx);
		return;
	}
	for(int i=1;i<=n2;++i){
		if(!vis[i]){
			vis[i]=true;
			b[s]=a[i];
			baoli(s+1);
			vis[i]=false;
		}
	}
}
inline void solve(){
	read(n); read(m); n2=n*2; tot=m+1;
	for(int i=1;i<=n2;++i){
		read(a[i]);
	}
	baoli(1);
	// int l=0,r=m,ans=m+1,mid;
	// while(l<=r){
		// mid=(l+r)>>1;
		// if(pd(mid)){
			// ans=mid;
			// r=mid-1;
		// }else{
			// l=mid+1;
		// }
	// }
	write(tot);
	// write(ans);
	putchar('\n');
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	read(t);
	while(t--) solve();
	return 0;
}