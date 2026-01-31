#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define getchar _getchar_nolock
#else
#define getchar getchar_unlocked
#endif 
inline int read(){
	int ret=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ret=(ret<<3)+(ret<<1)+c-'0';
		c=getchar();
	}
	return ret*w;
}
int T,n,m;
int a[505];
signed main(){
	freopen("starlight.in","r",stdin);
	freopen("starlight.out","w",stdout);
	cin>>T;
	int q[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)a[i]=read();
		int cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int f=1;
				for(int k=1;k<=n;k++){
					for(int aa=1;aa<=10;aa++){
						if((a[k]^q[aa])>(a[i]^q[aa])&&(a[k]^q[aa])<(a[j]^q[aa])){
							f=0;
							break;
						}
					}
					if(f==0)break;
				}
				cnt+=f;
			}
		}
		cout<<cnt<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
