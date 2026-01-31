#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T;
int n,m;
struct Node {
	int u;
	int siz;
	vector<int> E;
};
bool cmp(Node &a,Node &b) {
	return a.siz<b.siz;
}
Node V[2000010];
bool check(int x,int y) {
	int i=0,j=0;
	int cnt=0;
	while(i<V[x].siz&&j<V[y].siz) {
		if(V[x].E[i]==V[y].E[j]) {
			i++;
			j++;
			cnt++;
		}
		while(i<V[x].siz&&j<V[y].siz&&V[x].E[i]<V[y].E[j])
			i++;
		while(i<V[x].siz&&j<V[y].siz&&V[x].E[i]>V[y].E[j])
			j++;
	}
	return !(cnt&1);
}
bool flag;
int main() {
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			V[i].u=i;
			V[i].E.clear();
			V[i].E.push_back(i);
		}
		for(int i=1,u,v; i<=m; i++) {
			cin>>u>>v;
			V[u].E.push_back(v);
			V[v].E.push_back(u);
		}
		for(int i=1; i<=n; i++) {
			V[i].siz=V[i].E.size();
			sort(V[i].E.begin(),V[i].E.end());
		}
		sort(V+1,V+n+1,cmp);
		flag=0;
		for(int i=1; i<=n&&!flag; i++)
			for(int j=i+1; j<=n&&!flag; j++)
				if(check(i,j)) {
					cout<<V[i].u<<' '<<V[j].u<<'\n';
					flag=1;
				}
	}
	return 0;
}
