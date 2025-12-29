#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=1050;
int p[maxn];
int pos[maxn];
vector<vector<int> >opt;
void Add(vector<int> &g)
{
	opt.pb(g);
	g.clear();
}
void Print(vector<int> g)
{
	cout<<g.size()<<" ";
	for(auto it:g) cout<<it<<" ";
	cout<<"\n"; 
}
int To[maxn];
bool ok[maxn];
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	Ios();
	int n;
	cin>>n;
	REP(i,1,n) cin>>p[i],pos[p[i]]=i;
	//make x in small
	REP(i,1,n)
	{
		int u=pos[i];
		To[u]=i;
	}
	REP(i,1,n)
	if(!ok[i])
	{
		vector<int> v;
		int u=i;
		while(1)
		{
			v.pb(u);
			ok[u]=1;
			u=To[u];
			if(u==i) break;
		}
		if(v.size()>1) Add(v);
	}
	cout<<opt.size()<<"\n";
	for(auto it:opt) Print(it);
}
//证明：大概就是pos 和 i 是一一对应的，每个点都是入度出度为1的，所以最终的图是一堆环，所以把所有环输出就行了。 
//2 3 1 5 4
//1 2 3 4 5
//可以直接理解成把选中的下标整体向后循环平移一次。
/*
judge sort1.in sort1.out sort1.ans
judge sort2.in sort2.out sort2.ans
judge sort3.in sort3.out sort3.ans
judge sort4.in sort4.out sort4.ans
judge sort5.in sort5.out sort5.ans
*/
