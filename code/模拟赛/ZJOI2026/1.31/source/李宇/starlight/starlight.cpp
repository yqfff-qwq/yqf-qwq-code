#include<bits/stdc++.h>
#define bacKCM freopen
#define int long long
using namespace std;
const int N=1e6+10;
struct nnd{
	int id,id2;
	int vl;
}a[N];
int T,n,ans=0;
bool cmp(nnd x,nnd y){
	return x.vl<y.vl;
}
bool cmp2(nnd x,nnd y){
	return x.id<y.id;
}
int mn[N],mx[N];//mn[i]记录a[k]^a[i]的最小值，mx[i]记录a[k]^a[i]的最大值
signed main(){
	bacKCM("starlight.in","r",stdin);
	bacKCM("starlight.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(mn,127,sizeof mn);
		memset(mx,0,sizeof mx);
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i].vl),a[i].id=i;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				mn[i]=min(mn[i],a[j].vl^a[i].vl);
				mx[i]=max(mx[i],a[j].vl^(a[i].vl^2147483647));
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) a[i].id2=i;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(j==i) continue;
				if(a[j].id>a[i].id&&a[j].id2-a[i].id2<=1){
					int x=a[i].vl;
					bool fg=1;
					if(mn[i]<(a[j].vl^x)) fg=0;
					if(!fg) continue;
					x=(2147483647)^a[j].vl;
					if(mx[j]>(a[i].vl^x)) fg=0;
					if(fg) ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}