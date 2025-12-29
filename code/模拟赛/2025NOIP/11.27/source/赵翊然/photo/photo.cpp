#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,id;
};
signed main(){
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	int n,t;
	cin>>n>>t;
	vector<node>p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].a>>p[i].b;
		p[i].id=i;
	}
	sort(p.begin(),p.end(),[](const node &x,const node &y){return x.b<y.b;});
	vector<int>s(n);
	int l=-INT_MAX/2;
	for(int i=0;i<n;i++){
		int maxx=max(p[i].a,l);
		if(maxx+t>p[i].b){
			cout<<"no\n";
			return 0;
		}
		s[p[i].id]=maxx;
		l=maxx+t;
	}
	cout<<"yes\n";
	for(int i=0;i<n;i++)
	cout<<s[i]<<" ";
}

