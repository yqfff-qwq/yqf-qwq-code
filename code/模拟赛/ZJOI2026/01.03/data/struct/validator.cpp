#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ifstream fin;
const int MXN = 1e6;
int a[MXN + 5] , mn[MXN + 5] , mx[MXN + 5]; 
struct Q{int l , r;}qu[MXN + 5];
void Check(int task)
{
	int n = 0 , m = 0; 
	fin >> n >> m;
	assert(1 <= n && n <= MXN);
	assert(1 <= m && m <= MXN);
	memset(a , 0 , sizeof(int) * (n + 1));
	for(int i = 1 ; i <= m ; i++)qu[i].l = qu[i].r = 0;
	for(int i = 1 ; i <= n ; i++)
		fin >> a[i];
	for(int i = 1 ; i <= n ; i++)
		assert(1 <= a[i] && a[i] <= n);
	for(int i = 1 ; i <= m ; i++)
		fin >> qu[i].l >> qu[i].r;
	for(int i = 1 ; i <= m ; i++)
	{
		assert(1 <= qu[i].l && qu[i].l <= qu[i].r && qu[i].r <= n);
		if(i < m)
		{
			// assert(qu[i].r < qu[i + 1].r || (qu[i].r == qu[i + 1].r && qu[i].l >= qu[i + 1].l));
			assert(qu[i].r <= qu[i + 1].r);
		}
	}
	if(task == 5)
	{
		for(int i = 1 ; i <= n ; i++)
			assert(a[i] & 1);
	}
	if(task == 6)
	{
		for(int i = 1 ; i <= n ; i++)
			mx[i] = 0 , mn[i] = n + 1;
		for(int i = 1 ; i <= n ; i++)
		{
			mn[a[i]] = min(mn[a[i]] , i);
			mx[a[i]] = max(mx[a[i]] , i);
		}
		int sum = 0;
		for(int i = 1 ; i <= n ; i++)
			if(mn[i] <= mx[i])sum += mx[i] - mn[i] + 1;
		// assert(sum == n);
		for(int i = 1 ; i <= n ; i++)
			if(mn[i] <= mx[i])for(int j = mn[i] ; j <= mx[i] ; j++)
				if(a[j] != i)cerr << "a[" << j << "] != " << i << "\n" , assert(0);
	}
	if(task == 1)assert(max(n , m) <= 5000);
	if(task == 2)assert(n <= 5000);
	if(task == 3)assert(max(n , m) <= 50000);
	if(task == 4)assert(max(n , m) <= 200000);
}
int main()
{
	string name = "struct";		
	for(int cs = 1 ; cs <= 20 ; cs++)
	{
		int task = 0;
		if(cs <= 2)task = 1;
		else if(cs <= 5)task = 2;
		else if(cs <= 7)task = 3;
		else if(cs <= 9)task = 4;
		else if(cs <= 13)task = 5;
		else if(cs <= 16)task = 6;
		else if(cs <= 20)task = 7;
		cerr << "Case #" << cs << " " << task << "\n";
		string str = name + to_string(cs);
		fin.open((str + ".in").c_str());
		Check(task);
		fin.close();
	}
	return 0;
}
