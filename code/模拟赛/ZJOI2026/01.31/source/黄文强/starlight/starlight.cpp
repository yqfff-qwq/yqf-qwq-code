#include<bits/stdc++.h>
// #define hwq ___ Jan_31th_mock_race
#define ll long long
using namespace std;
const int N=1e6+5;
int n;
int a[N];
inline void read(int &x){
	char c; while((c=getchar())<'0'||c>'9');
	for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c^48);
}
inline string er(int x){
	string s="";
	for(;x;x>>=1){
		s=(char)((x&1)+48)+s;
	}
	while(s.size()<10) s='0'+s;
	return s;
}

inline void solve(){
	cin>>n;
	// read(n);
	int ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		// read(a[i]);
	}
	// sort(a+1,a+n+1);
	// for(int i=1;i<n;++i){
		// if((a[i]+1)==a[i+1])
			// ++ans,++i;
	// }
			
	// for(int i=1;i<=n;++i)
		// cerr<<a[i]<<' ';
	// cerr<<'\n';
	// sort(a+1,a+n+1);
	
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			bool f=true;
			for(int k=1;k<=n&&f;++k)
				for(int x=0;x<=128+64+32+16+8+4+2+1&&f;++x)
					if(!((a[k]^x)<=(a[i]^x)||(a[k]^x)>=(a[j]^x)))
						f=false;
			if(f){
				++ans;
				// cerr<<"ans="<<ans<<"\n";
				// cerr<<"i="<<i<<": "<<a[i]<<'\n'<<er(a[i])<<'\n';
				// cerr<<"j="<<j<<": "<<a[j]<<'\n'<<er(a[j])<<'\n';
			}
		}
	}
	
	// for(int i=1;i<=n;++i)
		// cerr<<er(a[i])<<'\n';
// 	
	// for(int i=1;i<n;++i){
		// for(int j=i+1;j<=n;++j){
			// bool f=true;
			// for(int k=1;k<=n&&f;++k)
				// for(int x=0;x<=128+64+32+16+8+4+2+1&&f;++x)
					// if(!((a[k]^x)<=(a[i]^x)||(a[k]^x)>=(a[j]^x)))
						// f=false;
			// if(f){
				// ++ans;
				// cerr<<"ans="<<ans<<"\n";
				// cerr<<"i="<<i<<": "<<a[i]<<'\n'<<er(a[i])<<'\n';
				// cerr<<"j="<<j<<": "<<a[j]<<'\n'<<er(a[j])<<'\n';
			// }
		// }
	// }
	// cerr<<'\n';
	
	cout<<ans<<'\n';
}
int main(){
	freopen("starlight.in","r",stdin);
	freopen("starlight.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	// read(t);
	while(t--) solve();
	return 0;
}
/*
1 4 5 2 6
001 100 101 010 110

001 ^ 110 = 111 > 101 ^ 
001 ^ 110 = 111 >   

001 100
001 110
001 010

100 010
101 010

3 1 4 5 9 2 6
0011 0001 0100 0101 1001 0010 0110

0100 0010
0101 0010
1001 0010

114      51       4
1110010  0110011  0000100
*/