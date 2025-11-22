#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=' ';
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(f) x=-x;
	}

	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;

#define int unsigned long long

const int mod=998244353;
const int N=3e3+10;
const int V=3e3;
const int M=1e6+10;
int n,m,k,s1,s2;

int l[M<<1],ne[M<<1],head[N],tail[N],idx;
void con(int u,int v){
	idx++;
	l[idx]=v;
	if(head[u]) ne[tail[u]]=idx;
	else head[u]=idx;
	tail[u]=idx;
}

namespace ques1{
	int du[N];
	void AK(){
		for(int i=1;i<=n;i++) if(du[i]) print(i),putchar(' ');
		exit(0);
	}
	void Main(){
		for(int i=n;i>=1;i--){
			int t=-1;
			for(int j=1;j<=n;j++){
				if(!du[j]) continue;
				if(t==-1) t=j;
				else if(t!=-1&&du[j]<du[t]) t=j;
			}
			if(du[t]>k) AK();
			du[t]=0;
			for(int j=head[t];j;j=ne[j]){
				int v=l[j];
				if(du[v]) du[v]--;
			}
		}
	}
}

namespace ques2{
	int f[N][N];
	int a[N];
	void add(int u,int x){
		for(int i=V;i>=x;i--)
			f[u][i]=(f[u][i]+f[u][i-x])%mod;
	}
	void del(int u,int x){
		for(int i=x;i<=V;i++)
			f[u][i]=(f[u][i]+mod-f[u][i-x])%mod;
	}
	
	void Main(){
		for(int i=1;i<=n;i++) input(a[i]);
		for(int u=1;u<=n;u++){
			f[u][0]=1;
			for(int i=head[u];i;i=ne[i]){
				int v=l[i];
				add(u,a[v]);
			}
		}
		for(int i=1;i<=s1+s2;i++){
			int ope,x,y;
			input(ope);
			input(x);
			input(y);
			if(ope==2) print(f[x][y]),putchar('\n');
			else{
				if(a[x]==y) continue;
				for(int i=head[x];i;i=ne[i]){
					int v=l[i];
					del(v,a[x]);
				}
				a[x]=y;
				for(int i=head[x];i;i=ne[i]){
					int v=l[i];
					add(v,a[x]);
				}
			}
		}
	}
} 
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	input(n);
	input(m);
	input(k);
	input(s1);
	input(s2);
	for(int i=1;i<=m;i++){
		int u,v;
		input(u);
		input(v);
		con(u,v);
		con(v,u);
		ques1::du[u]++;
		ques1::du[v]++;
	}
	ques1::Main();
	ques2::Main();
}

