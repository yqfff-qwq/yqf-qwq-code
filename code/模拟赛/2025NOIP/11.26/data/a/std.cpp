#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
    int x=0,y=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*y;
}
string s;
signed main(){
    freopen("a4_2.in","r",stdin);
    freopen("a4_2.ans","w",stdout);
    cin>>s;
    int ans=0;
    while(ans+1<s.size()&&s[ans+1]==s[0])ans++;
    cout<<ans+1<<'\n';
    return 0;
}