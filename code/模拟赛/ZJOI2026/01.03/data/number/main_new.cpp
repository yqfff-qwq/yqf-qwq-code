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
namespace PN
{
	const int N = 1e9 + 50 , T = 1e7 + 50 , M = 5.1e7 + 50;
	ll n , t , tot , pn[T];
	int m , mm , pr[M]; bitset<N>b;
	void Dfs(int x , ll v)
	{
		if(x == mm)return ;
		ll p = pr[x]; i128 pk = p * p;
		if((i128)v * pk <= n)Dfs(x + 1 , v);
		for(int i = 2 ; (i128)v * pk <= n ; i++ , pk *= p)
		{
			tot++ , pn[tot] = v * pk;
			Dfs(x + 1 , v * pk);
		}
	}
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
	bool Check(ll a)
	{
		for(int i = 1 ; (ll)pr[i] * pr[i] * pr[i] * pr[i] * pr[i] <= a ; i++)
		if(a % pr[i] == 0)
		{
			int c = 0;
			while(a % pr[i] == 0)a /= pr[i] , c++;
			if(c == 1)return 0;
		}
		ll t = sqrtl(a) , c = cbrtl(a);
		return t * t == a || c * c * c == a;
	}
	ll RandomPN(ll mx)
	{
		ll v = 1;
		while(v * 4 <= mx)
		{
			if(!Random(0 , 15))break ;
			int tp = Random(0 , 1);
			ll sq = sqrtl(mx / v) , cb = cbrtl(mx / v);
			int mn = tp ? upper_bound(pr + 1 , pr + m + 1 , sq) - pr - 1
					   : upper_bound(pr + 1 , pr + m + 1 , cb) - pr - 1;
			if(!mn)tp = 1 , mn = 1;
			ll x = P[18] / Random(1 , P[18]);
			ll p = pr[min(mn , int(lower_bound(pr + 1 , pr + m + 1 , x) - pr))];
			if(mn <= 2000)p = pr[Random(1 , mn)];
			// cerr << v << ":" << mn << ' ' << x << " " << p << "\n";
			if(tp)v *= p * p;
			else v *= p * p * p;
		}
		return v;
	}
	void Init()
	{
		Sieve(); 
		n = 1e13L; t = sqrt(n);
		for(mm = 1 ; pr[mm] <= t ; mm++);
		pn[1] = tot = 1; Dfs(1 , 1);
		sort(pn + 1 , pn + tot + 1);
	}	
}
using PN::tot;
using PN::pn;

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

void MakeData(int cs)
{
	int task = 0;
	if(cs <= 2)task = 1;
	else if(cs <= 4)task = 2;
	else if(cs <= 7)task = 3;
	else if(cs <= 9)task = 4;
	else if(cs <= 11)task = 5;
	else if(cs <= 14)task = 6;
	else if(cs <= 16)task = 7;
	else if(cs <= 19)task = 8;
	else if(cs <= 20)task = 9;

	int n = N[task] , m = 0; 
	ll mx = V[task];
	while(m < tot && pn[m + 1] <= mx)m++;

	int num = n / 2;
	if(mx > P[13])
	{
		for(int i = 1 ; i <= num ; i++)
			a[i] = PN::RandomPN(mx);
	}
	else
	{
		for(int i = 1 ; i <= num ; i++)
			a[i] = pn[Random(1 , m)];
	}
	for(int i = num + 1 ; i <= num + n / 3 ; i++)
	{
		ll v = Random(1 , mx);
		while(!MR::MillerRabbin(v))
			v = Random(1 , mx);
		a[i] = v;
	}
	num += n / 3;
	for(int i = num + 1 ; i <= n ; i++)
		a[i] = Random(1 , mx);

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
		PN::Init();
		for(int cs = 17 ; cs <= 17 ; cs++)
		{
			string str = name + to_string(cs);
			fout.open((str + ".in").c_str());
			MakeData(cs);
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
