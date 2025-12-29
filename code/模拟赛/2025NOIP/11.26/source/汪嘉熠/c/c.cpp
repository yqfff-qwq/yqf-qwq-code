#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int const N=305;
LL h[N],ct[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n; LL k;
	cin>>n>>k;
	LL mh=0,mct=0;
	for(int i=1;i<=n;i++){
		cin>>h[i]>>ct[i];
		mh=max(mh,h[i]);
		mct=max(mct,ct[i]);
	}
	if(k>=1e5&&mh<=300&&mct<=300){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(h[i]==mh)cnt++;
		if(cnt<=n-cnt){
			cout<<0;
			return 0;
		}
		vector<LL>vt;
		for(int i=1;i<=n;i++)
			if(h[i]!=mh)
				vt.emplace_back(ct[i]);
		sort(vt.begin(),vt.end());
		for(int i=1;i<n-cnt;i++)
			vt[i]+=vt[i-1];
		LL ans=(cnt*2-n)/(n-cnt)*vt[n-cnt-1]+vt[(cnt*2-n)%(n-cnt)-1];
		cout<<ans;
		return 0;
	}
	return 0;
}
