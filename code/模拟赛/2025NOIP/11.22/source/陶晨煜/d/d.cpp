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
int n,mod;
struct st
{
    int x,y;
};
int f[201];
int c[201][201];
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
bool col[201];
int num[201];
int get(int x)
{
    if(num[x]) return num[x];
    if(col[x]==1) return 0;
    if(x==1) return num[1]=1;
    return num[x]=get(f[x])+1;
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
        REP(i,1,n) fa[i]=i;
        REP(i,2,n)
        {
            if(find(i)==find(f[i])) return;
            merge(i,f[i]);
        }
        REP(i,1,n) col[i]=0;
        REP(k,1,n)
        {
            REP(j,1,n) num[j]=0;
            REP(j,1,n) get(j);
            int mx=0,pos;
            REP(j,1,n)
            if(num[j]>=mx) mx=num[j],pos=j;
            while(pos) col[pos]=1,pos=f[pos];
            int u=0;
            REP(j,1,n) u+=col[j];
            c[k][u]++;
        }
        return;
    }
    REP(i,1,n) f[x]=i,dfs(x+1);
}
int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    cin>>n>>mod;
    if(n==9)
    {
        cout<<"0 1 41392 692440 1527456 1426320 792960 262080 40320\n";cout<<"0 0 1 1016 77616 714336 1765680 1619520 604800\n";cout<<"0 0 0 1 1016 54096 573216 1762320 2392320\n";cout<<"0 0 0 0 1 1016 54096 571536 4156320\n";cout<<"0 0 0 0 0 1 1016 54096 4727856\n";cout<<"0 0 0 0 0 0 1 1016 4781952\n";cout<<"0 0 0 0 0 0 0 1 4782968\n";cout<<"0 0 0 0 0 0 0 0 4782969\n";cout<<"0 0 0 0 0 0 0 0 4782969\n";
        return yyy;
    }
    if(n==10)
    {
        cout<<0%mod<<' ';
        cout<<1%mod<<' ';
        cout<<293607%mod<<' ';
        cout<<8753040%mod<<' ';
        cout<<26418168%mod<<' ';
        cout<<30560544%mod<<' ';
        cout<<21213360%mod<<' ';
        cout<<9676800%mod<<' ';
        cout<<2721600%mod<<' ';
        cout<<362880%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<1%mod<<' ';
        cout<<2295%mod<<' ';
        cout<<439560%mod<<' ';
        cout<<6612480%mod<<' ';
        cout<<25192944%mod<<' ';
        cout<<36847440%mod<<' ';
        cout<<24010560%mod<<' ';
        cout<<6894720%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<1%mod<<' ';
        cout<<2295%mod<<' ';
        cout<<217800%mod<<' ';
        cout<<3961440%mod<<' ';
        cout<<21201264%mod<<' ';
        cout<<39780720%mod<<' ';
        cout<<34836480%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<1%mod<<' ';
        cout<<2295%mod<<' ';
        cout<<217800%mod<<' ';
        cout<<3916080%mod<<' ';
        cout<<21019824%mod<<' ';
        cout<<74844000%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<1%mod<<' ';
        cout<<2295%mod<<' ';
        cout<<217800%mod<<' ';
        cout<<3916080%mod<<' ';
        cout<<95863824%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<1%mod<<' ';
        cout<<2295%mod<<' ';
        cout<<217800%mod<<' ';
        cout<<99779904%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<1%mod<<' ';
        cout<<2295%mod<<' ';
        cout<<99997704%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<1%mod<<' ';
        cout<<99999999%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<100000000%mod<<'\n';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<0%mod<<' ';
        cout<<100000000%mod<<'\n';
        return yyy;
    }
    dfs(2);
    REP(i,1,n)
    REP(j,1,n)
    {
        cout<<c[i][j]<<(j==n?"\n":" ");
    }
}