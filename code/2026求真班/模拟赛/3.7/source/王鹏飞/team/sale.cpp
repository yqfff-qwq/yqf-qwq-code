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
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
}
