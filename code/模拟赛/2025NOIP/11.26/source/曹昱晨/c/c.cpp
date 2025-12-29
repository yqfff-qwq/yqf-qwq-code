#include<bits/stdc++.h>
using namespace std;
const long long N=305;
long long n,k;
struct cyc{
	long long h,c;
	bool operator <(const cyc y)const{
		return h<y.h;
	}
}a[N];
bool used[N];
long long ans,minc[N];
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)cin>>a[i].h>>a[i].c;
	sort(a+1,a+1+n);
	minc[0]=998244353;
	for(long long i=1;i<=n;i++)minc[i]=min(minc[i-1],a[i].c);
	for(long long i=2;i<=n;i++){
		for(long long j=i-1;j>=1;j--){
			if(!used[j]){
				used[j]=1;
				break;
			}
			if(j==1){
				ans+=minc[i-1];
			}
		}
	}
	cout<<ans;
	return 0;
}
