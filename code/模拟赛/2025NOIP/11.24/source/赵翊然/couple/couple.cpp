#include<bits/stdc++.h>
using namespace std;
#define int long long
int cost(const vector<pair<int,int> >& p){
	if(p.empty())return 0;
	int minn=p[0].first,maxx=p[0].first,ans=0,anss=0;
	map<int,int>mp;
	for(auto& i:p){
		minn=min(minn,i.first);
		maxx=max(maxx,i.first);
		mp[i.first]=max(mp[i.first],i.second);
	}
	for(auto&i:mp)
	ans+=2*i.second;
	if(minn>=0)anss=maxx;
	else if(maxx<=0)anss=-minn;
	else anss=min(2*(-minn)+maxx,2*maxx+(-minn));
	return ans+anss;
}
int n;
signed main(){
	freopen("couple.in","r",stdin);
	freopen("couple.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<pair<int,int> >p(n);
		for(int i=0;i<n;i++)
		cin>>p[i].first>>p[i].second;
		if(n==1){
			cout<<cost(p)<<"\n";
			continue;
		}
		sort(p.begin(),p.end());
		int a=1e8;
		for(int i=1;i<n;i++){
			if(p[i-1].first==p[i].first)continue;
			vector<pair<int,int> >l(p.begin(),p.begin()+i),r(p.begin()+i,p.end());
			int cl=cost(l),cr=cost(r);
			a=min(a,max(cl,cr));
		}
		a=min(a,cost(p));
		cout<<a<<"\n";
	}
}
