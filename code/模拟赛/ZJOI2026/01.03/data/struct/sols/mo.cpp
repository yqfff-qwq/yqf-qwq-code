#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n , m , a[N] , cnt[N] , ans[N];
int sz , t , L[N] , R[N] , id[N];
struct Q{int l , r , id;}qu[N];
bool operator < (const Q &a , const Q &b)
{
	if(id[a.l] == id[b.l])return id[a.l] & 1 ? a.r < b.r : a.r > b.r;
	return a.l < b.l;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 1 ; i <= m ; i++)
	{
		int l , r; cin >> l >> r;
		qu[i] = {l , r , i};
	}
	sz = max(1.0 , n / sqrt(m)) , t = (n + sz - 1) / sz;
	for(int i = 1 ; i <= t ; i++)
	{
		L[i] = R[i - 1] + 1;
		R[i] = min(i * sz , n);
		fill(id + L[i] , id + R[i] + 1 , i);
	}
	sort(qu + 1 , qu + m + 1);
	int res = 0 , l = 1 , r = 1;
	for(int i = 1 ; i <= n ; i++)
		if(!cnt[a[i] + (i == 1)]++)res++;
	auto add = [&](int i)
	{
		if(!--cnt[a[i]])res--;
		if(!cnt[a[i] + 1]++)res++;
	};
	auto del = [&](int i)
	{
		if(!--cnt[a[i] + 1])res--;
		if(!cnt[a[i]]++)res++;
	};
	for(int i = 1 ; i <= m ; i++)
	{
		auto [ql , qr , id] = qu[i];
		while(l > ql)add(--l);
		while(r < qr)add(++r);
		while(l < ql)del(l++);
		while(r > qr)del(r--);
		ans[id] = res;
	}
	for(int i = 1 ; i <= m ; i++)
		cout << ans[i] << "\n";
	return 0;
}

