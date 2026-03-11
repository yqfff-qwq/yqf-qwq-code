#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
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
	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	cin>>n;
	int t=1;
	while(t*5<=n) t*=10;
	int ans=0;
	for(int i=1;i<=9;i++){
		int x=t*i-1;
		int l=max(x-n,1ll),r=min(x-1,n);
		if(l<r){
			ans+=(r-l+1)/2;
		}
	}
	cout<<ans;
	return 0;
}

