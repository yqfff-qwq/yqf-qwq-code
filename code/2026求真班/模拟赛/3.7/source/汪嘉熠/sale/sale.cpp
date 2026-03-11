#include<bits/stdc++.h>
#define LL long long
using namespace std;
int const N=505;
LL w[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	LL I_cant_wait_no_mistake_I_m_in_love_like_a_drug_pick_me_up_These_feelings_will_never_leave_my_heart_love_me_love_me_ahhhh=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=j;k<=n;k++)
				I_cant_wait_no_mistake_I_m_in_love_like_a_drug_pick_me_up_These_feelings_will_never_leave_my_heart_love_me_love_me_ahhhh=max(I_cant_wait_no_mistake_I_m_in_love_like_a_drug_pick_me_up_These_feelings_will_never_leave_my_heart_love_me_love_me_ahhhh,(w[i]|w[j]|w[k]));
	cout<<I_cant_wait_no_mistake_I_m_in_love_like_a_drug_pick_me_up_These_feelings_will_never_leave_my_heart_love_me_love_me_ahhhh;
	return 0;
}
