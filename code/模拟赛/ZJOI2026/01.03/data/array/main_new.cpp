#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
ll Random(ll l , ll r){return rnd() % (r - l + 1) + l;}
ofstream fout;
const int N[] =  {1 , 5000  , 1 	, 2 	, 5 , 20 , 5000 , 16   , 700 , 5000 , 5000};
const int B[] =  {1 , 30000 , 30000 , 30000 , 8 , 20 , 5000 , 16   , 700 , 5000 , 30000};
const int CS[] = {0 , 1     , 2     , 4     , 6 , 9  , 12   , 15   , 19  , 21   , 23   , 26};
int p[30005] , b[5005];
void MakeData(int cs)
{
	int task = 0;
	if(cs <= 1)task = 1;
	else if(cs <= 3)task = 2;
	else if(cs <= 5)task = 3;
	else if(cs <= 8)task = 4;
	else if(cs <= 11)task = 5;
	else if(cs <= 14)task = 6;
	else if(cs <= 18)task = 7;
	else if(cs <= 20)task = 8;
	else if(cs <= 22)task = 9;
	else if(cs <= 25)task = 10;
	int n = Random(N[task] * 4 / 5 , N[task]);
	int sum = B[task];
	int t = sqrt(B[task] / 5);
	for(int i = 1 ; i <= t ; i++)
		b[i] = i , sum -= i;
	int nn = n - t;
	sum -= min(sum - nn , (int)Random(0 , (cs - CS[task]) * 2));
	if(sum & 1)sum -= 1;
	assert(nn <= sum);
	iota(p + 1 , p + sum , 1);
	shuffle(p + 1 , p + sum , rnd);
	sort(p + 1 , p + nn); p[nn] = sum;
	for(int i = 1 ; i <= nn ; i++)
		b[t + i] = p[i] - p[i - 1];
	shuffle(b + 1 , b + n + 1 , rnd);

	fout << n << "\n";
	for(int i = 1 ; i <= n ; i++)
		fout << b[i] << " \n"[i == n];
	fout << flush;
}
int main()
{
	int tp = 1;
	string name = "array";
	if(tp == 1)
	{
		for(int cs = 19 ; cs <= 20 ; cs++)
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
