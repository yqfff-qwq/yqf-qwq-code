#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int>a(n);
		for(int i=0;i<n;i++)
		cin>>a[i];
		set<vector<int> >s;
		queue<vector<int> >q;
		q.push(a);
		s.insert(a);
		while(!q.empty()){
			vector<int>c=q.front();
			q.pop();
			int l=c.size();
			if(l==1)continue;
			for(int i=0;i<l-1;i++){
				for(int x=0;x<k;x++){
					for(int y=0;y<k;y++){
						int z=(x*c[i]+y*c[i+1])%k;
						vector<int>nxt;
						for(int j=0;j<i;j++)
						nxt.push_back(c[j]);
						nxt.push_back(z);
						for(int j=i+2;j<l;j++)
						nxt.push_back(c[j]);
						if(s.find(nxt)==s.end())
						s.insert(nxt),q.push(nxt);
					}
				}
			}
		}
		cout<<s.size()%mod<<"\n";
	}
}

