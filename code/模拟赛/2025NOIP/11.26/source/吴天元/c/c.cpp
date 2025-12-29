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
    cint N = 305;
    int n,k;
    struct node{
        int h,c;
        friend bool operator<(const node &a,const node &b){
            if(a.h==b.h){
                return a.c>b.c;
            }
            return a.h<b.h;
        }
    }a[N],b[N];

    multiset<int>S;

    priority_queue<node,vector<node>,less<node>>q;

    int work(){
        int ans=0;
        while(!q.empty()){
            int h=q.top().h;
            int c=q.top().c;
            q.pop();
            int x=*S.begin();
            if(h<=x){
                ans+=c*(x-h+1);
                h=x+1;
                q.push((node){h,c});
            }else{
                auto y=prev(S.lower_bound(h));
                S.erase(y);
                S.insert(h);
            }
        }
        return ans;
    }

    void clear(){
        S.clear();
        while(!q.empty()){
            q.pop();
        }
    }

    void SOLVE(){
        n=rd(),k=rd();
        bool fl=1;
        if(k<=100000){
            fl=0;
        }
        F(i,1,n){
            int h=rd(),c=rd();
            a[i].h=h,a[i].c=c;
            if(c>100){
                fl=0;
            }
            b[i]=a[i];
        }
        if(fl){
            F(i,1,n){
                clear();
                S.insert(a[i].h);
                F(j,1,n){
                    if(i!=j){
                        q.push(a[i]);
                    }
                }
            }
            printf("%lld\n",work());
            return ;
        }
        int ans=INF;
        F(i,1,n){
            int du=0;
            swap(a[n],a[i]);
            F(j,1,n-1){
                b[j]=a[j];
                if(a[j].h<=a[n].h){
                    du+=(a[n].h-a[j].h+1)*a[j].c;
                    a[j].h=a[n].h+1;
                }
            }
            b[n]=a[n];
            int SS=5;
            F(SS,1,(1<<(n-1))-1){
                int sz=0;
                clear();
                F(j,0,n-2){
                    if((SS>>j)&1){
                        S.insert(a[j+1].h);
                        // cerr<<a[j+1].h<<'\n';
                        ++sz;
                    }else{
                        q.push(a[j+1]);
                        // cerr<<a[j+1].h<<' '<<a[j+1].c<<'\n';
                    }
                }
                int res=work()+sz*k+du;
                // cerr<<i<<' '<<SS<<' '<<res<<'\n';
                cmn(ans,res);
            }
            F(j,1,n){
                a[j]=b[j];
            }
            swap(a[n],a[i]);
        }
        printf("%lld\n",ans);
        return ;
    }
}

signed main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int T=1;
    // T=rd();
    while(T--){
        Day_Tao::SOLVE();
    }
    return 0;
}