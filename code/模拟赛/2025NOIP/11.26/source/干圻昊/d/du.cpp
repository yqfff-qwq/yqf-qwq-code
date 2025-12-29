#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template <typename T>
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

	template <typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;

#define int long long
const int N=3e3+10;
const int INF=1e15;

int a[N],b[N],sum[N][N],tmin[N][N],ne[N];
void solve(){
	int S,T,U;
	input(S);
	input(T);
	input(U);
	int now=0;
	int ans=0;
	for(int i=T-1;i>=S;i--){
		if(a[i]>U){
			print(-1);
			putchar('\n');
			return;
		}
	}
	for(int i=S;i<T&&i!=-1;i=ne[i]){
//		cout<<now<<" ";
		int g=0;
		if(ne[i]==-1||ne[i]>=T) g=sum[i][T-1];
		else g=sum[i][ne[i]-1];
		ans+=g*b[i];
//		cout<<now<<endl;
	}
	print(ans);
	putchar('\n');
//	cout<<endl;
}

vector<int> stk;
int n,q;
signed main(){
	freopen("d5.in","r",stdin);
//	freopen("d.out","w",stdout);
	input(n);
	input(q);
	for(int i=1;i<=n;i++) input(a[i]);
	for(int i=1;i<=n;i++) input(b[i]);
	for(int i=1;i<=n;i++) sum[i][i]=a[i];
	for(int len=2;len<=n;len++)
		for(int l=1,r=l+len-1;r<=n;l++,r++)
			sum[l][r]=sum[l][r-1]+sum[r][r];
	for(int i=1;i<=n;i++) tmin[i][i]=a[i];
	for(int len=2;len<=n;len++)
		for(int l=1,r=l+len-1;r<=n;l++,r++)
			tmin[l][r]=min(tmin[l][r-1],tmin[r][r]);
	for(int i=n;i>=1;i--){
		while(stk.size()&&b[stk.back()]>b[i]) stk.pop_back();
		if(stk.size()) ne[i]=stk.back();
		else ne[i]=-1;
		stk.push_back(i);
	}
	a[n+1]=0,b[n+1]=INF;
	while(q--) solve();
}

// 11 Pts
