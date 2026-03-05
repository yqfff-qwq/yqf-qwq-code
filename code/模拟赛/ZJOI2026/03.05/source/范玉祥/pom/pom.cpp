#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=1e6+5;
int n,t,c[N],f[N],z[N],x[N],y[N];
char a[N],b[N];
int calc(int *a,int *b,int *c,int n){
	a[n+1]=b[n+1]=0;
	for(int i=1;i<=n;i++)f[i]=1e18;
	f[n+1]=0;
	int mn=1e18,pre=1e18;
	for(int i=n;i;i--){
		if(a[i]){
			f[i]=min(f[i+1],mn);
			mn=1e18;
		}else{
			f[i]=f[i+1]+min(pre,c[i]);
			f[i]=min(f[i],c[i]+mn);
			mn=min(f[i+1]+c[i],mn);
		}
		pre=min(pre,c[i]);
	}
	return f[1];
}
void sol(){
	n=rd();
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;i++)c[i]=rd();
	for(int i=1;i<=n;i++)
		if(b[i]<a[i])return cout<<-1<<'\n',void();
	int ans=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='0')continue;
		int m=0,j;
		for(j=i;j<=n&&b[j]=='1';j++)
			x[++m]=a[j]-'0',y[m]=b[j]-'0',z[m]=c[j];
		ans+=calc(x,y,z,m);
		i=j-1;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("pom.in","r",stdin);
	freopen("pom.out","w",stdout);
	for(t=rd();t--;)sol();
	return 0;	
}