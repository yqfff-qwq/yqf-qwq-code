#include "bits/stdc++.h"
#include <unistd.h>
using namespace std;
typedef long long ll;
ifstream fin;
const ll N = 4e5 + 5 , INF = 1e18L;
ll n , a[N];
void Check(int task)
{
	n = 0;
	fin >> n;
	memset(a , 0 , sizeof(ll) * (n + 1));
	assert(1 <= n && n <= N - 5);
	for(int i = 1 ; i <= n ; i++)
		fin >> a[i];
	for(int i = 1 ; i <= n ; i++)
		assert(1 <= a[i] && a[i] <= INF);
	ll mx = *max_element(a + 1 , a + n + 1);
	if(task == 1)assert(max(n , mx) <= 5);
	if(task == 2)assert(n <= 10 && mx <= 1000);
	if(task == 3)assert(n <= 1000 && mx <= 10000);
	if(task == 4)assert(n <= (int)1e5 && mx <= (int)1e6);
	if(task == 5)assert(n <= (int)1e5 && mx <= (int)1e7);
	if(task == 6)assert(n <= 1000 && mx <= (int)1e9);
	if(task == 7)assert(n <= 500 && mx <= (ll)1e16L);
	if(task == 8)assert(n <= (int)4e5 && mx <= (ll)1e13L);
	if(task == 9)assert(n <= (int)4e5 && mx <= (ll)1e18L);
}
int main()
{
	string name = "number";		
	for(int task = 1 ; task <= 9 ; task++)
	{
		for(int cs = 1 ; ; cs++)
		{
			string str = name + to_string(task) + "-" + to_string(cs);
			if(access((str + ".in").c_str(), F_OK ) == -1)break ;
			cerr << "Task #" << task << " case " << cs << "\n";
			fin.open((str + ".in").c_str());
			Check(task);
			fin.close();
		}
	}	
	return 0;
}
