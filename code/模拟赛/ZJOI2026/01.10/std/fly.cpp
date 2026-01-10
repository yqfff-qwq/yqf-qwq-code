#include<bits/stdc++.h>
#define ll long long
#define dd double
#define ull unsigned ll
#define LL __int128
#define siz(A) ((int)A.size())
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int xx=505;
int A[xx][xx],n,m,f[xx][xx],vis[xx],dis[xx];
char ED;
int main(){
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
	n=read(),m=read();
	memset(A,0x3f,sizeof(A));
	while(m--)
	{
		int x=read(),y=read(),z=read();
		A[x][y]=A[y][x]=min(A[x][y],z);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=A[i][j]<1e9?1:1e9;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int I=1;I<=n;I++)dis[I]=1e9;
	dis[1]=0;
	for(int I=1;I<=n;I++)
	{
		int id=-1;
		for(int i=1;i<=n;i++)if(!vis[i]&&(id==-1||dis[i]<dis[id]))id=i;
//		cerr<<id<<" "<<dis[id]<<"@\n";
		vis[id]=1;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[k]=min(1ll*dis[k],dis[id]+1ll*A[id][j]*(f[j][k]+1));
	}
	cout<<dis[n]<<"\n";
	pc('1',1);
	return 0;
}
