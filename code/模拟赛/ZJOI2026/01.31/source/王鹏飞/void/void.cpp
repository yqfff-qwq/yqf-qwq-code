#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int ma=0;
	while(!('0'<=c&&c<='9'))c=getchar();
	while(('0'<=c&&c<='9'))ma=ma*10+c-'0',c=getchar();
	return ma;
}
const int N=2e5+20;
struct p{
	int head[N],l,next[N],go[N];
	inline void add(int x,int y){
		next[++l]=head[x];
		head[x]=l;
		go[l]=y;
	}
	inline void clear(){
		l=0;
		memset(head,0,sizeof(head));
	}
}q;
int n,m;
bool tp(int x,int y){
	int vis[N]={0},ma=0;
	vis[x]++;
	for(int i=q.head[x];i;i=q.next[i])
		vis[q.go[i]]++;
	if(vis[y])ma++;
	for(int i=q.head[y];i;i=q.next[i])
		if(vis[q.go[i]])ma++;
//	cout<<ma<<" ";
	if(ma%2)return 0;
	return 1;
}
inline void sol(){
	q.clear();n=read();m=read();
	for(int i=1;i<=m;i++){
		int x,y;
		x=read(),y=read();
		q.add(x,y);
		q.add(y,x);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(tp(i,j)){
				cout<<i<<" "<<j<<"\n";
				return ;
			}
		}
	
}
signed main(){
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	int t=read();
	while(t--)sol();
	return 0;
}
