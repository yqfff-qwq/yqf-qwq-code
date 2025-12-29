#include<bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define pb push_back
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=1e4+5;
int n,t,a[N],b[N],f[1<<20],fr[1<<20],ans[N];
signed main(){
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	n=rd();t=rd();
	for(int i=0;i<n;i++)a[i]=rd(),b[i]=rd();
	if(n<=20){	
		memset(f,0x3f,sizeof f);
		f[0]=-1;
		for(int s=1;s<1<<n;s++){
			for(int i=0;i<n;i++)if(s>>i&1){
				int g=f[s^1<<i];
				if(g+t>b[i])continue;
				int to=max(g,a[i])+t;
				if(to<f[s])f[s]=to,fr[s]=s^1<<i;
			}
		}
		if(f[(1<<n)-1]>1e9)return cout<<"no\n",0;
		cout<<"yes\n";
		for(int i=(1<<n)-1;i;i=fr[i]){
			int u=__lg(i^fr[i]);
			ans[u]=max(f[fr[i]],a[u]);
		}
		for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];
	}else{
		vector<array<int,3>>vec;
		for(int i=0;i<n;i++)vec.pb({a[i],b[i],i});
		sort(vec.begin(),vec.end());
		int cur=-1;
		for(auto [a,b,id]:vec){
			if(cur+t>b)return cout<<"no\n",0;
			ans[id]=max(cur,a);
			cur=max(cur,a+t);
		}
		cout<<"yes\n";
		for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];
	}
	return 0;
}
