#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int const N=5e5+5;
struct Node{
	LL v,w;
}t[N];
int n;
LL m;
namespace case1{
	int const M=1e4+5;
	LL dp[M];
	void solve(){
		for(int i=0;i<=m;i++)dp[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=m;j>=t[i].w;j--)
				dp[j]=max(dp[j],dp[j-t[i].w]+t[i].v);
		cout<<dp[m];
		return;
	}
}
namespace case2{
	void solve1(){
		sort(t+1,t+n+1,[](const Node&x,const Node&y){
			return x.v>y.v;
		});
		LL cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(cnt+t[i].w>m)break;
			cnt+=t[i].w;
			ans+=t[i].v;
		}
		cout<<ans;
		return;
	}
	LL f[N],g[N];
	void solve2(unordered_map<LL,int>&mp){
		sort(t+1,t+n+1,[](const Node&x,const Node&y){
			if(x.w!=y.w)return x.w>y.w;
			return x.v>y.v;
		});
		LL k1=t[1].w;
		LL k2=t[n].w;
		for(int i=1;i<=mp[k1];i++)
			f[i]=f[i-1]+t[i].v;
		for(int i=mp[k1]+1;i<=n;i++)
			g[i-mp[k1]]=g[i-mp[k1]-1]+t[i].v;
		LL ans=0;
		for(int i=1;i<=mp[k1];i++){
			LL m1=k1*i;
			if(m1>m)break;
			int j=min((m-m1)/k2,(LL)mp[k2]);
			ans=max(ans,f[i]+g[j]);
		}
		cout<<ans;
		return;
	}
}
namespace case3{
	void solve(){
		sort(t+1,t+n+1,[](const Node&x,const Node&y){
			if(x.w!=y.w)return x.w<y.w;
			return x.v>y.v;
		});
		vector<LL>vt[N];
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(t[i].w!=t[i-1].w)cnt++;
			vt[cnt].emplace_back(t[i].v);
		} // 3<=cnt<=40
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<vt[i].size();j++)
				vt[i][j]+=vt[i][j-1]; // good -> bad
		
		return;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout;
	for(int i=1;i<=n;i++){
		cin>>t[i].v>>t[i].w;
		mp[t[i].w]++;
	}
	if(n<=1e3&&m<=1e4)case1::solve();
	else if(mp.size()==1)case2::solve1();
	else if(mp.size()==2)case2::solve2(mp);
	case3::solve();
	return 0;
}