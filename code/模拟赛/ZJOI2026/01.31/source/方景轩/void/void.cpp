#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+5;
int T,n,m,cnt;
int ne[N],head[N],to[N],a[N];
void add(int x,int y){
	ne[++cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
}
bool check(int u,int v){
	memset(a,0,sizeof(a));
	int id=0;
	a[++id]=u;
	a[++id]=v;
	for(int j=head[u];j;j=ne[j]){
		a[++id]=to[j];
	}
	for(int j=head[v];j;j=ne[j]){
		a[++id]=to[j];
	}
	sort(a+1,a+id+1);
	int sum=0;
	for(int i=2;i<=id;i++){
		if(a[i]==a[i-1]) sum++;
	}
	if(sum%2==0&&sum!=0) return true;
	return false;
}
signed main(){
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		memset(ne,0,sizeof(ne));
		memset(head,0,sizeof(head));
		memset(to,0,sizeof(to));
		cin>>n>>m;
		if(m==0&&n>=2){
			cout<<"1 2"<<endl;
			continue;
		}
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			add(x,y),add(y,x);
		}
		bool f=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(check(i,j)){
					cout<<i<<" "<<j<<endl;
					f=true;
				}
				if(f) break;
			}
			if(f) break;
		}
	}
	return 0;
}
