#include<bits/stdc++.h>
#define ll long long 
#define vi vector<int>
#define pb push_back
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=2e5+5,mod=998244353;
int t,n,a[N],m,f[N],b[N];
void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
void sol(){
	n=rd();m=rd();
	for(int i=1;i<=n;i++)a[i]=rd(),b[i]=0;
	f[n+1]=1;
	vi ps;
	for(int i=n;i;i--){
		f[i]=f[i+1]+1;
		for(auto x:ps)b[x]=__gcd(b[x],a[i]);
		int pre=1;
		vi temp;
		for(int j=0;j<ps.size();j++)if(!j||b[ps[j]]!=b[ps[j-1]]){
			f[i]=(f[i]+1ll*f[ps[j]+1]*(m/__gcd(m,b[ps[j]])-pre))%mod;
			pre=m/__gcd(m,b[ps[j]]);
			temp.pb(ps[j]);
		}
		b[i]=a[i];
		temp.insert(temp.begin(),i);
		temp.swap(ps);
	}
	f[1]=(f[1]+mod-1)%mod;
	cout<<f[1]<<'\n';
}
signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	for(t=rd();t--;)sol();
	return 0;
}