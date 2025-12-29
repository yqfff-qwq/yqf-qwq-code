#include<bits/stdc++.h>
using namespace std;
int n,p[1005];
vector<vector<int> >opt;
bool vis[1005];
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>p[i];
	for(int i=1;i<=n;i++){
		if(!vis[i]&&p[i]!=i){
			vector<int>c;
			int cnt=i;
			while(!vis[cnt]){
				vis[cnt]=1;
				c.push_back(cnt);
				cnt=p[cnt];
			}
			if(c.size()>1)
			opt.push_back(c);
		}
	}
	cout<<opt.size()<<"\n";
	for(const auto &i:opt){
		cout<<i.size();
		for(int j:i)
		cout<<" "<<j;
		cout<<"\n";
	}
}
