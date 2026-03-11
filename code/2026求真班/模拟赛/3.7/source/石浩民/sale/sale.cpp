#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
#define int long long
int n;
int a[510];
//vector<bool>num[510];
//int sum[510];
//bool vis[510];
//void solve(int tttt){
//	int ans=0;
//	vector<int>gumi;
//	for(int i=1;i<=n;i++){
//		if(num[i][tttt]){
//			gumi.push_back(i);
//			vis[i]=1;
//		}
//	}
//	int k=gumi.size();
//	cout<<"k: "<<k<<endl;
//	int mans=0;
//	ans+=(1ll<<tttt);
//	mans=ans;
//	cout<<"ans: "<<ans<<endl;
//	int tmp=ans;
//	for(int t=tttt-1;t>=0;t--){
//		int teto=0;
//		for(int p=0;p<gumi.size();p++){
//			int i=gumi[p];
//			if(num[i][t]){
//				teto++;
//			}
//		}
////		if(teto>=max(1ll,k-2)) tmp+=(1ll<<t);
//		sum[t]=teto;
//	}
//	cout<<"tmp: "<<tmp<<endl;
//	mans=max(mans,tmp);
//	for(int x=1;x<=n;x++){
//		for(int y=1;y<=n;y++){
//			int miku=ans;
//			if(x==y) continue;
//			if(vis[x] && vis[y]) continue;
//			if(vis[x]){
//				for(int t=63;t>=0;t--){
//					int s=sum[t];
//					if(num[y][t]){
//						s++;
//					}
//					if(s>=max(1ll,k-1)) miku+=(1ll<<t);
//				}
//				mans=max(mans,miku);
//			}else if(vis[y]){
//				for(int t=63;t>=0;t--){
//					int s=sum[t];
//					if(num[x][t]){
//						s++;
//					}
//					if(s>=max(1ll,k-1)) miku+=(1ll<<t);
//				}
//				mans=max(mans,miku);
//			}else{
//				for(int t=63;t>=0;t--){
//					int s=sum[t];
//					if(num[y][t]){
//						s++;
//					}
//					if(num[x][t]){
//						s++;
//					}
//					if(s>=max(1ll,k)) miku+=(1ll<<t);
//				}
//				mans=max(mans,miku);
//			}
//		}
//	}
//	cout<<mans;
//}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int miku=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				miku=max(miku,(a[i]|a[j]|a[k]));
			}
		}
	}
	cout<<miku;
//	cout<<"ok"<<endl;
//	for(int i=1;i<=n;i++){
//		int x=a[i];
//		while(x){
//			num[i].push_back(x%2);
//			x/=2ll;
////			cout<<x<<endl;
//		}
//		for(int j=num[i].size()+1;j<=64;j++){
//			num[i].push_back(0);
//		}
////		cout<<"x: "<<x<<endl;
////		Sleep(500);
//	}
//	int ttt=-1ll;
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<64;j++){
//			if(num[i][j]){
//				ttt=max(ttt,j);
//			}
//			cout<<num[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<ttt<<endl;
//	if(ttt==-1ll) cout<<0;
//	else solve(ttt);
	return 0;
}
