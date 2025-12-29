#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5+5;
struct cyc {
	ll v, m;
	bool operator <(const cyc b)const{
		if(m!=b.m)return m<b.m;
		return v>b.v;
	}
} c[N];
vector<ll> v[45];
ll m[45];
ll cnt;
signed main() {
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, M,ansv=0;
	cin >> n >> M;
	for (ll i = 1; i <= n; i++) {
		cin >> c[i].v >> c[i].m;
	}
	sort(c+1,c+1+n);
	for (ll i = 1; i <= n; i++) {
		if (c[i].m > M) {
			n = i - 1;
			break;
		}
		if (c[i].m != c[i - 1].m)m[++cnt]=c[i].m;
		v[cnt].push_back(c[i].v);
	}
	M-=M%m[1];
	ll len=v[1].size();
	while(len*m[1]<M){
		v[1].push_back(0);
		len++;
	}
	for(ll i=1;i<cnt;i++){
		ll j=0;
		while(M%m[i+1]!=0){
			M-=m[i];
			ansv+=v[i][j];
			j++;
		}
		len=v[i].size()-1;
		ll summ=0,sumv=0;
		for(;j<=len;j++){
			summ+=m[i],sumv+=v[i][j];
			if(summ==m[i+1]){
				v[i+1].push_back(sumv);
				summ=sumv=0;
			}
		}
		sort(v[i+1].begin(),v[i+1].end(),greater<ll>());
	}
	for(ll i=0;i<M/m[cnt];i++){
		ansv+=v[cnt][i];
	}
	cout<<ansv;
	return 0;
}
/*
6 10
1 1
5 2
200 6
9 2
6 2
100 1
*/
