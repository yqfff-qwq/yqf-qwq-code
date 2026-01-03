#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ifstream fin;
int n , p[105]; bool vis[105];
void Check(int task)
{
	n = 0; fin >> n;
	assert(1 <= n && n <= 100 && n % 2 == 0);
	memset(p , 0 , sizeof(int) * (n + 1));
	for(int i = 1 ; i <= n ; i++)
		fin >> p[i];
	for(int i = 1 ; i <= n ; i++)
		assert(p[i] >= 1 && p[i] <= n && p[i] != i);
	for(int i = 1 ; i <= n ; i++)
		vis[i] = 0;
	for(int i = 1 ; i <= n ; i++)
		vis[p[i]] = 1;
	assert(count(vis + 1 , vis + n + 1 , 1) == n);

	if(task == 1)assert(n <= 4);
	if(task == 2)assert(n <= 20);
	if(task == 3)assert(n <= 24);
	if(task == 4)assert(n <= 28);
	if(task == 5)assert(n <= 32);
	if(task == 6)
	{
		assert(n <= 40);
		for(int i = 1 ; i <= n ; i++)
			assert(p[i] == ((i + 1) ^ 1) - 1);
	}
	if(task == 7)
	{
		assert(n <= 40);
		for(int i = 1 ; i <= n ; i++)
		{
			if(i <= n / 2)assert(p[i] == i + n / 2);
			else assert(p[i] == (i % (n / 2)) + 1);
		}
	}
	if(task == 8)assert(n <= 40);
	if(task == 9)assert(n <= 70);
}
int main()
{
	string name = "bracket";		
	for(int task = 1 ; task <= 10 ; task++)
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
