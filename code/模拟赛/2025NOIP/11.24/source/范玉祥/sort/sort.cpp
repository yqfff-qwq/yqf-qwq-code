#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=1e3+5;
int n,p[N],cnt;
bool vis[N];
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=rd();
	vector<vi>ans;
	for(int i=1;i<=n;i++)p[i]=rd();
	for(int i=1;i<=n;i++)if(!vis[i]){
		++cnt;
		vi vec;
		for(int j=i;!vis[j];j=p[j])vis[j]=1,vec.pb(j);
		ans.pb(vec);
	}
	cout<<cnt<<'\n';
	for(auto vec:ans){
		cout<<vec.size()<<" ";
		for(auto i:vec)cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
}