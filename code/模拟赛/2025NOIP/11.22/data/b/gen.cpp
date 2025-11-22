#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pr;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
int n=3000,m,k=5,s1=3000,s2=1000000,K=5,lim=3000,a[3005],vs[3005],b[2000005];vector<pr>vc;
int get(int l,int r){return rand()%(r-l+1)+l;}
int main(){
	freopen("b20.in","w",stdout);srand(time(0));
	for(int i=1;i<=n;++i)a[i]=i;
	random_shuffle(a+1,a+1+n);
	for(int i=n;i;--i){
		int lm=min(i-1,n/i+8),sm=min(lm,get(0,K));
		for(int j=1,x;j<=sm;++j){
			while(vs[x=get(1,lm)]==i);
			vc.push_back({a[i],a[x]});vs[x]=i;
		}
	}
	printf("%d %d %d %d %d\n",n,vc.size(),k,s1,s2);
	random_shuffle(vc.begin(),vc.end());
	for(auto i:vc)printf("%d %d\n",i.F,i.S);
	for(int i=1;i<=n;++i)printf("%d ",get(1,lim));puts("");
	for(int i=1;i<=s1;++i)b[i]=1;random_shuffle(b+1,b+1+s2+s1);
	for(int i=1;i<=s1+s2;++i)
	if(b[i]){
		int o=get(1,n);
		printf("1 %d %d\n",a[get(1,min(n,n/o+8))],get(1,lim));
	}else{
		int o=get(1,n);
		printf("2 %d %d\n",a[get(1,min(n,n/o+8))],get(1,lim));
	}
	return 0;
}
