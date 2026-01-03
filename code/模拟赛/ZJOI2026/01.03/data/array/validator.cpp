#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ifstream fin;
int n , b[5005];
void Check(int task)
{
	int sum = 0; 
	n = 0 , fin >> n;
	memset(b , 0 , sizeof(int) * (n + 1));
	for(int i = 1 ; i <= n ; i++)
		fin >> b[i];
	for(int i = 1 ; i <= n ; i++)
		sum += b[i];
	for(int i = 1 ; i <= n ; i++)
		assert(1 <= b[i] && b[i] <= 30000);
	assert(1 <= n && n <= 5000);
	assert(1 <= sum && sum <= 30000);
	if(task == 1)assert(sum & 1);
	if(task == 2)assert(n == 1);
	if(task == 3)assert(n == 2);
	if(task == 4)assert(n <= 5) , assert(sum <= 8);
	if(task == 5)assert(n <= 20) , assert(sum == n);
	if(task == 6)assert(sum == n);
	if(task == 7)assert(n <= 16) , assert(sum <= 16);
	if(task == 8)assert(n <= 700) , assert(sum <= 700);
	if(task == 9)assert(sum <= 5000);
}
int main()
{
	string name = "array";
	for(int cs = 1 ; cs <= 25 ; cs++)
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
		cerr << "Case #" << cs << " " << task << "\n";
		string str = name + to_string(cs);
		fin.open((str + ".in").c_str());
		Check(task);
		fin.close();
	}
	return 0;
}
