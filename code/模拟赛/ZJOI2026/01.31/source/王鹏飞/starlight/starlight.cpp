#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int ma=0;
	while(!('0'<=c&&c<='9'))c=getchar();
	while(('0'<=c&&c<='9'))ma=ma*10+c-'0',c=getchar();
	return ma;
}
const int N=1e6+20;
int n,ma=0;
struct p{
	int x,id;
}a[N];
bool hack(int x,int y){
	for(int k=1;k<=n;k++)
		for(int q=0;q<=log2(ma);q++){
			int p=1<<q;
			int xx=x^p,yy=y^p,z=a[k].x^p;
			if(xx<z&&z<yy){
//				cout<<x<<" "<<y<<" "<<a[k].x<<" "<<q<<"\n";
				return 0;
			}
		}
	return 1;
}
bool cmp(p n1,p n2){return n1.x<n2.x;}
inline void sol(){
	n=read();
	ma=0;
	int ans=0;
	for(int i=1;i<=n;i++)a[i].x=read(),ma=max(ma,a[i].x),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		int x=a[i].x,y=a[i+1].x;
		if(a[i].id>a[i+1].id)swap(x,y);
		if(hack(x,y))
//			cout<<x<<" "<<y<<"\n",
			ans++;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("starlight.in","r",stdin);
	freopen("starlight.out","w",stdout);
	int t=read();
	while(t--)sol();
	return 0;
}
/*
4
5 
1 4 5 2 6
7
3 1 4 5 9 2 6
3
114 51 4
6
1 2 4 8 16 32
*/
