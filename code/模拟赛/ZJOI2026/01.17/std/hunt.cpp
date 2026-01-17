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
    freopen("hunt.in","r",stdin);
    freopen("hunt.out","w",stdout);
	work();
	return 0;
}
