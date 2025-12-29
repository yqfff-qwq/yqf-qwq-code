#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int w,v;
}a[500005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int n,m,w[500005],u[500005],cnt,v[500005],ans;
priority_queue<int> q;
signed main(){
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v>>a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	w[++cnt]=a[1].w;
	for(int i=2;i<=n;i++){
		if(a[i].w!=a[i-1].w)
		w[++cnt]=a[i].w;
	}
	for(int i=cnt,mm=m;i;i--){
		u[i]=mm/w[i];
		mm%=w[i];
	}
	for(int i=1,pos=1;i<=cnt;i++){
		while(pos<=n&&a[pos].w==w[i])
		q.push(a[pos].v),pos+=1;
		for(int j=1;j<=u[i]&&q.size();j++){
			ans+=q.top();
			q.pop();
		}
		if(i==cnt) break;
		int p=0,num=w[i+1]/w[i],t=0,ct=0;
		while(!q.empty()){
			v[++p]=q.top();
			q.pop();
		}
		for(int i=1;i<=p;i++){
			t+=v[i];
			ct++;
			if(ct==num){
				q.push(t);
				ct=0;t=0;
			}
		}
		if(ct>0)
		q.push(t);
	}
	cout<<ans;
}

