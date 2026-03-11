#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
inline int read(){
	char c=getchar();
	int sum=0,f=1;
	while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(('0'<=c&&c<='9')){sum=(sum<<3)+(sum<<1)+c-'0';c=getchar();}
	return sum*f;
}
signed main(){
	//freopen("berry.in","r",stdin);
	//freopen("berry.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		int x,y;
		cin >>x>>y;
		if((x<=1)&&y>1)cout<<"Yes\n";
		else if(y<=1&&x>1)cout<<"Yes\n";
		else cout<<"No\n";
	}	
}
