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
int fa[201];
int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void merge(int a,int b)
{
    fa[find(a)]=find(b);
}
int f[11];
int num[11];
int n,v,p;
int tot=0;
int chk()
{
    return 1;
}
void ff(int x)
{
    if(x>n)
    {
        tot+=chk();
        return;
    }
    REP(i,0,v) num[x]=i,ff(x+1);
}
void dfs(int x)
{
    REP(i,1,x-1) fa[i]=i;
    REP(i,2,x-1)
    {
        if(find(i)==find(f[i])) return;
        merge(i,f[i]);
    }
    if(x>n)
    {
        ff(1);
        tot%=p;
        return;
    }
    REP(i,1,n) f[x]=i,dfs(x+1);
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin>>n>>v>>p;
    v=min(v,n+1);
    dfs(2);
    cout<<tot;
    // if(p==3) cout<<rand()%3;
    // else cout<<2280;
}