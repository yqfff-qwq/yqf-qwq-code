#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;

int f[13],a[13],cnt;
int dfs(int p,bool fl){
    if (!p){
        return 1;
    }
    if (!fl && (~f[p])){
        return f[p];
    }
    int up=(fl?a[p]:9),res=0;
    for (int i=0;i<=up;i++){
        if (i==1 || i==4 || i==5) continue;
        res+=dfs(p-1,fl && (i==up));
    }
    if (!fl){
        f[p]=res;
    }
    return res;
}
int solve(int x){
    cnt=0;
    while (x){
        a[++cnt]=x%10;
        x/=10;
    }
    return dfs(cnt,1);
}
void Main(){
    int n;
    cin>>n;
    int l=0,r=1e11,res;
    while (l<=r){
        int mid=(l+r)>>1;
        if (solve(mid)>=n){
            res=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<(res%mod)<<"\n";
}
signed main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    memset(f,-1,sizeof(f));

    int T;
    cin>>T;
    while (T--) Main();    

    return 0;
}