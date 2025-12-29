#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define SZ(a) ((int)(a).size())
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define gc getchar
#define pc putchar
#define cint const int

cint mod = 998244353;
cint INF = 1e18;

inline void cmx(int &a,int b){
    a=max(a,b);
}

inline void cmn(int &a,int b){
    a=min(a,b);
}

inline void add(int &a,int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
    if(a<mod){
        a+=mod;
    }
}

inline int rd(){
    int x=0,y=1;
    char c=gc();
    for(;!isdigit(c);c=gc()){
        if(c=='-'){
            y=-1;
        }
    }
    for(;isdigit(c);c=gc()){
        x=(x<<3)+(x<<1)+(c^48);
    }
    return x*y;
}

namespace Day_Tao{
    cint N = 2e5 + 5;
    int n,m,a[N],b[N];
    pii q[N];
    void SOLVE(){
        n=rd(),m=rd();
        F(i,1,n){
            a[i]=rd();
        }
        F(i,1,n){
            b[i]=rd();
        }
        while(m--){
            int s=rd(),t=rd(),u=rd();
            int ans=0,e=0,l=1,r=0;
            bool fl=0;
            F(i,s,t-1){
                int now=a[i];
                if(now>u){
                    fl=1;
                    break;
                }
                int res=u-e;
                while(l<=r&&b[i]<q[r].fi){
                    res+=q[r].se;
                    r--;
                }
                q[++r]=mp(b[i],res);
                e=u;
                while(now){
                    int t=min(q[l].se,now);
                    now-=t;
                    ans+=t*q[l].fi;
                    q[l].se-=t;
                    if(q[l].se==0){
                        ++l;
                    }
                }
                e-=a[i];
            }
            if(fl){
                puts("-1");
                continue;
            }
            printf("%lld\n",ans);
        }
        return ;
    }
}

signed main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int T=1;
    // T=rd();
    while(T--){
        Day_Tao::SOLVE();
    }
    return 0;
}