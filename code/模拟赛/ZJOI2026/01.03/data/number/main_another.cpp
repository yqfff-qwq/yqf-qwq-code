#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef __int128 i128;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
ll Random(ll l , ll r){return rnd() % (r - l + 1) + l;}
ofstream fout;
const ll P[] =  {1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000 , (int)1e7 , (int)1e8 , (int)1e9 
					, (ll)1e10 , (ll)1e11 , (ll)1e12 , (ll)1e13 , (ll)1e14 , (ll)1e15 , (ll)1e16 , (ll)1e17 , (ll)1e18};
const ll N[] =  {1 , 5 	, 10 	, 1000 	, P[5] , P[5] , 1000 , 500 		, 4 * P[5] 	, 4 * P[5]};
const ll V[] =  {1 , 5 	, 1000 	, P[4] 	, P[6] , P[7] , P[9] , P[16]   	, P[13] , P[18]};
const ll CS[] = {0 , 1  , 3     , 5     , 8    , 10   , 12   , 15   	, 17  	, 20   , 21};

ll a[1000005];
namespace PR
{
	const int N = 1e9 + 50 , M = 5.1e7 + 50;
	int m , pr[M]; bitset<N>b;
	void Sieve(const int n = N - 5)
	{
		for(int i = 2 ; i <= n ; i++)
		{
			if(!b[i])pr[++m] = i;
			for(int j = 1 ; j <= m && (ll)pr[j] * i <= n ; j++)
			{
				int x = pr[j] * i;
				b[x] = 1;
				if(i % pr[j] == 0)
					break ;
			}
		}
	}
}
namespace MR
{
	int pr[15] = {0 , 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37};
	ll Qpow(ll x , ll p , ll mod)
	{
		ll res = 1;
		for(; p > 0 ; x = (__int128)x * x % mod , p >>= 1)
			if(p & 1)res = (__int128)res * x % mod;
		return res;
	}
	bool MillerRabbin(ll n)
	{
		if(n < 3 || n % 2 == 0)return n == 2;
		ll u = n - 1 , t = 0;
		while(~u & 1)u >>= 1 , t++;
		for(int i = 1 ; i <= 12 ; i++)
		{
			ll v = Qpow(pr[i] , u , n);
			if(v == 1 || v == n - 1 || v == 0)continue;
			for(int j = 1 ; j <= t ; j++)
			{
				v = (__int128)v * v % n;
				if(v == n - 1 && j != t){v = 1; break;}
				if(v == 1)return 0;
			}
			if(v != 1)return 0;
		}
		return 1;
	}
}

void MakeData(int task)
{
	int n = N[task] , n2 = sqrtl(n * 2) + 30 , n3 = cbrtl(n * 6) + 30 , n5 = powl(n * 120 , 0.2L) + 30; 
	ll mx = V[task] , t2 = sqrtl(mx) , t3 = cbrtl(mx) , t5 = powl(mx , 0.2L);
	vector<int>p2 , p3 , p5;

	for(int i = PR::m ; i >= 1 ; i--)
	{
		int v = PR::pr[i];
		if((int)p2.size() < n2 && v <= t2)p2.push_back(v);
		if((int)p3.size() < n3 && v <= t3)p3.push_back(v);
		if((int)p5.size() < n5 && v <= t5)p5.push_back(v);
	}
	// cerr << n2 << ' ' << n3 << ' ' << n5 << "\n";
	// cerr << p2.size() << ' ' << p3.size() << ' ' << p5.size() << "\n";
	// n2 = p2.size() , n3 = p3.size() , n5 = p5.size();
	// cerr << "p2:"; for(int x : p2)cerr << x << ",";
	// cerr << "\np3:"; for(int x : p3)cerr << x << ",";
	// cerr << "\np5:"; for(int x : p5)cerr << x << ",";
	// cerr << "\n";
	int num = n / 3 , m = 0;
	for(int i = 0 ; i < n2 && m < num ; i++)
		for(int j = i ; j < n2 && m < num ; j++)
			a[++m] = (ll)p2[i] * p2[j];
	for(int i = 0 ; i < n3 && m < num * 2 ; i++)
		for(int j = i ; j < n3 && m < num * 2 ; j++)
			for(int k = j ; k < n3 && m < num * 2 ; k++)
				a[++m] = (ll)p3[i] * p3[j] * p3[k];
	for(int i = 0 ; i < n5 && m < n ; i++)
		for(int j = i ; j < n5 && m < n ; j++)
			for(int k = j ; k < n5 && m < n ; k++)
				for(int x = j ; x < n5 && m < n ; x++)
					for(int y = j ; y < n5 && m < n ; y++)
						a[++m] = (ll)p5[i] * p5[j] * p5[k] * p5[x] * p5[y];
	shuffle(a + 1 , a + n + 1 , rnd);
	fout << n << "\n";
	for(int i = 1 ; i <= n ; i++)
		fout << a[i] << "\n";
	fout << flush;
}
int main()
{
	int tp = 1;
	string name = "number";
	if(tp == 1)
	{
		PR::Sieve();
		for(int task = 8 ; task <= 9 ;task++)
		{
			string str = name + (task == 8 ? "8-5" : "9-3");
			fout.open((str + ".in").c_str());
			MakeData(task);
			fout.close();
			string op = "cat ./" + (str + ".in") + " | ./std > ./" + (str + ".out");
			printf("%s\n" , op.c_str());
			system(op.c_str());
		}		
	}
	else
	{
		system("./DP");
	}
	return 0;
}
