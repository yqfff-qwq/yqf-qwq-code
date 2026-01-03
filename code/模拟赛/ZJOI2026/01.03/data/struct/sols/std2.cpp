#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n , m , a[N] , ans[N];
vector<int>vc[N];
vector<pair<int , int> >qu[N];
struct U{int l , r , v;};
vector<U>upd[N];
struct BIT
{
	int c[N];
	void add(int x , int v)
	{
		for(int i = x ; i <= n ; i += i & -i)
			c[i] += v;
	}
	int ask(int x)
	{
		int sum = 0;
		for(int i = x ; i ; i -= i & -i)
			sum += c[i];
		return sum;
	}
	void update(int l , int r , int v)
	{
		if(l > r)return ;
		add(l , v) , add(r + 1 , -v);
	}
}bit;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 0 ; i <= n + 1 ; i++)
		vc[i].push_back(0);
	for(int i = 1 ; i <= n ; i++)
		vc[a[i]].push_back(i);
	for(int i = 0 ; i <= n + 1 ; i++)
		vc[i].push_back(n + 1);
	int cnt = 0;
	for(int v = 1 ; v <= n + 1 ; v++)
	{
		cnt++;
		int L = vc[v][1] , R = vc[v][vc[v].size() - 2];
		for(int k = 0 ; k + 1 < (int)vc[v - 1].size() ; k++)
		{
			int i = vc[v - 1][k] , j = vc[v - 1][k + 1];
			int mnl = i + 1 , mxl = min(j - 1 , L);
			int mnr = max(i + 1 , R) , mxr = j - 1;
			if(mnl <= mxl && mnr <= mxr)
			{
				// cerr << "v = " << v << ": l in [" << mnl << ',' << mxl << "] && r in [" << mnr << ',' << mxr << "]\n";
				upd[mnr].push_back({mnl , mxl , 1});
				upd[mxr + 1].push_back({mnl , mxl , -1});
			}
		}
	}
	for(int i = 1 ; i <= m ; i++)
	{
		int l , r; cin >> l >> r;
		qu[r].push_back({l , i});
	}
	for(int r = 1 ; r <= n ; r++)
	{
		for(auto [x , y , w] : upd[r])
			bit.update(x , y , w);
		for(auto [l , id] : qu[r])
			ans[id] = bit.ask(l);
	}
	for(int i = 1 ; i <= m ; i++)
		cout << cnt - ans[i] << "\n";
	return 0;
}

