#include <bits/stdc++.h>
#define int long long
#define mian main
using namespace std;
const int N=2e5+5;
int n;
int a[N];
inline int read(){
    int t=1,tot=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
        tot=tot*10+(ch^48);
		ch=getchar();
	}
	return tot*t;
}
signed mian(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	int ans=0;
	int l=1;
	for(int r=1;r<=n;r++){
		while(a[r]-a[l]>5&&l<=n&&r<=n) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
