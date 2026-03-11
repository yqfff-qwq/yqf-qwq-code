#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
inline int read(){
    int t=1,tot=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
        tot=tot*10+ch-'0';
		ch=getchar();
	}
	return tot*t;
}
signed main(){
	freopen("berry.in","r",stdin);
	freopen("berry.out","w",stdout);
	cin>>T;
	while(T--){
		int a=read(),b=read();
		if(a<b) swap(a,b);
		if(a-2>=b) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
