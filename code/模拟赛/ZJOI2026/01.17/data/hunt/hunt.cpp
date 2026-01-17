#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}

#define mod 998244353
struct modint{
	int x;
	modint(int o=0){x=o;}
	modint &operator = (int o){return x=o,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator ^=(int b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
};
inline modint qpow(modint x,int y){return x^y;}

vector<modint> fac,ifac,iv;
inline void initC(int n)
{
	if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
	int m=iv.size(); ++n;
	if(m>=n)return;
	iv.resize(n),fac.resize(n),ifac.resize(n);
	For(i,m,n-1){
		iv[i]=iv[mod%i]*(mod-mod/i);
		fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
	}
}
inline modint C(int n,int m){
	if(m<0||n<m)return 0;
	return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 500005
#define inf 0x3f3f3f3f

int n,x[maxn],y[maxn],z[maxn],vis[maxn];
struct cmpx{bool operator ()(int a,int b){return x[a]>x[b];}};priority_queue<int,vi,cmpx>qx;
struct cmpy{bool operator ()(int a,int b){return y[a]>y[b];}};priority_queue<int,vi,cmpy>qy;
struct cmpz{bool operator ()(int a,int b){return z[a]>z[b];}};priority_queue<int,vi,cmpz>qz;
int F(int i,int X,int Y,int Z){return max(x[i]-X,max(y[i]-Y,z[i]-Z));}
void work()
{
	while(qx.size())qx.pop();
	while(qy.size())qy.pop();
	while(qz.size())qz.pop();
	n=read();
	For(i,1,n)x[i]=read(),y[i]=read(),z[i]=read(),vis[i]=0;
	For(i,1,n)qx.push(i),qy.push(i),qz.push(i);
	int a,b,c,res=0;
	For(i,1,n){
		a=qx.top();while(vis[a])qx.pop(),a=qx.top();
		b=qy.top();while(vis[b])qy.pop(),b=qy.top();
		c=qz.top();while(vis[c])qz.pop(),c=qz.top();
		int nx=x[a],ny=y[b],nz=z[c];
		int da=F(a,nx,ny,nz),db=F(b,nx,ny,nz),dc=F(c,nx,ny,nz);
		if(da<=db&&da<=dc)vis[a]=1,res=max(res,(da+1)/2);
		else if(db<=da&&db<=dc)vis[b]=1,res=max(res,(db+1)/2);
		else vis[c]=1,res=max(res,(dc+1)/2);
	}
	cout<<res<<'\n';
}
int main()
{
    //freopen("hunt.in","r",stdin);
    //freopen("hunt.out","w",stdout);
	work();
	return 0;
}
