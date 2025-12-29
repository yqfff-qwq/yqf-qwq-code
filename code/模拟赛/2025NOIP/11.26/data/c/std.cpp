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
const int N=305,lim=1e14;
int n,m,a[N],b[N],f[N][N][N],c[N],cnt[N];
void chk(int &x,int y){
	if(x>y)x=y;
}
signed main(){
	n=rd();m=rd();
	vi v;
	for(int i=1;i<=n;i++)a[i]=rd(),b[i]=rd(),v.pb(a[i]);
	sort(v.begin(),v.end());
	for(int i=0;i+1<v.size();i++)v[i+1]=max(v[i+1],v[i]+1);
	memset(f,inf,sizeof f);
	fill(c,c+n+1,inf);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		c[a[i]]=min(c[a[i]],b[i]);	
		cnt[a[i]]++;
	}
	for(int i=2;i<=n;i++)c[i]=min(c[i],c[i-1]);
	f[1][1][cnt[1]-1]=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				int to=k+cnt[i+1],d=v[i]-v[i-1],w;
				if(k&&d*m>lim)w=lim+1;else w=d*m*k;
				if(to<=j)chk(f[i+1][j][0],f[i][j][k]+w);
				else {
					chk(f[i+1][j][to-j],f[i][j][k]+w);
					chk(f[i+1][j+1][to-j-1],f[i+1][j][to-j]+c[i]);
				}
			}
		}
	}
	int ans=lim;
	for(int i=0;i<=n;i++)chk(ans,f[n][i][0]);
	cout<<ans<<'\n';
	return 0;
}