#include<bits/stdc++.h>
using namespace std;
#define N 1000009
char d[N];
int n,l,r,ans;
inline int get(int l,int r){
	for(int i=l;i<=r;++i){
		if(d[i]=='0')
		return 1;
	}
	return r-l+1;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%s",d+1);
	n=strlen(d+1);
	d[0]=d[n+1]=d[n+2]='0';
	n+=2;
	l=1;r=0;
	for(int i=1;i<=n;++i){
		if(d[i]=='1')
		r=i;
		else if(d[i-1]=='0')
		ans+=get(l,r),l=i+1,r=i;
	}
	printf("%d",ans);
}
