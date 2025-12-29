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
#define uint unsigned int
#define yyy 0
const int mod=998244353;
const int maxn=3e3+10;
vector<int> g[maxn];
int deg[maxn];
int a[maxn];
bitset<maxn> del;
int dp[maxn][maxn];
void add(int x,int it)
{
    for(int j=3e3;j>=a[it];j--)
    dp[x][j]+=dp[x][j-a[it]],dp[x][j]-=(dp[x][j]>=mod?mod:0);
}
void work(int x)
{
    REP(i,0,3e3) dp[x][i]=0;
    dp[x][0]=1;
    for(auto it:g[x])
    add(x,it);
}
int tag[maxn];
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    Ios();
    int n,m,k,s1,s2;
    cin>>n>>m>>k>>s1>>s2;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++,deg[v]++;
    }
    REP(i,1,n) cin>>a[i];
    queue<int> q;
    REP(i,1,n) if(deg[i]<=k) q.push(i),del[i]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto it:g[t])
        {
            deg[it]--;
            if(deg[it]<=k&&!del[it]) q.push(it),del[it]=1;
        }
    }
    vector<int> v;
    REP(i,1,n) if(!del[i]) v.pb(i);
    if(!v.empty())
    {
        for(auto it:v) cout<<it<<" ";
        return yyy;
    }
    m=s1+s2;
    REP(x,1,n) tag[x]=0;
    while(m--)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int x,y;
            cin>>x>>y;
            int u=min(a[x],y);
            a[x]=y;
            for(auto it:g[x]) tag[it]=min(tag[it],u);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            if(tag[x]<=y) work(x),tag[x]=1e9;
            cout<<dp[x][y]<<"\n";
        }
    }
}