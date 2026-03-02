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
const int N=20,mod=998244353,iv2=mod+1>>1;
int n,a[1<<N],s,f[1<<N];
void fwt(int *a,int type){
	for(int x=2;x<=1<<n;x<<=1){
		int k=x>>1;
		for(int i=0;i<1<<n;i+=x)
			for(int j=0;j<k;j++)
				(a[i+j]+=a[i+j+k])%=mod,(a[i+j+k]=a[i+j]-a[i+j+k]*2)%=mod,
				a[i+j]=a[i+j]*type%mod,a[i+j+k]=a[i+j+k]*type%mod;
	}
}
int qpow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)res=1ll*res*x%mod;
	return res;
}
signed main(){
	freopen("expect.in","r",stdin);
	freopen("expect.out","w",stdout);
	n=rd();
	for(int i=0;i<1<<n;i++)a[i]=rd(),s+=a[i];
	for(int i=0;i<1<<n;i++)a[i]=1ll*a[i]*qpow(s,mod-2)%mod;
	a[0]=(a[0]+mod-1)%mod;
	fwt(a,1);
	f[0]=(1<<n)-1;
	for(int i=1;i<1<<n;i++)f[i]=mod-1;
	fwt(f,1);
	for(int i=0;i<1<<n;i++)f[i]=1ll*f[i]*qpow(a[i],mod-2)%mod;
	fwt(f,iv2);
	for(int i=0;i<1<<n;i++)f[i]=(f[i]+mod)%mod;
	for(int i=0;i<1<<n;i++)cout<<(f[i]-f[0]+mod)%mod<<'\n';
	return 0;
}