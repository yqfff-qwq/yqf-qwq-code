#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,head[1000001],cnt,x,ptt,tot,vis[1000001];
vector<int> v[100001];
char an[1000001];
struct dcz{
	int to,nex;
}a[1000001];
void add(int x,int y){
	a[++cnt].nex=head[x];
	a[cnt].to=y;
	head[x]=cnt;
}
void dfs(int u){
	vis[u]=1;
	v[tot].push_back(u);
	for(int i=head[u];i;i=a[i].nex){
		int v=a[i].to;
		if(!vis[v]) dfs(v);
	}
}
void get(int wh){
	if(wh>tot){
		bool f=1;
		int val=0;
		for(int i=1;i<=n;i++){
			if(an[i]=='(') val++;
			else if(val==0){f=1;break;}
			else val--;
		}
		if(f&&!val){
			for(int i=1;i<=n;i++){
				cout<<an[i];
			}
			exit(0);
		}
		return;
	}
	if(v[wh].size()==2){
		an[min(v[wh][0],v[wh][1])]='(';
		an[max(v[wh][0],v[wh][1])]=')';
		get(wh+1);
	}
	else{
		for(int i=0;i<v[wh].size();i++){
			an[v[wh][i]]=((i&1)?')':'(');	
		}
		get(wh+1);
		for(int i=0;i<v[wh].size();i++){
			an[v[wh][i]]=((i&1)?'(':')');	
		}
		get(wh+1);
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		add(i,x),add(x,i);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) tot++,dfs(i);
	}
	get(1);
	return 0;
}