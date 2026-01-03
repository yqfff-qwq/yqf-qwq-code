#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int , int> pr;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
ll Random(ll l , ll r){return rnd() % (r - l + 1) + l;}
ofstream fout;
const int MXN = 1e6;
const int N[] =  {1 , 5000  , 5000 	, 50000 , 200000 , MXN , MXN , MXN};
const int CS[] = {0 , 1     , 3     , 6     , 8		 , 10  , 14  , 17  , 21};
int a[MXN + 5] , p[MXN + 5]; 
struct Q{int l , r;}qu[MXN + 5];
bool operator < (const Q &a , const Q &b)
{
	if(a.r == b.r)return a.l > b.l;
	else return a.r < b.r;
}
void MakeData(int cs)
{
	int task = 0;
	if(cs <= 2)task = 1;
	else if(cs <= 5)task = 2;
	else if(cs <= 7)task = 3;
	else if(cs <= 9)task = 4;
	else if(cs <= 13)task = 5;
	else if(cs <= 16)task = 6;
	else if(cs <= 20)task = 7;

	int n = N[task] - (cs - CS[task]);
	int m = N[task] - (CS[task + 1] - cs);
	if(task == 2)m += 995000;

	for(int i = 1 ; i <= n ; i++)
	{
		a[i] = Random(1 , n);
		if(task == 5 && ~a[i] & 1)
			a[i]--;
	}
	if(task == 6)
	{
		sort(a + 1 , a + n + 1);
		iota(p + 1 , p + n + 1 , 1);
		shuffle(p + 1 , p + n + 1 , rnd);
		for(int i = 1 ; i <= n ; i++)
			a[i] = p[a[i]];
	}

	for(int i = 1 ; i <= m ; i++)
	{
		int l = Random(1 , n) , r = Random(1 , n);
		if(l > r)swap(l , r);
		qu[i] = {l , r};
	}
	sort(qu + 1 , qu + m + 1);

	fout << n << ' ' << m << "\n";
	for(int i = 1 ; i <= n ; i++)
		fout << a[i] << " \n"[i == n];
	for(int i = 1 ; i <= m ; i++)
		fout << qu[i].l << ' ' << qu[i].r << "\n";
	fout << flush;
}
int main()
{
	int tp = 1;
	string name = "struct";
	if(tp == 1)
	{
		for(int cs = 1 ; cs <= 20 ; cs++)
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
