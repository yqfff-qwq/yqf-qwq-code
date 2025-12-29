#include <bits/stdc++.h>
//#define int long long
using namespace std;
string s;
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>s;s+='#';
    for(int i=1;s[i];i++)if(s[i]!=s[0]){cout<<i;return 0;}
    return 0;
}