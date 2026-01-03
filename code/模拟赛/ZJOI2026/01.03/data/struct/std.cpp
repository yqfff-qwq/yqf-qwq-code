#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n , m , tot , a[N];
int head[N] , nxt[N];
struct U{int p , l , r , v;}upd[N * 4];
bool operator < (const U &a , const U &b){return a.p < b.p;}
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
	fill(head , head + n + 2 , n + 1);
	for(int i = n ; i >= 1 ; i--)
	{
		nxt[i] = head[a[i]];
		head[a[i]] = i;
	}
	for(int v = 1 ; v <= n + 1 ; v++)
	{
		auto add = [&](int i , int j , int L , int R)
		{
			int mnl = i + 1 , mxl = min(j - 1 , L);
			int mnr = max(i + 1 , R) , mxr = j - 1;
			if(mnl <= mxl && mnr <= mxr)
			{
				upd[++tot] = {mnr , mnl , mxl , 1};
				upd[++tot] = {mxr + 1 , mnl , mxl , -1};
			}
		};
		if(head[v] <= n)
		{
			int L = head[v] , R = L;
			while(nxt[R] <= n)R = nxt[R];
			for(int i = 0 , j = head[v - 1] ; j ; i = j , j = nxt[j])
			{
				if(j > R)
				{
					if(i < L)add(i , j , L , R);
					break ;
				}
			}
		}
		else
		{
			for(int i = 0 , j = head[v - 1] ; j ; i = j , j = nxt[j])
				add(i , j , n + 1 , 0);
		}
	}
	sort(upd + 1 , upd + tot + 1);
	for(int i = 1 , j = 1 ; i <= m ; i++)
	{
		int l , r; cin >> l >> r;
		for(; j <= tot && upd[j].p <= r ; j++)
			bit.update(upd[j].l , upd[j].r , upd[j].v);
		cout << n + 1 - bit.ask(l) << "\n";
	}
	return 0;
}