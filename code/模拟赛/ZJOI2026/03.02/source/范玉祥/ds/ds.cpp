#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const int N=5e3+5;
int n,q,a[N],b[N],c[N],f[N][N];
signed main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	n=rd(),q=rd();
	for(int i=0;i<1<<n;i++)a[i]=rd();
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<1<<n;j++)b[j]=a[j]^i;
		for(int l=0;l<1<<n;l++){
			fill(c,c+(1<<n),0);
			for(int r=l,ans=0;r<1<<n;r++){
				c[b[r]]++;
				while(c[ans])ans++;
				f[l][r]=max(f[l][r],ans);
			}
		}
	}
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<1<<n;j++){
			if(j)f[i][j]+=f[i][j-1];
			// cout<<f[i][j]<<" ";
		}
		// cout<<'\n';
	}
	for(int l1,r1,l2,r2;q--;){
		l1=rd()-1,r1=rd()-1,l2=rd()-1,r2=rd()-1;
		ll ans=0;
		for(int i=l1;i<=r1;i++)
			ans+=f[i][r2]-(l2?f[i][l2-1]:0);
		cout<<ans<<'\n';
	}
	return 0;
}