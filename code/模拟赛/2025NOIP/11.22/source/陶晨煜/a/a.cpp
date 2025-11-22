#include <bits/stdc++.h>
using namespace std;
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fir first
#define sec second
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ll long long
#define yyy 0
int dy[11]={0,2,3,6,7,8,9};
const int mod=998244353;
void solve()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<yyy<<"\n";
        return;
    }
    n--;
    string s="";
    while(n>0) s+=(dy[n%7]+'0'),n/=7;
    reverse(all(s));
    ll ans=0;
    REP(i,0,s.size()-1) ans*=10,ans%=mod,ans+=(s[i]-'0'),ans%=mod;
    cout<<ans<<"\n";
}
//0 1 2 3 4 5 6 7 8 9
//0 2 3 6 7 8 9
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    Ios();
    int t;
    cin>>t;
    while(t--) solve();
    return yyy;
}