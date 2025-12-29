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
const int N=5e5+5;
int n,m,a[N],b[N],ans;
vi vec[N];
signed main(){
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	n=rd();m=rd();
	vi v;
	for(int i=1;i<=n;i++)a[i]=rd(),b[i]=rd(),v.pb(b[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)vec[lower_bound(v.begin(),v.end(),b[i])-v.begin()].pb(a[i]);
	assert(v[0]);
	m/=v[0];
	// cerr<<v.size()<<'\n';
	for(int i=0;i<v.size();i++){
		sort(vec[i].begin(),vec[i].end(),greater<int>());
		if(i+1==v.size()){
			for(int j=0;j<min(m,(int)vec[i].size());j++)ans+=vec[i][j];
		}else{
			int d=v[i+1]/v[i];
			for(int j=0;j<min(m%d,(int)vec[i].size());j++)ans+=vec[i][j];
			if(m%d>=vec[i].size()){
				m/=d;
				continue;
			}
			for(int j=m%d;j<vec[i].size();j+=d){
				int sum=0;
				for(int k=j;k<min(j+d,(int)vec[i].size());k++)sum+=vec[i][k];
				vec[i+1].pb(sum);
			}
			m/=d;
		}
	}
	cout<<ans<<'\n';
	return 0;
}