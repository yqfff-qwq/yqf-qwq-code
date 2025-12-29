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
const int N=1e4+5;
ll T=1,n,t,ans[N];
struct node{
	ll l,r,x;
	bool operator< (const node& g) const {
		return l==g.l?r<g.r:l<g.l;
	}
}a[N];
struct qop{
	ll l,r,x;
	bool operator< (const qop& g) const {
		return r==g.r?l<g.l:r<g.r;
	}
};
priority_queue<qop>q;
signed main(){
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		t=read();
		bool f=false;
		for(int i=1;i<=n;i++){
			a[i].l=read();
			a[i].r=read();
			a[i].x=i;
			if(a[i].r-a[i].l<t) f=true;
		}
		if(f){
			puts("no");
			return 0;
		}
		sort(a+1,a+1+n);
		if(t==1){
			ll now=a[1].l,m=0;
			for(int i=1;i<=n;i++){
				if(a[i].l==now) q.push({a[i].l,a[i].r,a[i].x});
				else{
					while(!q.empty()&&now<a[i].l){
						qop p=q.top();
						q.pop();
						if(now<p.r){
							ans[p.x]=now++;
						}else{
							f=true;
							break;
						}
					}
					if(f) break;
					if(now<a[i].l) now=a[i].l;
					i--;
				}
			}
			if(f){
				puts("no");
				return 0;
			}
			while(!q.empty()){
				qop p=q.top();
				q.pop();
				if(now<p.r){
					ans[p.x]=now++;
				}else{
					puts("no");
					return 0;
				}
			}
			for(int i=1;i<=n;i++){
				write(ans[i]);
				putchar(' ');
			}
			putchar('\n');
			return 0;
		}
	}
	return 0;
}