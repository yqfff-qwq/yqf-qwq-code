#include<bits/stdc++.h>
using namespace std;
int as[10000];
int calc(int val){
	int res=0;
	while(val){
		if(val%10!=9)break;
		res++,val/=10;
	}
	return res;
}
signed main(){
	for(int n,ans,t;n<=1000;n++,t=ans=0){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int tmp=calc(i+j);
				if(tmp>ans)ans=tmp,t=1;
				else if(tmp==ans)t++;
			}
		}
		as[n]=t;
		cout<<n<<":"<<t<<' ';
		if(n<=100)cout<<'\n';
		else cout<<t-as[n-100]<<'\n';
	}
	return 0;
}

