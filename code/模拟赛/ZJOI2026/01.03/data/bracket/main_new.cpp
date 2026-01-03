#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
ll Random(ll l , ll r){return rnd() % (r - l + 1) + l;}
ofstream fout;
const int N[] = {0 , 4 , 20 , 24 , 28 , 32 , 40 , 40 , 40 , 70 , 100};
int p[105] , id[105] , len[105];
namespace SOL
{
	const int N = 105;
	int n , p[N] , c[N]; bool vis[N];
	int tot; vector<int>vc[N];
	bool Dfs(int x)
	{
		if(x == tot + 1)
		{
			bool ok = 1; int sum = 0;
			for(int i = 1 ; i <= n && ok ; i++)
			{
				sum += c[i];
				if(sum < 0)ok = 0;
			}
			return ok && sum == 0;
		}
		int m = vc[x].size();
		for(int i = 0 ; i < m ; i += 2)
			c[vc[x][i]] = 1 , c[vc[x][i + 1]] = -1;
		if(Dfs(x + 1))return 1;
		for(int i = 0 ; i < m ; i += 2)
			c[vc[x][i]] = -1 , c[vc[x][i + 1]] = 1;
		return Dfs(x + 1);
	}
	bool check(vector<int>a)
	{
		tot = 0 , n = a.size();
		for(int i = 0 ; i < n ; i++)
			p[i + 1] = a[i];
		memset(vis , 0 , sizeof(bool) * (n + 1));
		for(int i = 1 ; i <= n ; i++)
		{
			if(vis[i])continue ;
			tot++ , vc[tot].clear();
			for(int u = i ; !vis[u] ; u = p[u])
			{
				vis[u] = 1;
				vc[tot].push_back(u);
			}
			int sz = vc[tot].size();
			if(sz & 1)return 0;
			if(sz == 2)
			{
				int x = vc[tot][0] , y = vc[tot][1];
				if(x > y)swap(x , y);
				c[x] = 1 , c[y] = -1;
				vc[tot--].clear();
			}
		}
		return Dfs(1);
	}
}
void MakeData(int task , int tp)
{
	int n = N[task];
	if(task >= 6 && task <= 7)
	{
		n -= (tp - 1) * 2;
		if(task == 6)
		{
			for(int i = 1 ; i <= n ; i++)
				p[i] = ((i + 1) ^ 1) - 1;
		}
		if(task == 7)
		{
			for(int i = 1 ; i <= n ; i++)
			{
				if(i <= n / 2)p[i] = i + n / 2;
				else p[i] = (i % (n / 2)) + 1;
			}
		}
	}
	else
	{
		iota(id + 1 , id + n + 1 , 1);
		while(1)
		{
			int tot = max(1ll , n / (tp + 1) - Random(0 , tp));
			memset(len , 0 , sizeof len);
			memset(id , 0 , sizeof id);
			memset(p , 0 , sizeof p);
			iota(id + 1 , id + n + 1 , 1);
			set<int>st = {0 , n / 2};
			// cerr << n << ":" << tot << "; ";
			while((int)st.size() <= tot)
				st.insert(Random(1 , n / 2));
			// cerr << st.size() << ":";
			int i = 0 , lst = -1;
			for(int x : st)
			{
				if(lst >= 0)len[++i] = (x - lst) * 2;
				lst = x;
			}
			shuffle(id + 1 , id + n + 1 , rnd);
			for(int i = 1 , l = 1 ; i <= tot ; i++)
			{
				int r = l + len[i] - 1;
				if(Random(0 , tot / 2))sort(id + l , id + r + 1);
				for(int j = l ; j < r ; j++)
					p[id[j]] = id[j + 1];
				p[id[r]] = id[l];
				l += len[i];
			}
			// for(int i = 1 ; i <= n ; i++)
			// 	cerr << p[i] << " \n"[i == n];
			if(SOL::check(vector<int>(p + 1 , p + n + 1)))
				break ;
		}
	}
	fout << n << "\n";
	for(int i = 1 ; i <= n ; i++)
		fout << p[i] << " \n"[i == n];
	fout << flush;
}
int main()
{
	int tp = 1;
	string name = "bracket";
	if(tp == 1)
	{
		for(int task = 9 ; task <= 9 ; task++)
		{
			for(int cs = 1 ; cs <= 5 ; cs++)
			{
				string str = name + to_string(task) + "-" + to_string(cs);
				fout.open((str + ".in").c_str());
				MakeData(task , cs);
				fout.close();
				string op = "cat ./" + (str + ".in") + " | ./std > ./" + (str + ".out");
				printf("%s\n" , op.c_str());
				system(op.c_str());
			}
		}		
	}
	else
	{
		system("./DP");
	}
	return 0;
}
